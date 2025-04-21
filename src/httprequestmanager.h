#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <MissionController.h>

class RequestManager : public QObject {
    Q_OBJECT
   public:
    explicit RequestManager(QObject *parent = nullptr);
    void GET(const QString &url);

    Q_INVOKABLE void getCoordinates(const QString searchingLocation);
    Q_INVOKABLE void testFunc();

    static void registerQmlTypes();

   signals:
    void requestFinished(const QByteArray &response);

   private slots:
    void onReplyFinished();
    void parseJson(const QByteArray &json);

   private:
    QNetworkAccessManager *networkManager;
    QNetworkReply *reply;
    // MissionController _missionController;
};

#endif // REQUESTMANAGER_H
