import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0

Item{
    id: _customTextFieldItem
    width: 300
    implicitHeight: _customTextFieldCol.implicitHeight
    readonly property alias _textLabel: _customTextFieldLabel
    readonly property alias _textField: _customTextField
    readonly property alias _textLabelError: _customTextFieldErrorLabel
    ColumnLayout{
        id: _customTextFieldCol
        anchors.fill: parent
        anchors.margins: 10
        Label{
            id: _customTextFieldLabel
            font: Constants.blackFont.h3
            color: Constants.colors.white
            visible: text.length > 0
            padding: 4
        }
        TextField{
            id: _customTextField
            Layout.fillWidth: true
            padding: 4
            font: Constants.lightFont.h4
            placeholderText: "Enter placeholder"
            Material.accent: Constants.colors.white
            color: Constants.colors.white
            maximumLength: 255
        }
        Label{
            id: _customTextFieldErrorLabel
            font: Constants.lightFont.h4
            color: Constants.colors.danger
            visible: text.length > 0
            padding: 4
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            wrapMode: "WordWrap"
            maximumLineCount: 2
            horizontalAlignment: "AlignHCenter"
        }
    }
}
