#pragma once

#include <QObject>
#include <QString>
#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>
#include <QDateTime>

namespace res{
class Comic : public QObject
{
    Q_OBJECT
public:
    static constexpr const char* defaultDateTimeString = "yyyy-MM-dd HH:mm:ss";
    static constexpr const char* dateTimeFormatLong = "dddd, dd MMMM yy hh:mm:ss";
    static constexpr const char* dateTimeFormatShort = "dd, MMM yyyy hh:mm:ss";
    static constexpr const char* dateTimeFormatShortV2 = "dd, MMM yyyy";
public:
    struct Comment{
        QString email;
        QString message;
        QStringList likes;
        QList<Comment> replies;
        QDateTime dateCreated;
        QDateTime dateUpdated;
    };
private:
    QString id;
    QString name;
    QString authorId;
    QStringList categories;
    QJsonArray comments;
    QStringList likers;
    QStringList viewers;
    QString dataFileName;
    QString dataUrl;
    QDateTime dateCreated;
    QDateTime dateUpdated;
    QDateTime dateReleased;
    QString description;
    QString status;
    QString thumbnailFileName;
    QString thumbnailUrl;
public:
    explicit Comic(const QJsonObject& res,QObject *parent = nullptr);

    QString getId() const;
    void setId(const QString &newId);

    QString getName() const;
    void setName(const QString &newName);

    QString getAuthorId() const;
    void setAuthorId(const QString &newAuthorId);

    QStringList getCategories() const;
    void setCategories(const QStringList &newCategories);

    QJsonArray getComments() const;
    void setComments(const QJsonArray &newComments);

    QStringList getViewers() const;
    void setViewers(const QStringList &newViewers);

    QString getDataFileName() const;
    void setDataFileName(const QString &newDataFileName);

    QString getDataUrl() const;
    void setDataUrl(const QString &newDataUrl);

    QDateTime getDateCreated() const;
    void setDateCreated(const QDateTime &newDateCreated);

    QDateTime getDateUpdated() const;
    void setDateUpdated(const QDateTime &newDateUpdated);

    QDateTime getDateReleased() const;
    void setDateReleased(const QDateTime &newDateReleased);

    QString getDescription() const;
    void setDescription(const QString &newDescription);

    QString getStatus() const;
    void setStatus(const QString &newStatus);

    QString getThumbnailFileName() const;
    void setThumbnailFileName(const QString &newThumbnailFileName);

    QString getThumbnailUrl() const;
    void setThumbnailUrl(const QString &newThumbnailUrl);

public:
    bool operator==(const Comic* comic){
        return this->id.compare(comic->getId()) == 0;
    }
    bool operator!=(const Comic* comic){
        return this->id.compare(comic->getId()) != 0;
    }

    QStringList getLikers() const;
    void setLikers(const QStringList &newLikers);

signals:


};

}
