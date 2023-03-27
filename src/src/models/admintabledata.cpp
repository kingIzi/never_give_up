#include "admintabledata.hpp"

AdminTableData::AdminTableData(const QList<res::FoundUser>& admins, QObject *parent)
    : QObject{parent},
      admins(admins)
{
    this->tableData.reserve(this->admins.size());
    for (const auto& admin : this->admins){
        const auto data = admin.getFullNameAndEmailAndTelephoneAndRoleAndDateCreated();
        this->tableData.emplaceBack(data);
    }
}

AdminTableData::AdminTableData(QObject *parent)
{

}

AdminTableData::~AdminTableData()
{

}

void AdminTableData::itemModified()
{
    if (!this->tableData.isEmpty())
        this->tableData.clear();
    this->tableData.reserve(this->admins.size());
    for (const auto& admin : this->admins){
        const auto data = admin.getFullNameAndEmailAndTelephoneAndRoleAndDateCreated();
        this->tableData.emplaceBack(data);
    }
}

void AdminTableData::setItemAt(const res::FoundUser &admin,const QModelIndex & index)
{
    if (!index.isValid()) { return; }
    const auto currAdmin = this->admins.at(index.row());
    if (currAdmin == admin) { return; }
    this->admins[index.row()] = admin;
}

void AdminTableData::addItem(const res::FoundUser &admin)
{
    emit AdminTableData::preItemAppended();
    this->admins.push_back(admin);
    emit AdminTableData::postItemAppended();
}

void AdminTableData::removeItem(const QModelIndex &index)
{
    emit AdminTableData::preItemRemoved(index);
    this->admins.remove(index.row());
    emit AdminTableData::postItemRemoved();
}

const QList<res::FoundUser>  &AdminTableData::getAdmins() const
{
    return this->admins;
}

QList<res::FoundUser> &AdminTableData:: getModifiableAdmins()
{
    return this->admins;
}

void AdminTableData::setTableData(const QList<QList<QVariant> > &variants)
{
    if (this->tableData != variants)
        this->tableData = variants;
}

const QList<QList<QVariant> > AdminTableData::getTableData() const
{
    return this->tableData;
}

void AdminTableData::setAdmins(const QList<res::FoundUser> &admins)
{
    if (this->admins != admins)
        this->admins = admins;
}

