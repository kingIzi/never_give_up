#include <QtTest>
#include <QCoreApplication>
#include "../../src/include/admin.hpp"

// add necessary includes here

class ComicTests : public QObject
{
    Q_OBJECT
private:
    std::unique_ptr<Admin> admin;
public:
    ComicTests();
    ~ComicTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void createComic();

};

ComicTests::ComicTests()
{
    this->admin = std::make_unique<Admin>("http://localhost:8084");
}

ComicTests::~ComicTests()
{

}

void ComicTests::initTestCase()
{

}

void ComicTests::cleanupTestCase()
{

}

void ComicTests::createComic()
{
    QVERIFY(!this->admin->getIdToken().isEmpty());
}

QTEST_MAIN(ComicTests)

#include "tst_comictests.moc"
