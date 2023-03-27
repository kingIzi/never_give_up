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
    Connections{
        target: _admin
        function onReadUsersList(users){
            _defaultTableView._tableViewModel.populate(users)
        }
    }
    Component.onCompleted: {
        const users = Req.availableUsersList()
        _admin.requestUsersList(users)
    }

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
                        Component.onCompleted: {
                            const users = Req.availableUsersList();
                            _admin.requestUsersList(users)
                        }
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
