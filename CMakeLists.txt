#-----------------------------------------------------------------
# description: CMakeLists.txt for the BowlingScoreBoard-project.
# author: mail@marcelpetrick.it
#-----------------------------------------------------------------

# 3.8 is required because of C++11 - but somehow this
# still works (and 3.2 is the version I have installed on GNU Linux..)
cmake_minimum_required(VERSION 3.2)

# define the project name
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
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "C:\\include-what-you-use\\bin\\include-what-you-use.exe")

# enforce (testwise x86 32 bit version)
#set(CMAKE_C_FLAGS -m32)
#set(CMAKE_CXX_FLAGS -m32)

# put all sources into one variable: no distinction between h, cpp and ui (or qrc)
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

# create the final result
add_executable(BowlingScoreBoard ${BowlingScoreBoard_SOURCES})
target_link_libraries (BowlingScoreBoard Qt5::Widgets)
target_link_libraries (BowlingScoreBoard Qt5::Core)
target_link_libraries (BowlingScoreBoard Qt5::Network)
