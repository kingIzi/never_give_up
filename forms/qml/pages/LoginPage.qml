import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../components/customs"
import "./forms"

Page{
    id: _loginPage
    width: Constants.width
    height: Constants.height
    background: Image{
        source: Constants.images.loginBg
    }

    StackView{
        id: _sessionStack
        anchors.centerIn: parent
        implicitHeight: currentItem.implicitHeight
        width: _root.width < 640 ? parent.width : parent.width / 2
        initialItem: LoginForm{}
    }
}
