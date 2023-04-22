#include "authorlistmodel.hpp"

AuthorListModel::AuthorListModel(QAbstractListModel *parent)
    : QAbstractListModel{parent},
      _authorListData(nullptr),
      _isEmpty(true)
{
    QObject::connect(this,&AuthorListModel::populate,this,&AuthorListModel::onPopulate);
}

AuthorListModel::~AuthorListModel()
{
    qDebug() << "AuthorListModel destroyed";
}

AuthorListData *AuthorListModel::authorListData() const
{
    return this->_authorListData;
}

void AuthorListModel::populationSignals()
{
    if (this->_authorListData){
        QObject::connect(this->_authorListData,&AuthorListData::postItemAppended,this,[this](){
            const auto index = this->_authorListData->getAuthors().size();
            this->beginInsertRows(QModelIndex(),index,index);
        });
        QObject::connect(this->_authorListData,&AuthorListData::postItemAppended,this,[this](){
            this->endInsertRows();
        });
        QObject::connect(this->_authorListData,&AuthorListData::preItemRemoved,this,[this](QModelIndex index){
            this->beginRemoveRows(QModelIndex(),index.row(),index.row());
        });
        QObject::connect(this->_authorListData,&AuthorListData::postItemRemoved,this,[this](){
            this->endRemoveRows();
        });
    }
}

int AuthorListModel::rowCount(const QModelIndex &index) const
{
    if (index.isValid() || !this->_authorListData)
        return 0;
    return this->_authorListData->getAuthors().size();
}

QVariant AuthorListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !this->_authorListData)
        return QVariant();
    const auto& author = this->_authorListData->getAuthors().at(index.row());
    switch (role){
    case AUTHOR_ID:
        return author.authorId;
    case FIRST_NAME:
        return author.firstName;
    case LAST_NAME:
        return author.lastName;
    case DATE_OF_BIRTH:
        return author.dateOfBirth;
    case STATUS:
        return author.status;
    case PHONE_NUMBER:
        return author.phoneNumber;
    case DATE_CREATED:
        return author.dateCreated;
    case DATE_UPDATED:
        return author.dateUpdated;
    case ADDRESS:
        return author.address;
    case PHOTO_URL:
        return author.photoUrl;
    case PHOTO_FILENAME:
        return author.photoFileName;
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> AuthorListModel::roleNames() const
{
    return {
        {AUTHOR_ID,"authorId"},
        {FIRST_NAME,"firstName"},
        {LAST_NAME,"lastName"},
        {DATE_OF_BIRTH,"dateOfBirth"},
        {STATUS,"status"},
        {PHONE_NUMBER,"phoneNumber"},
        {DATE_CREATED,"dateCreated"},
        {DATE_UPDATED,"dateUpdated"},
        {ADDRESS,"address"},
        {PHOTO_URL,"photoUrl"},
        {PHOTO_FILENAME,"photoFileName"}
    };
}

bool AuthorListModel::isEmpty() const
{
    return this->_isEmpty;
}

res::Author AuthorListModel::getItemAt(const QModelIndex &index)
{
    return this->_authorListData->getAuthors().at(index.row());
}

res::Author AuthorListModel::getItemAt(const int index)
{
    if (index < this->_authorListData->getAuthors().size())
        return this->_authorListData->getAuthors().at(index);
    return res::Author();
}

void AuthorListModel::onPopulate(const QList<res::Author> authors)
{
    if (authors.isEmpty())
        return;
    this->beginResetModel();
    this->_authorListData->setAuthors(authors);
    this->setIsEmpty(authors.isEmpty());
    this->populationSignals();
    this->endResetModel();

}

void AuthorListModel::setAuthorListData(AuthorListData* authorList)
{
    if (this->_authorListData != authorList){
        this->_authorListData = authorList;
        emit AuthorListModel::authorListDataChanged();
    }
}

void AuthorListModel::setIsEmpty(const bool isEmpty)
{
    if (this->_isEmpty != isEmpty){
        this->_isEmpty = isEmpty;
        emit AuthorListModel::isEmptyChanged();
    }
}
