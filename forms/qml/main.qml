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
        sourceComponent: _loginPage
        state: "session"
        states: [
            State {
                name: "session"
                PropertyChanges {
                    target: _appLoader
                    sourceComponent: _loginPage
                }
            },
            State {
                name: "navigate"
                PropertyChanges {
                    target: _appLoader
                    sourceComponent: _mainNavigationPage
                }
            }
        ]
    }
}
