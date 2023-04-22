#pragma once

#include <QAbstractListModel>
#include <qqml.h>

#include "comiclistdata.hpp"
#include "author.hpp"


class ComicListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)
    Q_PROPERTY(ComicListData* comicListData READ comicListData WRITE setComicListData NOTIFY comicListDataChanged)
private:
    ComicListData* _comicListData;
private:
    const QVariant authorName(const QVariant& authorId);
public:
    explicit ComicListModel(QAbstractListModel *parent = nullptr);
    ~ComicListModel();
    void populationSignals();
    int rowCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    ComicListData* comicListData() const;

    enum {
        ID = Qt::UserRole,NAME,DESCRIPTION,THUMBNAIL_URL,THUMBNAIL_FILE_NAME,DATA_URL,DATA_FILE_NAME,
        CATEGORIES,LIKERS,VIEWERS,AUTHOR_ID,COMMENTS,STATUS,DATE_CREATED,DATE_RELEASED,DATE_UPDATED
    };
signals:
    void populateList(const QList<res::Comic*>);
    void comicListDataChanged();
    void findAuthorName(const QVariant);
    void updateAuthorIdToName(const res::Author author);
public slots:
    void onPopulate(const QList<res::Comic*> comics);
    void setComicListData(ComicListData * comicListData);
    void onUpdateAuthorIdToName(const res::Author author);
};

