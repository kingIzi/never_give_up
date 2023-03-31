#include "agent.hpp"

#include <QException>
#include <QSettings>
#include <QQmlApplicationEngine>
#include <QQmlEngine>



Agent::Agent(QObject *parent)
    : QObject{parent},
      agentLogin(nullptr),
      request_ptr(std::make_shared<Request>("http://localhost:8084")),
      isRequesting_prop(false),
      isLoggedIn_prop(false)
{

}

void Agent::onRequestLogin(const QJsonDocument res)
{
    try{
        const auto data = this->response.parseResponse(res);
        if (!data.isNull()){
            const auto login = this->response.createLogin(data.toObject());
            this->agentLogin = std::make_unique<Agent::Login>(login.idToken.toStdString(),login.refreshToken.toStdString(),login.email.toStdString(),login.localId.toStdString(),login.expiresIn);
            this->setIsLoggedIn(true);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to login user",500));
    }
    catch(const std::exception& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to login user",500));
    }
    this->setIsRequesting(false);
}

void Agent::onRequestUsersList(const QJsonDocument res){
    try{
        const auto data = this->response.parseLoginResponse(res);
        if (!data.isNull()){
            const auto users = this->response.createFoundUserTableData(data.toArray());
            emit Agent::usersList(users);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to retrieve all users",500));
    }
    catch(const std::exception& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to retrieve all users",500));
    }
    this->setIsRequesting(false);
}

void Agent::onRequestUserUpdate(const QJsonDocument res)
{
    try{
        const auto data = this->response.parseResponse(res);
        if (!data.isNull()){
            const auto user = this->response.createFoundUser(data.toObject());
            emit Agent::updatedUser(user);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request user update",500));
    }
    catch(const std::exception& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request user update",500));
    }
    this->setIsRequesting(false);
}

void Agent::setIsRequesting(const bool arg)
{
    if (this->isRequesting_prop != arg) {
        this->isRequesting_prop = arg;
        emit Agent::isRequestingChanged();
    }
}

void Agent::setIsLoggedIn(const bool arg)
{
    if (this->isLoggedIn_prop != arg){
        this->isLoggedIn_prop = arg;
        emit Agent::isLoggedInChanged();
    }
}

void Agent::storeAgentAuth() const
{
    try{
        if (this->agentLogin.get()){
            QSettings settings("IziIndustries","BoyebiApp");
            settings.setValue("idToken",this->agentLogin->idToken.c_str());
            settings.setValue("refreshToken",this->agentLogin->refreshToken.c_str());
            settings.setValue("localId",this->agentLogin->localId.c_str());
        }
    }
    catch(const std::exception& err){
        qDebug() << err.what();
    }
}

void Agent::requestLogin(const QVariantMap body)
{
    try{
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::sessionLogin);
        QObject::connect(this->request_ptr.get(),&Request::replyReadyRead,this,&Agent::onRequestLogin);
        this->setIsRequesting(true);
        const auto reply = this->request_ptr->makeRequestNoIdtoken(url, QJsonDocument::fromVariant(body));
        this->request_ptr->connectReplyReadyRead(reply);
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Request Failed",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Request Failed",500));
    }
}

void Agent::requestUsersList(const QVariantMap body){
    const QSettings settings("IziIndustries","BoyebiApp");
    const auto idToken = settings.value("idToken").toString();
    try{
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::userList);
        QObject::connect(this->request_ptr.get(),&Request::replyReadyRead,this,&Agent::onRequestUsersList);
        this->setIsRequesting(true);
        const auto reply = this->request_ptr->makeJsonPostRequest(url,idToken,QJsonDocument::fromVariant(body));
        this->request_ptr->connectReplyReadyRead(reply);
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Request Failed",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Request Failed",500));
    }
}

void Agent::requestUserUpdate(const QString userId,const res::FoundUser user)
{
    const QSettings settings("IziIndustries","BoyebiApp");
    const auto idToken = settings.value("idToken").toString();
    try{
       const auto queries = (QList<std::pair<QString,QString>>) {std::make_pair("userId",userId)};
       const auto url = this->request_ptr->buildUrl(queries,Request::Endpoint::userUpdateOne);
       QObject::connect(this->request_ptr.get(),&Request::replyReadyRead,this,&Agent::onRequestUserUpdate);
       const auto reply = this->request_ptr->makeMultiPutRequest(url,idToken,user.userModifiableValuesDocumentForm());
       if (reply){
           this->setIsRequesting(true);
           this->request_ptr->connectReplyReadyRead(reply);
       }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request user update",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request user update",500));
    }
}

const bool Agent::isRequesting() const
{
    return this->isRequesting_prop;
}

const bool Agent::isLoggedIn() const
{
    return this->isRequesting_prop;
}
