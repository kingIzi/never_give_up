#include "person.hpp"

Person::Person(QObject *parent)
    : QObject{parent}
{

}

Person::Person(const QJsonObject &person,QObject * parent) :
    QObject{parent},
    _userId(person.value("id").toString()),_email(person.value("email").toString()),
    _localId(person.value("localId").toString()),_phoneNumber(person.value("phoneNumber").toString()),
    _fullName(person.value("fullName").toString()),_photoUrl(person.value("photoUrl").toString()),
    _photoFileName(person.value("photoFileName").toString()),_role(person.value("role").toString()),
    _dateCreated(person.value("dateCreated").toVariant().toDateTime()),
    _dateUpdated(person.value("dateUpdated").toVariant().toDateTime()),_status(person.value("status").toString())
{

}

const QJsonDocument Person::userModifiableValuesDocumentForm() const
{
    QVariantMap form;
    form.insert("email",this->_email);
    form.insert("localId",this->_localId);
    form.insert("phoneNumber",this->_phoneNumber);
    form.insert("role",this->_role);
    form.insert("fullName",this->_fullName);
    return QJsonDocument::fromVariant(form);
}

const QString Person::userId() const
{
    return this->_userId;
}

const QString Person::email() const
{
    return this->_email;
}

const QString Person::localId() const
{
    return this->_localId;
}

const QString Person::phoneNumber() const
{
    return this->_phoneNumber;
}

const QString Person::fullName() const
{
    return this->_fullName;
}

const QString Person::photoFileName() const
{
    return this->_photoFileName;
}

const QString Person::photoUrl() const
{
    return this->_photoUrl;
}

const QString Person::role() const
{
    return this->_role;
}

const QString Person::status() const
{
    return this->_status;
}

const QDateTime Person::dateCreated() const
{
    return this->_dateCreated;
}

const QDateTime Person::dateUpdated() const
{
    return this->_dateUpdated;
}

const QVariantMap Person::getAsMap() const
{
    const auto map = (QVariantMap) {
        {QString("userId"),this->_userId},
        {QString("email"),this->_email},
        {QString("localId"),this->_localId},
        {QString("phoneNumber"),this->_phoneNumber},
        {QString("fullName"),this->_fullName},
        {QString("photoFileName"),this->_photoFileName},
        {QString("photoUrl"),this->_photoUrl},
        {QString("role"),this->_role},
        {QString("status"),this->_status},
        {QString("dateCreated"),this->_dateCreated},
        {QString("dateUpdated"),this->_dateUpdated}
    };
    return map;
}

void Person::setUserId(const QString &userId)
{
    if (this->_userId.compare(userId) != 0){
        this->_userId = userId;
        emit Person::userIdChanged();
    }
}

void Person::setEmail(const QString &email)
{
    if (this->_email.compare(email) != 0){
        this->_email = email;
        emit Person::emailChanged();
    }
}

void Person::setLocalId(const QString &localId)
{
    if (this->_localId.compare(localId) != 0){
        this->_localId = localId;
        emit Person::localIdChanged();
    }
}

void Person::setPhoneNumber(const QString &phoneNumber)
{
    if (this->_phoneNumber.compare(phoneNumber) != 0){
        this->_phoneNumber = phoneNumber;
        emit Person::phoneNumberChanged();
    }
}

void Person::setfullName(const QString &fullName)
{
    if (this->_fullName.compare(fullName) != 0){
        this->_fullName = fullName;
        emit Person::fullNameChanged();
    }
}

void Person::setPhotoFileName(const QString &photoFileName)
{
    if (this->_photoFileName.compare(photoFileName) != 0){
        this->_photoFileName = photoFileName;
        emit Person::photoFileNameChanged();
    }
}

void Person::setPhotoUrl(const QString &photoUrl)
{
    if (this->_photoUrl.compare(photoUrl) != 0){
        this->_photoUrl = photoUrl;
        emit Person::photoUrlChanged();
    }
}

void Person::setRole(const QString &role)
{
    if (this->_role.compare(role) != 0){
        this->_role = role;
        emit Person::roleChanged();
    }
}

void Person::setStatus(const QString &status)
{
    if (this->_status.compare(status) != 0){
        this->_status = status;
        emit Person::statusChanged();
    }
}

void Person::setDateCreated(const QDateTime &dateCreated)
{
    if (this->_dateCreated != _dateCreated){
        this->_dateCreated = dateCreated;
        emit Person::dateCreatedChanged();
    }
}

void Person::setDateUpdated(const QDateTime &dateUpdated)
{
    if (this->_dateUpdated != dateUpdated){
        this->_dateUpdated = dateUpdated;
        emit Person::dateUpdatedChanged();
    }
}
