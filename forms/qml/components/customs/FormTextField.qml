import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0

Item{
    id: _formField
    implicitHeight: _col4L.implicitHeight
    property string _title: ""
    readonly property alias _textField: _textFieldForm
    readonly property alias _textFieldError: _textFieldFormError
    ColumnLayout{
        id: _col4L
        anchors.fill: parent
        anchors.margins: 10
        Label{
            text: _formField._title
            font: Constants.blackFont.h5
            Material.foreground: Constants.colors.white
            Layout.alignment: Qt.AlignLeft
            Layout.fillWidth: true
        }
        TextField{
            id: _textFieldForm
            font: Constants.lightFont.h4
            Layout.fillWidth: true
            background: Rectangle{
                color: Constants.colors.gray500
            }
            Material.foreground: Constants.colors.white
            placeholderText: "Choississez un titre"
            placeholderTextColor: Constants.colors.gray
            padding: 10
        }
        Label{
            id: _textFieldFormError
            font: Constants.lightFont.h5
            Material.foreground: Constants.colors.danger
            Layout.alignment: Qt.AlignLeft
            Layout.fillWidth: true
            visible: text.length > 0
        }
    }
}
