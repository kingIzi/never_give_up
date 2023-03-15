#pragma once

//#include "response.hpp"
#include <QObject>

class AdminTableData : public QObject
{
    Q_OBJECT
private:
    //QList<QList<res::User>> admins;
    QStringList headers;
public:
    explicit AdminTableData(const QList<QList<res::User>>& admins, const QStringList headersSize, QObject *parent = nullptr);
    //const QList<QList<res::User>>& getAdmins() const;
    Q_INVOKABLE const QStringList getHeaders() const;
};

