#pragma once

#include "response.hpp"
#include <QObject>
#include <QModelIndex>

class AdminTableData : public QObject
{
    Q_OBJECT
private:
    QList<res::FoundUser> admins;
    QList<QList<QVariant>> tableData;
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(const QModelIndex&);
    void postItemRemoved();
public:
    explicit AdminTableData(const QList<res::FoundUser>& admins, QObject *parent = nullptr);
    AdminTableData(QObject *parent = nullptr);
    ~AdminTableData();
    const QList<res::FoundUser>& getAdmins() const;
    QList<res::FoundUser>& getModifiableAdmins();
    void setTableData(const QList<QList<QVariant>>& variants);
    const QList<QList<QVariant>> getTableData() const;
    void itemModified();
public slots:
    void setItemAt(const res::FoundUser& admin,const QModelIndex & index = QModelIndex());
    void setItemAt(const int index,const res::FoundUser& item);
    void addItem(const res::FoundUser& admin);
    void removeItem(const QModelIndex& index = QModelIndex());
public:
    Q_INVOKABLE void setAdmins(const QList<res::FoundUser>& admins);
};

