#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>

int main(int argc, char *argv[])
{
    // wait a bit to sync with weston that is still starting
    QThread::sleep(1);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url("qrc:/helloWorld/QML/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
