#include <QtTest>
#include <QCoreApplication>
#include "../../src/include/admin.hpp"

// add necessary includes here

class sessionTests : public QObject
{
    Q_OBJECT
private:
    std::unique_ptr<Admin> admin;
public:
    sessionTests();
    ~sessionTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void loginEmailNotFound();
    void loginEmptyEmail();
    void loginEmptyEmailAndPassword();
    void loginMissingPassword();
    void loginIncorrectPassword();
    void loginCorrectCrudentials();

};

sessionTests::sessionTests()
{
    this->admin = std::make_unique<Admin>("http://localhost:8084");
}

sessionTests::~sessionTests()
{

}

void sessionTests::initTestCase()
{

}

void sessionTests::cleanupTestCase()
{

}

void sessionTests::loginEmailNotFound()
{
    const QVariantMap loginUser = {
        {QString("email"),QString("admin@admin.m")},
        {QString("password"),QString("admin123")},
        {QString("returnSecureToken"),true}
    };
    const auto expectedMsg = "EMAIL_NOT_FOUND";
    const auto code = 400;
    QSignalSpy readyRead(this->admin->getRequestPtr(),SIGNAL(replyReadyRead(QJsonDocument)));
    QSignalSpy unsuccessfull(this->admin->getResponsePtr(),SIGNAL(requestUnsuccessfullError(const res::Error)));
    QObject::connect(this->admin->getResponsePtr(),&Response::requestUnsuccessfullError,this,[this,expectedMsg](const res::Error error){
        QCOMPARE(error.message,expectedMsg);
        QCOMPARE(error.code,code);
    });
    this->admin->requestLoginUser(loginUser);
    readyRead.wait(5000);
    QCOMPARE(readyRead.count(),1);
    QCOMPARE(unsuccessfull.count(),1);
    QVERIFY(this->admin->getIdToken().isEmpty());
}

void sessionTests::loginEmptyEmail()
{
    const QVariantMap loginUser = {
        {QString("email"),QString("")},
        {QString("password"),QString("adMin123456")},
        {QString("returnSecureToken"),true}
    };
    const auto expectedMsg = "EMAIL_NOT_FOUND";
    const auto code = 400;
    QSignalSpy readyRead(this->admin->getRequestPtr(),SIGNAL(replyReadyRead(QJsonDocument)));
    QSignalSpy unsuccessfull(this->admin->getResponsePtr(),SIGNAL(requestUnsuccessfullError(const res::Error)));
    QObject::connect(this->admin->getResponsePtr(),&Response::requestUnsuccessfullError,this,[this,expectedMsg](const res::Error error){
        QCOMPARE(error.message,expectedMsg);
        QCOMPARE(error.code,code);
    });
    this->admin->requestLoginUser(loginUser);
    readyRead.wait(5000);
    QCOMPARE(readyRead.count(),1);
    QCOMPARE(unsuccessfull.count(),1);
    QVERIFY(this->admin->getIdToken().isEmpty());
}

void sessionTests::loginEmptyEmailAndPassword()
{
    const QVariantMap loginUser = {
        {QString("email"),QString("")},
        {QString("password"),QString("")},
        {QString("returnSecureToken"),true}
    };
    const auto expectedMsg = "EMAIL_NOT_FOUND";
    const auto code = 400;
    QSignalSpy readyRead(this->admin->getRequestPtr(),SIGNAL(replyReadyRead(QJsonDocument)));
    QSignalSpy unsuccessfull(this->admin->getResponsePtr(),SIGNAL(requestUnsuccessfullError(const res::Error)));
    QObject::connect(this->admin->getResponsePtr(),&Response::requestUnsuccessfullError,this,[this,expectedMsg](const res::Error error){
        QCOMPARE(error.message,expectedMsg);
        QCOMPARE(error.code,code);
    });
    this->admin->requestLoginUser(loginUser);
    readyRead.wait(5000);
    QCOMPARE(readyRead.count(),1);
    QCOMPARE(unsuccessfull.count(),1);
    QVERIFY(this->admin->getIdToken().isEmpty());
}

void sessionTests::loginMissingPassword()
{
    const QVariantMap loginUser = {
        {QString("email"),QString("admin@admin.com")},
        {QString("password"),QString("")},
        {QString("returnSecureToken"),true}
    };
    const auto expectedMsg = "MISSING_PASSWORD";
    const auto code = 400;
    QSignalSpy readyRead(this->admin->getRequestPtr(),SIGNAL(replyReadyRead(QJsonDocument)));
    QSignalSpy unsuccessfull(this->admin->getResponsePtr(),SIGNAL(requestUnsuccessfullError(const res::Error)));
    QObject::connect(this->admin->getResponsePtr(),&Response::requestUnsuccessfullError,this,[this,expectedMsg](const res::Error error){
        QCOMPARE(error.message,expectedMsg);
        QCOMPARE(error.code,code);
    });
    this->admin->requestLoginUser(loginUser);
    readyRead.wait(5000);
    QCOMPARE(readyRead.count(),1);
    QCOMPARE(unsuccessfull.count(),1);
    QVERIFY(this->admin->getIdToken().isEmpty());
}

void sessionTests::loginIncorrectPassword()
{
    const QVariantMap loginUser = {
        {QString("email"),QString("admin@admin.com")},
        {QString("password"),QString("adMin123456")},
        {QString("returnSecureToken"),true}
    };
    const auto expectedMsg = "INVALID_PASSWORD";
    const auto code = 400;
    QSignalSpy readyRead(this->admin->getRequestPtr(),SIGNAL(replyReadyRead(QJsonDocument)));
    QSignalSpy unsuccessfull(this->admin->getResponsePtr(),SIGNAL(requestUnsuccessfullError(const res::Error)));
    QObject::connect(this->admin->getResponsePtr(),&Response::requestUnsuccessfullError,this,[this,expectedMsg](const res::Error error){
        QCOMPARE(error.message,expectedMsg);
        QCOMPARE(error.code,code);
    });
    this->admin->requestLoginUser(loginUser);
    readyRead.wait(5000);
    QCOMPARE(readyRead.count(),1);
    QCOMPARE(unsuccessfull.count(),1);
    QVERIFY(this->admin->getIdToken().isEmpty());
}

void sessionTests::loginCorrectCrudentials()
{
    const QVariantMap loginUser = {
        {QString("email"),QString("admin@admin.com")},
        {QString("password"),QString("admin123456")},
        {QString("returnSecureToken"),true}
    };
    QSignalSpy readyRead(this->admin->getRequestPtr(),SIGNAL(replyReadyRead(QJsonDocument)));
    QSignalSpy unsuccessfull(this->admin->getResponsePtr(),SIGNAL(requestUnsuccessfullError(const res::Error)));
    this->admin->requestLoginUser(loginUser);
    readyRead.wait(5000);
    QCOMPARE(readyRead.count(),1);
    QCOMPARE(unsuccessfull.count(),0);
    QVERIFY(!this->admin->getIdToken().isEmpty());
}




QTEST_MAIN(sessionTests)

#include "tst_sessiontests.moc"
