import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import Constants 1.0

Popup {
    id: _promptUserForm
    width: parent.width / 2
    height: 300
    anchors.centerIn: parent
    Material.background: Constants.colors.gray200
    property string _promptText: ""
    contentItem: Item{
        anchors.fill: parent
        ColumnLayout{
            id: _col11L
            anchors.fill: parent
            Label{
                id: _promptTextLabel
                font: Constants.blackFont.h3
                Layout.fillWidth: true
                wrapMode: "WordWrap"
                Material.foreground: Constants.colors.white
                horizontalAlignment: "AlignHCenter"
                Layout.alignment: Qt.AlignHCenter
                text: _promptUserForm._promptText
            }
            Item{
                Layout.fillWidth: true
                Layout.preferredHeight: _row8L.implicitHeight
                RowLayout{
                    id: _row8L
                    anchors.fill: parent
                    Button{
                        font: Constants.blackFont.h4
                        text: "NO"
                        Material.foreground: Constants.colors.white
                        Layout.fillWidth: true
                        background: Rectangle{
                            color: "transparent"
                            border.width: 2
                            border.color: Constants.colors.danger
                        }
                    }
                    Button{
                        Layout.fillWidth: true
                        font: Constants.blackFont.h4
                        text: "YES"
                        Material.background: Constants.colors.success
                        Material.foreground: Constants.colors.white
                    }
                }
            }
        }
    }
}
