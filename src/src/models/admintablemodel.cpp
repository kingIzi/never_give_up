#include "admintablemodel.hpp"

#include <QModelIndex>

void AdminTableModel::populationSignals()
{
    if (this->adminTableData_ptr){
        QObject::connect(this->adminTableData_ptr,&AdminTableData::postItemAppended,this,[=](){
            const auto index = this->adminTableData_ptr->getAdmins().size();
            this->beginInsertRows(QModelIndex(),index,index);
        });
        QObject::connect(this->adminTableData_ptr,&AdminTableData::postItemAppended,this,[=](){
            this->endInsertRows();
        });
        QObject::connect(this->adminTableData_ptr,&AdminTableData::preItemRemoved,this,[=](QModelIndex index){
            this->beginRemoveRows(QModelIndex(),index.row(),index.row());
        });
        QObject::connect(this->adminTableData_ptr,&AdminTableData::postItemRemoved,this,[=](){
            this->endRemoveRows();
        });
    }
}

AdminTableModel::AdminTableModel(QAbstractTableModel *parent)
    : QAbstractTableModel{parent},
      request(nullptr),
      response(nullptr),
      adminTableData_ptr(nullptr)
{
    QObject::connect(this,&AdminTableModel::populate,this,&AdminTableModel::onPopulate);
}

int AdminTableModel::rowCount(const QModelIndex &) const
{
    if (!this->adminTableData_ptr)
        return 0;
    return this->adminTableData_ptr->getAdmins().size();
}

int AdminTableModel::columnCount(const QModelIndex &) const
{
    if (this->tableHeaders.isEmpty())
        return 0;
    return this->tableHeaders.size();
}

QVariant AdminTableModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        try{
            const auto& data = this->switchDataResponse(index);
            if (data.isNull() || !data.isValid())
                throw std::bad_cast();
            return data;
        }
        catch(const std::bad_cast& e){
            qDebug() << "Failed to retrieve data" << e.what();
            return QVariant();
        }
    default:
        break;
    }
    return QVariant();
}

const QVariant AdminTableModel::switchDataResponse(const QModelIndex& index) const{
    if (this->adminTableData_ptr){
        const auto& users = this->adminTableData_ptr->getTableData();
        switch (index.column()){
        case 0:
            return users.at(index.row()).at(index.column()).toString();
        case 1:
            return users.at(index.row()).at(index.column()).toString();
        case 2:
            return users.at(index.row()).at(index.column()).toString();
        case 3:
            return users.at(index.row()).at(index.column()).toString();
        case 4:
            return users.at(index.row()).at(index.column()).toDateTime().toString(res::dateTimeFormatShort);
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QHash<int, QByteArray> AdminTableModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}

AdminTableData *AdminTableModel::tableData() const
{
    return this->adminTableData_ptr;
}

const QStringList AdminTableModel::headers() const
{
    return this->tableHeaders;
}

Response *AdminTableModel::tableResponse() const
{
    return this->response;
}

Request *AdminTableModel::tableRequests() const
{
    return this->request;
}

void AdminTableModel::setItemAt(const QModelIndex& index,const QString data)
{
    this->beginResetModel();
    switch (index.column()) {
    case 0:
        this->adminTableData_ptr->getModifiableAdmins()[index.row()].fullName = data.trimmed();
        break;
    case 1:
        this->adminTableData_ptr->getModifiableAdmins()[index.row()].email = data.trimmed();
        break;
    case 2:
        this->adminTableData_ptr->getModifiableAdmins()[index.row()].phoneNumber = data.trimmed();
        break;
    case 3:
        this->adminTableData_ptr->getModifiableAdmins()[index.row()].role = data.trimmed();
        break;
    case 4:
        this->adminTableData_ptr->getModifiableAdmins()[index.row()].dateCreated = QDateTime::fromString(data.trimmed(),res::dateTimeFormatShort);
        break;
    default:
        break;
    }
    this->adminTableData_ptr->itemModified();
    this->populationSignals();
    this->endResetModel();
    emit AdminTableModel::itemChanged(this->adminTableData_ptr->getAdmins().at(index.row()));
}

void AdminTableModel::onPopulate(const QList<res::FoundUser> users)
{
    if (this->adminTableData_ptr && this->adminTableData_ptr->getAdmins() == users){
        return;
    }
    this->beginResetModel();
    if (this->adminTableData_ptr){
        this->adminTableData_ptr->disconnect(this);
        this->adminTableData_ptr->deleteLater();
    }
    this->adminTableData_ptr = new AdminTableData(users);
    this->populationSignals();
    this->endResetModel();

}

void AdminTableModel::setHeaders(const QStringList &headers)
{
    if (this->tableHeaders != headers)
        this->tableHeaders = headers;
}

void AdminTableModel::setTableResponse(Response *response)
{
    this->response = response;
    emit AdminTableModel::tableResponseChanged();
}

void AdminTableModel::setTableRequests(Request *request)
{
    this->request = request;
    emit AdminTableModel::tableRequestsChanged();
}

void AdminTableModel::setTableData(AdminTableData *adminTableData)
{
    if (this->adminTableData_ptr){
        this->adminTableData_ptr->disconnect(this);
        this->adminTableData_ptr->deleteLater();
    }
    this->adminTableData_ptr = adminTableData;
}

