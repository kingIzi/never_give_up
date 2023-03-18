import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0

Item{
    id: _formField
    implicitHeight: _col4L.implicitHeight
    property string _title: ""
    readonly property alias _textArea: _textAreaForm
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
        TextArea{
            id: _textAreaForm
            font: Constants.lightFont.h4
            Layout.fillWidth: true
            Layout.preferredHeight: 200
            color: Constants.colors.white
            wrapMode: "Wrap"
            padding: 10
            HoverHandler{
                cursorShape: "IBeamCursor"
                enabled: true
            }
            placeholderText: "Optional"
            placeholderTextColor: Constants.colors.gray
            onTextChanged: if (length > 500) remove(500, length);
//            Label{
//                text: "Optional"
//                padding: 10
//                font: Constants.lightFont.h4
//                Material.foreground: Constants.colors.gray
//                visible: _textAreaForm.text.length === 0
//            }
        }
    }
}
