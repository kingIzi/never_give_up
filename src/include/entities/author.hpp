#pragma once

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QJsonObject>

namespace res{
class Author
{
    Q_GADGET
public:
    static constexpr const char* defaultDateTimeString = "yyyy-MM-dd HH:mm:ss";
    static constexpr const char* dateTimeFormatLong = "dddd, dd MMMM yy hh:mm:ss";
    static constexpr const char* dateTimeFormatShort = "dd, MMM yyyy hh:mm:ss";
    static constexpr const char* dateTimeFormatShortV2 = "dd, MMM yyyy";
public:
    Q_PROPERTY(QString authorId MEMBER authorId)
    Q_PROPERTY(QString firstName MEMBER firstName)
    Q_PROPERTY(QString lastName MEMBER lastName)
    Q_PROPERTY(QDateTime dateOfBirth MEMBER dateOfBirth)
    Q_PROPERTY(QString address MEMBER address)
    Q_PROPERTY(QString phoneNumber MEMBER phoneNumber)
    Q_PROPERTY(QString fullName MEMBER fullName)
    Q_PROPERTY(QString status MEMBER status)
    Q_PROPERTY(QString photoUrl MEMBER photoUrl)
    Q_PROPERTY(QString photoFileName MEMBER photoFileName)
    Q_PROPERTY(QDateTime dateCreated MEMBER dateCreated)
    Q_PROPERTY(QDateTime dateUpdated MEMBER dateUpdated)
    QString authorId;
    QString firstName;
    QString lastName;
    QDateTime dateOfBirth;
    QString address;
    QString phoneNumber;
    QString status;
    QString photoUrl;
    QString photoFileName;
    QString fullName = this->firstName + " " + this->lastName;
    QDateTime dateCreated;
    QDateTime dateUpdated;
    Author() = default;
    Author(const QJsonObject& author);
    Author& operator=(const Author& author){
        this->authorId = author.authorId;
        this->firstName = author.firstName;
        this->lastName = author.lastName;
        this->dateOfBirth = author.dateOfBirth;
        this->address = author.address;
        this->phoneNumber = author.phoneNumber;
        this->status = author.status;
        this->photoUrl = author.photoUrl;
        this->photoFileName = author.photoFileName;
        this->dateCreated = author.dateCreated;
        this->dateUpdated = author.dateUpdated;
        return (*this);
    }
    bool operator==(const Author& author) const{
        const auto matchAuthorId = this->authorId.compare(author.authorId) == 0;
        return matchAuthorId;
//        const auto matchFirstName = this->firstName.compare(author.firstName) == 0;
//        const auto matchLastName = this->lastName.compare(author.lastName) == 0;
//        const auto matchDateOfBirth = this->dateOfBirth.toString(Author::dateTimeFormatShortV2).compare(author.dateOfBirth.toString(Author::dateTimeFormatShortV2)) == 0;
//        const auto matchAddress = this->address.compare(author.address) == 0;
//        const auto matchPhoneNumber = this->phoneNumber.compare(author.phoneNumber) == 0;
//        const auto matchStatus = this->status.compare(author.status) == 0;
//        const auto matchPhotoUrl = this->photoUrl.compare(author.photoUrl) == 0;
//        const auto matchPhotoFileName = this->photoFileName.compare(author.photoFileName) == 0;
//        const auto matchDateCreated = this->dateCreated.toString(Author::dateTimeFormatShortV2).compare(author.dateCreated.toString(Author::dateTimeFormatShortV2)) == 0;
//        const auto matchDateUpdated = this->dateUpdated.toString(Author::dateTimeFormatShortV2).compare(author.dateCreated.toString(Author::dateTimeFormatShortV2)) == 0;
//        return matchAuthorId && matchFirstName && matchLastName && matchDateOfBirth && matchAddress && matchPhoneNumber &&
//                matchStatus && matchPhotoUrl && matchPhotoFileName && matchDateCreated && matchDateUpdated;
    }
    bool operator!=(const Author& author) const{
        const auto matchAuthorId = this->authorId.compare(author.authorId) != 0;
        return matchAuthorId;
//        const auto matchFirstName = this->firstName.compare(author.firstName) != 0;
//        const auto matchLastName = this->lastName.compare(author.lastName) != 0;
//        const auto matchDateOfBirth = this->dateOfBirth.toString(Author::dateTimeFormatShortV2).compare(author.dateOfBirth.toString(Author::dateTimeFormatShortV2)) != 0;
//        const auto matchAddress = this->address.compare(author.address) != 0;
//        const auto matchPhoneNumber = this->phoneNumber.compare(author.phoneNumber) != 0;
//        const auto matchStatus = this->status.compare(author.status) != 0;
//        const auto matchPhotoUrl = this->photoUrl.compare(author.photoUrl) != 0;
//        const auto matchPhotoFileName = this->photoFileName.compare(author.photoFileName) != 0;
//        const auto matchDateCreated = this->dateCreated.toString(Author::dateTimeFormatShortV2).compare(author.dateCreated.toString(Author::dateTimeFormatShortV2)) != 0;
//        const auto matchDateUpdated = this->dateUpdated.toString(Author::dateTimeFormatShortV2).compare(author.dateCreated.toString(Author::dateTimeFormatShortV2)) != 0;
//        return matchAuthorId && matchFirstName && matchLastName && matchDateOfBirth && matchAddress && matchPhoneNumber &&
//                matchStatus && matchPhotoUrl && matchPhotoFileName && matchDateCreated && matchDateUpdated;
    }
};

}
