import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../../../scripts/utilities.js" as Utils

Pane {
    id: _navBar
    width: _root.width
    height: 80
    Material.background: Constants.colors.primary
    Material.elevation: 4
    readonly property var _navItems: Utils.getNavItems(Constants.images)
    readonly property int currentIndex: _navItemsListView.currentIndex
    Drawer{
        id: _navDrawer
        width: _root.width * 0.66
        height: parent.height
        Material.background: Constants.colors.black
        contentItem: Item{
            id: _navDrawerItem
            ListView{
                id: _navItemsListView
                anchors.fill: parent
                anchors.topMargin: 60
                model: _navBar._navItems
                delegate: Pane{
                    id: _navItemItem
                    width: _navItemsListView.width
                    height: 50
                    Material.background: _navItemsListView.currentIndex == index ? "#1B1B1B" : "transparent"
                    MouseArea{
                        anchors.fill: parent
                        cursorShape: "PointingHandCursor"
                        onClicked: {
                            _navItemsListView.currentIndex = index
                            _navDrawer.close()
                        }
                    }
                    RowLayout{
                        id: _navItemRow
                        anchors.fill: parent
                        spacing: 4
                        Item{
                            id: _navItemIconItem
                            Layout.preferredWidth: 30
                            Layout.preferredHeight: 30
                            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                            Image{
                                anchors.fill: parent
                                source: modelData.icon
                                fillMode: Image.PreserveAspectFit
                            }
                        }
                        Label{
                            id: _navItemLabel
                            font: Constants.blackFont.h3
                            text: modelData.label
                            Material.foreground: _navItemsListView.currentIndex == index ? Constants.colors.link : Constants.colors.white
                            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                            Layout.fillWidth: true
                        }
                    }
                }
            }
        }
    }
    RowLayout{
        id: _navBarRow
        anchors.fill: parent
        Label{
            id: _navBarTitle
            text: _navBar._navItems[_navBar.currentIndex].label
            Material.foreground: Constants.colors.white
            font: Constants.blackFont.h2
            padding: 20
            Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
        }
        Button{
            id: _menuBtn
            Layout.alignment: Qt.AlignRight| Qt.AlignVCenter
            icon.source: Constants.icons.list
            icon.color: Constants.colors.white
            padding: 20
            font: Constants.blackFont.h1
            Material.background: "transparent"
            onClicked: _navDrawer.open()
        }
    }
}
