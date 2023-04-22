import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import Qt5Compat.GraphicalEffects
import AdminTableModel 1.0
import "../components/layouts"
import "../../scripts/utilities.js" as Utils
import "../../scripts/requests.js" as Req

ScrollView{
        id: _dashboardScroll
        contentWidth: availableWidth
        contentHeight: _dashboardContentItem.implicitHeight
        readonly property alias _adminsTableView: _defaultTableView
        Item{
            id: _dashboardContentItem
            width: _dashboardScroll.contentWidth
            implicitHeight: _dashboardCol.implicitHeight
            anchors.fill: parent
            ColumnLayout {
                id: _dashboardCol
                anchors.fill: parent
                spacing: 20
                Item{
                    id: _detailsItem
                    Layout.fillWidth: true
                    Layout.preferredHeight: _dashboardDetailsGrid.implicitHeight
                    GridLayout{
                        id: _dashboardDetailsGrid
                        anchors.fill: parent
                        columns: _root.width < 640 ? 1 : 2
                        GeneralReview{
                            id: _generalReviews
                            Layout.fillWidth: true
                            Layout.preferredHeight: 200
                        }
                        DashboardMostPopularAuthor{
                            id: _dashBoardMostPopularAuthor
                            Layout.fillWidth: true
                            Layout.preferredHeight: 200
                        }
                    }
                }
                Item{
                    id: _dataItem
                    Layout.fillWidth: true
                    Layout.preferredHeight: _dashboardDataGrid.implicitHeight
                    GridLayout{
                        id: _dashboardDataGrid
                        anchors.fill: parent
                        columns: _root.width < 640 ? 1 : 2
                        DefaultTableView{
                            id: _defaultTableView
                            Layout.fillWidth: true
                            Layout.preferredHeight: implicitHeight
                            _titleLabel.text: "Admins"
                        }
                        DashboardCharts{
                            id: _dashboardChart
                            Layout.fillWidth: true
                            Layout.preferredHeight: implicitHeight
                        }
                    }
                }
            }
        }
    }

//Page{
//    //id: _dashboardPage
//    width: Constants.width
//    height: Constants.height
//    background: Image{
//        source: Constants.images.loginBg
//    }
//    LoadingScreen{
//        id: _dashboardPage
//    }
//    header: NavBar{
//        id: _navBar
//        anchors.top: parent.top
//        anchors.left: parent.left
//        anchors.right: parent.right
//        anchors.bottom: _dashboardScroll.top
//    }
//    contentItem: ScrollView{
//        id: _dashboardScroll
//        contentWidth: availableWidth
//        contentHeight: _dashboardContentItem.implicitHeight
//        Item{
//            id: _dashboardContentItem
//            width: _dashboardScroll.contentWidth
//            implicitHeight: _dashboardCol.implicitHeight
//            anchors.fill: parent
//            ColumnLayout {
//                id: _dashboardCol
//                anchors.fill: parent
//                spacing: 20
//                Item{
//                    id: _detailsItem
//                    Layout.fillWidth: true
//                    Layout.preferredHeight: _dashboardDetailsGrid.implicitHeight
//                    GridLayout{
//                        id: _dashboardDetailsGrid
//                        anchors.fill: parent
//                        columns: _root.width < 640 ? 1 : 2
//                        GeneralReview{
//                            id: _generalReviews
//                            Layout.fillWidth: true
//                            Layout.preferredHeight: 200
//                        }
//                        DashboardMostPopularAuthor{
//                            id: _dashBoardMostPopularAuthor
//                            Layout.fillWidth: true
//                            Layout.preferredHeight: 200
//                        }
//                    }
//                }
//                Item{
//                    id: _dataItem
//                    Layout.fillWidth: true
//                    Layout.preferredHeight: _dashboardDataGrid.implicitHeight
//                    GridLayout{
//                        id: _dashboardDataGrid
//                        anchors.fill: parent
//                        columns: _root.width < 640 ? 1 : 2
//                        DefaultTableView{
//                            id: _defaultTableView
//                            Layout.fillWidth: true
//                            Layout.preferredHeight: implicitHeight
//                            _titleLabel.text: "Admins"
//                        }
//                        DashboardCharts{
//                            id: _dashboardChart
//                            Layout.fillWidth: true
//                            Layout.preferredHeight: implicitHeight
//                        }
//                    }
//                }
//            }
//        }
//    }

//}

