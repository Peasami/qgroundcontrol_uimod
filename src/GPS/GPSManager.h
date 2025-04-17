/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtCore/QLoggingCategory>
#include <QtCore/QObject>

#include "httprequestmanager.h" //San remove later

Q_DECLARE_LOGGING_CATEGORY(GPSManagerLog)

class GPSRtk;

class GPSManager : public QObject
{
    Q_OBJECT

public:
    GPSManager(QObject *parent = nullptr);
    ~GPSManager();

    static GPSManager *instance();

    GPSRtk *gpsRtk() { return _gpsRtk; }

private slots:
    void handleResponse(const QByteArray &response); //San remove later

private:
    GPSRtk *_gpsRtk = nullptr;

    RequestManager *requestManager; //San remove later
};
