#pragma once

#include <QThread>
#include <QDate>
#include <QDateTime>
#include <QStringList>
#include "person.hpp"
#include "request.hpp"

namespace res{

    static constexpr const char* defaultDateTimeString = "yyyy-MM-dd HH:mm:ss";
    static constexpr const char* dateTimeFormatLong = "dddd, dd MMMM yy hh:mm:ss";
    static constexpr const char* dateTimeFormatShort = "dd, MMM yyyy hh:mm:ss";


	struct Error{
	private:
		Q_GADGET
	public:
        Q_PROPERTY(QString message MEMBER message)
        Q_PROPERTY(int code MEMBER code)
		QString message;
		int code;
        Error() = default;
		Error(const QString& message,const int code) : 
			message(message), code(code)
		{}
        Error& operator=(const Error& error){
            this->message = error.message;
            this->code = error.code;
            return (*this);
        }
        bool operator!=(const Error& error){
            return this->message.compare(error.message) != 0 && this->code != error.code;
        }
	};
	struct Register{
	private:
		Q_GADGET
	public:
        Q_PROPERTY(QString idToken MEMBER idToken)
        Q_PROPERTY(QString localId MEMBER localId)
        Q_PROPERTY(QString email MEMBER email)
        Q_PROPERTY(int expiresIn MEMBER expiresIn)
        Q_PROPERTY(QString refreshToken MEMBER refreshToken)
        QString idToken;
		QString localId;
		QString email;
		int expiresIn;
		QString refreshToken;
        Register() = default;
		Register(const QString& idToken,const QString& localId,
			const QString& email,const int& expiresIn,const QString& refreshToken) : 
			idToken(idToken),localId(localId),email(email),expiresIn(expiresIn),
			refreshToken(refreshToken)
		{}
        Register& operator=(const Register& registeredUser){
            this->idToken = registeredUser.idToken;
            this->localId = registeredUser.localId;
            this->email = registeredUser.email;
            this->expiresIn = registeredUser.expiresIn;
            this->refreshToken = registeredUser.refreshToken;
            return (*this);
        }
        bool operator!=(const Register& registeredUser) const{
            const auto matchIdToken = this->idToken.compare(registeredUser.idToken) != 0;
            const auto matchLocalId = this->localId.compare(registeredUser.localId) != 0;
            const auto matchEmail = this->email.compare(registeredUser.email) != 0;
            const auto matchExpiresIn = this->expiresIn != registeredUser.expiresIn;
            const auto matchRefreshToken = this->refreshToken.compare(registeredUser.refreshToken) != 0;
            return matchIdToken && matchLocalId && matchEmail && matchExpiresIn && matchRefreshToken;
        }
        bool operator==(const Register& registeredUser) const{
            const auto matchIdToken = this->idToken.compare(registeredUser.idToken) == 0;
            const auto matchLocalId = this->localId.compare(registeredUser.localId) == 0;
            const auto matchEmail = this->email.compare(registeredUser.email) == 0;
            const auto matchExpiresIn = this->expiresIn == registeredUser.expiresIn;
            const auto matchRefreshToken = this->refreshToken.compare(registeredUser.refreshToken) == 0;
            return matchIdToken && matchLocalId && matchEmail && matchExpiresIn && matchRefreshToken;
        }
	};
	struct Login : public Register{
	private:
		Q_GADGET
	public:
		Login(const QString& idToken,const QString& localId,const QString& email,
			const int& expiresIn,const QString& refreshToken) : 
			Register{idToken,localId,email,expiresIn,refreshToken}
		{}
        Login() {};
	};
	struct FoundUser{
    private:
		Q_GADGET
    public:
        Q_PROPERTY(QString userId MEMBER userId)
        Q_PROPERTY(QString email MEMBER email)
        Q_PROPERTY(QString localId MEMBER localId)
        Q_PROPERTY(QString phoneNumber MEMBER phoneNumber)
        Q_PROPERTY(QString fullName MEMBER fullName)
        Q_PROPERTY(QString photoFileName MEMBER photoFileName)
        Q_PROPERTY(QString photoUrl MEMBER photoUrl)
        Q_PROPERTY(QString role MEMBER role)
        Q_PROPERTY(QDateTime dateCreated MEMBER dateCreated)
        Q_PROPERTY(QDateTime dateUpdated MEMBER dateUpdated)
        Q_PROPERTY(QString status MEMBER status)
        Q_PROPERTY(QStringList favorites MEMBER favorites)
		QString userId;
		QString email;
		QString localId;
        QString phoneNumber;
		QString fullName;
		QString photoFileName;
		QString photoUrl;
		QString role;
        QDateTime dateCreated;
        QDateTime dateUpdated;
		QString status;
		QStringList favorites;
        FoundUser() = default;
		FoundUser(const QString& userId,const QString& email,const QString& localId,
			const QString& telephone,const QString& fullName,const QString& photoFileName,
            const QString& photoUrl, const QString& role, const QDateTime& dateCreated,
            const QDateTime& dateUpdated, const QString& status,const QStringList& favorites,
                  const res::Register& registeredUser) :
            userId(userId),email(email),localId(localId),phoneNumber(telephone),fullName(fullName),
			photoFileName(photoFileName),photoUrl(photoUrl),role(role),dateCreated(dateCreated),
            dateUpdated(dateUpdated),status(status),favorites(favorites)
		{}
        FoundUser(const QJsonObject& user,const res::Register& registeredUser) :
            userId(user.value("id").toString()),email(user.value("email").toString()),
            localId(user.value("localId").toString()),phoneNumber(user.value("phoneNumber").toString()),
            fullName(user.value("fullName").toString()),photoUrl(user.value("photoUrl").toString()),
            photoFileName(user.value("photoFileName").toString()),role(user.value("role").toString()),
            dateCreated(user.value("dateCreated").toVariant().toDateTime()),
            dateUpdated(user.value("dateUpdated").toVariant().toDateTime()),status(user.value("status").toString()),
            favorites(user.value("favorites").toVariant().toStringList())
        {}
        FoundUser(const QJsonObject& user) :
            userId(user.value("id").toString()),email(user.value("email").toString()),
            localId(user.value("localId").toString()),phoneNumber(user.value("phoneNumber").toString()),
            fullName(user.value("fullName").toString()),photoUrl(user.value("photoUrl").toString()),
            photoFileName(user.value("photoFileName").toString()),role(user.value("role").toString()),
            dateCreated(user.value("dateCreated").toVariant().toDateTime()),
            dateUpdated(user.value("dateUpdated").toVariant().toDateTime()),status(user.value("status").toString()),
            favorites(user.value("favorites").toVariant().toStringList())
        {}
        FoundUser& operator=(const res::FoundUser& user){
            this->userId = user.userId;
            this->email = user.email;
            this->localId = user.localId;
            this->phoneNumber = user.phoneNumber;
            this->fullName = user.fullName;
            this->photoFileName = user.photoFileName;
            this->photoUrl = user.photoUrl;
            this->dateCreated = user.dateCreated;
            this->dateUpdated = user.dateUpdated;
            this->favorites = user.favorites;
            this->status = user.status;
            this->role = user.role;
            return (*this);
        }
        void updateData(const QVariantMap& map){
            this->userId = map.value("id").isNull() ? this->userId : map.value("id").toString();
            this->email = map.value("email").isNull() ? this->email : map.value("email").toString();
            this->localId = map.value("localId").isNull() ? this->localId : map.value("localId").toString();
            this->phoneNumber = map.value("phoneNumber").isNull() ? this->phoneNumber : map.value("phoneNumber").toString();
            this->fullName = map.value("fullName").isNull() ? this->fullName : map.value("fullName").toString();
            this->photoFileName = map.value("photoFileName").isNull() ? this->photoFileName : map.value("photoFileName").toString();
            this->photoUrl = map.value("photoUrl").isNull() ? this->photoUrl : map.value("photoUrl").toString();
            this->dateCreated = map.value("dateCreated").isNull() ? this->dateCreated : map.value("dateCreated").toDateTime();
            this->dateUpdated = map.value("dateUpdated").isNull() ? this->dateUpdated : map.value("dateUpdated").toDateTime();
            this->favorites = map.value("favorites").isNull() ? this->favorites : map.value("favorites").toStringList();
            this->status = map.value("status").isNull() ? this->status : map.value("status").toString();
            this->role = map.value("role").isNull() ? this->role : map.value("role").toString();
        }
        const QJsonDocument userModifiableValuesDocumentForm() const{
            QVariantMap form;
            form.insert("email",this->email);
            form.insert("localId",this->localId);
            form.insert("phoneNumber",this->phoneNumber);
            form.insert("favorites",this->favorites);
            form.insert("role",this->role);
            form.insert("fullName",this->fullName);
            return QJsonDocument::fromVariant(form);
        }
        bool operator==(res::FoundUser const& user) const{
            const auto matchUserId = this->userId.compare(user.userId) == 0;
            const auto matchEmail = this->email.compare(user.email) == 0;
            const auto matchLocalId = this->localId.compare(user.localId) == 0;
            const auto matchTelephone = this->phoneNumber.compare(user.phoneNumber) == 0;
            const auto matchFullName = this->fullName.compare(user.fullName) == 0;
            const auto matchPhotoFileName = this->photoFileName.compare(user.photoFileName) == 0;
            const auto matchPhotoUrl = this->photoUrl.compare(user.photoUrl) == 0;
            const auto matchDates = [](const QDateTime& date1,const QDateTime& date2) {
                return date1.toString("dd, MMM yyyy hh:mm:ss").compare(date2.toString("dd, MMM yyyy hh:mm:ss")) == 0;
            };
            const auto matchDateCreated = matchDates(this->dateCreated,user.dateCreated);
            const auto matchDateUpdated = matchDates(this->dateUpdated,user.dateUpdated);
            const auto matchFavorites = this->favorites == user.favorites;
            const auto matchStatus = this->status.compare(user.status) == 0;
            const auto matchRole = this->role.compare(user.role) == 0;
            return matchUserId && matchEmail && matchLocalId && matchTelephone && matchFullName && matchPhotoFileName &&
                    matchPhotoUrl && matchDateCreated && matchDateUpdated && matchFavorites && matchStatus && matchRole;

        }
        bool operator!=(const res::FoundUser& user) const{
            const auto matchUserId = this->userId.compare(user.userId) != 0;
            const auto matchEmail = this->email.compare(user.email) != 0;
            const auto matchLocalId = this->localId.compare(user.localId) != 0;
            const auto matchTelephone = this->phoneNumber.compare(user.phoneNumber) != 0;
            const auto matchFullName = this->fullName.compare(user.fullName) != 0;
            const auto matchPhotoFileName = this->photoFileName.compare(user.photoFileName) != 0;
            const auto matchPhotoUrl = this->photoUrl.compare(user.photoUrl) != 0;
            const auto matchDates = [](const QDateTime& date1,const QDateTime& date2) {
                return date1.toString(res::dateTimeFormatShort).compare(date2.toString(res::dateTimeFormatShort)) != 0;
            };
            const auto matchDateCreated = matchDates(this->dateCreated,user.dateCreated);
            const auto matchDateUpdated = matchDates(this->dateUpdated,user.dateUpdated);
            const auto matchFavorites = this->favorites != user.favorites;
            const auto matchStatus = this->status.compare(user.status) != 0;
            const auto matchRole = this->role.compare(user.role) != 0;
            return matchUserId && matchEmail && matchLocalId && matchTelephone && matchFullName && matchPhotoFileName &&
                    matchPhotoUrl && matchDateCreated && matchDateUpdated && matchFavorites && matchStatus && matchRole;

        }
        const QList<QVariant> getFullNameAndEmailAndTelephoneAndRoleAndDateCreated() const{
            return {this->fullName,this->email,this->phoneNumber,this->role,this->dateCreated};
        }
	};
	struct Author{
    private:
		Q_GADGET
    public:
        Q_PROPERTY(QString authorId MEMBER authorId)
        Q_PROPERTY(QString firstName MEMBER firstName)
        Q_PROPERTY(QString lastName MEMBER lastName)
        Q_PROPERTY(QDate dateOfBirth MEMBER dateOfBirth)
        Q_PROPERTY(QString address MEMBER address)
        Q_PROPERTY(QString phoneNumber MEMBER phoneNumber)
        Q_PROPERTY(QString status MEMBER status)
        Q_PROPERTY(QString photoUrl MEMBER photoUrl)
        Q_PROPERTY(QString photoFileName MEMBER photoFileName)
        Q_PROPERTY(QDate dateCreated MEMBER dateCreated)
        Q_PROPERTY(QDate dateUpdated MEMBER dateUpdated)
		QString authorId;
		QString firstName;
		QString lastName;
		QDate dateOfBirth;
		QString address;
		QString phoneNumber;
		QString status;
		QString photoUrl;
		QString photoFileName;
		QDate dateCreated;
		QDate dateUpdated;
		Author(const QString& authorId,const QString& firstName,const QString& lastName,
			const QDate& dateOfBirth,const QString& address,const QString& phoneNumber,
			const QString& status,const QString& photoUrl,const QString& photoFileName, 
			const QDate& dateCreated, const QDate& dateUpdated) : 
			authorId(authorId),firstName(firstName),lastName(lastName),dateOfBirth(dateOfBirth),
			address(address),phoneNumber(phoneNumber),status(status),photoUrl(photoUrl),
			photoFileName(photoFileName),dateCreated(dateCreated),dateUpdated(dateUpdated)
		{}
        Author(const QJsonObject& author) :
            authorId(author.value("id").toString()),firstName(author.value("firstName").toString()),
            lastName(author.value("lastName").toString()),dateOfBirth(author.value("dateOfBirth").toVariant().toDate()),
            address(author.value("address").toString()),phoneNumber(author.value("phoneNumber").toString()),
            status(author.value("status").toString()),photoUrl(author.value("photoUrl").toString()),
            photoFileName(author.value("photoFileName").toString()),dateCreated(author.value("dateCreated").toVariant().toDate()),
            dateUpdated(author.value("dateUpdated").toVariant().toDate())
        {}
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
            const auto matchFirstName = this->firstName.compare(author.firstName) == 0;
            const auto matchLastName = this->lastName.compare(author.lastName) == 0;
            const auto matchDateOfBirth = this->dateOfBirth == author.dateOfBirth;
            const auto matchAddress = this->address.compare(author.address) == 0;
            const auto matchPhoneNumber = this->phoneNumber.compare(author.phoneNumber) == 0;
            const auto matchStatus = this->status.compare(author.status) == 0;
            const auto matchPhotoUrl = this->photoUrl.compare(author.photoUrl) == 0;
            const auto matchPhotoFileName = this->photoFileName.compare(author.photoFileName) == 0;
            const auto matchDateCreated = this->dateCreated == author.dateCreated;
            const auto matchDateUpdated = this->dateUpdated == author.dateUpdated;
            return matchAuthorId && matchFirstName && matchLastName && matchDateOfBirth && matchAddress && matchPhoneNumber &&
                    matchStatus && matchPhotoUrl && matchPhotoFileName && matchDateCreated && matchDateUpdated;
        }
        bool operator!=(const Author& author) const{
            const auto matchAuthorId = this->authorId.compare(author.authorId) != 0;
            const auto matchFirstName = this->firstName.compare(author.firstName) != 0;
            const auto matchLastName = this->lastName.compare(author.lastName) != 0;
            const auto matchDateOfBirth = this->dateOfBirth != author.dateOfBirth;
            const auto matchAddress = this->address.compare(author.address) != 0;
            const auto matchPhoneNumber = this->phoneNumber.compare(author.phoneNumber) != 0;
            const auto matchStatus = this->status.compare(author.status) != 0;
            const auto matchPhotoUrl = this->photoUrl.compare(author.photoUrl) != 0;
            const auto matchPhotoFileName = this->photoFileName.compare(author.photoFileName) != 0;
            const auto matchDateCreated = this->dateCreated != author.dateCreated;
            const auto matchDateUpdated = this->dateUpdated != author.dateUpdated;
            return matchAuthorId && matchFirstName && matchLastName && matchDateOfBirth && matchAddress && matchPhoneNumber &&
                    matchStatus && matchPhotoUrl && matchPhotoFileName && matchDateCreated && matchDateUpdated;
        }
	};
	struct Category{
		Q_GADGET
		QString categoryId;
		QString name;
		QString description;
		QString status;
		QString color;
		QDate dateCreated;
		QDate dateUpdated;
		QString thumbnailUrl;
		QString thumbnailFileName;
		Category(const QString& categoryId,const QString& name,const QString& description,
			const QString& status,const QString& color,const QDate& dateCreated,
			const QDate& dateUpdated, const QString& thumbnailUrl,const QString& thumbnailFileName) : 
			categoryId(categoryId),name(name),description(description),status(status),color(color),
			dateCreated(dateCreated),dateUpdated(dateUpdated),thumbnailUrl(thumbnailUrl),
			thumbnailFileName(thumbnailFileName)
		{}
	};
	struct Comment{
		Q_GADGET
		QString email;
		QString message;
		QStringList likes;
		QList<Comment> replies;
		QDate dateCreated;
		QDate dateUpdated;
		Comment(const QString& email,const QString& message,const QStringList& likes,
			const QList<Comment>& replies, const QDate& dateCreated,const QDate& dateUpdated) : 
			email(email), message(message), replies(replies),dateCreated(dateCreated), 
			dateUpdated(dateUpdated)
		{}
	};
	struct Comic{
		Q_GADGET
		QString comicId;
		QString name;
		QDate dateReleased;
		QString description;
		QStringList categories;
		QString authorId;
		QStringList viewers;
		QStringList likers;
		QList<Comment> comments;  
		QDate dateCreated;
		QDate dateUpdated;
		QString thumbnailUrl;
		QString thumbnailFileName;
		QString dataUrl;
		QString dataFileName;
		QString status;
		Comic(const QString& comicId,const QString& name,const QDate& dateReleased,
			const QString& description, const QStringList& categories,const QString& authorId,
			const QStringList& viewers, const QStringList& likers, const QList<Comment>& comments,
			const QDate& dateCreated, const QDate& dateUpdated, const QString& thumbnailUrl,
            const QString& thumbnailFileName, const QString& dataUrl, const QString& dataFileName,
			const QString& status) : 
			comicId(comicId),name(name),dateReleased(dateReleased),description(description),
			viewers(viewers),likers(likers),comments(comments),dateCreated(dateCreated), 
			dateUpdated(dateUpdated),thumbnailUrl(thumbnailUrl),thumbnailFileName(thumbnailFileName),
			dataUrl(dataUrl), dataFileName(dataFileName),status(status)
		{}
	};
} //res

class Response : public QObject{
	Q_OBJECT
private:
	QNetworkReply * reply;
signals:
    void requestUnsuccessfullError(const res::Error);
public:
	explicit Response(QNetworkReply* reply = nullptr,QObject * parent = nullptr);
	~Response();

	// template <class T>
    // const T parseResponse(const QJsonDocument& data) const;
    const QJsonValue parseLoginResponse(const QJsonDocument& response);

    const QJsonValue parseResponse(const QJsonDocument& data);

    const res::Error createError(const QJsonObject& error) const noexcept;
    const res::Login createLogin(const QJsonObject& object) const noexcept;
    //const res::FoundUser createFoundUser(const QJsonObject& res,const res::Register& registeredUser) const noexcept;
    Person* createPerson(const QJsonObject& personRes) const noexcept;
    const res::FoundUser createFoundUser(const QJsonObject& res) const noexcept;
    //const QList<res::FoundUser> createFoundUserTableData(const QJsonArray& array) const noexcept;
    const QList<Person*> createPersonList(const QJsonArray& personsRes) const noexcept;
    const res::Author createAuthor(const QJsonObject& author) const noexcept;
    void connectNewReply(QNetworkReply * reply);
	QNetworkReply* getReply() const;
};
