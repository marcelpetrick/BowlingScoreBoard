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
    widgets

TARGET = BowlingScoreBoard
TEMPLATE = app

CONFIG += c++11

SOURCES += \
    main.cpp \
    BSB_MainWindow.cpp

HEADERS += \
    BSB_MainWindow.h

FORMS += \
    BSB_MainWindow.ui \
    BSB_GameStepWidget.ui
