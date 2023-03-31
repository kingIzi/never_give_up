import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../../components/customs"
import "../../../scripts/utilities.js" as Utils


Popup {
    id: _addAuthorForm
    width: parent.width - 40
    height: parent.height - 40
    anchors.centerIn: parent
    Material.background: Constants.colors.gray200
    contentItem: ScrollView{
        contentWidth: availableWidth
        contentHeight: _col3L.implicitHeight
        Item{
            id: _addAuthorFormItem
            anchors.fill: parent
            ColumnLayout{
                id: _col3L
                anchors.fill: parent
                spacing: 20
                Label{
                    id: _tableTitleLabel
                    text: "Ajouter un utilisateur"
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
                    _title: "Prenom, Postnom"
                    _textField.placeholderText: "Choississez un titre"
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                }
                FormTextField{
                    _title: "Nom"
                    _textField.placeholderText: "Choississez un titre"
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                }
                FormTextField{
                    _title: "Addresse email"
                    _textField.placeholderText: "Choississez un titre"
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                }
                FormTextField{
                    _title: "Telephone"
                    _textField.placeholderText: "Choississez un titre"
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                }
                FormTextField{
                    _title: "Addresse residentielle"
                    _textField.placeholderText: "Choississez un titre"
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                }
                FormDatePicker{
                    _title: "Date de naissance"
                    Layout.fillWidth: true
                    _textField.text: "Choississez une date"
                    Layout.preferredHeight: implicitHeight
                }
                FormFileSelector{
                    _title: "Photo profil"
                    Layout.fillWidth: true
                    _textField.text: "la photo profil"
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
