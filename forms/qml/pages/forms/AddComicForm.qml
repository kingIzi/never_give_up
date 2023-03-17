import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../../components/customs"
import "../../../scripts/utilities.js" as Utils


Popup {
    id: _addComicForm
    width: parent.width - 40
    height: parent.height - 40
    anchors.centerIn: parent
    Material.background: Constants.colors.gray200
    contentItem: ScrollView{
        contentWidth: availableWidth
        contentHeight: _col3L.implicitHeight
        Item{
            id: _addComicFormItem
            anchors.fill: parent
            ColumnLayout{
                id: _col3L
                anchors.fill: parent
                spacing: 20
                Label{
                    id: _tableTitleLabel
                    text: "Ajouter une BD"
                    font: Constants.blackFont.h2
                    Material.foreground: Constants.colors.white
                    Layout.alignment: Qt.AlignHCenter
                    Layout.fillWidth: true
                    horizontalAlignment: "AlignHCenter"
                }
                ToolSeparator{
                    orientation: "Horizontal"
                    Layout.fillWidth: true
                    Material.background: Constants.colors.white
                }
                FormTextField{
                    id: _titleFormField
                    _title: "Titre"
                    _textField.placeholderText: "Choississez un titre"
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                }
                FormComboBox{
                    _model:["Romance","Tragedy","Comedy"]
                    Layout.fillWidth: true
                    _title: "Category"
                    Layout.preferredHeight: implicitHeight
                }
                FormComboBox{
                    _model:["Malory Blackman","Michael Scott","Rosemary Stuffcrif"]
                    Layout.fillWidth: true
                    _title: "Author"
                    Layout.preferredHeight: implicitHeight
                }
                FormDatePicker{
                    _title: "Date Publier"
                    Layout.fillWidth: true
                    _textField.text: "Choississez une date"
                    Layout.preferredHeight: implicitHeight
                }
                FormFileSelector{
                    _title: "Photo profil"
                    Layout.fillWidth: true
                    _textField.text: "la photo profil"
                }
                FormFileSelector{
                    _title: "Le BD"
                    Layout.fillWidth: true
                    _textField.text: "Le BD"
                }
                Item{
                    Layout.fillWidth: true
                    Layout.preferredHeight: _row8L.implicitHeight
                    RowLayout{
                        id: _row8L
                        anchors.fill: parent
                        Button{
                            font: Constants.blackFont.h4
                            text: "Preview"
                            Material.foreground: Constants.colors.white
                            Layout.fillWidth: true
                            background: Rectangle{
                                color: "transparent"
                                border.width: 2
                                border.color: Constants.colors.primary
                            }
                        }
                        Button{
                            Layout.fillWidth: true
                            font: Constants.blackFont.h4
                            text: "Ajouter"
                            Material.background: Constants.colors.primary
                            Material.foreground: Constants.colors.white
                        }
                    }
                }
            }
        }
    }
}
