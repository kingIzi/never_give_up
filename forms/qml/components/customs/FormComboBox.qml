import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0

Item{
    id: _formField
    implicitHeight: _col4L.implicitHeight
    property string _title: ""
    readonly property alias _combobox: _formComboBox
    readonly property alias _textFieldError: _textFieldFormError
    property var _model: []
    signal valueChanged(string value)
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
        ComboBox{
            id: _formComboBox
            Layout.fillWidth: true
            model: _formField._model
            onCurrentValueChanged: {
                valueChanged(currentValue)
            }
            leftPadding: 30
            background: Rectangle{
                color: Constants.colors.gray500
            }
            Material.foreground: Constants.colors.white
            font: Constants.lightFont.h4
            rightPadding: 20
            topPadding: 20
            bottomPadding: 20
            Button{
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                icon.source: Constants.icons.dash
                icon.color: Constants.colors.white
                icon.width: 20
                icon.height: 20
                Material.background: "transparent"
            }
            popup: Popup {
                y: _formComboBox.height - 1
                width: _formComboBox.width
                implicitHeight: contentItem.implicitHeight
                padding: 1
                Material.background: Constants.colors.gray200
                contentItem: ListView {
                    clip: true
                    implicitHeight: contentHeight
                    model: _formComboBox.popup.visible ? _formComboBox.delegateModel : null
                    currentIndex: _formComboBox.highlightedIndex
                    ScrollIndicator.vertical: ScrollIndicator { }
                }
            }
            delegate: ItemDelegate {
                width: _formComboBox.width
                text: modelData
                Material.foreground: Constants.colors.white
                highlighted: _formComboBox.highlightedIndex === index
            }
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


