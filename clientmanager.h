#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>
#include <QDebug>

//    "lat":0,
//    "lon":0,
//    "latRaw":0,
//    "lonRaw":0,
//    "alt":0,
//    "relativealt":0,
//    "vx":0,
//    "vy":0,
//    "vz":0,
//    "hdg":0,
//    "roll":0,
//    "pitch":0,
//    "yaw":0,
//    "rollspeed":0,
//    "pitchspeed":0,
//    "yawspeed":0,


namespace Client{
    namespace DataFrame{
        struct FlightData{
            double Lat;
            double Lon;
            double latRaw;
            double lonRaw;
            double Alt;
            double RelativeAlt;
            double Vx;
            double Vy;
            double Vz;
            double Hdg;
            double Row;
            double Pitch;
            double Yaw;
            double RollSpeed;
            double PitchSpeed;
            double YawSpeed;
        };

    }

    namespace Manager{
        typedef int ReqDelay;
        class ClientManager : public QObject
        {
            Q_OBJECT
        public:
            explicit ClientManager(QObject *parent = nullptr);
            void establishConnection();
            QUrl getEndpointAddress() const;
            void setEndpointAddress(const QUrl &value);
            Q_INVOKABLE void startDownloadData();
           // ~ClientManager(){delete requestTimer; delete }
        signals:

        public slots:
            void getREST();
            void getRequestData(QNetworkReply* reply);

        private:
            QTimer* requestTimer;
            ReqDelay delay;
            QNetworkAccessManager* network;
            QUrl endpointAddress;
            QNetworkRequest request;
        };
      }
}
#endif // CLIENTMANAGER_H
