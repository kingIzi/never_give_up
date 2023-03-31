import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../../components/customs"
import "../../../scripts/requests.js" as Req

ColumnLayout{
    id: _loginForm
    spacing: 10
    Component{
        id: _registerForm
        RegisterForm{}
    }
    Component{
        id: _resetPasswordForm
        ResetPasswordForm{}
    }
    Connections{
        target: _agent
        function onRequestErrorMsg(error){
            _emailTextField._textLabelError.text = error.message
        }
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
        id: _emailTextField
        readonly property string _email: _emailTextField._textField.text
        Layout.fillWidth: true
        _textLabel.text: "Addresse Email"
        _textField.placeholderText: "Votre Email"
        _textField.text: "admin@admin.com"
        _textField.validator: RegularExpressionValidator { regularExpression: /\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*/ }
    }
    CustomTextField{
        id: _passwordTextField
        readonly property string _password: _passwordTextField._textField.text
        Layout.fillWidth: true
        _textLabel.text: "Mot de passe"
        _textField.placeholderText: "Votre mot de passe"
        _textField.text: "admin123456"
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
                Material.accent: Constants.colors.primary
                padding: 4
                Material.foreground: Constants.colors.white
            }
            LinkButton{
                Component.onCompleted: font.capitalization = Font.Capitalize
                text: "Mot de passe oublier?"
                onClicked: _sessionStack.push(_resetPasswordForm)
            }
        }
    }
    CustomBtn{
        text: "Connecter vous"
        Layout.alignment: Qt.AlignHCenter
        onButtonClicked: {
            _emailTextField._textLabelError.text = ""
            const loginUser = Req.loginUser(_emailTextField._email,_passwordTextField._password)
            _agent.requestLogin(loginUser)
            //_admin.requestLoginUser(loginUser)
            //_appLoader.state ="navigate";
        }
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
