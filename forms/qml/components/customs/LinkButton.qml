import QtQuick.Controls.Material
import QtQuick.Layouts
import QtQuick
import Constants 1.0

Button{
    id: _linkBtn
    flat: true
    text: "Mot de passe oublier?"
    Material.background: "transparent"
    Material.foreground: Constants.colors.link
    padding: 4

    font.underline: _hover.hovered ? true : false
    font.family: Constants.blackFont.h5.family
    font.pixelSize: Constants.blackFont.h5.pixelSize
    font.letterSpacing: Constants.blackFont.h5.letterSpacing
    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
    HoverHandler{
        id: _hover
        enabled: true
    }
}
