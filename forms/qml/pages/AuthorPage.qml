import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../components/layouts"
import "../components/customs"
import "../pages/forms"
import "../../scripts/utilities.js" as Utils


ScrollView{
    id: _authorPageScroll
    contentWidth: availableWidth
    contentHeight: _authorCol.implicitHeight
    AddAuthorForm{ id: _addComicsForm }
    UpdateComicForm{ id: _updateComicForm }
    PromptUserForm{ id: _promptUserForm }
    ColumnLayout{
        id: _authorCol
        anchors.fill: parent
        spacing: 20
        AuthorNavHeader{
            id: _authorNavHeader
            Layout.fillWidth: true
            Layout.preferredHeight: implicitHeight
            onOpenAddComicForm: _addComicsForm.open()
            onOpenUpdateComicForm: _updateComicForm.open()
            onOpenDeleteComicForm: {
                _promptUserForm._promptText = "Vous etes sur de supprimer cette utilisateur?"
                _promptUserForm.open()
            }
        }
        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: _col9L.implicitHeight
            ColumnLayout{
                id: _col9L
                anchors.fill: parent
                Item{
                    Layout.fillWidth: true
                    Layout.preferredHeight: _authorGrid.implicitHeight
                    GridLayout{
                        id: _authorGrid
                        anchors.fill: parent
                        columns: _root.width < 640 ? 1 : 3
                        ListView{
                            id: _authorListView
                            Layout.column: _root.width < 640 ? 0 : 1
                            Layout.fillWidth: _root.width < 640 ? true : false
                            Layout.preferredWidth: 400
                            Layout.preferredHeight: contentHeight
                            currentIndex: -1
                            spacing: 20
                            header: Label{
                                id: _resultsLabel
                                text: "Resultat(s)"
                                font: Constants.blackFont.h5
                                Material.foreground: Constants.colors.white
                                horizontalAlignment: "AlignRight"
                                padding: 10
                            }
                            model: [1,2,3,4,5,6]
                            delegate: Rectangle{
                                color: Constants.colors.gray500
                                width: _authorListView.width
                                height: _col11L.implicitHeight
                                ColumnLayout{
                                    id: _col11L
                                    anchors.fill: parent
                                    Rectangle{
                                        Layout.preferredWidth: 60
                                        Layout.preferredHeight: 60
                                        radius: 30
                                        color: Constants.colors.gray
                                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                    }
                                    Flow{
                                        id: _titleFlow
                                        Layout.fillWidth: true
                                        spacing: 2
                                        Label{
                                            text: "Full name:"
                                            font: Constants.blackFont.h5
                                            padding: 10
                                            Material.foreground: Constants.colors.white
                                        }
                                        Label{
                                            id: _comicTitleLabel
                                            text: "Malory Blackman"
                                            font: Constants.lightFont.h4
                                            padding: 10
                                            Material.foreground: Constants.colors.white
                                        }
                                    }
                                    Flow{
                                        id: _authorFlow
                                        Layout.fillWidth: true
                                        spacing: 2
                                        Label{
                                            text: "Email:"
                                            font: Constants.blackFont.h5
                                            padding: 10
                                            Material.foreground: Constants.colors.white
                                        }
                                        Label{
                                            id: _comicAuthorLabel
                                            text: "mb@best.com"
                                            font: Constants.lightFont.h5
                                            padding: 10
                                            Material.foreground: Constants.colors.white
                                        }
                                    }
                                    Flow{
                                        id: _releasedFlow
                                        Layout.fillWidth: true
                                        spacing: 2
                                        Label{
                                            text: "Depuis:"
                                            font: Constants.blackFont.h5
                                            padding: 10
                                            Material.foreground: Constants.colors.white
                                        }
                                        Label{
                                            id: _comicReleasedLabel
                                            text: "2 Juillet 1706"
                                            font: Constants.lightFont.h5
                                            padding: 10
                                            Material.foreground: Constants.colors.white
                                        }
                                    }
                                }
                            }

                            highlightFollowsCurrentItem: true
                        }
                        Loader{
                            id: _pdfLoader
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Layout.columnSpan: 1
                            Layout.column: 0
                            visible: _root.width > 640
                            active: visible
                            sourceComponent: Item{
                                id: _viewer
                                visible: _root.width > 640
                                Image{
                                    id: _bg
                                    source: Constants.images.detailsFrame
                                    anchors.fill: _viewer
                                    fillMode: Image.PreserveAspectCrop
                                }
                                ColumnLayout{
                                    id: _col13L
                                    anchors.fill: _bg
                                    spacing: 10
                                    Item{
                                        Layout.fillWidth: true
                                        Layout.preferredHeight: _row14L.implicitHeight
                                        Layout.alignment: Qt.AlignTop
                                        RowLayout{
                                            id: _row14L
                                            anchors.fill: parent
                                            Item{
                                                id: _authorImg
                                                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                                                Layout.preferredWidth: 150
                                                Layout.preferredHeight: 120
                                                Image{
                                                    id: _profile
                                                    source: Constants.images.maloryBlackman
                                                    sourceSize.width: _authorImg.Layout. preferredWidth
                                                    sourceSize.height: _authorImg.Layout.preferredHeight
                                                    fillMode: Image.PreserveAspectFit
                                                }
                                            }
                                            Item{
                                                id: _item12
                                                Layout.fillWidth: true
                                                Layout.preferredHeight: _col12L.implicitHeight
                                                Layout.leftMargin: 20
                                                ColumnLayout{
                                                    id: _col12L
                                                    Flow{
                                                        Layout.fillWidth: true
                                                        spacing: 2
                                                        Label{
                                                            text: "Full name:"
                                                            font: Constants.blackFont.h5
                                                            padding: 10
                                                            Material.foreground: Constants.colors.white
                                                        }
                                                        Label{
                                                            text: "Malory Blackman"
                                                            font: Constants.lightFont.h4
                                                            padding: 10
                                                            Material.foreground: Constants.colors.white
                                                        }
                                                    }
                                                    Flow{
                                                        Layout.fillWidth: true
                                                        spacing: 2
                                                        Label{
                                                            text: "Email:"
                                                            font: Constants.blackFont.h5
                                                            padding: 10
                                                            Material.foreground: Constants.colors.white
                                                        }
                                                        Label{
                                                            text: "mb@best.com"
                                                            font: Constants.lightFont.h5
                                                            padding: 10
                                                            Material.foreground: Constants.colors.white
                                                        }
                                                    }
                                                    Flow{
                                                        Layout.fillWidth: true
                                                        spacing: 2
                                                        Label{
                                                            text: "Depuis:"
                                                            font: Constants.blackFont.h5
                                                            padding: 10
                                                            Material.foreground: Constants.colors.white
                                                        }
                                                        Label{
                                                            text: "2 Juillet 1706"
                                                            font: Constants.lightFont.h5
                                                            padding: 10
                                                            Material.foreground: Constants.colors.white
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    Rectangle{
                                        Layout.fillWidth: true
                                        Layout.fillHeight: true
                                        color: "transparent"
                                        border.color: "red"
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
