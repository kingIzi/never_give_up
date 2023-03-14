import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../../components/customs"

ColumnLayout{
            id: _registerForm
            anchors.margins: 10
            anchors.fill: parent
            spacing: 10
            Label{
                id: _registerLabel
                text: "Bienvenu"
                font: Constants.blackFont.h1
                color: Constants.colors.white
                leftPadding: 4
                bottomPadding: 20
            }
            CustomTextField{
                Layout.fillWidth: true
                _textLabel.text: "Votre nom"
                _textField.placeholderText: "Prenom, postnom, nom"
                _textField.validator: RegularExpressionValidator { regularExpression:/^[a-zA-ZàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð ,.'-]+$/u }
            }
            CustomTextField{
                Layout.fillWidth: true
                _textLabel.text: "Votre numero de telephone"
                _textField.placeholderText: "+234 (0)"
                _textField.validator: RegularExpressionValidator { regularExpression: /\d{1,11}(?:,\d{1,11})+$/ }
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
                    text: "Deja Aboner?"
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
                    text: "Connectez vous!"
                    padding: 4
                    horizontalAlignment: "AlignHCenter"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: _sessionStack.pop()
                    }
                }
            }
        }
