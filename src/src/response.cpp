#include "response.hpp"

const QJsonValue Response::parseLoginResponse(const QJsonDocument &response)
{
    const auto loginError = [](const QJsonObject& status,const int& code){
        const auto statusError = QJsonDocument::fromJson(status.value("message").toString().toUtf8());
        const auto message = statusError.object().value("message").toString();
        return res::Error(message,code);
    };
    try{
        if (response.isEmpty() || !response.isObject())
            throw std::runtime_error("Please verify your internet connection.");
        const auto status = response.object().value("status").toObject();
        const auto code = static_cast<int>(status.value("code").toVariant().toUInt());
        if (code == 200)
            return response.object().value("response");
        const auto error = loginError(status,code);
        emit Response::requestUnsuccessfullError(error);
    }
    catch(const std::runtime_error& e){
        const auto error = res::Error(e.what(),401);
        emit Response::requestUnsuccessfullError(error);
    }
    return QJsonValue();
}

Response::Response(QNetworkReply* reply, QObject * parent) :
    QObject{parent},
    reply(reply)
{

}

Response::~Response() {

}

void Response::connectNewReply(QNetworkReply * reply) {
    QObject::connect(reply, &QNetworkReply::readyRead, this, [reply, this]() {
        qDebug() << QJsonDocument::fromJson(reply->readAll());
    });
    QObject::connect(reply, &QNetworkReply::finished, this, [reply, this]() {
        /*if (reply) {
            emit Response::replyReadyRead(QJsonDocument::fromJson(reply->readAll()));
            reply->deleteLater();
        }*/
    });
}

QNetworkReply* Response::getReply() const {
    return this->reply;
}

// template<class T>
// const T Response::parseResponse(const QJsonDocument &document) const
// {
// 	try{
// 		if (!document.isObject())
// 			throw std::runtime_error("Error occured...All Requests should be objects");
// 		const auto res = document.object();
// 		if (res.value("status").toObject().value("code") == 200)
// 			return res.value("response");
// 		else
// 			return res.value("status");
// 	}
// 	catch(const std::runtime_error& e){
// 		qDebug() << e.what();
// 		return QJsonValue();
// 	}
// }

const QJsonValue Response::parseResponse(const QJsonDocument& document) {
    try{
        if (document.isEmpty() || !document.isObject())
            throw std::runtime_error("Please verify your internet connection.");
        const auto status = document.object().value("status").toObject();
        const auto code = status.value("code").toVariant().toUInt();
        if (code == 200)
            return document.object().value("response");
        const auto error = this->createError(status);
        emit Response::requestUnsuccessfullError(error);
    }
    catch(const std::runtime_error& e){
        const auto error = res::Error(e.what(),401);
        emit Response::requestUnsuccessfullError(error);
    }
    return QJsonValue();
}

const res::Error Response::createError(const QJsonObject& res) const noexcept{
    const auto message = res.value("message").toString();
    const auto code = res.value("code").toVariant().toUInt();
    return res::Error(message,code);
}

const res::Login Response::createLogin(const QJsonObject& res) const noexcept{
    const auto idToken = res.value("idToken").toString();
    const auto localId = res.value("localId").toString();
    const auto email = res.value("email").toString();
    const auto expiresIn = res.value("expiresIn").toVariant().toUInt();
    const auto refreshToken = res.value("refreshToken").toString();
    return res::Login(idToken,localId,email,expiresIn,refreshToken);
}

const res::FoundUser Response::createFoundUser(const QJsonObject &res, const res::Register& registeredUser) const noexcept
{
    return res::FoundUser (res,registeredUser);
}

const res::FoundUser Response::createFoundUser(const QJsonObject &res) const noexcept
{
    return res::FoundUser(res);
}

const QList<res::FoundUser> Response::createFoundUserTableData(const QJsonArray &array) const noexcept
{
    QList<res::FoundUser> admins; admins.reserve(array.size());
    for (const auto& item : array){
        const auto admin = res::FoundUser(item.toObject());
        admins.emplaceBack(admin);
    }
    return admins;
}

const res::Author Response::createAuthor(const QJsonObject &author) const noexcept
{
    return res::Author(author);
}
