#pragma once

#include <QObject>
#include <QAbstractListModel>
#include "categorieslistdata.hpp"

class CategoriesModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(CategoriesListData* categoriesListData READ categoriesListData WRITE setCategoriesListData NOTIFY categoriesListDataChanged)
private:
    CategoriesListData* _categoriesListData;
public:
    explicit CategoriesModel(QAbstractListModel *parent = nullptr);
    CategoriesListData* categoriesListData() const;
    ~CategoriesModel();
    void populationSignals();
    int rowCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    enum {
        CATEGORY_ID = Qt::UserRole,CATEGORY_NAME,DESCRIPTION,THUMBNAIL_URL,THUMBNAIL_FILE_NAME,STATUS,DATE_CREATED,
        CATEGORY_COLOR,DATE_UPDATED
    };

public slots:
    void setCategoriesListData(CategoriesListData * const categoriesListData);
    void onPopulate(const QList<res::Category>);
signals:
    void categoriesListDataChanged();
    void populate(const QList<res::Category>);
};

