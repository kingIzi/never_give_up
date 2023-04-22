#include "categoriesmodel.hpp"

CategoriesModel::CategoriesModel(QAbstractListModel *parent)
    : QAbstractListModel{parent},
      _categoriesListData(nullptr)
{
    QObject::connect(this,&CategoriesModel::populate,this,&CategoriesModel::onPopulate);
}

CategoriesListData *CategoriesModel::categoriesListData() const
{
    return this->_categoriesListData;
}

CategoriesModel::~CategoriesModel()
{
    qDebug() << "CategoriesModel destroyed";
}

void CategoriesModel::populationSignals()
{
    if (this->_categoriesListData){
        QObject::connect(this->_categoriesListData,&CategoriesListData::postItemAppended,this,[this](){
            const auto index = this->_categoriesListData->getCategories().size();
            this->beginInsertRows(QModelIndex(),index,index);
        });
        QObject::connect(this->_categoriesListData,&CategoriesListData::postItemAppended,this,[this](){
            this->endInsertRows();
        });
        QObject::connect(this->_categoriesListData,&CategoriesListData::preItemRemoved,this,[this](QModelIndex index){
            this->beginRemoveRows(QModelIndex(),index.row(),index.row());
        });
        QObject::connect(this->_categoriesListData,&CategoriesListData::postItemRemoved,this,[this](){
            this->endRemoveRows();
        });
    }
}

int CategoriesModel::rowCount(const QModelIndex &index) const
{
    if (index.isValid() || !this->_categoriesListData)
        return 0;
    return this->_categoriesListData->getCategories().size();
}

QVariant CategoriesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !this->_categoriesListData)
        return QVariant();
    const auto& category = this->_categoriesListData->getCategories().at(index.row());
    switch (role){
    case CATEGORY_ID:
        return category.categoryId;
    case CATEGORY_COLOR:
        return category.color;
    case DESCRIPTION:
        return category.description;
    case THUMBNAIL_URL:
        return category.thumbnailUrl;
    case THUMBNAIL_FILE_NAME:
        return category.thumbnailFileName;
    case STATUS:
        return category.status;
    case CATEGORY_NAME:
        return category.name;
    case DATE_CREATED:
        return category.dateCreated.toString(res::Category::dateTimeFormatShortV2);
    case DATE_UPDATED:
        return category.dateUpdated.toString(res::Category::dateTimeFormatShortV2);
    default:
        return QVariant();
    }
    return QVariant();
}

QHash<int, QByteArray> CategoriesModel::roleNames() const
{
    return {
        {CATEGORY_ID,"categoryId"},
        {CATEGORY_NAME,"categoryName"},
        {CATEGORY_COLOR,"categoryColor"},
        {DESCRIPTION,"description"},
        {DATE_CREATED,"dateCreated"},
        {DATE_UPDATED,"dateUpdated"},
        {STATUS,"status"},
        {THUMBNAIL_URL,"thumbnailUrl"},
        {THUMBNAIL_FILE_NAME,"thumbnailFileName"}
    };
}

void CategoriesModel::setCategoriesListData(CategoriesListData * const categoriesListData)
{
    if (this->_categoriesListData != categoriesListData){
        this->_categoriesListData = categoriesListData;
        emit CategoriesModel::categoriesListDataChanged();
    }
}

void CategoriesModel::onPopulate(const QList<res::Category> categories)
{
    if (categories.isEmpty())
        return;
    this->beginResetModel();
    this->_categoriesListData->setCategories(categories);
    this->populationSignals();
    this->endResetModel();

}
