import QtQuick
import QtQuick.Controls.Material
import Constants 1.0
import "./pages"

ApplicationWindow {
    id: _root
    width: Constants.width
    height: Constants.height
    visible: true
    title: qsTr("App")
    Loader{
        id: _appLoader
        anchors.fill: parent
        visible: true
        active: visible
        sourceComponent: LoginPage{}
    }
}
