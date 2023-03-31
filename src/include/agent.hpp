#pragma once

#include "response.hpp"
#include "request.hpp"

class Agent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isRequesting READ isRequesting WRITE setIsRequesting NOTIFY isRequestingChanged)
    Q_PROPERTY(bool isLoggedIn READ isLoggedIn WRITE setIsLoggedIn NOTIFY isLoggedInChanged)
private:
    struct Login{
        const std::string idToken;
        const std::string refreshToken;
        const std::string email;
        const std::string localId;
        const int expiresIn;
        Login(const std::string& idToken,const std::string& refreshToken,const std::string& email,
              const std::string& localId,const int expiresIn) :
            idToken(idToken),refreshToken(refreshToken),email(email),expiresIn(expiresIn),localId(localId)
        {}
    };
    std::unique_ptr<Agent::Login> agentLogin;
    std::shared_ptr<Request> request_ptr;
    Response response;
    bool isRequesting_prop;
    bool isLoggedIn_prop;
private slots:
    void onRequestLogin(const QJsonDocument);
    void onRequestUsersList(const QJsonDocument);
    void onRequestUserUpdate(const QJsonDocument);
public slots:
    void setIsRequesting(const bool arg);
    void setIsLoggedIn(const bool arg);
public:
    explicit Agent(QObject *parent = nullptr);
    Q_INVOKABLE  void storeAgentAuth() const;
    Q_INVOKABLE void requestLogin(const QVariantMap body);
    Q_INVOKABLE void requestUsersList(const QVariantMap body);
    Q_INVOKABLE void requestUserUpdate(const QString userId,const res::FoundUser user);
    const bool isRequesting() const;
    const bool isLoggedIn() const;

signals:
    void requestFailedError(const QString);
    void isRequestingChanged();
    void requestErrorMsg(const res::Error);
    void isLoggedInChanged();

    //requests
    void usersList(const QList<res::FoundUser>);
    void updatedUser(const res::FoundUser);
};

