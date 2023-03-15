import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtCharts
import Constants 1.0
import "../components/layouts"

Page{
    id: _loginPage
    width: Constants.width
    height: Constants.height
    background: Image{
        source: Constants.images.loginBg
    }
    header: NavBar{
        id: _navBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: _mainNavItem.top
    }
    contentItem: Item{
        id: _mainNavItem
        width: parent.height
        height: parent.height - _navBar.height
        anchors.top: _navBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        StackLayout{
            id: _mainStack
            anchors.fill: parent
            anchors.margins: 10
            currentIndex: _navBar.currentIndex
            DashboardPage{}
            Rectangle{}
            Rectangle{}
            Rectangle{}
        }
    }
}
