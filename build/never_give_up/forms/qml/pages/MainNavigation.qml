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
        anchors.bottom: _dashboardPage.top
    }
    contentItem: DashboardPage{
        id: _dashboardPage
        anchors.top: _navBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}

