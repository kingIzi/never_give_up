#pragma once

#include "admintabledata.hpp"
#include <qqml.h>
#include <QAbstractTableModel>

class AdminTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)
    Q_PROPERTY(QStringList headers READ headers WRITE setHeaders NOTIFY headersChanged);
    Q_PROPERTY(AdminTableData* adminTableData READ adminTableData WRITE setAdminTableData NOTIFY adminTableDataChanged)
private:
    QStringList tableHeaders;
    AdminTableData* adminTableData_ptr2;
private:
    void populationSignals();
public:
    explicit AdminTableModel(QAbstractTableModel * parent = nullptr);
    ~AdminTableModel();

    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    const QVariant switchDataResponse(const QModelIndex& index) const;

    QHash<int, QByteArray> roleNames() const override;

    const QStringList headers() const;
    AdminTableData* adminTableData() const;

    Q_INVOKABLE void setItemAt(const QModelIndex& index,const QString data);
    //Q_INVOKABLE res::FoundUser findItemAt(const QModelIndex& index) const;
    Q_INVOKABLE Person* findItemAt(const QModelIndex& index) const;
    Q_INVOKABLE QVariantMap getItemAtAsMap(const QModelIndex& index) const;
signals:
    void headersChanged();
    //void populate(const QList<res::FoundUser>);
    void populate(const QList<Person*>);
    void tableDataChanged();
    void itemChanged(const res::FoundUser);
    //void updatedItem(const res::FoundUser);
    void updatedItem(Person*);
    void adminTableDataChanged();
    //void adminTableDataChanged();

public slots:
    void onPopulate(const QList<Person*> users);
    //void onUpdatedItem(const res::FoundUser item);
    void onUpdatedItem(Person* person);
    void setHeaders(const QStringList& headers);
    void setAdminTableData(AdminTableData* adminTableData);
    //void setAdminTableData(AdminTableData* adminTableData);
};


