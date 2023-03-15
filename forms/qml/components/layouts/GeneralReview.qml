import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import Constants 1.0


Item{
    id: _item1
    Layout.fillWidth: true
    Layout.fillHeight: true
    property string _label: ""
    property int _total: 0
    property real _percent: 0.0
    RowLayout{
        id: _rowL
        anchors.fill: parent
        Label{
            id: _usesLabel
            text: _item1._total + " " + _item1._label
            font: Constants.lightFont.h3
            color: Constants.colors.white
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
            padding: 10
        }
        Item{
            Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
            Layout.preferredWidth: _row2L.implicitWidth
            Layout.preferredHeight: _row2L.implicitHeight
            RowLayout{
                id: _row2L
                anchors.fill: parent
                Item{
                    Layout.preferredWidth: 20
                    Layout.preferredHeight: 20
                    Image {
                        id: _upArrow
                        source: _item1._percent < 0 ? Constants.icons.arrowDown : Constants.icons.arrowUp
                        fillMode: Image.PreserveAspectFit
                        anchors.fill: parent
                        ColorOverlay{
                            anchors.fill: _upArrow
                            source: _upArrow
                            color: _item1._percent < 0 ? Constants.colors.danger : Constants.colors.success
                        }
                    }
                }
                Label{
                    id: _usesUpdatePercentLabel
                    text: _item1._percent < 0 ? _item1._percent.toString().substring(1) + "%" : _item1._percent + "%"
                    padding: 10
                    font: Constants.blackFont.h3
                    color: _item1._percent < 0 ? Constants.colors.danger : Constants.colors.success
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                }
            }
        }
    }
}
