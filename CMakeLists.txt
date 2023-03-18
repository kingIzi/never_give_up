cmake_minimum_required(VERSION 3.16)

project(never_give_up VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)


find_package(Qt6 6.2 COMPONENTS Quick Charts REQUIRED)


qt_add_executable(appnever_give_up
    main.cpp

    src/include/models/admintablemodel.hpp

    src/src/models/admintablemodel.cpp
)

set(QML_FONTS
    forms/fonts/static/Montserrat-Bold.ttf
    forms/fonts/static/Montserrat-Light.ttf
)

set(BOOTSTRAP_ICONS
    forms/icons/person-lock.svg
    forms/icons/list.svg
    forms/icons/arrow-up.svg
    forms/icons/arrow-down.svg
    forms/icons/plus.svg
    forms/icons/pen.svg
    forms/icons/dash.svg
    forms/icons/columns-gap.svg
    forms/icons/bookshelf.svg
    forms/icons/funnel.svg
    forms/icons/calendar.svg
)

set(QML_IMAGES
    forms/images/login-bg.png
    forms/images/comics-man.png
    forms/images/hut.png
    forms/images/admins.png
    forms/images/dashboard.png
    forms/images/details-frame.png
    forms/images/malory-blackman.png
    forms/images/search-bar.png
    forms/images/nzinga.png

    ${BOOTSTRAP_ICONS}
)

include_directories(src/include/models)

set(QML_SCRIPTS
    forms/scripts/utilities.js
)

set(QML_FILES
    forms/qml/main.qml
    forms/qml/Constants.qml
    forms/qml/DirectoryFontLoader.qml

    #pages
    forms/qml/pages/LoginPage.qml
    forms/qml/pages/MainNavigation.qml
    forms/qml/pages/DashboardPage.qml
    forms/qml/pages/ComicPage.qml
    forms/qml/pages/AuthorPage.qml
    forms/qml/pages/AdminsPage.qml

    forms/qml/pages/forms/LoginForm.qml
    forms/qml/pages/forms/RegisterForm.qml
    forms/qml/pages/forms/ResetPasswordForm.qml
    forms/qml/pages/forms/AddComicForm.qml
    forms/qml/pages/forms/UpdateComicForm.qml
    forms/qml/pages/forms/PromptUserForm.qml
    forms/qml/pages/forms/AddAuthorForm.qml
    forms/qml/pages/forms/UpdateAuthorForm.qml
    forms/qml/pages/forms/AddAdminForm.qml
    forms/qml/pages/forms/UpdateAdminForm.qml
    forms/qml/pages/forms/AddUserForm.qml
    forms/qml/pages/forms/UpdateUserForm.qml
    forms/qml/pages/forms/AddCategoryForm.qml
    forms/qml/pages/forms/UpdateCategoryForm.qml

    #components
    forms/qml/components/customs/CustomTextField.qml
    forms/qml/components/customs/LinkButton.qml
    forms/qml/components/customs/CustomBtn.qml
    forms/qml/components/customs/SearchField.qml
    forms/qml/components/customs/FormTextField.qml
    forms/qml/components/customs/FormComboBox.qml
    forms/qml/components/customs/FormDatePicker.qml
    forms/qml/components/customs/FormFileSelector.qml
    forms/qml/components/customs/FormTextArea.qml

    forms/qml/components/layouts/NavBar.qml
    forms/qml/components/layouts/GeneralReview.qml
    forms/qml/components/layouts/DashboardMostPopularAuthor.qml
    forms/qml/components/layouts/DefaultTableView.qml
    forms/qml/components/layouts/DashboardCharts.qml
    forms/qml/components/layouts/ComicNavHeader.qml
    forms/qml/components/layouts/AuthorNavHeader.qml
    forms/qml/components/layouts/AdminNavHeader.qml
    forms/qml/components/layouts/GenericTableView.qml

    ${QML_FONTS}
    ${QML_SCRIPTS}
)

qt_add_qml_module(appnever_give_up
    URI never_give_up
    VERSION 1.0
    RESOURCES ${QML_IMAGES}
    QML_FILES ${QML_FILES}
)

set_target_properties(appnever_give_up PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appnever_give_up
    PRIVATE Qt::Quick Qt::Charts)

install(TARGETS appnever_give_up
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
