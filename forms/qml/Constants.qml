pragma Singleton
import QtQuick
import QtQuick.Controls.Material 2.15
import QtQuick.Window


QtObject {
    readonly property int width: 411
    readonly property int height: 823

    readonly property FontLoader montserratBold: FontLoader { source: "qrc:/never_give_up/forms/fonts/static/Montserrat-Bold.ttf" }
    readonly property FontLoader montserratLight: FontLoader { source: "qrc:/never_give_up/forms/fonts/static/Montserrat-Light.ttf" }


    readonly property DirectoryFontLoader directoryFontLoader: DirectoryFontLoader {
        id: directoryFontLoader
    }

    readonly property QtObject colors: QtObject{
        readonly property color white: "#ffffee"
        readonly property color danger: "#df4759"
        readonly property color link: "#5bc0de"
        readonly property color primary: "#15242D"
    }

    readonly property QtObject blackFont: QtObject{
        readonly property font h1: Qt.font({
                                               family: montserratBold.name,
                                               pixelSize: 32,
                                               letterSpacing: 2,
                                               bold: true
                                           })
        readonly property font h2: Qt.font({
                                               family: montserratBold.name,
                                               pixelSize: 24,
                                               letterSpacing: 2,
                                               bold: true
                                           })
        readonly property font h3: Qt.font({
                                               family: montserratBold.name,
                                               pixelSize: 18.72,
                                               letterSpacing: 2,
                                               bold: true
                                           })
        readonly property font h4: Qt.font({
                                               family: montserratBold.name,
                                               pixelSize: 16,
                                               letterSpacing: 2,
                                               bold: true
                                           })
        readonly property font h5: Qt.font({
                                               family: montserratBold.name,
                                               pixelSize: 13.28,
                                               letterSpacing: 2,
                                               bold: true
                                           })
        readonly property font h6: Qt.font({
                                               family: montserratBold.name,
                                               pixelSize: 10.72,
                                               letterSpacing: 2,
                                               bold: true
                                           })
    }

    readonly property QtObject lightFont: QtObject{
        readonly property font h1: Qt.font({
                                               family: montserratLight.name,
                                               pixelSize: 32,
                                               letterSpacing: 2,
                                               bold: false
                                           })
        readonly property font h2: Qt.font({
                                               family: montserratLight.name,
                                               pixelSize: 24,
                                               letterSpacing: 2,
                                               bold: false
                                           })
        readonly property font h3: Qt.font({
                                               family: montserratLight.name,
                                               pixelSize: 18.72,
                                               letterSpacing: 2,
                                               bold: false
                                           })
        readonly property font h4: Qt.font({
                                               family: montserratLight.name,
                                               pixelSize: 16,
                                               letterSpacing: 2,
                                               bold: false
                                           })
        readonly property font h5: Qt.font({
                                               family: montserratLight.name,
                                               pixelSize: 13.28,
                                               letterSpacing: 2,
                                               bold: false
                                           })
        readonly property font h6: Qt.font({
                                               family: montserratLight.name,
                                               pixelSize: 10.72,
                                               letterSpacing: 2,
                                               bold: false
                                           })
    }

    readonly property QtObject images: QtObject{
        readonly property url loginBg: "qrc:/never_give_up/forms/images/login-bg.png"
    }
}
