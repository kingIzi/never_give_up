#include "admintablemodel.hpp"

#include <QModelIndex>
#include <QQmlApplicationEngine>

void AdminTableModel::populationSignals()
{
    if (this->adminTableData_ptr2){
        QObject::connect(this->adminTableData_ptr2,&AdminTableData::postItemAppended,this,[this](){
            const auto index = this->adminTableData_ptr2->getPersons().size();
            this->beginInsertRows(QModelIndex(),index,index);
        });
        QObject::connect(this->adminTableData_ptr2,&AdminTableData::postItemAppended,this,[this](){
            this->endInsertRows();
        });
        QObject::connect(this->adminTableData_ptr2,&AdminTableData::preItemRemoved,this,[this](QModelIndex index){
            this->beginRemoveRows(QModelIndex(),index.row(),index.row());
        });
        QObject::connect(this->adminTableData_ptr2,&AdminTableData::postItemRemoved,this,[this](){
            this->endRemoveRows();
        });
    }
}

AdminTableModel::AdminTableModel(QAbstractTableModel *parent)
    : QAbstractTableModel{parent},
      request(nullptr),
      response(nullptr),
      adminTableData_ptr2(nullptr)
{
    QObject::connect(this,&AdminTableModel::populate,this,&AdminTableModel::onPopulate);
    QObject::connect(this,&AdminTableModel::updatedItem,this,&AdminTableModel::onUpdatedItem);
}

AdminTableModel::~AdminTableModel()
{
    qDebug() << "Admin Table Model destroyed";
}

int AdminTableModel::rowCount(const QModelIndex &) const
{
    if (!this->adminTableData_ptr2)
        return 0;
    return this->adminTableData_ptr2->getPersons().size();
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
    if (this->adminTableData_ptr2){
        const auto& users = this->adminTableData_ptr2->getTableData();
        switch (index.column()){
        case 0:
            return this->adminTableData_ptr2->getPersons().at(index.row())->fullName();
        case 1:
            return this->adminTableData_ptr2->getPersons().at(index.row())->email();
        case 2:
            return this->adminTableData_ptr2->getPersons().at(index.row())->phoneNumber();
        case 3:
            return this->adminTableData_ptr2->getPersons().at(index.row())->role();
        case 4:
            return this->adminTableData_ptr2->getPersons().at(index.row())->dateCreated().toString(res::dateTimeFormatShort);
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

AdminTableData *AdminTableModel::adminTableData() const
{
    return this->adminTableData_ptr2;
}

void AdminTableModel::setItemAt(const QModelIndex& index,const QString data)
{
    if (data.isEmpty()) { return; }
    this->beginResetModel();
    switch (index.column()) {
    case 0:
        this->adminTableData_ptr2->getModifiablePersons()[index.row()]->setfullName(data.trimmed());
        break;
    case 1:
        this->adminTableData_ptr2->getModifiablePersons()[index.row()]->setEmail(data.trimmed());
        break;
    case 2:
        this->adminTableData_ptr2->getModifiablePersons()[index.row()]->setPhoneNumber(data.trimmed());
        break;
    case 3:
        this->adminTableData_ptr2->getModifiablePersons()[index.row()]->setRole(data.trimmed());
        break;
    default:
        break;
    }
    this->adminTableData_ptr2->itemModified();
    this->populationSignals();
    this->endResetModel();
}

Person *AdminTableModel::findItemAt(const QModelIndex &index) const
{
    return this->adminTableData_ptr2->getPersons().at(index.row());
}

QVariantMap AdminTableModel::getItemAtAsMap(const QModelIndex &index) const
{
    const auto& person = this->adminTableData_ptr2->getPersons().at(index.row());
    return person->getAsMap();
}

void AdminTableModel::onPopulate(const QList<Person*> persons)
{
    if (persons.isEmpty())
        return;
    this->beginResetModel();
    if (this->adminTableData_ptr2 && this->adminTableData_ptr2->getPersons() == persons){
        this->adminTableData_ptr2->disconnect(this);
        this->adminTableData_ptr2->deleteLater();
    }
    this->adminTableData_ptr2 = new AdminTableData(persons);
    this->adminTableData_ptr2->setPersons(persons);
    this->populationSignals();
    this->adminTableData_ptr2->itemModified();
    this->endResetModel();
}

void AdminTableModel::onUpdatedItem(Person *person)
{
//    const auto it = std::find_if(std::begin(this->adminTableData_ptr2->getPersons()),std::end(this->adminTableData_ptr2->getPersons()),[person](const Person* value){
//        return person->userId().compare(value->userId()) == 0;
//    });
//    if (it != std::end(this->adminTableData_ptr2->getPersons())){
//        qDebug() << "ITEM FOUND";
//        this->beginResetModel();
//        this->adminTableData_ptr2->setItemAt(std::distance(it,std::end(this->adminTableData_ptr2->getPersons())),person);
//        this->populationSignals();
//        this->endResetModel();
//    }
    const auto it = std::find_if(std::begin(this->adminTableData_ptr2->getPersons()),std::end(this->adminTableData_ptr2->getPersons()),[person](const Person* value){
        return person->userId().compare(value->userId()) == 0;
    });
    if (it != std::end(this->adminTableData_ptr2->getPersons())){
        qDebug() << "ITEM FOUND";
        this->beginResetModel();
        this->adminTableData_ptr2->setItemAt(std::distance(it,std::end(this->adminTableData_ptr2->getPersons())),person);
        this->populationSignals();
        this->endResetModel();
    }
    qDebug() << this->adminTableData_ptr2->getPersons().at(0)->phoneNumber();
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

void AdminTableModel::setAdminTableData(AdminTableData *adminTableData)
{
    if (this->adminTableData_ptr2 != adminTableData){
        this->adminTableData_ptr2 = adminTableData;
        emit AdminTableModel::adminTableDataChanged();
    }
}
