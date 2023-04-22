import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material
import QtCharts
import Constants 1.0
import "../components/layouts"
import "../../scripts/requests.js" as Req
import "../../scripts/utilities.js" as Utils


Page{
    id: _loginPage
    width: Constants.width
    height: Constants.height
    background: Image{
        source: Constants.images.loginBg
    }
    header: NavBar{
        id: _navBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: _layout.top
    }
    Connections{
        target: _agent
        function onUsersList(users){
            _dashboard._adminsTableView._tableViewModel.populate(users)
        }
        function onUpdatedUser(updatedUser){
            _dashboard._adminsTableView._tableViewModel.onUpdatedItem(updatedUser)
        }
        function onComicList(comics){
            if (_layout.currentIndex === 1)
                _comics._comicListModel.populateList(comics)

        }
        function onFindOneAuthor(author){
            _comics._comicListModel.updateAuthorIdToName(author)
        }
        function onCategoryList(categories){
            _comics._addComic._categoriesListModel.populate(categories)
        }
        function onAuthorList(authors){
            _comics._addComic._authorsListModel.populate(authors)
        }
    }
    contentItem: StackLayout{
        id: _layout
        currentIndex: _navBar.currentIndex
        onCurrentIndexChanged: Utils.navBarCurrentIndexChanged(currentIndex)
        Component.onCompleted: Utils.navBarCurrentIndexChanged(currentIndex)
        anchors.top: _navBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        DashboardPage{
            id: _dashboard
        }
        ComicPage{
            id: _comics
        }
        AuthorPage{
        }
        AdminsPage{
        }
    }
}

