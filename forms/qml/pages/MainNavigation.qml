//import QtQuick
//import QtQuick.Layouts
//import QtQuick.Controls.Material
//import QtCharts
//import Constants 1.0
//import "../components/layouts"

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

//Page{
//    id: _loginPage
//    width: Constants.width
//    height: Constants.height
//    background: Image{
//        source: Constants.images.loginBg
//    }
//    header: NavBar{
//        id: _navBar
//        anchors.top: parent.top
//        anchors.left: parent.left
//        anchors.right: parent.right
//        anchors.bottom: _mainNavItem.top
//    }
//    Component{
//        id: _dashboard
//        DashboardPage{}
//    }
//    Component{
//        id: _comics
//        ComicPage{}
//    }
//    Component{
//        id: _author
//        AuthorPage{}
//    }
//    Component{
//        id: _admin
//        AdminsPage{}
//    }

//    contentItem: Item{
//        id: _mainNavItem
//        width: parent.height
//        height: parent.height - _navBar.height
//        anchors.top: _navBar.bottom
//        anchors.left: parent.left
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
//        DashboardPage{anchors.fill: parent}


////        SwipeView{
////            id: _mainStack
////            anchors.fill: parent
////            currentIndex: _navBar.currentIndex
////            Repeater{
////                model: [_dashboard,_comics,_author,_admin]
////                delegate: Loader{
////                    active: SwipeView.isCurrentItem
////                    sourceComponent: modelData
////                }
////            }
////        }

////        StackLayout{
////            id: _mainStack
////            anchors.fill: parent
////            currentIndex: _navBar.currentIndex
////            Repeater{
////                model: [_dashboard,_comics,_author,_admin]
////                delegate: Loader{
////                    active: StackLayout.isCurrentItem
////                    sourceComponent: modelData
////                }
////            }
////        }
//    }
//}
