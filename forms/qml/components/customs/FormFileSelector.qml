import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Qt.labs.platform
import QtQuick.Dialogs
import Constants 1.0

Item{
    id: _formDatePicker
    implicitHeight: _col4L.implicitHeight
    property string _title: ""
    readonly property alias _textField: _textFieldForm
    readonly property alias _textFieldError: _textFieldFormError
    property url filePath
    property var nameFilters: []
    FileDialog {
        id: fileDialog
        currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        onAccepted: {
            _formDatePicker.filePath = fileDialog.currentFile
            _formDatePicker._title = _agent.selectedFileName(selectedFile.toString())
        }

        nameFilters: _formDatePicker.nameFilters
    }
    ColumnLayout{
        id: _col4L
        anchors.fill: parent
        anchors.margins: 10
        Label{
            text: _formDatePicker._title
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
            padding: 20
            Button{
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                Material.background: Constants.colors.primary
                text: "Fichier"
                font: Constants.blackFont.h4
                onClicked: fileDialog.open()
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
