//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180905
//!
//! Coding challenge with C++/Qt/CMake.
//! Create a score-board which computes the score and displays it to the player.
//!
//! @class  BSB_MainWindow
//! @brief  Contains the main ..
//!----------------------------------------------------------------------------------

// own includes
#include "BSB_MainWindow.h"

// Qt includes
#include <QtWidgets/QApplication>

//----------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    BSB_MainWindow w;
    w.show();
    int const result = a.exec();

    return result;
}

//----------------------------------------------------------------------------------
