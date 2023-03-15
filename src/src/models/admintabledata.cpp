#include "admintabledata.hpp"

AdminTableData::AdminTableData(const QList<QList<res::User>>& admins,const QStringList headers, QObject *parent)
    : QObject{parent},
      admins(admins),
      headers(headers)
{

}

//const QList<QList<res::User> > &AdminTableData::getAdmins() const
//{
//    return this->admins;
//}

//const QStringList AdminTableData::getHeaders() const
//{
//    return this->headers;
//}
