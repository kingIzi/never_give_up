#include "admintabledata.hpp"

//AdminTableData::AdminTableData(const QList<res::FoundUser>& admins, QObject *parent)
//    : QObject{parent},
//      admins(admins)
//{
//    this->tableData.reserve(this->admins.size());
//    for (const auto& admin : this->admins){
//        const auto data = admin.getFullNameAndEmailAndTelephoneAndRoleAndDateCreated();
//        this->tableData.emplaceBack(data);
//    }
//}

AdminTableData::AdminTableData(const QList<Person*>& persons,QObject * parent) :
    QObject{parent},
    persons(persons)
{
    if (this->persons.isEmpty()) { return; }
    this->tableData.reserve(this->persons.size());
    for (const auto& person : this->persons){
        const auto dataList = person->getFullNameAndEmailAndTelephoneAndRoleAndDateCreated();
        this->tableData.emplaceBack(dataList);
    }
}

AdminTableData::AdminTableData(QObject *parent)
{

}

AdminTableData::~AdminTableData()
{
    qDebug() << "Admin table data destroyed";
}

const QList<Person *> &AdminTableData::getPersons() const
{
    return this->persons;
}

QList<Person *> &AdminTableData::getModifiablePersons()
{
    return this->persons;
}

void AdminTableData::itemModified()
{
    if (!this->tableData.isEmpty())
        this->tableData.clear();
    this->tableData.reserve(this->persons.size());
    for (const auto& person : this->persons){
        const auto data = person->getFullNameAndEmailAndTelephoneAndRoleAndDateCreated();
        this->tableData.emplaceBack(data);
    }
}

void AdminTableData::setItemAt(Person *person, const QModelIndex &index)
{
    if (!index.isValid()) { return; }
    const auto currAdmin = this->persons.at(index.row());
    if (currAdmin == person) { return; }
    this->persons[index.row()] = person;
}

void AdminTableData::setItemAt(const int index, Person *person)
{
    if (index < 0 || index >= this->getPersons().size()) { return; }
    const auto currAdmin = this->persons.at(index);
    if (currAdmin == person) { return; }
    this->persons[index] = person;
}

void AdminTableData::addItem(Person *person)
{
    emit AdminTableData::preItemAppended();
    this->persons.push_back(person);
    emit AdminTableData::postItemAppended();
}

//void AdminTableData::setItemAt(const res::FoundUser &admin,const QModelIndex & index)
//{
//    if (!index.isValid()) { return; }
//    const auto currAdmin = this->admins.at(index.row());
//    if (currAdmin == admin) { return; }
//    this->admins[index.row()] = admin;
//}

//void AdminTableData::setItemAt(const int index, const res::FoundUser &admin)
//{
//    if (index < 0 || index >= this->admins.size()) { return; }
//    const auto currAdmin = this->admins.at(index);
//    if (currAdmin == admin) { return; }
//    this->admins[index] = admin;
//}

//void AdminTableData::addItem(const res::FoundUser &admin)
//{
//    emit AdminTableData::preItemAppended();
//    this->admins.push_back(admin);
//    emit AdminTableData::postItemAppended();
//}

void AdminTableData::removeItem(const QModelIndex &index)
{
    emit AdminTableData::preItemRemoved(index);
    this->persons.remove(index.row());
    emit AdminTableData::postItemRemoved();
}

void AdminTableData::setPersons(const QList<Person *> &persons)
{
    this->persons = persons;
}

//const QList<res::FoundUser>  &AdminTableData::getAdmins() const
//{
//    return this->admins;
//}

//QList<res::FoundUser> &AdminTableData:: getModifiableAdmins()
//{
//    return this->admins;
//}

void AdminTableData::setTableData(const QList<QList<QVariant> > &variants)
{
    if (this->tableData != variants)
        this->tableData = variants;
}

const QList<QList<QVariant> > AdminTableData::getTableData() const
{
    return this->tableData;
}

//void AdminTableData::setAdmins(const QList<res::FoundUser> &admins)
//{
//    if (this->admins != admins)
//        this->admins = admins;
//}

