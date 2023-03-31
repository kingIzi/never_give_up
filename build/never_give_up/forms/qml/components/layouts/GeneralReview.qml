import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
//import Qt5Compat.GraphicalEffects
import Constants 1.0
import "../../../scripts/utilities.js" as Utils

Item{
    id: _generalReview
    Image {
        id: _detailsFrameImg
        source: Constants.images.detailsFrame
        fillMode: Image.PreserveAspectCrop
        anchors.fill: parent
    }
    ColumnLayout{
        id: _generalReviewCol
        anchors.fill: parent
        anchors.margins: 10
        Label{
            text: "Examen général"
            font: Constants.blackFont.h4
            Material.foreground: Constants.colors.white
        }
        Repeater{
            model: Utils.getDashboardGeneralReview()
            delegate: Item{
                id: _item1
                Layout.fillWidth: true
                Layout.fillHeight: true
                readonly property string _label: modelData.label
                readonly property real _percent: modelData.percent
                readonly property int _total: modelData.total
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
                    Button{
                        id: _stats
                        Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                        padding: 10
                        font: Constants.lightFont.h3
                        Material.foreground: _item1._percent < 0 ? Constants.colors.danger : Constants.colors.success
                        Material.background: "transparent"
                        text: _item1._percent < 0 ? _item1._percent.toString().substring(1) + "%" : _item1._percent + "%"
                        icon.source: _item1._percent < 0 ? Constants.icons.arrowDown : Constants.icons.arrowUp
                        icon.color: _item1._percent < 0 ? Constants.colors.danger : Constants.colors.success
                    }
                }
            }
        }
    }
}


