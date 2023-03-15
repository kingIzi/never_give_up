import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts
import Constants 1.0
import "../../components/customs"

ColumnLayout{
    id: _colL
    spacing: 10
    Label{
        id: _loginLabel
        text: "Mot de passe Oublier?"
        font: Constants.blackFont.h1
        color: Constants.colors.white
        leftPadding: 4
        bottomPadding: 20
        Layout.margins: 10
        wrapMode: "WordWrap"
        Layout.fillWidth: true
    }
    CustomTextField{
        id: _email
        _textLabel.text: "Nous vous envoyons un lien"
        _textLabel.wrapMode: "WordWrap"
        _textField.placeholderText: "Ecrivez votre email"
        Layout.fillWidth: true
    }
    CustomBtn{
        Layout.alignment: Qt.AlignHCenter
        Layout.fillWidth: true
        Layout.margins: 30
        text: "Envoyer"
    }
    Flow {
        spacing: 2
        Layout.alignment: Qt.AlignHCenter
        LinkButton{
            text: "Login here."
            onClicked: _sessionStack.pop()
        }
    }
}


