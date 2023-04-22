#include "categorieslistdata.hpp"
#include <algorithm>

CategoriesListData::CategoriesListData(QObject *parent)
    : QObject{parent}
{

}

CategoriesListData::CategoriesListData(const QList<res::Category> &categories, QObject *parent) :
    categories(categories),
    QObject{parent}
{

}

CategoriesListData::~CategoriesListData()
{
    qDebug() << "CategoriesListData destroyed";
}

QList<res::Category> CategoriesListData::getCategories() const
{
    return this->categories;
}

void CategoriesListData::setCategories(const QList<res::Category> &newCategories)
{
    this->categories = newCategories;
}

void CategoriesListData::setItemAt(res::Category category, const QModelIndex index)
{
    if (!index.isValid()) { return; }
    const auto current = this->categories.at(index.row());
    if (current == category) { return; }
    emit CategoriesListData::preItemAppended();
    this->categories.insert(index.row(),category);
    emit CategoriesListData::postItemAppended();
}

void CategoriesListData::addItem(res::Category category)
{
    emit CategoriesListData::preItemAppended();
    this->categories.emplaceBack(category);
    emit CategoriesListData::postItemAppended();
}
