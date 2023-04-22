#include "response.hpp"

#include <QQmlEngine>
#include <algorithm>
#include <vector>

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

Response::Response(QObject * parent) :
    QObject{parent}
{

}

Response::~Response() {

}

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

Person* Response::createPerson(const QJsonObject &personRes) const noexcept
{
    const auto person = new Person(personRes);
    QQmlEngine::setObjectOwnership(person,QQmlEngine::CppOwnership);
    return person;
}

const res::FoundUser Response::createFoundUser(const QJsonObject &res) const noexcept
{
    return res::FoundUser(res);
}

const QList<Person*> Response::createPersonList(const QJsonArray &personsRes) const noexcept
{
    QList<Person*> persons; persons.reserve(personsRes.size());
    std::for_each(std::begin(personsRes),std::end(personsRes),[this,&persons](const QJsonValue& value){
        const auto person = this->createPerson(value.toObject());
        persons.emplaceBack(person);
    });
    return persons;
}

const res::Author Response::createAuthor(const QJsonObject &author) const noexcept
{
    return res::Author(author);
}

const QList<res::Author> Response::createAuthorList(const QJsonArray &res) const noexcept
{
    QList<res::Author> authors; authors.reserve(res.size());
    std::for_each(std::begin(res),std::end(res),[this,&authors](const QJsonValue& value){
        const auto author = this->createAuthor(value.toObject());
        authors.emplaceBack(author);
    });
    return authors;
}

const QList<res::Comic*> Response::createComicList(const QJsonArray res) const noexcept
{
    using namespace res;
    QList<Comic*> comics; comics.reserve(res.size());
    std::for_each(std::begin(res),std::end(res),[this,&comics](const QJsonValue& value){
        comics.emplaceBack(this->createComic(value.toObject()));
    });
    return comics;
}

const QList<res::Category> Response::createCategoriesList(const QJsonArray& res) const noexcept
{
    QList<res::Category> categories; categories.reserve(res.size());
    for (const auto& i : res){
        const auto category = this->createCategory(i.toObject());
        categories.emplaceBack(category);
    }
    return categories;
}

const res::Category Response::createCategory(const QJsonObject &res) const noexcept
{
    return res::Category(res);
}

res::Comic* Response::createComic(const QJsonObject &object) const noexcept
{
    const auto comic = new res::Comic(object);
    return comic;
}



