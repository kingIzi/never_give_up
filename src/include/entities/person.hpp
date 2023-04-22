#pragma once

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariantMap>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userId READ userId WRITE setUserId NOTIFY userIdChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString localId READ localId WRITE setLocalId NOTIFY localIdChanged)
    Q_PROPERTY(QString phoneNumber READ phoneNumber WRITE setPhoneNumber NOTIFY phoneNumberChanged)
    Q_PROPERTY(QString fullName READ fullName WRITE setfullName NOTIFY fullNameChanged)
    Q_PROPERTY(QString photoFileName READ photoFileName WRITE setPhotoFileName NOTIFY photoFileNameChanged)
    Q_PROPERTY(QString photoUrl READ photoUrl WRITE setPhotoUrl NOTIFY photoUrlChanged)
    Q_PROPERTY(QString role READ role WRITE setRole NOTIFY roleChanged)
    Q_PROPERTY(QDateTime dateCreated READ dateCreated WRITE setDateCreated NOTIFY dateCreatedChanged)
    Q_PROPERTY(QDateTime dateUpdated READ dateUpdated WRITE setDateUpdated NOTIFY dateUpdatedChanged)
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)
public:
    static constexpr const char* defaultDateTimeString = "yyyy-MM-dd HH:mm:ss";
    static constexpr const char* dateTimeFormatLong = "dddd, dd MMMM yy hh:mm:ss";
    static constexpr const char* dateTimeFormatShort = "dd, MMM yyyy hh:mm:ss";
private:
    QString _userId;
    QString _email;
    QString _localId;
    QString _phoneNumber;
    QString _fullName;
    QString _photoFileName;
    QString _photoUrl;
    QString _role;
    QDateTime _dateCreated;
    QDateTime _dateUpdated;
    QString _status;
public:
    explicit Person(QObject *parent = nullptr);
    Person(const QJsonObject& res,QObject * parent = nullptr);
    const QJsonDocument userModifiableValuesDocumentForm() const;
    const QString userId() const;
    const QString email() const;
    const QString localId() const;
    const QString phoneNumber() const;
    const QString fullName() const;
    const QString photoFileName() const;
    const QString photoUrl() const;
    const QString role() const;
    const QString status() const;
    const QDateTime dateCreated() const;
    const QDateTime dateUpdated() const;
    const QVariantMap getAsMap() const;
public slots:
    void setUserId(const QString& userId);
    void setEmail(const QString& email);
    void setLocalId(const QString& localId);
    void setPhoneNumber(const QString& phoneNumber);
    void setfullName(const QString& fullName);
    void setPhotoFileName(const QString& photoFileName);
    void setPhotoUrl(const QString& photoUrl);
    void setRole(const QString& role);
    void setStatus(const QString& status);
    void setDateCreated(const QDateTime& dateCreated);
    void setDateUpdated(const QDateTime& dateUpdated);
public:
    Person& operator=(const Person& person){
        this->_userId = person._userId;
        this->_email = person._email;
        this->_localId = person._localId;
        this->_phoneNumber = person._phoneNumber;
        this->_fullName = person._fullName;
        this->_photoFileName = person._photoFileName;
        this->_photoUrl = person._photoUrl;
        this->_dateCreated = person._dateCreated;
        this->_dateUpdated = person._dateUpdated;
        this->_status = person._status;
        this->_role = person._role;
        return (*this);
    }
    bool operator==(Person const& user) const{
        const auto matchUserId = this->_userId.compare(user._userId) == 0;
        const auto matchEmail = this->_email.compare(user._email) == 0;
        const auto matchLocalId = this->_localId.compare(user._localId) == 0;
        const auto matchTelephone = this->_phoneNumber.compare(user._phoneNumber) == 0;
        const auto matchFullName = this->_fullName.compare(user._fullName) == 0;
        const auto matchPhotoFileName = this->_photoFileName.compare(user._photoFileName) == 0;
        const auto matchPhotoUrl = this->_photoUrl.compare(user._photoUrl) == 0;
        const auto matchDates = [](const QDateTime& date1,const QDateTime& date2) {
            return date1.toString("dd, MMM yyyy hh:mm:ss").compare(date2.toString("dd, MMM yyyy hh:mm:ss")) == 0;
        };
        const auto matchDateCreated = matchDates(this->_dateCreated,user._dateCreated);
        const auto matchDateUpdated = matchDates(this->_dateUpdated,user._dateUpdated);
        const auto matchStatus = this->_status.compare(user._status) == 0;
        const auto matchRole = this->_role.compare(user._role) == 0;
        return matchUserId && matchEmail && matchLocalId && matchTelephone && matchFullName && matchPhotoFileName &&
                matchPhotoUrl && matchDateCreated && matchDateUpdated && matchStatus && matchRole;

    }
    bool operator!=(Person const& user) const{
        const auto matchUserId = this->_userId.compare(user._userId) != 0;
        const auto matchEmail = this->_email.compare(user._email) != 0;
        const auto matchLocalId = this->_localId.compare(user._localId) != 0;
        const auto matchTelephone = this->_phoneNumber.compare(user._phoneNumber) != 0;
        const auto matchFullName = this->_fullName.compare(user._fullName) != 0;
        const auto matchPhotoFileName = this->_photoFileName.compare(user._photoFileName) != 0;
        const auto matchPhotoUrl = this->_photoUrl.compare(user._photoUrl) != 0;
        const auto matchDates = [](const QDateTime& date1,const QDateTime& date2) {
            return date1.toString(Person::dateTimeFormatShort).compare(date2.toString(Person::dateTimeFormatShort)) != 0;
        };
        const auto matchDateCreated = matchDates(this->_dateCreated,user._dateCreated);
        const auto matchDateUpdated = matchDates(this->_dateUpdated,user._dateUpdated);
        const auto matchStatus = this->_status.compare(user._status) != 0;
        const auto matchRole = this->_role.compare(user._role) != 0;
        return matchUserId && matchEmail && matchLocalId && matchTelephone && matchFullName && matchPhotoFileName &&
                matchPhotoUrl && matchDateCreated && matchDateUpdated && matchStatus && matchRole;

    }
    const QList<QVariant> getFullNameAndEmailAndTelephoneAndRoleAndDateCreated() const{
        return {this->_fullName,this->_email,this->_phoneNumber,this->_role,this->_dateCreated};
    }
signals:
    void userIdChanged();
    void emailChanged();
    void localIdChanged();
    void phoneNumberChanged();
    void fullNameChanged();
    void photoFileNameChanged();
    void photoUrlChanged();
    void roleChanged();
    void statusChanged();
    void dateCreatedChanged();
    void dateUpdatedChanged();
};

