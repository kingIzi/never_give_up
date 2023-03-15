import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import Qt5Compat.GraphicalEffects
import "../components/layouts"
import "../../scripts/utilities.js" as Utils

ScrollView{
    id: _dashboardScroll
    contentWidth: availableWidth
    contentHeight: _dashboardContentItem.implicitHeight
    Item{
        id: _dashboardContentItem
        width: _dashboardScroll.contentWidth
        implicitHeight: _dashboardCol.implicitHeight
        anchors.fill: parent
        ColumnLayout {
            id: _dashboardCol
            anchors.fill: parent
            Item{
                Layout.fillWidth: true
                Layout.preferredHeight: _dashboardDetailsGrid.implicitHeight
                GridLayout{
                    id: _dashboardDetailsGrid
                    anchors.fill: parent
                    columns: _root.width < 640 ? 1 : 2
                    Item{
                        id: _generalReview
                        Layout.fillWidth: true
                        Layout.preferredHeight: 200
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
                                delegate: GeneralReview{
                                    _label: modelData.label
                                    _percent: modelData.percent
                                    _total: modelData.total
                                }
                            }
                        }
                    }
                    Rectangle{
                        id: _authorReview
                        Layout.fillWidth: true
                        Layout.preferredHeight: 200
                        color: "#1B1B1B"
                        RowLayout{
                            id: _authorReviewRow
                            anchors.fill: parent
                            Item{
                                Layout.preferredWidth: 200
                                Layout.fillHeight: true
                                Image{
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    source: Constants.images.maloryBlackman
                                    fillMode: Image.PreserveAspectCrop
                                }
                            }
                            Item{
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                ColumnLayout{
                                    id: _col1L
                                    anchors.fill: parent
                                    anchors.topMargin: 10
                                    anchors.bottomMargin: 10
                                    spacing: 10
                                    Label{
                                        text: "Plus polulaire"
                                        font: Constants.lightFont.h3
                                        Material.foreground: Constants.colors.white
                                    }
                                    Label{
                                        text: "Malory Blackman"
                                        font: Constants.blackFont.h3
                                        Material.foreground: Constants.colors.white
                                    }
                                    Label{
                                        text: "8 Comic(s)"
                                        font: Constants.lightFont.h3
                                        Material.foreground: Constants.colors.white
                                    }
                                    ToolSeparator{
                                        orientation: "Horizontal"
                                        Layout.fillWidth: true
                                        contentItem: Rectangle {
                                            implicitWidth: parent.vertical ? 1 : 24
                                            implicitHeight: parent.vertical ? 24 : 1
                                            color: Constants.colors.gray
                                        }
                                    }
                                    Item{
                                        Layout.fillWidth: true
                                        Layout.fillHeight: true
                                        Timer {
                                            id: _timer
                                            interval: 3000
                                            running: true
                                            repeat: true
                                            onTriggered: {
                                                _titlesListView.incrementCurrentIndex()
                                                _titlesListView.positionViewAtIndex(_titlesListView.currentIndex,ListView.SnapPosition)

                                            }
                                        }
                                        Item{
                                            anchors.fill: parent
                                            clip: true
                                            ColumnLayout{
                                                anchors.fill: parent
                                                Label{
                                                    text: "Meilleurs choix"
                                                    font: Constants.blackFont.h4
                                                    Material.foreground: Constants.colors.white
                                                    color: Constants.colors.sunset
                                                }
                                                ListView{
                                                    id: _titlesListView
                                                    Layout.fillWidth: true
                                                    Layout.fillHeight: true
                                                    keyNavigationWraps: true
                                                    orientation: ListView.Horizontal
                                                    model: ["Kosambisama ya YAYA KIMPA VITA,","Naughts & Crosses,","The Man Who Shot Liberty Valence."]
                                                    interactive: false
                                                    spacing: 10
                                                    highlightRangeMode: ListView.StrictlyEnforceRange
                                                    snapMode: ListView.SnapOneItem
                                                    delegate: Label{
                                                        id: _authorTitles
                                                        text:modelData
                                                        //font: Constants.lightFont.h4
                                                        font.family: Constants.lightFont.h4.family
                                                        font.pixelSize: Constants.lightFont.h4.pixelSize
                                                        font.letterSpacing: Constants.lightFont.h4.letterSpacing
                                                        font.underline: _hover.hovered
                                                        Component.onCompleted: font.italic = true
                                                        Material.foreground: Constants.colors.white
                                                        color: Constants.colors.sunset
                                                        clip: true
                                                        HoverHandler{
                                                            id: _hover
                                                            enabled: true
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
