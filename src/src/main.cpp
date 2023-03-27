#include <QApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
//#include <QtWebEngineQuick/QtWebEngineQuick>

#include "admintablemodel.hpp"
#include "admin.hpp"

int main(int argc, char *argv[])
{
    QApplication::setOrganizationName("Izi industries");
    QApplication::setOrganizationDomain("http://localhost:8084");
    QApplication::setApplicationName("Boyebi App");
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    //QtWebEngineQuick::initialize();

    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "never_give_up_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    Admin admin("http://localhost:8084");
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/never_give_up/forms/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("_admin",&admin);
    qmlRegisterType<AdminTableModel>("AdminTableModel",1,0,"AdminTableModel");
    qmlRegisterSingletonType(QUrl("qrc:/never_give_up/forms/qml/Constants.qml"), "Constants", 1, 0, "Constants");
    engine.load(url);

    return app.exec();
}
