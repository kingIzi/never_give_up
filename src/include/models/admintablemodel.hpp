#pragma once

#include <qqml.h>
#include <QAbstractTableModel>

class AdminTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)
    //Q_PROPERTY(AdminTableData* adminTableData READ adminTableData WRITE setAdminTableData NOTIFY adminTableDataChanged)
private:
    //AdminTableData* adminTableData_ptr;
public:
    explicit AdminTableModel(QAbstractTableModel * parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE const int rowSize() const;

    //AdminTableData* adminTableData() const;

    enum {
        FIRST_NAME, LAST_NAME, TELEPHONE, ADDRESS, EMAIL, DATE_OF_BIRTH
    };

public slots:
    //void setAdminTableData(AdminTableData* adminTableData);

};


