#include "comiclistdata.hpp"

const QList<res::Comic *>& ComicListData::getComics() const
{
    return comics;
}

void ComicListData::setComics(const QList<res::Comic *> &newComics)
{
    comics = newComics;
}

void ComicListData::setItemAt(res::Comic *comic, const QModelIndex index)
{
    if (!index.isValid()) { return; }
    const auto currAdmin = this->comics.at(index.row());
    if (currAdmin == comic) { return; }
    this->comics[index.row()] = comic;
}

void ComicListData::addItem(res::Comic *comic)
{
    emit ComicListData::preItemAppended();
    this->comics.push_back(comic);
    emit ComicListData::postItemAppended();
}

ComicListData::ComicListData(const QList<res::Comic*>& comics,QObject *parent)
    : QObject{parent}
    ,comics(comics)
{
    qDebug() << "Comic list data created";
}

ComicListData::ComicListData(QObject *parent) :
    QObject{parent}
{

}

ComicListData::~ComicListData()
{
    qDebug() << "Comic list data destroyed";
}

