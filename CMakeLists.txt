#-----------------------------------------------------------------
# description: CMakeLists.txt for the BownlingScoreBoard-project.
# author: mail@marcelpetrick.it
#-----------------------------------------------------------------

cmake_minimum_required(VERSION 3.10.0)
project(BowlingScoreBoard)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(BSB_MainWindow BSB_MainWindow.cpp)
target_link_libraries (BSB_MainWindow Qt5::Widgets)

set(BowlingScoreBoard_SOURCES "main.cpp BSB_MainWindow.h") 
set(BowlingScoreBoard_HEADERS "BSB_MainWindow.h")

add_executable(BowlingScoreBoard ${BowlingScoreBoard_SOURCES} ${BowlingScoreBoard_HEADERS})
target_link_libraries (BowlingScoreBoard BSB_MainWindow)
