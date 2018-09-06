#-----------------------------------------------------------------
# description: CMakeLists.txt for the BowlingScoreBoard-project.
# author: mail@marcelpetrick.it
#-----------------------------------------------------------------

# maybe set to 3.10.0; 3.8 is because of C++11
#cmake_minimum_required(VERSION 3.8.0)
project(BowlingScoreBoard)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# C++11 support - else we run into issues with the non-static nullptr-assignment
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# put all sources into one variable
set(BowlingScoreBoard_SOURCES
	main.cpp
	BSB_MainWindow.h
	BSB_MainWindow.cpp
	BSB_MainWindow.ui
	BSB_UdpListener.h
	BSB_UdpListener.cpp
	BSB_Controller.h
	BSB_Controller.cpp
	BSB_GameData.h
	BSB_GameData.cpp
)

# maybe add WIN32 before the source-var
add_executable(BowlingScoreBoard ${BowlingScoreBoard_SOURCES})
target_link_libraries (BowlingScoreBoard Qt5::Widgets)
target_link_libraries (BowlingScoreBoard Qt5::Core)
target_link_libraries (BowlingScoreBoard Qt5::Network)
