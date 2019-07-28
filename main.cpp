#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "clientmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Client::Manager::ClientManager manager;
    manager.setEndpointAddress(QUrl("http://localhost:8080/currTele"));


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("manager", &manager);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
