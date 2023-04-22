#pragma once

#include <QObject>
#include <QList>
#include <QModelIndex>
#include "category.hpp"

class CategoriesListData : public QObject
{
    Q_OBJECT
private:
    QList<res::Category> categories;
public:
    explicit CategoriesListData(QObject *parent = nullptr);
    CategoriesListData(const QList<res::Category>& categories,QObject *parent = nullptr);
    ~CategoriesListData();
    QList<res::Category> getCategories() const;
    void setCategories(const QList<res::Category> &newCategories);
    void setItemAt(res::Category comic,const QModelIndex index);
    void addItem(res::Category comic);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(const QModelIndex&);
    void postItemRemoved();
};

