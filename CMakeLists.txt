cmake_minimum_required(VERSION 3.16)

project(never_give_up VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appnever_give_up
    main.cpp
)

set(QML_FONTS
    forms/fonts/static/Montserrat-Bold.ttf
    forms/fonts/static/Montserrat-Light.ttf
)

set(QML_IMAGES
    forms/images/login-bg.png
)

set(QML_FILES
    forms/qml/main.qml
    forms/qml/Constants.qml
    forms/qml/DirectoryFontLoader.qml

    #pages
    forms/qml/pages/LoginPage.qml
    forms/qml/pages/forms/LoginForm.qml
    forms/qml/pages/forms/RegisterForm.qml

    #components
    forms/qml/components/customs/CustomTextField.qml
    forms/qml/components/customs/LinkButton.qml
    forms/qml/components/customs/CustomBtn.qml

    ${QML_FONTS}
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
    PRIVATE Qt6::Quick)

install(TARGETS appnever_give_up
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
