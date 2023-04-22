#include "admintabledata.hpp"

AdminTableData::AdminTableData(const QList<Person*>& persons,QObject * parent) :
    QObject{parent},
    persons(persons)
{

}

AdminTableData::AdminTableData(QObject *parent) :
    QObject{parent}
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
