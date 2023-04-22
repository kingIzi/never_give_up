#include "request.hpp"

#include <algorithm>

#include <QRegularExpression>
#include <QDebug>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QVariantMap>
#include <QMimeDatabase>
#include <QMimeType>
#include <QFileInfo>
#include <QFile>
#include <QIODevice>
#include <QVariant>
#include <map>




//init static members

const char* Request::URL_FORMAT_REGEX = "^(https?:\/\/)?[0-9a-z]+\.[-_0-9a-z]+\.[0-9a-z]+$";

//constructors

//construct class initializes all members
Request::Request(const QString& baseUrl, QObject* parent) :
    QObject{parent},idToken(),baseUrl(baseUrl),
    manager(std::make_unique<QNetworkAccessManager>()), isOperating(false)
{
    try {
        if (this->baseUrl == nullptr)
            throw std::invalid_argument("Error! baseUrl was nullptr");
        else if (!this->baseUrl.contains(QRegularExpression(Request::URL_FORMAT_REGEX)))
            throw std::invalid_argument("Error! baseUrl was did not match regex");
    }
    catch (const std::invalid_argument&  e) {
        qDebug() << "Failed to register member Request::baseUrl" << e.what();
        this->setBaseUrl("");
    }
}

//default destructor
Request::~Request() {

}

//getter & setters

//sets the base url of the requests
void Request::setBaseUrl(const QString& baseUrl) {
    this->baseUrl = baseUrl;
}

//returns the app base url
const QString Request::getBaseUrl() const {
    return this->baseUrl;
}

//resets network manager and points to newManager
void Request::setManager(QNetworkAccessManager* manager) {

}

void Request::setIsOperating(const bool isOperating) {
    this->isOperating = isOperating;
}

//returns network manager
QNetworkAccessManager* Request::getManager() {
    return this->manager.get();
}

//returns whether or not a request is being proccessed
const bool Request::getIsOperating() const {
    return this->isOperating;
}

void Request::connectReplyReadyRead(QNetworkReply *reply)
{
    QObject::connect(reply,&QNetworkReply::finished,[this,reply](){
        try{
            if (reply){
                const auto document = QJsonDocument::fromJson(reply->readAll());
                emit Request::replyReadyRead(document);
                reply->deleteLater();
            }
        }
        catch(const std::exception& e){
            qDebug() << e.what();
        }
    });
}

void Request::connectReplyReadyRead(QNetworkReply * const reply, QHttpMultiPart * const multiPart)
{
    QObject::connect(reply,&QNetworkReply::finished,this,[reply,multiPart,this](){
        if (reply){
            const auto document = QJsonDocument::fromJson(reply->readAll());
            emit Request::replyReadyRead(document);
            reply->deleteLater();
        }
        if (multiPart){
            multiPart->deleteLater();
        }
    });
}

//make network requests

void Request::makeJsonPostRequest(const QUrl& url, const QString& idToken, const QJsonDocument& document) {
    if (idToken.isEmpty())
        throw std::runtime_error("NO IDTOKEN FOUND TO REQUEST");
    if (document.isEmpty())
        return;
    if (!url.isValid())
        throw std::runtime_error("RUNTIME ERROR: INVALID_URL");

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
    const auto reply = this->manager->post(request,document.toJson());
    QObject::connect(reply,&QNetworkReply::uploadProgress,this,&Request::uploadProgressChanged);
    this->connectReplyReadyRead(reply);
}

void Request::makeRequestNoIdtoken(const QUrl& url, const QJsonDocument& document) {
    if (document.isEmpty())
        return;
    if (!url.isValid())
        throw std::runtime_error("RUNTIME ERROR: INVALID_URL");

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    const auto reply = this->manager->post(request, document.toJson());
    QObject::connect(reply,&QNetworkReply::uploadProgress,this,&Request::uploadProgressChanged);
    this->connectReplyReadyRead(reply);
}

void Request::makeMultiPutRequest(const QUrl& url, const QString& idToken, const QJsonDocument& document) {
    if (idToken.isEmpty())
        throw std::runtime_error("NO IDTOKEN FOUND TO REQUEST");
    if (document.isNull() || document.isEmpty())
        return;
    if (!url.isValid())
        throw std::runtime_error("RUNTIME ERROR: INVALID_URL");

    const auto multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    this->appendHttpParts(document,multiPart);
    QNetworkRequest request(url);
    request.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
    const auto reply = this->manager->put(request,multiPart);
    multiPart->setParent(reply);
    QObject::connect(reply,&QNetworkReply::uploadProgress,this,&Request::uploadProgressChanged);
    this->connectReplyReadyRead(reply,multiPart);
}

void Request::makeMultiPostRequest(const QUrl &url, const QString &idToken, const QJsonDocument &document)
{
    if (idToken.isEmpty())
        throw std::runtime_error("NO IDTOKEN FOUND TO REQUEST");
    if (document.isNull() || document.isEmpty())
        return;
    if (!url.isValid())
        throw std::runtime_error("RUNTIME ERROR: INVALID_URL");

    const auto multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    this->appendHttpParts(document,multiPart);
    QNetworkRequest request(url);
    request.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());
    const auto reply = this->manager->post(request,multiPart);
    multiPart->setParent(reply);
    QObject::connect(reply,&QNetworkReply::uploadProgress,this,&Request::uploadProgressChanged);
    this->connectReplyReadyRead(reply,multiPart);
}

void Request::makeGetRequest(const QUrl& url, const QString& idToken) {
    if (idToken.isEmpty())
        throw std::runtime_error("NO IDTOKEN FOUND TO REQUEST");
    if (!url.isValid())
        throw std::runtime_error("RUNTIME ERROR: INVALID_URL");

    QNetworkRequest request(url);
    request.setRawHeader(QByteArray("Authorization"), QString("Bearer %1").arg(idToken).toUtf8());

    const auto reply = this->manager->get(request);
    this->setIsOperating(true);
    QObject::connect(reply,&QNetworkReply::uploadProgress,this,&Request::uploadProgressChanged);
    this->connectReplyReadyRead(reply);
}

//helpers

//uses query params and a valid path to build a url (endpoint)
const QUrl Request::buildUrl(const QList<QPair<QString, QString>>& queries, const QString& path) const {
    if (this->baseUrl.isEmpty())
        throw std::invalid_argument("Error! base url is empty");

    const auto removeMissingQueryItems = [](const QPair<QString, QString>& value) {
        return value.first != nullptr && !value.first.isEmpty() && value.second != nullptr
                && !value.second.isEmpty();
    };
    QList<QPair<QString, QString>> queryItems;
    std::copy_if(queries.begin(), queries.end(), std::back_inserter(queryItems), removeMissingQueryItems);

    QUrl endpoint(this->baseUrl);
    endpoint.setPath(path);
    if (!queryItems.isEmpty()) {
        QUrlQuery query;
        query.setQueryItems(queryItems);
        endpoint.setQuery(query);
    }
    return endpoint;
}

const QByteArray Request::buildRawJsonFromDocument(const QJsonDocument& document) const {
    if (document.isEmpty())
        return QByteArray();
    return ((QByteArray) document.toJson()).insert(0, "form-data; ");
}

const QString Request::contentDispositionValue(const QString key) const
{
    return QString("form-data; name=\"" + key + "\"");
}

void Request::appendHttpParts(const QJsonDocument &document,QHttpMultiPart * const multiPart) const
{
    if (document.isObject() && multiPart){
        const auto values = document.object();
        const auto keys = values.keys();
        std::for_each(keys.begin(),keys.end(),[this,values,multiPart](const QString& key){
            QHttpPart textPart;
            textPart.setHeader(QNetworkRequest::ContentDispositionHeader,this->contentDispositionValue(key));
            textPart.setBody(values.value(key).toVariant().toByteArray());
            multiPart->append(textPart);
        });
        const auto files = values.value("files").isNull() ? QJsonObject() : values.value("files").toObject();
        this->appendHttpFilePart(files,multiPart);
    }
}

QString Request::getIdToken() const
{
    return this->idToken;
}

void Request::setIdToken(const QString &newIdToken)
{
    this->idToken = newIdToken;
}

void Request::appendHttpFilePart(const QJsonObject &files,QHttpMultiPart * const multiPart) const
{
    if (files.isEmpty() || !multiPart) { return; }
    const auto keys = files.keys();
    for (const auto& key : keys){
        const QFileInfo fileInfo(files.value(key).toString());
        if (!fileInfo.isFile())
            throw std::invalid_argument("One of the files specified does not exist or has been deleted from location.");

        QHttpPart filePart;
        filePart.setHeader(QNetworkRequest::ContentTypeHeader, QMimeDatabase().mimeTypeForFile(fileInfo.absoluteFilePath()).name());
        filePart.setHeader(QNetworkRequest::ContentDispositionHeader,this->contentDispositionValue(key));
        auto * file = new QFile(fileInfo.absoluteFilePath());
        if (!file->open(QIODevice::ReadOnly))
            throw std::invalid_argument("Failed to open file specified. Please verify path exists");
        filePart.setBodyDevice(file);
        file->setParent(multiPart);
        multiPart->append(filePart);
    }
}

//slots

//slot for network reply res
void Request::requestFinished(const QNetworkReply* reply) {

}

void Request::uploadProgressChanged(qint64 bytesReceived, qint64 bytesTotal) {
    qDebug() << "BYTES SENT" << bytesReceived;
    qDebug() << "BYTES TOTAL" << bytesTotal;
}

void Request::downloadProgessChanged(qint64 bytesReceived, qint64 bytesTotal) {

}
