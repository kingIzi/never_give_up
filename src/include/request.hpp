#pragma once

#include <memory>

#include <QtCore/QString>
#include <QtCore/QJsonDocument>
#include <QtCore/QList>
#include <QtCore/QUrl>
#include <QtCore/QObject>
#include <QtCore/QPair>
#include <QtCore/QByteArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonValue>
#include <QtCore/QJsonArray>

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QHttpPart>
#include <QtNetwork/QHttpMultiPart>




class Request : public QObject {
	Q_OBJECT
private:
	QString baseUrl;
    QString idToken;
	std::unique_ptr<QNetworkAccessManager> manager;
    //std::unique_ptr<QHttpMultiPart> multiPart;
	bool isOperating;
	static const char* URL_FORMAT_REGEX;
private:
    const QString contentDispositionValue(const QString key) const;
    void connectReplyReadyRead(QNetworkReply * reply);
    void connectReplyReadyRead(QNetworkReply * const reply,QHttpMultiPart * const multiPart);
public:
    void appendHttpFilePart(const QJsonObject& files,QHttpMultiPart * const multiPart) const;
    void appendHttpParts(const QJsonDocument& document,QHttpMultiPart *const multiPart) const;
	struct Endpoint {
		//session
		static constexpr const char* sessionLogin = "/session/login";
		static constexpr const char* sessionRegister = "/session/register";

		//user
		static constexpr const char* userDetails = "/user/details";
		static constexpr const char* userList = "/user/list";
		static constexpr const char* userFindOne = "/user/findOne";
		static constexpr const char* userUpdateOne = "/user/updateOne";
		static constexpr const char* userFavorites = "/user/updateFavorites";

		//author
		static constexpr const char* createAuthor = "/author/createOne";
		static constexpr const char* updateAuthor = "/author/updateOne";
		static constexpr const char* deleteAuthor = "/author/deleteOne";
		static constexpr const char* findAuthor = "/author/findOne";
		static constexpr const char* listAuthor = "/author/list";

		//category
		static constexpr const char* createCategory = "/category/createOne";
		static constexpr const char* updateCategory = "/category/updateOne";
		static constexpr const char* findCategory = "/category/findOne";
		static constexpr const char* deleteCategory = "/category/deleteOne";
		static constexpr const char* listCategory = "/category/list";

		//comic
        static constexpr const char* createComic = "/comic/createOne";
		static constexpr const char* updateComic = "/comic/updateOne";
		static constexpr const char* listComic = "/comic/list";
		static constexpr const char* deleteComic = "/comic/delete";
		static constexpr const char* findComic = "/comic/findOne";
		static constexpr const char* likeComic = "/comic/video/like";
		static constexpr const char* viewComic = "/comic/video/view";
		static constexpr const char* findComicComment = "/comic/comment/find";
		static constexpr const char* replyComicComment = "/comic/comment/reply";
		static constexpr const char* addComicComment = "/comic/comment/add";
		static constexpr const char* likeComicComment = "/comic/comment/like";
		static constexpr const char* removeComicComment = "/comic/comment/remove";
        static constexpr const char* comicTest = "/comic/test";
	};
public:
	//constructor destructor
	explicit Request(const QString& baseUrl, QObject* parent = nullptr);
	~Request();

	//Getters & Setters
	void setManager(QNetworkAccessManager* manager);
    QNetworkAccessManager* getManager();
	void setBaseUrl(const QString& baseUrl);
	const QString getBaseUrl() const;
	void setIsOperating(const bool isOperating);
	const bool getIsOperating() const;

	//make request

    void makeJsonPostRequest(const QUrl& url, const QString& idToken,
	                                        const QJsonDocument& document);
    void makeRequestNoIdtoken(const QUrl& url,const QJsonDocument& document);

    void makeMultiPutRequest(const QUrl& url, const QString& idToken,const QJsonDocument& document);
    void makeMultiPostRequest(const QUrl& url, const QString& idToken,const QJsonDocument& document);

    void makeGetRequest(const QUrl& url, const QString& idToken);

	//helper
	const QUrl buildUrl(const QList<QPair<QString, QString>>& queries, const QString& path) const;
    const QByteArray buildRawJsonFromDocument(const QJsonDocument& document) const;
    QString getIdToken() const;
    void setIdToken(const QString &newIdToken);


signals:
	void response(const QJsonDocument);
    void replyReadyRead(const QJsonDocument);
public slots:
	void requestFinished(const QNetworkReply* reply); //emits Request::response(QJsonDocument)
	void uploadProgressChanged(qint64 bytesReceived, qint64 bytesTotal);
	void downloadProgessChanged(qint64 bytesReceived, qint64 bytesTotal);
};
