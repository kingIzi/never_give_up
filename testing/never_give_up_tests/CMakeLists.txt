cmake_minimum_required(VERSION 3.5)

project(sessionTests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Test)

include_directories(../../src/include/models/request.hpp)
include_directories(../../src/include/request.hpp)

add_executable(sessionTests tst_comicTests.cpp)
add_test(NAME sessionTests COMMAND sessionTests)

target_link_libraries(sessionTests PRIVATE appnever_give_up Qt${QT_VERSION_MAJOR}::Test ${GTestFiles}
Threads::Threads)

