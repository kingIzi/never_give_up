import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../../components/customs"

ColumnLayout{
    id: _loginForm
    anchors.margins: 10
    anchors.fill: parent
    spacing: 10
    Component{
        id: _registerForm
        RegisterForm{}
    }
    Label{
        id: _loginLabel
        text: "Bienvenu"
        font: Constants.blackFont.h1
        color: Constants.colors.white
        leftPadding: 4
        bottomPadding: 20
    }
    CustomTextField{
        Layout.fillWidth: true
        _textLabel.text: "Addresse Email"
        _textField.placeholderText: "Votre Email"
        _textField.validator: RegularExpressionValidator { regularExpression: /\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*/ }
    }
    CustomTextField{
        Layout.fillWidth: true
        _textLabel.text: "Mot de passe"
        _textField.placeholderText: "Votre mot de passe"
        _textField.echoMode: TextField.Password
    }
    Item{
        Layout.fillWidth: true
        Layout.preferredHeight: _loginActionsRow.implicitHeight
        RowLayout{
            id: _loginActionsRow
            anchors.fill: parent
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            CheckBox{
                font: Constants.blackFont.h5
                Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
                text: "Rappele toi"
                Material.accent: Constants.colors.white
                padding: 4
                Material.foreground: Constants.colors.white
            }
            LinkButton{
                Component.onCompleted: font.capitalization = Font.Capitalize
                text: "Mot de passe oublier?"
            }
        }
    }
    CustomBtn{
        text: "Connecter vous"
        Layout.alignment: Qt.AlignHCenter
        onButtonClicked: console.log("Button Clicked")
    }
    Flow{
        Layout.alignment: Qt.AlignHCenter
        spacing: 2
        Label{
            font: Constants.blackFont.h5
            color: Constants.colors.white
            text: "Pas Aboner?"
            padding: 4
            horizontalAlignment: "AlignHCenter"
        }
        Label{
            font.underline: _hover.hovered ? true : false
            font.family: Constants.blackFont.h5.family
            font.pixelSize: Constants.blackFont.h5.pixelSize
            font.letterSpacing: Constants.blackFont.h5.letterSpacing
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            HoverHandler{
                id: _hover
                enabled: true
            }
            Material.foreground: Constants.colors.link
            text: "Enregistrer maintenant"
            padding: 4
            horizontalAlignment: "AlignHCenter"
            MouseArea{
                anchors.fill: parent
                onClicked: _sessionStack.push(_registerForm)
            }
        }
    }
}
