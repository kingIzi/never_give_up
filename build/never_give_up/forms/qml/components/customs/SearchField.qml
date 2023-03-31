import QtQuick
import QtQuick.Controls.Material
import Constants 1.0

TextField{
    id: _searchBar
    font: Constants.lightFont.h3
    Material.foreground: Constants.colors.white
    placeholderText: "Rechercher"
    placeholderTextColor: Constants.colors.primary
    maximumLength: 255
    leftPadding: 10
    rightPadding: 10
    background: Rectangle{
        color: Constants.colors.gray
        radius: 30
    }
}
