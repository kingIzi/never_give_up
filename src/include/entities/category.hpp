#pragma once

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QJsonObject>


namespace res{
class Category
{
    Q_GADGET
public:
    static constexpr const char* defaultDateTimeString = "yyyy-MM-dd HH:mm:ss";
    static constexpr const char* dateTimeFormatLong = "dddd, dd MMMM yy hh:mm:ss";
    static constexpr const char* dateTimeFormatShort = "dd, MMM yyyy hh:mm:ss";
    static constexpr const char* dateTimeFormatShortV2 = "dd, MMM yyyy";
public:
    Q_PROPERTY(QString categoryId MEMBER categoryId)
    Q_PROPERTY(QString name MEMBER name)
    Q_PROPERTY(QString description MEMBER description)
    Q_PROPERTY(QString status MEMBER status)
    Q_PROPERTY(QString color MEMBER color)
    Q_PROPERTY(QDateTime dateCreated MEMBER dateCreated)
    Q_PROPERTY(QDateTime dateUpdated MEMBER dateUpdated)
    Q_PROPERTY(QString thumbnailUrl MEMBER thumbnailUrl)
    Q_PROPERTY(QString thumbnailFileName MEMBER thumbnailFileName)
    QString categoryId;
    QString name;
    QString description;
    QString status;
    QString color;
    QDateTime dateCreated;
    QDateTime dateUpdated;
    QString thumbnailUrl;
    QString thumbnailFileName;
public:
    Category() = default;
    Category(const QJsonObject& res);
    bool operator==(const Category& category) const{
        return this->categoryId.compare(category.categoryId) == 0;
    }
    bool operator!=(const Category& category) const{
        return this->categoryId.compare(category.categoryId) != 0;
    }
};
}
