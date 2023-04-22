#pragma once
#include <QObject>
#include <QModelIndex>
#include "author.hpp"


class AuthorListData : public QObject
{
    Q_OBJECT
private:
    QList<res::Author> authors;
public:
    explicit AuthorListData(QObject *parent = nullptr);
    AuthorListData(const QList<res::Author>& author,QObject * parent = nullptr);
    ~AuthorListData();
    QList<res::Author> getAuthors() const;
    void setAuthors(const QList<res::Author> &newAuthors);
    void setItemAt(res::Author author,const QModelIndex index);
    void addItem(res::Author author);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(const QModelIndex&);
    void postItemRemoved();
};

