import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import AdminTableModel 1.0

Item{
    id: _tableItem
    Layout.fillWidth: true
    Layout.maximumWidth: _root.width < 640 ? parent.width : parent.width / 2
    implicitHeight: _col5L.implicitHeight
    ColumnLayout{
        id: _col5L
        anchors.fill: parent
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _row6L.implicitHeight
            Layout.bottomMargin: 10
            Layout.topMargin: 10
            RowLayout{
                id: _row6L
                anchors.fill: parent
                Label{
                    id: _tableTitleLabel
                    text: "Admin(s)"
                    font: Constants.blackFont.h3
                    Material.foreground: Constants.colors.white
                }
                TextField{
                    id: _searchBar
                    Layout.fillWidth: true
                    font: Constants.lightFont.h3
                    Material.foreground: Constants.colors.white
                    placeholderText: "Rechercher"
                    placeholderTextColor: Constants.colors.gray
                    maximumLength: 255
                    leftPadding: 10
                    rightPadding: 10
                    background: Rectangle{
                        color: Constants.colors.black
                        radius: 30
                    }
                }
            }
        }
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _col6L.implicitHeight
            ColumnLayout{
                id: _col6L
                anchors.fill: parent
                HorizontalHeaderView{
                    model: ["#","First name", "Last name", "Telephone", "Date of Birth"]
                    syncView: _dashboardTableView
                    Layout.fillWidth: true
                    delegate: ItemDelegate{
                        id: _tableHeader
                        font: Constants.blackFont.h6
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
                    id: _dashboardTableView
                    Layout.fillWidth: true
                    Layout.preferredHeight: _adminTableModel.rowCount() * 50//height
                    Layout.maximumHeight: 500
                    columnSpacing: 1
                    rowSpacing: 1
                    clip: true
                    interactive: true
                    alternatingRows: true
                    model: AdminTableModel{
                        id: _adminTableModel
                    }
                    delegate: ItemDelegate{
                        id: _tableDelegateItem
                        font: Constants.blackFont.h6
                        text: display
                        implicitWidth: _tableItem.width / _adminTableModel.columnCount()
                        implicitHeight: 50
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
