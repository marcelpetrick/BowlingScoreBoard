#----------------------------------------------------------------------------------
# pro file for the application "BowlingScoreBoard"
#
# description:  Coding challenge with C++/Qt.
#               Create a score-board which computes the score and displays it to the player.
# author: mail@marcelpetrick.it
# date: 20180905
#----------------------------------------------------------------------------------

QT += \
    core \
    gui \
    widgets \
    network

TARGET = BowlingScoreBoard
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    main.cpp \
    BSB_MainWindow.cpp \
    BSB_UdpListener.cpp \
    BSB_Controller.cpp \
    BSB_GameData.cpp

HEADERS += \
    BSB_MainWindow.h \
    BSB_UdpListener.h \
    BSB_Controller.h \
    BSB_GameData.h

FORMS += \
    BSB_MainWindow.ui
