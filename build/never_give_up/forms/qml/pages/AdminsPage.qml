import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import Constants 1.0
import "../../qml/pages/forms"
import "../components/layouts"

ScrollView{
    id: _adminScroll
    contentWidth: availableWidth
    contentHeight: _col15L.implicitHeight
    AddAdminForm{id: _adminForm}
    UpdateAdminForm{id: _updateAdminForm}
    PromptUserForm{ id: _promptUserForm }
    AddUserForm{id: _userForm}
    UpdateUserForm{id: _updateUserForm}
    AddCategoryForm{id: _addCategoryForm}
    UpdateCategoryForm{id: _updateCategoryForm}
    ColumnLayout{
        id: _col15L
        anchors.fill: parent
        GenericTableView{
            id: _adminsTableView
            Layout.fillWidth: true
            Layout.preferredHeight: implicitHeight
            _titleLabel.text: "Nos Admin(s)"
            _modelHeaders: ["#","First name", "Last name", "Telephone", "Date of Birth"]
            onAddForm: _adminForm.open()
            onEditForm: _updateAdminForm.open()
            onRemoveForm: {
                _promptUserForm._promptText = "Voullez vous vraiment supprimer cette element"
                _promptUserForm.open()
            }
        }
        GenericTableView{
            id: _usersTableView
            Layout.fillWidth: true
            Layout.preferredHeight: implicitHeight
            _titleLabel.text: "Utilisateur(s)"
            _modelHeaders: ["#","First name", "Last name", "Telephone", "Date of Birth"]
            onAddForm: _userForm.open()
            onEditForm: _updateUserForm.open()
            onRemoveForm: {
                _promptUserForm._promptText = "Voullez vous vraiment supprimer cette element"
                _promptUserForm.open()
            }
        }
        GenericTableView{
            id: _categoriesTableView
            Layout.fillWidth: true
            Layout.preferredHeight: implicitHeight
            _titleLabel.text: "Nos Categories"
            _modelHeaders: ["#","Thumbnail","Category","Description","color"]
            onAddForm: _addCategoryForm.open()
            onEditForm: _updateCategoryForm.open()
            onRemoveForm: {
                _promptUserForm._promptText = "Voullez vous vraiment supprimer cette element"
                _promptUserForm.open()
            }
        }
    }
}
