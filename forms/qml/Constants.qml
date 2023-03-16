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
        readonly property color gray: "#A4A4A4"
        readonly property color black: "#141414"
        readonly property color success: "#399E29"
        readonly property color sunset: "#D5AC2A"
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
        readonly property url dashboard: "qrc:/never_give_up/forms/images/dashboard.png"
        readonly property url comicMan: "qrc:/never_give_up/forms/images/comics-man.png"
        readonly property url hut: "qrc:/never_give_up/forms/images/hut.png"
        readonly property url admin: "qrc:/never_give_up/forms/images/admins.png"
        readonly property url detailsFrame: "qrc:/never_give_up/forms/images/details-frame.png"
        readonly property url maloryBlackman: "qrc:/never_give_up/forms/images/malory-blackman.png"
        readonly property url searchBar: "qrc:/never_give_up/forms/images/search-bar.png"
        readonly property url nzinga: "qrc:/never_give_up/forms/images/nzinga.png"
    }

    readonly property QtObject icons: QtObject{
        readonly property url list: "qrc:/never_give_up/forms/icons/list.svg"
        readonly property url arrowUp: "qrc:/never_give_up/forms/icons/arrow-up.svg"
        readonly property url arrowDown: "qrc:/never_give_up/forms/icons/arrow-down.svg"
        readonly property url plus: "qrc:/never_give_up/forms/icons/plus.svg"
        readonly property url pen: "qrc:/never_give_up/forms/icons/pen.svg"
        readonly property url dash: "qrc:/never_give_up/forms/icons/dash.svg"
        readonly property url columnsGap: "qrc:/never_give_up/forms/icons/columns-gap.svg"
        readonly property url bookshelf: "qrc:/never_give_up/forms/icons/bookshelf.svg"
        readonly property url funnel: "qrc:/never_give_up/forms/icons/funnel.svg"
    }
}
