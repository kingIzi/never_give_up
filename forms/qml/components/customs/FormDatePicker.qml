import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0

Item{
    id: _formDatePicker
    implicitHeight: _col4L.implicitHeight
    property string _title: ""
    readonly property alias _textField: _textFieldForm
    readonly property alias _textFieldError: _textFieldFormError
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
                icon.source: Constants.icons.calendar
                icon.color: Constants.colors.white
                Material.background: "transparent"
                onClicked: _datePicker.visible = true
            }
            Loader{
                id: _datePicker
                visible: false
                active: visible
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width
                height: 400
                sourceComponent: Item{
                    GridView {
                            anchors.fill: parent
                            model: 2000
                            cellWidth: page.width
                            cellHeight: page.height
                            flow: GridView.FlowTopToBottom
                            snapMode: GridView.SnapOneRow
                            delegate: Item {
                                width: page.width
                                height: page.height
                                ColumnLayout {
                                    Text {
                                        text: Qt.formatDateTime(grid.year + "-" + (grid.month + 1).toString().padStart(2, "0") + "-01", "MMMM yyyy")
                                    }
                                    DayOfWeekRow {
                                        Layout.fillWidth: true
                                        locale: grid.locale
                                    }
                                    MonthGrid {
                                        id: grid
                                        Layout.fillWidth: true
                                        month: index % 12
                                        year: 2021 + Math.floor(index / 12)
                                        locale: Qt.locale("en_US")
                                        delegate: Text {
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            opacity: model.month === grid.month ? 1 : 0.2
                                            text: model.day
                                            font: grid.font
                                            required property var model
                                            Rectangle {
                                                anchors.fill: parent
                                                anchors.margins: -5
                                                z: -2
                                                radius: 5
                                                border.color: "red"
                                                border.width: 3
                                                color: "transparent"
                                                visible: currentTime === model.date.getTime()
                                            }
                                            MouseArea {
                                                anchors.fill: parent
                                                onClicked: currentTime = model.date.getTime()
                                            }
                                        }
                                    }
                                }
                            }
                        }
                }
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
