#pragma once

#include "admin.hpp"
#include <qqml.h>
#include <QAbstractTableModel>

class AdminTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)
    Q_PROPERTY(Request* tableRequests READ tableRequests WRITE setTableRequests NOTIFY tableRequestsChanged);
    Q_PROPERTY(Response* tableResponse READ tableResponse WRITE setTableResponse NOTIFY tableResponseChanged);
    Q_PROPERTY(QStringList headers READ headers WRITE setHeaders NOTIFY headersChanged);
    Q_PROPERTY(AdminTableData* tableData READ tableData WRITE setTableData NOTIFY tableDataChanged)
    //Q_PROPERTY(AdminTableData* adminTableData READ adminTableData WRITE setAdminTableData NOTIFY adminTableDataChanged)
private:
    QStringList tableHeaders;
    AdminTableData* adminTableData_ptr;
    Request* request;
    Response* response;
private:
    void populationSignals();
public:
    explicit AdminTableModel(QAbstractTableModel * parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    const QVariant switchDataResponse(const QModelIndex& index) const;

    QHash<int, QByteArray> roleNames() const override;

    AdminTableData* tableData() const;

    const QStringList headers() const;
    //const AdminTableData* adminTableData() const;
    Response* tableResponse() const;
    Request* tableRequests() const;

    Q_INVOKABLE void setItemAt(const QModelIndex& index,const QString data);

signals:
    void headersChanged();
    void populate(const QList<res::FoundUser>);
    void tableRequestsChanged();
    void tableResponseChanged();
    void tableDataChanged();
    void itemChanged(const res::FoundUser);
    //void adminTableDataChanged();

public slots:
    void onPopulate(const QList<res::FoundUser> users);
    void setHeaders(const QStringList& headers);
    void setTableResponse(Response* response);
    void setTableRequests(Request* request);
    void setTableData(AdminTableData* adminTableData);
    //void setAdminTableData(AdminTableData* adminTableData);
};


