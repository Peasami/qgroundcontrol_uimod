#include "httprequestmanager.h"
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <QDebug>
#include <QJsonDocument>

RequestManager::RequestManager(QObject *parent) : QObject(parent) {
    networkManager = new QNetworkAccessManager(this);
    // _missionController = new MissionController() //San fix this
}

void RequestManager::GET(const QString &url) {
    qDebug() << "Sending GET request to:" << url;

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setRawHeader("User-Agent", "MyQtApp/1.0 (your@email.com)");

    reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, &RequestManager::onReplyFinished);
}

QByteArray RequestManager::getCoordinates(const QString searchingLocation)
{
    GET(searchingLocation);
    QByteArray data = QByteArray("Test data for RequestManager::getCoordinates()");

    return data;
}

void RequestManager::onReplyFinished() {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        qDebug() << "Response received:" << response;
        parseJson(response);
        emit requestFinished(response);
    } else {
        qDebug() << "Error:" << reply->errorString();
    }

    reply->deleteLater();
}

void RequestManager::parseJson(const QByteArray &jsonData)
{
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON parse error:" << parseError.errorString();
        return;
    }

    if (!doc.isArray()) {
        qDebug() << "Expected a JSON array";
        return;
    }

    const QJsonArray array = doc.array();
    for (const QJsonValue &value : array) {
        QJsonObject obj = value.toObject();
        QString name = obj["name"].toString();
        QString lat = obj["lat"].toString();
        QString lon = obj["lon"].toString();
        QString displayName = obj["display_name"].toString();

        qDebug() << "Name:" << name;
        qDebug() << "Lat:" << lat << "Lon:" << lon;
        qDebug() << "Display Name:" << displayName;
        qDebug() << "-----";


    }
}

