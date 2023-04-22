#include "comic.hpp"

namespace res {

QStringList Comic::getLikers() const
{
    return likers;
}

void Comic::setLikers(const QStringList &newLikers)
{
    likers = newLikers;
}

Comic::Comic(const QJsonObject& res,QObject *parent)
    : QObject{parent},
      id(res.value("id").toString()),thumbnailFileName(res.value("thumbnailFileName").toString()),
      thumbnailUrl(res.value("thumbnailUrl").toString()),status(res.value("status").toString()),
      dataFileName(res.value("dataFileName").toString()),dataUrl(res.value("dataUrl").toString()),
      name(res.value("name").toString()),dateCreated(res.value("dateCreated").toVariant().toDateTime()),
      dateUpdated(res.value("dateUpdated").toVariant().toDateTime()),authorId(res.value("authorId").toString()),
      dateReleased(res.value("dateReleased").toVariant().toDateTime()),
      description(res.value("description").toString()),likers(res.value("likers").toVariant().toStringList()),
      viewers(res.value("viewers").toVariant().toStringList()),
      categories(res.value("categories").toVariant().toStringList())

{

}

QString Comic::getId() const
{
    return this->id;
}

void Comic::setId(const QString &newId)
{
    this->id = newId;
}

QString Comic::getThumbnailUrl() const
{
    return thumbnailUrl;
}

void Comic::setThumbnailUrl(const QString &newThumbnailUrl)
{
    thumbnailUrl = newThumbnailUrl;
}

QString Comic::getThumbnailFileName() const
{
    return thumbnailFileName;
}

void Comic::setThumbnailFileName(const QString &newThumbnailFileName)
{
    thumbnailFileName = newThumbnailFileName;
}

QString Comic::getStatus() const
{
    return status;
}

void Comic::setStatus(const QString &newStatus)
{
    status = newStatus;
}

QString Comic::getDescription() const
{
    return description;
}

void Comic::setDescription(const QString &newDescription)
{
    description = newDescription;
}

QDateTime Comic::getDateReleased() const
{
    return dateReleased;
}

void Comic::setDateReleased(const QDateTime &newDateReleased)
{
    dateReleased = newDateReleased;
}

QDateTime Comic::getDateUpdated() const
{
    return dateUpdated;
}

void Comic::setDateUpdated(const QDateTime &newDateUpdated)
{
    dateUpdated = newDateUpdated;
}

QDateTime Comic::getDateCreated() const
{
    return dateCreated;
}

void Comic::setDateCreated(const QDateTime &newDateCreated)
{
    dateCreated = newDateCreated;
}

QString Comic::getDataUrl() const
{
    return dataUrl;
}

void Comic::setDataUrl(const QString &newDataUrl)
{
    dataUrl = newDataUrl;
}

QString Comic::getDataFileName() const
{
    return dataFileName;
}

void Comic::setDataFileName(const QString &newDataFileName)
{
    dataFileName = newDataFileName;
}

QStringList Comic::getViewers() const
{
    return viewers;
}

void Comic::setViewers(const QStringList &newViewers)
{
    viewers = newViewers;
}

QJsonArray Comic::getComments() const
{
    return comments;
}

void Comic::setComments(const QJsonArray &newComments)
{
    comments = newComments;
}

QStringList Comic::getCategories() const
{
    return categories;
}

void Comic::setCategories(const QStringList &newCategories)
{
    categories = newCategories;
}

QString Comic::getAuthorId() const
{
    return this->authorId;
}

void Comic::setAuthorId(const QString &newAuthorId)
{
    authorId = newAuthorId;
}

QString Comic::getName() const
{
    return this->name;
}

void Comic::setName(const QString &newName)
{
    this->name = newName;
}

}
