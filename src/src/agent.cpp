#include "agent.hpp"

#include <QException>
#include <QSettings>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QFileInfo>
#include <QMimeDatabase>



Agent::Agent(QObject *parent)
    : QObject{parent},
      agentLogin(nullptr),
      request_ptr(std::make_shared<Request>("http://localhost:8084")),
      isRequesting_prop(false),
      isLoggedIn_prop(false)
{

}

const QString Agent::selectedFileName(const QString selectedFile) const
{
    return QFileInfo(selectedFile).fileName();
}

const QString Agent::getIdTokenFromSettings() const noexcept
{
    const QSettings settings("IziIndustries","BoyebiApp");
    return settings.value("idToken").toString();
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
            const auto users = this->response.createPersonList(data.toArray());
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
            const auto person = this->response.createPerson(data.toObject());
            emit Agent::updatedUser(person);
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

void Agent::onRequestComicList(const QJsonDocument res)
{
    try{
        const auto data = this->response.parseResponse(res);
        if (!data.isNull()){
            const auto comics = this->response.createComicList(data.toArray());
            emit Agent::comicList(comics);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request comic list",500));
    }
    catch(const std::exception& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request comic list",500));
    }
}

void Agent::onRequestFindOneAuthor(const QJsonDocument res)
{
    try{
        const auto data = this->response.parseResponse(res);
        if (!data.isNull()){
            const auto author = this->response.createAuthor(data.toObject());
            emit Agent::findOneAuthor(author);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request find author",500));
    }
    catch(const std::exception& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request find author",500));
    }
}

void Agent::onRequestCategoriesList(const QJsonDocument res)
{
    try {
        const auto data = this->response.parseLoginResponse(res);
        if (!data.isNull()){
            const auto categories = this->response.createResponseList(QList<res::Category>(),data.toArray());
            emit Agent::categoryList(categories);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories listr",500));
    }
    catch(const std::exception& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
    }
}

void Agent::onRequestAuthorList(const QJsonDocument res)
{
    try {
        const auto data = this->response.parseLoginResponse(res);
        if (!data.isNull()){
            const auto authors = this->response.createResponseList(QList<res::Author>(),data.toArray());
            emit Agent::authorList(authors);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request authors list",500));
    }
    catch(const std::exception& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request authors list",500));
    }
}

void Agent::onRequestCreateComic(const QJsonDocument res)
{
    try {
        const auto data = this->response.parseLoginResponse(res);
        if (!data.isNull()){
            qDebug() << data.toObject();
            const auto comic = this->response.createComic(data.toObject());
            emit createdComic(comic);
        }
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request authors list",500));
    }
    catch(const std::exception& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request authors list",500));
    }

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
        const auto doc = [body](){ return QJsonDocument::fromVariant(body); };
        const auto login = [this](const QByteArray data){ this->onRequestLogin(QJsonDocument::fromJson(data)); };
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::sessionLogin);
        QNetworkRequest req(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        const auto man = new QNetworkAccessManager(this);
        this->setIsRequesting(true);
        const auto reply = man->post(req,doc().toJson());
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,login](){
            if (reply){
                login(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });
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
    try{
        const auto idToken = this->getIdTokenFromSettings();
        const auto doc = [body]() { return QJsonDocument::fromVariant(body); };
        const auto users = [this](const QByteArray data){ this->onRequestUsersList(QJsonDocument::fromJson(data)); };
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::userList);
        QNetworkRequest req(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        req.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
        const auto man = new QNetworkAccessManager(this);
        this->setIsRequesting(true);
        const auto reply = man->post(req,doc().toJson());
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,users](){
            if (reply){
                users(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });
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

void Agent::requestUserUpdate(const QString userId,const Person* person)
{
    try{
        const auto contentDispositionValue = [](const QString& key){ return QString("form-data; name=\"" + key + "\""); };
        const auto multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        const auto doc = person->userModifiableValuesDocumentForm();
        const auto values = doc.isObject() ? doc.object() : QJsonObject();
        if (!values.isEmpty() && multiPart){
            const auto keys = values.keys();
            std::for_each(keys.begin(),keys.end(),[this,values,multiPart,contentDispositionValue](const QString& key){
                QHttpPart textPart;
                textPart.setHeader(QNetworkRequest::ContentDispositionHeader,contentDispositionValue(key));
                textPart.setBody(values.value(key).toVariant().toByteArray());
                multiPart->append(textPart);
            });
        }
        const auto files = values.value("files").isNull() ? QJsonObject() : values.value("files").toObject();
        if (!files.empty() && multiPart){
            const auto fileKeys = files.keys();
            for (const auto& key : fileKeys){
                const QFileInfo fileInfo(files.value(key).toString());
                if (!fileInfo.isFile())
                    throw std::invalid_argument("One of the files specified does not exist or has been deleted from location.");

                QHttpPart filePart;
                filePart.setHeader(QNetworkRequest::ContentTypeHeader, QMimeDatabase().mimeTypeForFile(fileInfo.absoluteFilePath()).name());
                filePart.setHeader(QNetworkRequest::ContentDispositionHeader,contentDispositionValue(key));
                auto * file = new QFile(fileInfo.absoluteFilePath());
                if (!file->open(QIODevice::ReadOnly))
                    throw std::invalid_argument("Failed to open file specified. Please verify path exists");
                filePart.setBodyDevice(file);
                file->setParent(multiPart);
                multiPart->append(filePart);
            }
        }
        const auto idToken = this->getIdTokenFromSettings();
        const auto man = new QNetworkAccessManager(this);
        const auto url = this->request_ptr->buildUrl({std::make_pair("userId",userId)},Request::Endpoint::userUpdateOne);
        QNetworkRequest req(url);
        req.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
        this->setIsRequesting(true);
        const auto reply = man->put(req,multiPart);
        const auto userUpdate = [this](const QByteArray data) { this->onRequestUserUpdate(QJsonDocument::fromJson(data)); };
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,userUpdate](){
            if (reply){
                userUpdate(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request user update",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request user update",500));
    }
    catch(const std::invalid_argument& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request user update",500));
    }
}

void Agent::requestComicList(const QVariantMap body)
{
    try{
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::listComic);
        const auto idToken = this->getIdTokenFromSettings();
        QNetworkRequest req(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        req.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
        const auto man = new QNetworkAccessManager(this);
        this->setIsRequesting(true);
        const auto reply = man->get(req);
        const auto comics = [this](const QByteArray data) { this->onRequestComicList(QJsonDocument::fromJson(data)); };
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,comics](){
            if (reply){
                comics(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });


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

void Agent::requestFindOneAuthor(const QString authorId)
{
    try{
        const auto url = this->request_ptr->buildUrl({std::make_pair("authorId",authorId)},Request::Endpoint::findAuthor);
        const auto idToken = this->getIdTokenFromSettings();
        QNetworkRequest req(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        req.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
        const auto man = new QNetworkAccessManager(this);
        this->setIsRequesting(true);
        const auto reply = man->get(req);
        const auto findAuthor = [this](const QByteArray data) { this->onRequestFindOneAuthor(QJsonDocument::fromJson(data)); };
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,findAuthor](){
            if (reply){
                findAuthor(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });

    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request find Author",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request find Author",500));
    }
}

void Agent::requestCategoriesList(const QVariantMap body)
{
    try{
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::listCategory);
        const auto idToken = this->getIdTokenFromSettings();
        QNetworkRequest req(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        req.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
        const auto man = new QNetworkAccessManager(this);
        this->setIsRequesting(true);
        const auto reply = man->get(req);
        const auto categories = [this](const QByteArray data) { this->onRequestCategoriesList(QJsonDocument::fromJson(data)); };
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,categories](){
            if (reply){
                categories(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
    }
}

void Agent::requestAuthorList()
{
    try{
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::listAuthor);
        const auto idToken = this->getIdTokenFromSettings();
        QNetworkRequest req(url);
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
        req.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
        const auto man = new QNetworkAccessManager(this);
        this->setIsRequesting(true);
        const auto reply = man->get(req);
        const auto listAuthor = [this](const QByteArray data) { this->onRequestAuthorList(QJsonDocument::fromJson(data)); };
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,listAuthor](){
            if (reply){
                listAuthor(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });

    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
    }
}

void Agent::requestCreateComic(const QVariantMap body)
{
    try{
        qDebug() << QJsonDocument::fromVariant(body);
        return;
        const auto contentDispositionValue = [](const QString& key){ return QString("form-data; name=\"" + key + "\""); };
        const auto multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        const auto doc = QJsonDocument::fromVariant(body);
        const auto values = doc.isObject() ? doc.object() : QJsonObject();
        if (!values.isEmpty() && multiPart){
            const auto keys = values.keys();
            std::for_each(keys.begin(),keys.end(),[this,values,multiPart,contentDispositionValue](const QString& key){
                QHttpPart textPart;
                textPart.setHeader(QNetworkRequest::ContentDispositionHeader,contentDispositionValue(key));
                textPart.setBody(values.value(key).toVariant().toByteArray());
                multiPart->append(textPart);
            });
        }
        const auto files = values.value("files").isNull() ? QJsonObject() : values.value("files").toObject();
        if (!files.empty() && multiPart){
            const auto fileKeys = files.keys();
            for (const auto& key : fileKeys){
                const QFileInfo fileInfo(files.value(key).toString());
                if (!fileInfo.isFile())
                    throw std::invalid_argument("One of the files specified does not exist or has been deleted from location.");

                QHttpPart filePart;
                filePart.setHeader(QNetworkRequest::ContentTypeHeader, QMimeDatabase().mimeTypeForFile(fileInfo.absoluteFilePath()).name());
                filePart.setHeader(QNetworkRequest::ContentDispositionHeader,contentDispositionValue(key));
                auto * file = new QFile(fileInfo.absoluteFilePath());
                if (!file->open(QIODevice::ReadOnly))
                    throw std::invalid_argument("Failed to open file specified. Please verify path exists");
                filePart.setBodyDevice(file);
                file->setParent(multiPart);
                multiPart->append(filePart);
            }
        }
        const auto idToken = this->getIdTokenFromSettings();
        const auto man = new QNetworkAccessManager(this);
        const auto url = this->request_ptr->buildUrl({},Request::Endpoint::createComic);
        QNetworkRequest req(url);
        req.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
        this->setIsRequesting(true);
        const auto reply = man->post(req,multiPart);
        const auto userUpdate = [this](const QByteArray data) { this->onRequestCreateComic(QJsonDocument::fromJson(data)); };
        QObject::connect(reply,&QNetworkReply::finished,this,[reply,man,userUpdate](){
            if (reply){
                userUpdate(reply->readAll());
                reply->deleteLater();
            }
            man->deleteLater();
        });
    }
    catch(const QException& e){
        qDebug() << e.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
    }
    catch(const std::runtime_error& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
    }
    catch(const std::invalid_argument& err){
        qDebug() << err.what();
        emit Agent::requestErrorMsg(res::Error("Failed to request categories list",500));
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
