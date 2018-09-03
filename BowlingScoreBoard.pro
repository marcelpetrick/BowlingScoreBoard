#----------------------------------------------------------------------------------
# pro file for the application "BowlingScoreBoard"
#
# description:  Coding challenge with C++/Qt.
#               Create a score-board which computes the score and displays it to the player.
# author: mail@marcelpetrick.it
# date: 20180903
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
    BSB_UdpListener.cpp

HEADERS += \
    BSB_MainWindow.h \
    BSB_UdpListener.h

FORMS += \
    BSB_MainWindow.ui \
    BSB_GameStepWidget.ui
