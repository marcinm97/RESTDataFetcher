#include "clientmanager.h"

namespace Client{
    namespace Manager{

        ClientManager::ClientManager(QObject *parent) : QObject(parent), network(new QNetworkAccessManager(this)),
            requestTimer(new QTimer(this)), delay(1) {}

        QUrl ClientManager::getEndpointAddress() const{
            return endpointAddress;
        }

        void ClientManager::setEndpointAddress(const QUrl &value){
            if(!value.isValid())
                return;

            endpointAddress = value;
            establishConnection();
        }

        void ClientManager::establishConnection(){
            request.setUrl(endpointAddress);

            connect(network, &QNetworkAccessManager::finished,this, &ClientManager::getRequestData);
            connect(requestTimer, &QTimer::timeout, this, &ClientManager::getREST);

        }
        void ClientManager::startDownloadData(){
            if(!requestTimer->isActive()){
                requestTimer->start(delay);
            }else
                requestTimer->stop();
        }

        void ClientManager::getREST(){
            network->get(request);
        }

        void ClientManager::getRequestData(QNetworkReply* reply){
            qDebug() << reply->readAll();

            reply->deleteLater();
        }
    }
}
