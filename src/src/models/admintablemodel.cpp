#include "admintablemodel.hpp"
#include <QModelIndex>

AdminTableModel::AdminTableModel(QAbstractTableModel *parent)
    : QAbstractTableModel{parent}
{

}

int AdminTableModel::rowCount(const QModelIndex &) const
{
    return 10;
    //return this->adminTableData_ptr->getAdmins().size();
}

int AdminTableModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QVariant AdminTableModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
        case Qt::DisplayRole:
            return QString("%1, %2").arg(index.column()).arg(index.row());
        default:
            break;
    }
//    const auto admins = this->adminTableData_ptr->getAdmins();
//    switch (role) {
//    case AdminTableModel::FIRST_NAME:
//        return admins.at(index.row()).at(index.column()).fullName;
//    case AdminTableModel::LAST_NAME:
//        return QVariant();
//    case AdminTableModel::TELEPHONE:
//        return admins.at(index.row()).at(index.column()).telephone;
//    default:
//        break;
//    }

    return QVariant();
}

QHash<int, QByteArray> AdminTableModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
//    return { {FIRST_NAME, "firstName"}, {LAST_NAME, "lastname"},{TELEPHONE, "telephone"},
    //    {ADDRESS, "address"}, {DATE_OF_BIRTH, "dateOBirth"}};
}

const int AdminTableModel::rowSize() const
{
    return 5;
}

//AdminTableData *AdminTableModel::adminTableData() const
//{
//    return this->adminTableData_ptr;
//}

//void AdminTableModel::setAdminTableData(AdminTableData *adminTableData)
//{
//    if (this->adminTableData_ptr)
//        this->adminTableData_ptr->disconnect();

//    this->adminTableData_ptr = adminTableData;

//    if (this->adminTableData_ptr)
//        this->adminTableData_ptr = adminTableData;

//}

