#pragma once

#include <QAbstractListModel>
#include "authorlistdata.hpp"

class AuthorListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(AuthorListData* authorListData READ authorListData WRITE setAuthorListData NOTIFY authorListDataChanged)
    Q_PROPERTY(bool isEmpty READ isEmpty WRITE setIsEmpty NOTIFY isEmptyChanged)
private:
    AuthorListData* _authorListData;
    bool _isEmpty;
public:
    explicit AuthorListModel(QAbstractListModel *parent = nullptr);
    ~AuthorListModel();
    AuthorListData* authorListData() const;
    void populationSignals();
    int rowCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    bool isEmpty() const;

    enum {
        AUTHOR_ID = Qt::UserRole,FIRST_NAME,LAST_NAME,DATE_OF_BIRTH,PHONE_NUMBER,STATUS,DATE_CREATED,
        DATE_UPDATED,ADDRESS,PHOTO_URL,PHOTO_FILENAME
    };
public:
    Q_INVOKABLE res::Author getItemAt(const QModelIndex& index);
    Q_INVOKABLE res::Author getItemAt(const int index);
private slots:
    void onPopulate(const QList<res::Author> authors);

public slots:
    void setAuthorListData(AuthorListData* authorList);
    void setIsEmpty(const bool isEmpty);
signals:
    void authorListDataChanged();
    void populate(const QList<res::Author> authors);
    void isEmptyChanged();
};

