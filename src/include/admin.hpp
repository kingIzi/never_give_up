#pragma once

#include <QVariantMap>
#include "admintabledata.hpp"
#include "response.hpp"

class Admin : public QObject {
	Q_OBJECT
    Q_PROPERTY(res::FoundUser currentUser READ currentUser WRITE setCurrentUser NOTIFY currentUserChanged)
    Q_PROPERTY(res::Error errorMessage READ errorMessage WRITE setErrorMessage NOTIFY errorMessageChanged)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged);
    Q_PROPERTY(AdminTableData* adminTableData READ adminTableData WRITE setAdminTableData NOTIFY adminTableDataChanged);
private:
	std::unique_ptr<Request> request_ptr;
	std::unique_ptr<Response> response_ptr;
    AdminTableData* adminTableData_ptr;
    res::FoundUser currentUserProp;
    res::Error error_ptr;
    QString idToken;
    bool isLoadingProp;

private:
    void saveAuthCookies(const res::Register registeredUser); //save idToken
    void rememberedUser();
    void findCurrentUser(const QString& localId,const res::Register& registeredUser);
signals:
    //properties
    void currentUserChanged();
    void errorMessageChanged();
    void isLoadingChanged();
    void adminTableDataChanged();

    //error dialogs
    void requestError(const res::Error);

	//session
    void registeredSuccessfully();
	void readLoginResponseError(res::Error);
	void readLoginResponse(res::Login);
	void readRegisterResponseError(res::Error);
	void readRegisterResponse(res::Register);

	//user
	void readFindUser(res::FoundUser);
	void readUpdateUser(res::FoundUser);
	void readAddComicToFavorite(res::FoundUser);
    void readUsersList(const QList<res::FoundUser>);

	//author
	void readCreateAuthor(res::Author);
	void readUpdateAuthor(res::Author);
	void readDeleteAuthor(res::Author);
	void readFindAuthor(res::Author);
	void readAuthorList(QList<res::Author>);

	//category
	void readCreateCategory(res::Category);
	void readUpdateCategory(res::Category);
	void readFindCategory(res::Category);
	void readRemoveCategory(res::Category);
	void readCategoryList(QList<res::Category>);

	//comic
	void readCreateComic(res::Comic);
	void readUpdateComic(res::Comic);
	void readComicList(QList<res::Comic>);
	void readRemoveComic(res::Comic);
	void readFindComic(res::Comic);
	void readLikeComic(res::Comic);
	void readViewComic(res::Comic);
	void readFindComment(res::Comic);
	void readReplyComment(res::Comic);
	void readLikeComment(res::Comic);
	void readRemoveComment(res::Comic);
private slots:
	//session 
	void onLoginUser(const QJsonDocument document);
    void onRegisterUser(const QJsonDocument document);
	
	//user
	void onFindUser(const QJsonDocument document);
	void onUpdateUser(const QJsonDocument document);
	void onAddComicToFavorite(const QJsonDocument document);
    void onUsersList(const QJsonDocument);
	
	//author
	void onCreateAuthor(const QJsonDocument document);
	void onUpdateAuthor(const QJsonDocument document);
	void onDeleteAuthor(const QJsonDocument document);
	void onFindAuthor(const QJsonDocument document);
	void onAuthorList(const QJsonDocument document);

	//category
	void onCreateCategory(const QJsonDocument document);
	void onUpdateCategory(const QJsonDocument document);
	void onFindCategory(const QJsonDocument document);
	void onRemoveCategory(const QJsonDocument document);
	void onCategoryList(const QJsonDocument document);

	//comic
	void onCreateComic(const QJsonDocument document);
	void onUpdateComic(const QJsonDocument document);
	void onComicList(const QJsonDocument document);
	void onRemoveComic(const QJsonDocument document);
	void onFindComic(const QJsonDocument document);
	void onLikeComic(const QJsonDocument document);
	void onViewComic(const QJsonDocument document);
	void onFindComment(const QJsonDocument document);
	void onReplyComment(const QJsonDocument document);
	void onLikeComment(const QJsonDocument document);
	void onRemoveComment(const QJsonDocument document);

public slots:

    //properties
    void setAdminTableData(AdminTableData* adminTableData);
    void setCurrentUser(const res::FoundUser& user);
    void setErrorMessage(const res::Error& error);
    void setIsLoading(const bool isLoading);

	//session resource
    void requestLoginUser(const QVariantMap& body);
    void requestRegisterUser(const QVariantMap& registerUser);
    void requestUpdateUser(const res::FoundUser profile);

	//user resource
    void requestAddComicToFavorite(const QString comicId);
    void requestFindUser(const QString localId);

	
	//author resource
    void requestCreateAuthor(const QVariantMap author);
    void requestUpdateAuthor(const QString authorId,const QVariantMap author);
    void requestDeleteAuthor(const QString authorId);
    void requestFindAuthor(const QString authorId);
    void requestAuthorList(const int limit,const QVariantMap options);

	//category resource
    void requestCreateCategory(const QVariantMap category);
    void requestUpdateCategory(const QString categoryId,const QVariantMap category);
    void requestFindCategory(const QString categoryId);
    void requestRemoveCategory(const QString categoryId);
    void requestCategoryList(const int limit,const QVariantMap options);

	//comic resource
    void requestCreateComic(const QVariantMap comic);
    void requestUpdateComic(const QString comicId,const QVariantMap comic);
    void requestComicList(const int limit,const QVariantMap option);
    void requestRemoveComic(const QString comicId);
    void requestFindComic(const QString comicId);
    void requestLikeComic(const QString comicId);
    void requestViewComic(const QString comicId);
    void requestFindComment(const QString comicId,const QVariantMap comment);
    void requestReplyComment(const QString comicId,const QVariantMap comment);
    void requestLikeComment(const QString comicId,const QVariantMap comment);
    void requestRemoveComment(const QString comicId,const QVariantMap comment);
public:
	explicit Admin(const QString& baseUrl, QObject * parent = nullptr);
	~Admin();

	void findUser();
    const res::FoundUser currentUser() const;
    const res::Error& errorMessage() const;
    const bool isLoading() const;
    Q_INVOKABLE Request* getRequestPtr() const;
    Q_INVOKABLE Response* getResponsePtr() const;

    Q_INVOKABLE void requestUsersList(const QVariantMap&);

    //properties
    AdminTableData *adminTableData() const;

    void setIdToken(const QString& idToken);
    const QString getIdToken() const;
};
