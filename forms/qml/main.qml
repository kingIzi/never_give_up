import QtQuick
import QtQuick.Controls.Material
import Constants 1.0
import "./pages"

ApplicationWindow {
    id: _root
    width: Constants.width
    height: Constants.height
    minimumWidth: Constants.width
    minimumHeight: Constants.height / 2
    visible: true
    title: qsTr("App")
    Component{
        id: _loginPage
        LoginPage{}
    }
    Component{
        id: _mainNavigationPage
        MainNavigation{}
    }

    Loader{
        id: _appLoader
        anchors.fill: parent
        visible: true
        active: visible
        source: "pages/LoginPage.qml"
        //state: _admin.isLoggedIn ? "navigate" : "session"
        state: _agent.isLoggedIn ? "navigate" : "session"
        onStateChanged: {
            if (state !== "session")
                _agent.storeAgentAuth()
        }
        states: [
            State {
                name: "session"
                PropertyChanges {
                    target: _appLoader
                    source: "pages/LoginPage.qml"
                }
            },
            State {
                name: "navigate"
                PropertyChanges {
                    target: _appLoader
                    source: "pages/MainNavigation.qml"
                }
            }
        ]
    }
}
