import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import CategoriesModel 1.0
import AuthorListModel 1.0
import "../../components/customs"
import "../../../scripts/utilities.js" as Utils
import "../../../scripts/requests.js" as Req


Popup {
    id: _addComicForm
    width: parent.width - 40
    height: parent.height - 40
    anchors.centerIn: parent
    Material.background: Constants.colors.gray200
    readonly property alias _categoriesListModel: _categoryListModel
    readonly property alias _authorsListModel: _authorListModel
    QtObject{
        id: _addComicFormObj
        property var categories:[]
        //readonly property string authorId: _authorListModel.rowCount() > 0 ? _authorListModel.getItemAt(_formComboBox.currentIndex).authorId : ""
        readonly property string authorId: _authorListModel.isEmpty ? "" : _authorListModel.getItemAt(_formComboBox.currentIndex).authorId
        readonly property string name: _titleFormField._textField.text
        property var dateReleased: new Date()
        readonly property url thumbnailFile: _thumbnailFile.filePath
        readonly property url comicFile: _comicFile.filePath
        readonly property string description: _description._textArea.text
    }
    //    Connections{
    //        target: _agent
    //        function onCategoryList(categories){
    //            _categoryListModel.populate(categories)
    //        }
    //        function onAuthorList(authors){
    //            _authorListModel.populate(authors)
    //        }
    //    }
    contentItem: ScrollView{
        contentWidth: availableWidth
        contentHeight: _col3L.implicitHeight
        Item{
            id: _addComicFormItem
            anchors.fill: parent
            ColumnLayout{
                id: _col3L
                anchors.fill: parent
                spacing: 20
                Label{
                    id: _tableTitleLabel
                    text: "Ajouter une BD"
                    font: Constants.blackFont.h2
                    Material.foreground: Constants.colors.white
                    Layout.alignment: Qt.AlignHCenter
                    Layout.fillWidth: true
                    horizontalAlignment: "AlignHCenter"
                }
                ToolSeparator{
                    orientation: "Horizontal"
                    Layout.fillWidth: true
                    Material.background: Constants.colors.white
                }
                FormTextField{
                    id: _titleFormField
                    _title: "Titre"
                    _textField.placeholderText: "Choississez un titre"
                    Layout.fillWidth: true
                    Layout.preferredHeight: implicitHeight
                }
                Item{
                    Layout.fillWidth: true
                    Layout.preferredHeight: _categoriesGrid.implicitHeight
                    GridLayout{
                        id: _categoriesGrid
                        anchors.fill: parent
                        columnSpacing: 3
                        rowSpacing: 3
                        Repeater{
                            model: CategoriesModel{
                                id: _categoryListModel
                                categoriesListData: _categoryListData
                            }
                            delegate: ItemDelegate{
                                id: _lbl
                                property bool isSelected: false
                                text: categoryName
                                font: Constants.blackFont.h5
                                Material.foreground: categoryColor
                                icon.color: isSelected ? Constants.colors.white : ""
                                icon.source: isSelected ? Constants.icons.checkCircle : ""
                                onClicked: isSelected = !isSelected
                                onIsSelectedChanged: {
                                    let indexOf = _addComicFormObj.categories.indexOf(categoryName)
                                    if (indexOf === -1){
                                        _addComicFormObj.categories.push(categoryName)
                                    }
                                    else{
                                        _addComicFormObj.categories.splice(indexOf,1)
                                    }
                                    console.log(_addComicFormObj.categories)
                                }
                            }
                        }
                        Label{
                            Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                            text: " items picked."
                            font: Constants.blackFont.h6
                            Material.foreground: Constants.colors.gray200
                            horizontalAlignment: "AlignRight"
                        }
                    }
                }
                ComboBox{
                    id: _formComboBox
                    Layout.fillWidth: true
                    //model: _formField._model
                    model: AuthorListModel{
                        id: _authorListModel
                        authorListData: _authorListData
                    }
                    leftPadding: 30
                    background: Rectangle{
                        color: Constants.colors.gray500
                    }
                    Material.foreground: Constants.colors.white
                    font: Constants.lightFont.h4
                    padding: 20
                    currentIndex: 0
                    displayText: currentIndex == -1 ? "Select author" : currentText + " " + currentValue
                    textRole: "firstName"
                    valueRole: "lastName"
                    popup: Popup {
                        y: _formComboBox.height - 1
                        width: _formComboBox.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1
                        Material.background: Constants.colors.gray200
                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: _formComboBox.popup.visible ? _formComboBox.delegateModel : null
                            currentIndex: _formComboBox.highlightedIndex
                            ScrollIndicator.vertical: ScrollIndicator { }
                        }
                    }
                    delegate: ItemDelegate {
                        width: _formComboBox.width
                        text: model.firstName + " " + model.lastName
                        Material.foreground: Constants.colors.white
                        highlighted: _formComboBox.highlightedIndex === index
                    }
                }
                Item{
                    id: _comicDatePublished
                    Layout.fillWidth: true
                    Layout.preferredHeight: 180
                    ColumnLayout{
                        id: _col11
                        anchors.fill: parent
                        Item{
                            Layout.fillWidth: true
                            Layout.preferredHeight: _rowl3.implicitHeight
                            RowLayout{
                                id: _rowl3
                                anchors.fill: parent
                                Label{
                                    id: _date
                                    Layout.alignment: Qt.AlignBottom | Qt.AlignRight
                                    text: "Date published"
                                    font: Constants.blackFont.h6
                                    Material.foreground: Constants.colors.white
                                    horizontalAlignment: "AlignRight"
                                }
                                Button{
                                    Layout.alignment: Qt.AlignVCenter | Qt.AlignRight
                                    icon.source: Constants.icons.calendar
                                    icon.color: Constants.colors.white
                                    Material.background: "transparent"
                                    onClicked: _datePickerRent.visible = true
                                }
                            }
                        }
                        Item{
                            id: _datePickerRent
                            Layout.fillWidth: true
                            //Layout.preferredHeight: _datePicker.implicitHeight
                            Layout.fillHeight: true
                            Layout.maximumWidth: _root.width > 640 ? parent.width / 2 : parent.width
                            visible: false
                            GridLayout {
                                id: _datePicker
                                columns: 2
                                anchors.fill: parent
                                DayOfWeekRow {
                                    locale: grid.locale
                                    font: Constants.blackFont.h6
                                    Material.foreground: Constants.colors.white
                                    Layout.column: 1
                                    Layout.fillWidth: true
                                }
                                WeekNumberColumn {
                                    month: grid.month
                                    year: grid.year
                                    locale: grid.locale
                                    Layout.fillHeight: true
                                    font: Constants.blackFont.h6
                                    Material.foreground: Constants.colors.white
                                    opacity: 0
                                }
                                MonthGrid {
                                    id: grid
                                    month: _addComicFormObj.dateReleased.getMonth()
                                    year: _addComicFormObj.dateReleased.getFullYear()
                                    locale: Qt.locale("en_US")
                                    font: Constants.blackFont.h6
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    delegate: Label {
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            opacity: model.month === grid.month ? 1 : 0
                                            text: model.day
                                            font: grid.font
                                            Material.foreground: Constants.colors.white
                                            required property var model
                                            Rectangle{
                                                anchors.centerIn: parent
                                                width: 44
                                                height: 44
                                                color: "transparent"
                                                border.width: 1
                                                border.color: "white"
                                                visible: _addComicFormObj.dateReleased == model.date
                                            }
                                        }
                                    Connections{
                                        target: grid
                                        function onClicked(date){
                                            _addComicFormObj.dateReleased = date
                                            _date.text = date
                                            _datePickerRent.visible = false
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                FormFileSelector{
                    id: _thumbnailFile
                    _title: "Le thumbnail"
                    Layout.fillWidth: true
                    _textField.text: "la photo profil"
                    nameFilters: ["*.jpg","*.png","*.jpeg"]
                }
                FormFileSelector{
                    id: _comicFile
                    _title: "Le BD"
                    Layout.fillWidth: true
                    _textField.text: "Le BD"
                    nameFilters: ["*pdf"]
                }
                FormTextArea{
                    id: _description
                    _title: "Description"
                    Layout.fillWidth: true
                }
                Item{
                    Layout.fillWidth: true
                    Layout.preferredHeight: _row8L.implicitHeight
                    RowLayout{
                        id: _row8L
                        anchors.fill: parent
                        Button{
                            font: Constants.blackFont.h4
                            text: "Preview"
                            Material.foreground: Constants.colors.white
                            Layout.fillWidth: true
                            background: Rectangle{
                                color: "transparent"
                                border.width: 2
                                border.color: Constants.colors.primary
                            }
                        }
                        Button{
                            Layout.fillWidth: true
                            font: Constants.blackFont.h4
                            text: "Ajouter"
                            Material.background: Constants.colors.primary
                            Material.foreground: Constants.colors.white
                            onClicked: {
                                const form = Req.createAddComicForm(_addComicFormObj)
                                _agent.requestCreateComic(form)
                            }
                        }
                    }
                }
            }
        }
    }
}
