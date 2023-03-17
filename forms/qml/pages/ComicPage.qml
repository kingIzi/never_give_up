import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
//import QtWebEngine
import AdminTableModel 1.0
import "../components/layouts"
import "../components/customs"
import "../pages/forms"
import "../../scripts/utilities.js" as Utils

ScrollView{
    id: _comicScroll
    contentWidth: availableWidth
    contentHeight: _comicContentItem.implicitHeight
    AddComicForm{ id: _addComicsForm }
    UpdateComicForm{ id: _updateComicForm }
    PromptUserForm{ id: _promptUserForm }
    Component{
        id: _comicItemDelegateHighlighted
        Rectangle{
            id: _comicItem
            width: _comicListView.width
            height: 150
            gradient: Gradient {
                GradientStop { position: 0.0; color: Constants.colors.black }
                GradientStop { position: 0.33; color: Constants.colors.sunset }
                GradientStop { position: 1.0; color: Constants.colors.black }
            }

            MouseArea{
                anchors.fill: parent
                cursorShape: "PointingHandCursor"
            }
            HoverHandler{
                id: _comicItemHoverHandler
                enabled: true
            }
            ColumnLayout{
                id: _col
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                spacing: 10
                Flow{
                    id: _titleFlow
                    Layout.fillWidth: true
                    spacing: 2
                    Label{
                        text: "Titre:"
                        font: Constants.blackFont.h5
                        padding: 10
                        Material.foreground: Constants.colors.white
                    }
                    Label{
                        id: _comicTitleLabel
                        text: "Kosambisamam ya Kimpa Vita"
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
                        text: "Author:"
                        font: Constants.blackFont.h5
                        padding: 10
                        Material.foreground: Constants.colors.white
                    }
                    Label{
                        id: _comicAuthorLabel
                        text: "Malory Blackman"
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
                        text: "Released:"
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
    }
    Component{
        id: _comicItemDelegate
        Item{
            id: _comicItem
            width: _comicListView.width
            height: 150
            opacity: _comicItemHoverHandler.hovered ? 0.8 : 1
            Image{
                id: _img
                anchors.fill: parent
                source: Constants.images.detailsFrame
                fillMode: Image.PreserveAspectCrop
            }
            MouseArea{
                anchors.fill: parent
                cursorShape: "PointingHandCursor"
                onClicked: _comicListView.currentIndex = index
            }
            HoverHandler{
                id: _comicItemHoverHandler
                enabled: true
            }
            ColumnLayout{
                id: _col
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                spacing: 10
                Flow{
                    id: _titleFlow
                    Layout.fillWidth: true
                    spacing: 2
                    Label{
                        text: "Titre:"
                        font: Constants.blackFont.h5
                        padding: 10
                        Material.foreground: Constants.colors.white
                    }
                    Label{
                        id: _comicTitleLabel
                        text: "Kosambisamam ya Kimpa Vita"
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
                        text: "Author:"
                        font: Constants.blackFont.h5
                        padding: 10
                        Material.foreground: Constants.colors.white
                    }
                    Label{
                        id: _comicAuthorLabel
                        text: "Malory Blackman"
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
                        text: "Released:"
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
    }

    Item{
        id: _comicContentItem
        width: _comicScroll.contentWidth
        implicitHeight: _comicCol.implicitHeight
        anchors.fill: parent
        ColumnLayout {
            id: _comicCol
            anchors.fill: parent
            spacing: 20
            ComicNavHeader{
                id: _comicNavHeader
                Layout.fillWidth: true
                Layout.preferredHeight: implicitHeight
                onOpenAddComicForm: _addComicsForm.open()
                onOpenUpdateComicForm: _updateComicForm.open()
                onOpenDeleteComicForm: {
                    _promptUserForm._promptText = "Vous etes sur de supprimer ce comic?"
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
                        Layout.preferredHeight: _comicGrid.implicitHeight
                        GridLayout{
                            id: _comicGrid
                            anchors.fill: parent
                            columns: _root.width < 640 ? 1 : 3
                            ListView{
                                id: _comicListView
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
                                }
                                model: [1,2,3,4,5,6,7,8,9]
                                delegate: _comicItemDelegate
                                highlight: _comicItemDelegateHighlighted
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
                                sourceComponent: Rectangle{
                                    id: _viewer
                                    visible: _root.width > 640
//                                    WebEngineView{
//                                        id: _pdfWebEngine
//                                        anchors.fill: parent
//                                        url: "https://www.qt.io"
//                                        Component.onCompleted: {
//                                            //_pdfWebEngine.settings.pluginsEnabled = true
//                                            //_pdfWebEngine.settings.pdfViewerEnabled = true
//                                        }
//                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
