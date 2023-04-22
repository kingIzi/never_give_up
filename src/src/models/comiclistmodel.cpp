#include "comiclistmodel.hpp"

ComicListModel::ComicListModel(QAbstractListModel *parent)
    : QAbstractListModel{parent},
      _comicListData(nullptr)
{
    QObject::connect(this,&ComicListModel::populateList,this,&ComicListModel::onPopulate);
    QObject::connect(this,&ComicListModel::updateAuthorIdToName,&ComicListModel::onUpdateAuthorIdToName);
}

ComicListModel::~ComicListModel()
{
    qDebug() << "Comic list model destroyed";
}

void ComicListModel::populationSignals()
{
    if (this->_comicListData){
        QObject::connect(this->_comicListData,&ComicListData::postItemAppended,this,[this](){
            const auto index = this->_comicListData->getComics().size();
            this->beginInsertRows(QModelIndex(),index,index);
        });
        QObject::connect(this->_comicListData,&ComicListData::postItemAppended,this,[this](){
            this->endInsertRows();
        });
        QObject::connect(this->_comicListData,&ComicListData::preItemRemoved,this,[this](QModelIndex index){
            this->beginRemoveRows(QModelIndex(),index.row(),index.row());
        });
        QObject::connect(this->_comicListData,&ComicListData::postItemRemoved,this,[this](){
            this->endRemoveRows();
        });
    }
}

int ComicListModel::rowCount(const QModelIndex & index) const
{
    if (index.isValid() || !this->_comicListData)
        return 0;
    return this->_comicListData->getComics().size();
}

QVariant ComicListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !this->_comicListData)
        return QVariant();
    const auto& comic = this->_comicListData->getComics().at(index.row());
    switch (role){
    case ID:
        return comic->getId();
    case NAME:
        return comic->getName();
    case CATEGORIES:
        return comic->getCategories();
    case LIKERS:
        return comic->getLikers();
    case VIEWERS:
        return comic->getViewers();
    case DATA_URL:
        return comic->getDataUrl();
    case DATA_FILE_NAME:
        return comic->getDataFileName();
    case THUMBNAIL_URL:
        return comic->getThumbnailUrl();
    case THUMBNAIL_FILE_NAME:
        return comic->getThumbnailFileName();
    case STATUS:
        return comic->getStatus();
    case DESCRIPTION:
        return comic->getDescription();
    case AUTHOR_ID:
        return comic->getAuthorId();
    case COMMENTS:
        return comic->getComments();
    case DATE_RELEASED:
        return comic->getDateReleased().toString(res::Comic::dateTimeFormatShortV2);
    case DATE_CREATED:
        return comic->getDateCreated().toString(res::Comic::dateTimeFormatShortV2);
    case DATE_UPDATED:
        return comic->getDateUpdated().toString(res::Comic::dateTimeFormatShortV2);
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> ComicListModel::roleNames() const
{
    return {
        {ID,"comicId"},
        {NAME,"name"},
        {CATEGORIES,"categories"},
        {LIKERS,"likers"},
        {VIEWERS,"viewers"},
        {DATA_URL,"dataUrl"},
        {DATA_FILE_NAME,"dataFileName"},
        {THUMBNAIL_URL,"thumbnailUrl"},
        {THUMBNAIL_FILE_NAME,"thumbnailFileName"},
        {STATUS,"status"},
        {DESCRIPTION,"description"},
        {AUTHOR_ID,"authorId"},
        {COMMENTS,"comments"},
        {DATE_RELEASED, "dateReleased"},
        {DATE_CREATED, "dateCreated"},
        {DATE_UPDATED, "dateUpdated"}
    };
}

ComicListData *ComicListModel::comicListData() const
{
    return this->_comicListData;
}

void ComicListModel::onPopulate(const QList<res::Comic*> comics)
{
    if (comics.isEmpty())
        return;
    for (const auto& i : comics){
        if (i->getAuthorId().isEmpty())
            return;
    }
    this->beginResetModel();
    this->_comicListData->setComics(comics);
    this->populationSignals();
    this->endResetModel();
}

void ComicListModel::setComicListData(ComicListData * comicListData)
{
    if (this->_comicListData != comicListData){
        this->_comicListData = comicListData;
        emit ComicListModel::comicListDataChanged();
    }
}

void ComicListModel::onUpdateAuthorIdToName(const res::Author author)
{
    auto authors = this->_comicListData->getComics();
    const auto it = std::find_if(authors.begin(),authors.end(),[author](const res::Comic* value){
        return author.authorId.compare(value->getAuthorId()) == 0;
    });
    if (it != authors.end()){

    }
}
