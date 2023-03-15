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
    Component{
        id: _dashboard
        DashboardPage{}
    }
    Component{
        id: _comics
        ComicPage{}
    }
    Component{
        id: _author
        Rectangle{}
    }
    Component{
        id: _admin
        Rectangle{}
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
            Repeater{
                model: [_dashboard,_comics,_author,_admin]
                delegate: Loader{
                    active: StackLayout.isCurrentItem
                    sourceComponent: modelData
                }
            }
        }
    }
}
