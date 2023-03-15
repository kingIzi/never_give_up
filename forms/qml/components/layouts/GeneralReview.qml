import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
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

        }
    }
}


