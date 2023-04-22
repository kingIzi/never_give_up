#pragma once
#include "comic.hpp"

#include <QObject>
#include <QList>
#include <QModelIndex>

class ComicListData : public QObject
{
    Q_OBJECT
private:
    QList<res::Comic*> comics;
public:
    explicit ComicListData(const QList<res::Comic*>& comics,QObject *parent = nullptr);
    ComicListData(QObject *parent = nullptr);
    ~ComicListData();
    const QList<res::Comic *>& getComics() const;
    void setComics(const QList<res::Comic *> &newComics);
    void setItemAt(res::Comic* comic,const QModelIndex index);
    void addItem(res::Comic* comic);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(const QModelIndex&);
    void postItemRemoved();
};

