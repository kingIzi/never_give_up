#include "author.hpp"

using namespace res;

Author::Author(const QJsonObject &author) :
    authorId(author.value("id").toString()),firstName(author.value("firstName").toString()),
    lastName(author.value("lastName").toString()),dateOfBirth(author.value("dateOfBirth").toVariant().toDateTime()),
    address(author.value("address").toString()),phoneNumber(author.value("phoneNumber").toString()),
    status(author.value("status").toString()),photoUrl(author.value("photoUrl").toString()),
    photoFileName(author.value("photoFileName").toString()),dateCreated(author.value("dateCreated").toVariant().toDateTime()),
    dateUpdated(author.value("dateUpdated").toVariant().toDateTime())
{

}
