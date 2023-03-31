import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import AdminTableModel 1.0
import "../customs"

Item{
    id: _genericTableViewItem
    Layout.fillWidth: true
    Layout.maximumWidth: _root.width < 640 ? parent.width : parent.width / 2
    implicitHeight: _col5L.implicitHeight
    property var _modelHeaders: []
    readonly property alias _titleLabel: _tableTitleLabel
    readonly property alias _adminTableModel: _tableModel
    signal addForm()
    signal editForm()
    signal removeForm()
    ColumnLayout{
        id: _col5L
        anchors.fill: parent
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _row6L.implicitHeight
            Layout.bottomMargin: 10
            Layout.topMargin: 10
            ColumnLayout{
                id: _row6L
                anchors.fill: parent
                Item{
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                    implicitHeight: _row16L.implicitHeight
                    RowLayout{
                        id: _row16L
                        anchors.fill: parent
                        Label{
                            id: _tableTitleLabel
                            Material.foreground: Constants.colors.white
                            padding: 10
                            font: Constants.blackFont.h2
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
                                    HoverHandler{
                                        enabled: true
                                        cursorShape: "PointingHandCursor"
                                    }
                                    onClicked: addForm()
                                }
                                ToolButton {
                                    icon.source: Constants.icons.pen
                                    icon.color: Constants.colors.sunset
                                    HoverHandler{
                                        enabled: true
                                        cursorShape: "PointingHandCursor"
                                    }
                                    onClicked: editForm()
                                }
                                ToolButton {
                                    icon.source: Constants.icons.dash
                                    icon.color: Constants.colors.danger
                                    HoverHandler{
                                        enabled: true
                                        cursorShape: "PointingHandCursor"
                                    }
                                    onClicked: removeForm()
                                }
                            }
                        }
                    }
                }
                SearchField{
                    Layout.fillWidth: true
                }
            }
        }
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _col6L.implicitHeight
            clip: true
            ColumnLayout{
                id: _col6L
                anchors.fill: parent
                HorizontalHeaderView{
                    model: _modelHeaders
                    syncView: _genericTableView
                    Layout.fillWidth: true
                    delegate: ItemDelegate{
                        id: _tableHeader
                        font: Constants.blackFont.h5
                        Material.foreground: Constants.colors.white
                        text: modelData
                        Binding{
                            target: _tableHeader.background
                            property: "color"
                            value: Constants.colors.black
                        }
                    }
                }
                TableView{
                    id: _genericTableView
                    Layout.fillWidth: true
                    Layout.preferredHeight: contentHeight
                    Layout.maximumHeight: 500
                    columnSpacing: 1
                    rowSpacing: 1
                    clip: true
                    interactive: false
                    alternatingRows: true
                    model: AdminTableModel{
                        id: _tableModel
                    }
                    delegate: ItemDelegate{
                        id: _tableDelegateItem
                        font: Constants.blackFont.h6
                        text: display
                        implicitWidth: width
                        implicitHeight: height
                        //width: _root.width < 640 ? 150 : _tableItem.width / _adminTableModel.columnCount()
                        width: 150
                        height: 50
                        Binding{
                            target: _tableDelegateItem.background
                            property: "color"
                            value: model.row % 2 === 0 ? "#616161" : "#1F1F1F"
                        }
                        contentItem: Label{
                            text: _tableDelegateItem.text
                            font: _tableDelegateItem.font
                            horizontalAlignment: "AlignHCenter"
                        }
                    }
                }
            }
        }
    }
}
