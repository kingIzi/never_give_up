import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import Qt5Compat.GraphicalEffects
import AdminTableModel 1.0
import "../components/layouts"
import "../../scripts/utilities.js" as Utils

ScrollView{
    id: _comicScroll
    contentWidth: availableWidth
    contentHeight: _comicContentItem.implicitHeight
    Item{
        id: _comicContentItem
        width: _comicScroll.contentWidth
        implicitHeight: _comicCol.implicitHeight
        anchors.fill: parent
        ColumnLayout {
            id: _comicCol
            anchors.fill: parent
            spacing: 20
        }
    }
    Component.onCompleted: console.log("hello world")
}
