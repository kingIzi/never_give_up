import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0

Button {
    id: _btn
    padding: 10
    Material.background: Constants.colors.primary
    font: Constants.blackFont.h3
    Material.foreground: Constants.colors.white
    signal buttonClicked()
    MouseArea{
        anchors.fill: parent
        cursorShape: "PointingHandCursor"
        onClicked: buttonClicked()
    }
}
