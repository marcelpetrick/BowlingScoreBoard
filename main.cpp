//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180903
//!
//! Coding challenge with C++/Qt/Cmake.
//! Create a score-board which computes the score and displays it to the player.
//!
//! @class  BSB_MainWindow
//! @brief  todo
//!----------------------------------------------------------------------------------

// own includes
#include "BSB_MainWindow.h"

// Qt includes
#include <QtWidgets/QApplication>

//----------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BSB_MainWindow w;
    w.show();
    int const result = a.exec();

    return result;
}

//----------------------------------------------------------------------------------
