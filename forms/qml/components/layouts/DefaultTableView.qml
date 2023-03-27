import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import AdminTableModel 1.0
import "../customs"

Item{
    id: _tableItem
    Layout.fillWidth: true
    Layout.maximumWidth: _root.width < 640 ? parent.width : parent.width / 2
    implicitHeight: _col5L.implicitHeight
    readonly property alias _titleLabel: _tableTitleLabel
    readonly property alias _tableViewModel: _tableModel
    Component{
        id: _tableDel
        Loader{
            id: _tableDelegateItem
            readonly property font font: Constants.blackFont.h6
            readonly property string text: model.display
            required property bool selected
            required property bool current
            width: 250
            height: 50
            Component{
                id: _labelComponent
                ItemDelegate{
                    id: _del2
                    font: Constants.blackFont.h6
                    text: model.display
                    implicitWidth: width
                    implicitHeight: height
                    width: _tableDelegateItem.width
                    height: _tableDelegateItem.height
                    Binding{
                        target: _del2.background
                        property: "color"
                        value: model.row % 2 === 0 ? "#616161" : "#1F1F1F"
                    }
                    contentItem: Label{
                        text: _del2.text
                        font: _del2.font
                        Material.foreground: Constants.colors.white
                    }
                    onDoubleClicked: {
                        _itemSelectionModel.select(_tableModel.index(model.row,model.column), ItemSelectionModel.Select | ItemSelectionModel.Current)
                    }
                }
            }
            Component{
                id: _textFieldComponent
                ItemDelegate{
                    id: _del1
                    font: Constants.blackFont.h6
                    text: model.display
                    implicitWidth: width
                    implicitHeight: height
                    width: _tableDelegateItem.width
                    height: _tableDelegateItem.height
                    Component.onCompleted: {
                        _dashboardTableView.selection
                    }
                    Binding{
                        target: _del1.background
                        property: "color"
                        value: model.row % 2 === 0 ? "#616161" : "#1F1F1F"
                    }
                    contentItem: TextField{
                        id: _editText
                        onAccepted: {
                            if (_editText.text.length === 0)
                                _itemSelectionModel.clearSelection();
                            else
                                _tableModel.setItemAt(_tableModel.index(model.row,model.column),_editText.text)
                        }
                        focus: true
                        text: _del1.text
                        font: _del1.font
                        Material.foreground: Constants.colors.white
                    }
                }
            }
            sourceComponent: _tableDelegateItem.selected ? _textFieldComponent : _labelComponent
        }
    }
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
                    font: Constants.blackFont.h3
                    Material.foreground: Constants.colors.white
                }
                SearchField{
                    id: _searchBar
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
                    model: _tableModel.headers
                    syncView: _dashboardTableView
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
                        contentItem: Label{
                            text: _tableHeader.text
                            font: _tableHeader.font
                            horizontalAlignment: "AlignHCenter"
                            Material.foreground: Constants.colors.white
                        }
                    }
                }
                TableView{
                    id: _dashboardTableView
                    Layout.fillWidth: true
                    Layout.preferredHeight: contentHeight
                    Layout.maximumHeight: 500
                    columnSpacing: 1
                    rowSpacing: 1
                    clip: true
                    interactive: true
                    alternatingRows: true
                    Connections{
                        target: _tableModel
                        function onItemChanged(item){
                            _admin.requestUpdateUser(item)
                        }
                    }

                    model: AdminTableModel{
                        id: _tableModel
                        headers: ["Full Name","Email","Phone Number","Role","Since"]
                    }
                    selectionModel: ItemSelectionModel{
                        id: _itemSelectionModel
                        model: _tableModel
                    }
                    delegate: _tableDel
                }
            }
        }
    }
}
