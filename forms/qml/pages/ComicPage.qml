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
            Pane{
                id: _comicPaneHeader
                Layout.fillWidth: true
                Layout.preferredHeight: _col6L.implicitHeight
                Material.background: Constants.colors.black
                ColumnLayout{
                    id: _col6L
                    anchors.fill: parent
                    Item{
                        Layout.fillWidth: true
                        Layout.preferredHeight: _row7L.implicitHeight
                        RowLayout{
                            id: _row7L
                            anchors.fill: parent
                            Label{
                                id: _tableTitleLabel
                                text: "In Stock"
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
                                    }
                                    ToolButton {
                                        icon.source: Constants.icons.pen
                                        icon.color: Constants.colors.sunset
                                    }
                                    ToolButton {
                                        icon.source: Constants.icons.dash
                                        icon.color: Constants.colors.danger
                                    }
                                }
                            }
                        }
                    }
                    Item{
                        Layout.fillWidth: true
                        Layout.preferredHeight: _row10L.implicitHeight
                        RowLayout{
                            id: _row10L
                            anchors.fill: parent
//                            ComboBox {
//                                id: _phoneNavItems
//                                model: ["Romance","Comedy","Tragedy"]
//                                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
//                                Layout.leftMargin: _root.width < 900 ? 0 : 30
//                                Layout.rightMargin: _root.width < 900 ? 0 : 30
//                                Layout.fillWidth: true
//                                Material.background: "transparent"
//                                Material.accent: Material.LightBlue
//                                delegate: ItemDelegate {
//                                    width: _phoneNavItems.width
//                                    contentItem: Label {
//                                        text: _phoneNavItems.textRole
//                                              ? (Array.isArray(control.model) ? modelData[control.textRole] : model[control.textRole])
//                                              : modelData
//                                        Material.foreground: Colors
//                                        font: _phoneNavItems.font
//                                        elide: Text.ElideRight
//                                        verticalAlignment: Text.AlignVCenter
//                                    }
//                                    highlighted: _phoneNavItems.highlightedIndex === index
//                                }
//                                Binding{
//                                    target: _phoneNavItems.popup
//                                    property: "background.color"
//                                    value: "#141414"
//                                }
//                                Binding{
//                                    target: _phoneNavItems.contentItem
//                                    property: "color"
//                                    value: "#fff"
//                                }
//                            }
                            Item{
                                Layout.fillWidth: true
                                Layout.preferredHeight: _col11L.implicitHeight
                                ColumnLayout{
                                    id: _col11L
                                    anchors.fill: parent

                                }
                            }

                            Item{
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                Layout.preferredWidth: _row9L.implicitWidth
                                Layout.preferredHeight: _row9L.implicitHeight
                                RowLayout{
                                    id: _row9L
                                    anchors.fill: parent
                                    RadioButton{
                                        text: "Tout(s)"
                                        Material.accent: Constants.colors.success
                                        font: _root.width < 640 ? Constants.lightFont.h4 : Constants.lightFont.h3
                                        Material.foreground: Constants.colors.white
                                    }
                                    RadioButton{
                                        text: "Available"
                                        Material.accent: Constants.colors.success
                                        font: _root.width < 640 ? Constants.lightFont.h4 : Constants.lightFont.h3
                                        Material.foreground: Constants.colors.white
                                    }
                                    RadioButton{
                                        text: "Pending"
                                        Material.accent: Constants.colors.success
                                        font: _root.width < 640 ? Constants.lightFont.h4 : Constants.lightFont.h3
                                        Material.foreground: Constants.colors.white
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}
