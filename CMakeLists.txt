#-----------------------------------------------------------------
# Project converted from qmake file using q2c
# https://github.com/benapetr/q2c at Mo Sep 3 14:33:16 2018
#-----------------------------------------------------------------
cmake_minimum_required (VERSION 2.6)
project(BowlingScoreBoard)
option(QT5BUILD "Build using Qt5 libs" TRUE)
IF (QT5BUILD)
    find_package(Qt5Core REQUIRED)
    set(QT_INCLUDES ${Qt5Core_INCLUDE_DIRS})
    include_directories(${QT_INCLUDES})
    QT5_WRAP_CPP(BowlingScoreBoard_HEADERS_MOC ${HuggleLite_HEADERS})
ELSE()
    find_package(Qt4 REQUIRED)
ENDIF()
set(BowlingScoreBoard_SOURCES "")
set(BowlingScoreBoard_HEADERS "")
add_executable(BowlingScoreBoard ${BowlingScoreBoard_SOURCES} ${BowlingScoreBoard_HEADERS})
IF (QT5BUILD)
    qt5_use_modules(BowlingScoreBoard Core)
ENDIF()
