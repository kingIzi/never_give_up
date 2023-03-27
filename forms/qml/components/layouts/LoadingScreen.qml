import QtQuick
import QtQuick.Layouts 1.0
import QtQuick.Controls.Material
import Constants 1.0

Popup {
    id: _loadingScreen
    width: _root.width
    height: _root.height
    Material.background: "transparent"
    readonly property bool isLoading: _admin.isLoading
    onIsLoadingChanged: {
        if (isLoading)
            _loadingScreen.open()
        else
            _loadingScreen.close()
    }
    contentItem: Item{
        anchors.fill: parent
        BusyIndicator{
            Material.background: Constants.colors.primary
            anchors.centerIn: parent
            running: _loadingScreen.isLoading
        }
    }
}
