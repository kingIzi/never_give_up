#include <QApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#include <QQmlContext>

#include "admintablemodel.hpp"
#include "comiclistmodel.hpp"
#include "categoriesmodel.hpp"
#include "authorlistmodel.hpp"
//#include "admin.hpp"
#include "agent.hpp"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QSettings::setDefaultFormat(QSettings::IniFormat); // personal preference

    QApplication app(argc, argv);
    app.setOrganizationName("IziIndustries");
    app.setOrganizationDomain("http://localhost:8084");
    app.setApplicationName("BoyebiApp");

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "never_give_up_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

//    Admin admin("http://localhost:8084");
    //Agent agent;
    const auto agent = std::make_unique<Agent>(&app);

    const auto adminTableData = std::make_unique<AdminTableData>(agent.get());
    const auto comicListData = std::make_unique<ComicListData>(agent.get());
    const auto categoryListData =  std::make_unique<CategoriesListData>(agent.get());
    const auto authorListData = std::make_unique<AuthorListData>(agent.get());

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/never_give_up/forms/qml/main.qml"_qs);

    engine.rootContext()->setContextProperty("_agent",agent.get());

    engine.rootContext()->setContextProperty("_adminTableData",adminTableData.get());
    engine.rootContext()->setContextProperty("_comicListData",comicListData.get());
    engine.rootContext()->setContextProperty("_categoryListData",categoryListData.get());
    engine.rootContext()->setContextProperty("_authorListData",authorListData.get());

    qmlRegisterType<AdminTableModel>("AdminTableModel",1,0,"AdminTableModel");
    qmlRegisterType<ComicListModel>("ComicTableModel",1,0,"ComicTableModel");
    qmlRegisterType<CategoriesModel>("CategoriesModel",1,0,"CategoriesModel");
    qmlRegisterType<AuthorListModel>("AuthorListModel",1,0,"AuthorListModel");
    qmlRegisterSingletonType(QUrl("qrc:/never_give_up/forms/qml/Constants.qml"), "Constants", 1, 0, "Constants");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
