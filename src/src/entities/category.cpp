#include "category.hpp"

using namespace res;

Category::Category(const QJsonObject& res) :
    categoryId(res.value("id").toString()),
    name(res.value("name").toString()),
    description(res.value("description").toString()),
    status(res.value("status").toString()),
    color(res.value("color").toString()),
    thumbnailFileName(res.value("thumbnailFileName").toString()),
    thumbnailUrl(res.value("thumbnailUrl").toString()),
    dateUpdated(res.value("dateUpdated").toVariant().toDateTime()),
    dateCreated(res.value("dateCreated").toVariant().toDateTime())
{

}
