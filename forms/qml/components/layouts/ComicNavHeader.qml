import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../customs"
import "../../../scripts/utilities.js" as Utils
import "../../../scripts/requests.js" as Req



//Pane{
//    id: _comicPaneHeader
//    implicitHeight: _col6L.implicitHeight
//    Material.background: Constants.colors.black
//    padding: 10
//    signal openAddComicForm()
//    signal openUpdateComicForm()
//    signal openDeleteComicForm()
//    ColumnLayout{
//        id: _col6L
//        anchors.fill: parent
//        Label{
//            id: _tableTitleLabel
//            text: "In Stock"
//            font: Constants.blackFont.h2
//            Material.foreground: Constants.colors.white
//            Layout.alignment: Qt.AlignVCenter
//            Layout.fillWidth: true
//        }
//        ToolBar {
//            Layout.fillWidth: true
//            Layout.preferredHeight: _row18L.implicitHeight
//            RowLayout {
//                id: _row18L
//                anchors.fill: parent
//                ToolButton {
//                    text: qsTr("‹")
//                    onClicked: stack.pop()
//                }
//                Label {
//                    text: "Title"
//                    elide: Label.ElideRight
//                    horizontalAlignment: Qt.AlignHCenter
//                    verticalAlignment: Qt.AlignVCenter
//                    Layout.fillWidth: true
//                }
//                ToolButton {
//                    text: qsTr("⋮")
//                    onClicked: menu.open()
//                }
//            }
//        }
//    }
//}




Pane{
    id: _comicPaneHeader
    implicitHeight: _col6L.implicitHeight
    Material.background: Constants.colors.black
    padding: 10
    signal openAddComicForm()
    signal openUpdateComicForm()
    signal openDeleteComicForm()
    ColumnLayout{
        id: _col6L
        anchors.fill: parent
        spacing: 10
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
                            HoverHandler{
                                enabled: true
                                cursorShape: "PointingHandCursor"
                            }
                            onClicked: {
                                openAddComicForm()
                                _agent.requestCategoriesList(Req.availableCategories())
                                _agent.requestAuthorList()
                            }
                        }
                        ToolButton {
                            icon.source: Constants.icons.pen
                            icon.color: enabled ? Constants.colors.sunset : Constants.colors.gray
                            enabled: _comicListView.currentIndex >= 0
                            HoverHandler{
                                enabled: true
                                cursorShape: "PointingHandCursor"
                            }
                            onClicked: openUpdateComicForm()
                        }
                        ToolButton {
                            icon.source: Constants.icons.dash
                            icon.color: enabled ? Constants.colors.danger : Constants.colors.gray
                            enabled: _comicListView.currentIndex >= 0
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
                    model: Utils.getComicFilters(Constants.icons)
                    delegate: ComboBox{
                        id: _categoriesComboBox
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
                                 y: _categoriesComboBox.height - 1
                                 width: _categoriesComboBox.width
                                 implicitHeight: contentItem.implicitHeight
                                 padding: 1
                                 Material.background: "#1B1B1B"
                                 contentItem: ListView {
                                     clip: true
                                     implicitHeight: contentHeight
                                     model: _categoriesComboBox.popup.visible ? _categoriesComboBox.delegateModel : null
                                     currentIndex: _categoriesComboBox.highlightedIndex
                                     ScrollIndicator.vertical: ScrollIndicator { }
                                 }
                             }
                        delegate: ItemDelegate {
                            width: _categoriesComboBox.width
                            contentItem: Label {
                                text: _categoriesComboBox.textRole
                                      ? (Array.isArray(control.model) ? modelData[_categoriesComboBox.textRole] : model[_categoriesComboBox.textRole])
                                      : modelData
                                color: Constants.colors.white
                                font: _categoriesComboBox.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: _categoriesComboBox.highlightedIndex === index
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
            placeholderText: "Rechercher une BD par titre"
        }
    }
}
