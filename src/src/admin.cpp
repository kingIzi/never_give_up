#include "admin.hpp"

#include <QSettings>

Admin::Admin(const QString& baseUrl, QObject * parent) :
	QObject{parent},
	request_ptr(std::make_unique<Request>(baseUrl)),
	response_ptr(std::make_unique<Response>()),
    idToken(""),
    currentUserProp(),
    error_ptr(),
    isLoadingProp(false)
{
    QObject::connect(this->response_ptr.get(),&Response::requestUnsuccessfullError,this,&Admin::setErrorMessage);
    QObject::connect(this,&Admin::readUsersList,this,[](const QList<res::FoundUser> users){

    });
}

Admin::~Admin() {

}

///////////////////////////////////////////////////////////////////////////////////////////////////////

//private

void Admin::saveAuthCookies(const res::Register registeredUser) {
    QSettings settings;
    settings.setValue("idToken",registeredUser.idToken);
    settings.setValue("refreshToken",registeredUser.refreshToken);
    settings.setValue("email",registeredUser.email);
}

void Admin::rememberedUser() {
    QSettings settings;
    try{
        //this->registeredUser.idToken = settings.value("idToken").isNull() ? "" : settings.value("idToken").toString();
        //this->registeredUser.email = settings.value("email").isNull() ? "" : settings.value("email").toString();
        //this->registeredUser.refreshToken = settings.value("refreshToken").isNull() ? "" : settings.value("refreshToken").toString();
    }
    catch (const std::bad_cast& e){
        qDebug() << e.what();
    }
}

void Admin::findCurrentUser(const QString &localId, const res::Register &registeredUser)
{
    const QVariantMap form = {{QString("localId"),registeredUser.localId},{QString("status"),QString("ON")}};
    const auto url = this->request_ptr->buildUrl({},Request::Endpoint::userList);
    QObject::connect(this->request_ptr.get(), &Request::replyReadyRead, this, [this,registeredUser](const QJsonDocument document){
        const auto response = this->response_ptr->parseLoginResponse(document);
        if (response.isNull()) { return; }
        const auto users = response.toArray();
        if (!users.isEmpty()){
            const auto user = this->response_ptr->createFoundUser(users.first().toObject(),registeredUser);
            this->setCurrentUser(user);
        }
        this->setIsLoading(false);
    });
    this->setIsLoading(true);
    const auto reply = this->request_ptr->makeJsonPostRequest(url,this->getIdToken(),QJsonDocument::fromVariant(form));
    this->request_ptr->connectReplyReadyRead(reply);

}

//public slots

void Admin::onLoginUser(const QJsonDocument document) {
    try{
        const auto response = this->response_ptr->parseResponse(document);
        this->setIsLoading(false);
        if (response.isNull()) { return; }
        const auto loggedInUser = this->response_ptr->createLogin(response.toObject());
        this->saveAuthCookies(loggedInUser);
        this->setIdToken(loggedInUser.idToken);
        this->findCurrentUser(loggedInUser.localId,loggedInUser);
    }
    catch(const std::exception& e){
        qDebug() << e.what();
    }
}

void Admin::onRegisterUser(const QJsonDocument document) {
    try {
        const auto response = this->response_ptr->parseResponse(document);
        this->setIsLoading(false);
        if (response.isNull()) { return; }
        emit Admin::registeredSuccessfully();

    } catch (const std::exception& err) {
        qDebug() << err.what();
    }
}

void Admin::onFindUser(const QJsonDocument document) {


}

void Admin::onUpdateUser(const QJsonDocument document) {

}

void Admin::onAddComicToFavorite(const QJsonDocument document) {

}

void Admin::onUsersList(const QJsonDocument document)
{
    const auto response = this->response_ptr->parseResponse(document);
    this->setIsLoading(false);
    if (response.isNull()) { return; }
    const auto users = this->response_ptr->createFoundUserTableData(response.toArray());
    emit Admin::readUsersList(users);
}

void Admin::onCreateAuthor(const QJsonDocument document) {
    const auto response = this->response_ptr->parseResponse(document);
    this->setIsLoading(false);
    if (response.isNull()) { return; }
    const auto author = this->response_ptr->createAuthor(response.toObject());
    emit Admin::readCreateAuthor(author);
}

void Admin::onUpdateAuthor(const QJsonDocument document) {

}

void Admin::onDeleteAuthor(const QJsonDocument document) {

}

void Admin::onFindAuthor(const QJsonDocument document) {

}

void Admin::onAuthorList(const QJsonDocument document) {

}

void Admin::onCreateCategory(const QJsonDocument document) {

}

void Admin::onUpdateCategory(const QJsonDocument document) {

}

void Admin::onFindCategory(const QJsonDocument document) {

}

void Admin::onRemoveCategory(const QJsonDocument document) {

}

void Admin::onCategoryList(const QJsonDocument document) {

}

void Admin::onCreateComic(const QJsonDocument document) {

}

void Admin::onUpdateComic(const QJsonDocument document) {

}

void Admin::onComicList(const QJsonDocument document) {

}

void Admin::onRemoveComic(const QJsonDocument document) {

}

void Admin::onFindComic(const QJsonDocument document) {

}

void Admin::onLikeComic(const QJsonDocument document) {

}

void Admin::onViewComic(const QJsonDocument document) {

}

void Admin::onFindComment(const QJsonDocument document) {

}

void Admin::onReplyComment(const QJsonDocument document) {

}

void Admin::onLikeComment(const QJsonDocument document) {

}

void Admin::onRemoveComment(const QJsonDocument document) {

}

void Admin::setAdminTableData(AdminTableData *adminTableData)
{
    if (this->adminTableData_ptr){
        this->adminTableData_ptr->disconnect(this);
        this->adminTableData_ptr->deleteLater();
    }
    this->adminTableData_ptr = adminTableData;
}

void Admin::setCurrentUser(const res::FoundUser &user)
{
    this->currentUserProp = user;
    emit Admin::currentUserChanged();
}

void Admin::setErrorMessage(const res::Error& error)
{
    this->error_ptr = error;
    emit Admin::errorMessageChanged();
}

void Admin::setIsLoading(const bool isLoading)
{
    this->isLoadingProp = isLoading;
    emit Admin::isLoadingChanged();
}

//Q_INVOKABLES

void Admin::requestLoginUser(const QVariantMap& body) {
    const auto url = this->request_ptr->buildUrl({}, Request::Endpoint::sessionLogin);
    QObject::connect(this->request_ptr.get(), &Request::replyReadyRead, this, &Admin::onLoginUser);
    const auto reply = this->request_ptr->makeRequestNoIdtoken(url, QJsonDocument::fromVariant(body));
    this->setIsLoading(true);
    this->request_ptr->connectReplyReadyRead(reply);
}

void Admin::requestRegisterUser(const QVariantMap& registerUser) {
    const auto url = this->request_ptr->buildUrl({},Request::Endpoint::sessionRegister);
    this->setIsLoading(true);
    QObject::connect(this->request_ptr.get(), &Request::replyReadyRead, this, &Admin::onRegisterUser);
    const auto reply = this->request_ptr->makeRequestNoIdtoken(url, QJsonDocument::fromVariant(registerUser));
    this->request_ptr->connectReplyReadyRead(reply);
}

void Admin::requestUpdateUser(const res::FoundUser user) {
    const auto form = user.userModifiableValuesDocumentForm();
    const auto url = this->request_ptr->buildUrl({std::make_pair(QString("userId"),user.userId)},Request::Endpoint::userUpdateOne);
    this->setIsLoading(true);
    QObject::connect(this->request_ptr.get(),&Request::replyReadyRead,this,&Admin::onUpdateUser);
}

void Admin::requestAddComicToFavorite(const QString comicId) {

}

void Admin::requestFindUser(const QString localId)
{
//    const QVariantMap form = {{QString("localId"),localId},{QString("status"),QString("ON")}};
//    const auto url = this->request_ptr->buildUrl({},Request::Endpoint::userList);
//    QObject::connect(this->request_ptr.get(), &Request::replyReadyRead, this, &Admin::onFindUser);
//    const auto reply = this->request_ptr->makeJsonPostRequest(url,this->getIdToken(),QJsonDocument::fromVariant(form));
//    this->setIsLoading(true);
//    this->request_ptr->connectReplyReadyRead(reply);
    qDebug() << "requestFindUser()" << localId;
}

void Admin::requestUsersList(const QVariantMap& form)
{
    const auto url = this->request_ptr->buildUrl({},Request::Endpoint::userList);
    QObject::connect(this->request_ptr.get(),&Request::replyReadyRead,this,&Admin::onUsersList);
    const auto reply = this->request_ptr->makeJsonPostRequest(url,this->currentUserProp.registeredUser.idToken,QJsonDocument::fromVariant(form));
    this->setIsLoading(true);
    this->request_ptr->connectReplyReadyRead(reply);
}

AdminTableData *Admin::adminTableData() const
{
    return this->adminTableData_ptr;
}

void Admin::requestCreateAuthor(const QVariantMap author) {
    const auto url = this->request_ptr->buildUrl({},Request::Endpoint::createAuthor);
    QObject::connect(this->request_ptr.get(),&Request::replyReadyRead,this,&Admin::onCreateAuthor);
    const auto reply = this->request_ptr->makeJsonPostRequest(url,this->currentUserProp.registeredUser.idToken,QJsonDocument::fromVariant(author));
    this->setIsLoading(true);
    this->request_ptr->connectReplyReadyRead(reply);
}

void Admin::requestUpdateAuthor(const QString authorId, const QVariantMap author) {
    const auto updateAuthorUrl = this->request_ptr->buildUrl({std::make_pair(QString("authorId"),authorId)},Request::Endpoint::updateAuthor);

}

void Admin::requestDeleteAuthor(const QString authorId) {

}

void Admin::requestFindAuthor(const QString authorId) {

}

void Admin::requestAuthorList(const int limit, const QVariantMap options) {

}

void Admin::requestCreateCategory(const QVariantMap category) {

}

void Admin::requestUpdateCategory(const QString categoryId, const QVariantMap category) {

}

void Admin::requestFindCategory(const QString categoryId) {

}

void Admin::requestRemoveCategory(const QString categoryId) {

}

void Admin::requestCategoryList(const int limit, const QVariantMap options) {

}

void Admin::requestCreateComic(const QVariantMap comic) {

}

void Admin::requestUpdateComic(const QString comicId, const QVariantMap comic) {

}

void Admin::requestComicList(const int limit, const QVariantMap option) {

}

void Admin::requestRemoveComic(const QString comicId) {

}

void Admin::requestFindComic(const QString comicId) {

}

void Admin::requestLikeComic(const QString comicId) {

}

void Admin::requestViewComic(const QString comicId) {

}

void Admin::requestFindComment(const QString comicId, const QVariantMap comment) {

}

void Admin::requestReplyComment(const QString comicId, const QVariantMap comment) {

}

void Admin::requestLikeComment(const QString comicId, const QVariantMap comment) {

}

void Admin::requestRemoveComment(const QString comicId, const QVariantMap comment) {

}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void Admin::findUser() {

}

const res::FoundUser Admin::currentUser() const
{
    return this->currentUserProp;
}

const res::Error& Admin::errorMessage() const
{
    return this->error_ptr;
}

const bool Admin::isLoading() const
{
    return this->isLoadingProp;
}

Request* Admin::getRequestPtr() const {
    return this->request_ptr.get();
}

Response* Admin::getResponsePtr() const {
    return this->response_ptr.get();
}

const QString Admin::getIdToken() const{
    return this->idToken;
}

void Admin::setIdToken(const QString& idToken){
    this->idToken = idToken;
}
