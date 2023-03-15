import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import Qt5Compat.GraphicalEffects
import "../components/layouts"
import "../../scripts/utilities.js" as Utils

ScrollView{
    id: _dashboardScroll
    contentWidth: availableWidth
    contentHeight: _dashboardContentItem.implicitHeight
    Item{
        id: _dashboardContentItem
        width: _dashboardScroll.contentWidth
        implicitHeight: _dashboardCol.implicitHeight
        anchors.fill: parent
        ColumnLayout {
            id: _dashboardCol
            anchors.fill: parent
            Item{
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
        }
    }
}
