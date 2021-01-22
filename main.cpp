#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tasklist.h"
#include <QtQml>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<TaskList>("TaskList", 1, 0, "TaskList");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
