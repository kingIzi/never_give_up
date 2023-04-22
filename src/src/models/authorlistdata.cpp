#include "authorlistdata.hpp"


AuthorListData::AuthorListData(QObject *parent)
    : QObject{parent}
{

}

AuthorListData::AuthorListData(const QList<res::Author> &authors, QObject *parent)
    : QObject{parent},
      authors(authors)
{

}

AuthorListData::~AuthorListData()
{
    qDebug() << "AuthorListData destroyed";
}

QList<res::Author> AuthorListData::getAuthors() const
{
    return this->authors;
}

void AuthorListData::setAuthors(const QList<res::Author> &newAuthors)
{
    this->authors = newAuthors;
}

void AuthorListData::setItemAt(res::Author author, const QModelIndex index)
{
    if (!index.isValid()) { return; }
    const auto current = this->authors.at(index.row());
    if (current == author) { return; }
    emit AuthorListData::preItemAppended();
    this->authors.insert(index.row(),author);
    emit AuthorListData::postItemAppended();
}

void AuthorListData::addItem(res::Author author)
{
    emit AuthorListData::preItemAppended();
    this->authors.emplaceBack(author);
    emit AuthorListData::postItemAppended();

}
