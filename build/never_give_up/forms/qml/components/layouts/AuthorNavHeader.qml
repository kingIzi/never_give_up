import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../customs"
import "../../../scripts/utilities.js" as Utils

Pane{
    id: _authorPaneHeader
    implicitHeight: _col6L.implicitHeight
    Material.background: Constants.colors.black
    padding: 10
    signal openAddComicForm()
    signal openUpdateComicForm()
    signal openDeleteComicForm()
    ColumnLayout{
        id: _col6L
        anchors.fill: parent
        spacing: 20
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _row7L.implicitHeight
            RowLayout{
                id: _row7L
                anchors.fill: parent
                Label{
                    id: _tableTitleLabel
                    text: "All Authors"
                    font: Constants.blackFont.h2
                    Material.foreground: Constants.colors.white
                    Layout.alignment: Qt.AlignVCenter
                    Layout.fillWidth: true
                }
                ToolBar {
                    id: _toolBar
                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    Layout.preferredWidth: _row8L.implicitWidth
                    Layout.preferredHeight: _row8L.implicitHeight
                    Material.background: "transparent"
                    background: Rectangle {
                        color: "transparent"
                    }
                    RowLayout {
                        id: _row8L
                        anchors.fill: parent
                        ToolButton {
                            icon.source: Constants.icons.plus
                            icon.color: Constants.colors.success
                            enabled: _authorListView.currentIndex >= 0
                            HoverHandler{
                                enabled: true
                                cursorShape: "PointingHandCursor"
                            }
                            onClicked: openAddComicForm()
                        }
                        ToolButton {
                            icon.source: Constants.icons.pen
                            icon.color: Constants.colors.sunset
                            enabled: _authorListView.currentIndex >= 0
                            HoverHandler{
                                enabled: true
                                cursorShape: "PointingHandCursor"
                            }
                            onClicked: openUpdateComicForm()
                        }
                        ToolButton {
                            icon.source: Constants.icons.dash
                            icon.color: Constants.colors.danger
                            enabled: _authorListView.currentIndex >= 0
                            HoverHandler{
                                enabled: true
                                cursorShape: "PointingHandCursor"
                            }
                            onClicked: openDeleteComicForm()
                        }
                    }
                }
            }
        }
        Label{
            id: _filterLabel
            text: "Filtre"
            font: Constants.blackFont.h5
            Material.foreground: Constants.colors.white
            Layout.alignment: Qt.AlignVCenter
            Layout.fillWidth: true
        }
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _filterGrid.implicitHeight
            GridLayout{
                id: _filterGrid
                anchors.fill: parent
                columns: _root.width < 640 ? 2 : 3
                Repeater{
                    model: Utils.getAuthorFilters(Constants.icons)
                    delegate: ComboBox{
                        id: _authorComboBox
                        Layout.fillWidth: true
                        model: modelData.model
                        leftPadding: 30
                        Material.background: "#1B1B1B"
                        Material.foreground: Constants.colors.white
                        font: Constants.lightFont.h4
                        Button{
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            icon.source: modelData.icon
                            icon.color: Constants.colors.white
                            icon.width: 20
                            icon.height: 20
                            Material.background: "transparent"
                        }
                        popup: Popup {
                                 y: _authorComboBox.height - 1
                                 width: _authorComboBox.width
                                 implicitHeight: contentItem.implicitHeight
                                 padding: 1
                                 Material.background: "#1B1B1B"
                                 contentItem: ListView {
                                     clip: true
                                     implicitHeight: contentHeight
                                     model: _authorComboBox.popup.visible ? _authorComboBox.delegateModel : null
                                     currentIndex: _authorComboBox.highlightedIndex
                                     ScrollIndicator.vertical: ScrollIndicator { }
                                 }
                             }
                        delegate: ItemDelegate {
                            width: _authorComboBox.width
                            contentItem: Label {
                                text: _authorComboBox.textRole
                                      ? (Array.isArray(control.model) ? modelData[_authorComboBox.textRole] : model[_authorComboBox.textRole])
                                      : modelData
                                color: Constants.colors.white
                                font: _authorComboBox.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: _authorComboBox.highlightedIndex === index
                        }
                    }
                }
                Button{
                    id: _filterBtn
                    Layout.fillWidth: true
                    font: Constants.blackFont.h4
                    Material.background: Constants.colors.primary
                    Material.foreground: Constants.colors.white
                    text: "Filtre"
                }
            }
        }
        SearchField{
            id: _searchComic
            Layout.fillWidth: true
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            placeholderText: "Rechercher l'auteur par nom"
        }
    }
}
