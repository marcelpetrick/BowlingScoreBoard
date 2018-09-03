
QT += \
	core \
	gui \
	widgets

TARGET = BowlingScoreBoard
TEMPLATE = app

CONFIG += c++11

SOURCES += \
	main.cpp \
	ScoreboardMainWindow.cpp

HEADERS += \
	ScoreboardMainWindow.h

FORMS += \
	ScoreBoardMainWindow.ui \
	GameStepWidget.ui

