//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180905
//!
//! Coding challenge with C++/Qt/Cmake.
//! Create a score-board which computes the score and displays it to the player.
//!
//! @class  BSB_MainWindow
//! @brief  todo
//!----------------------------------------------------------------------------------

#pragma once

// own includes
#include "BSB_Controller.h"

// Qt includes
#include <QtWidgets/QMainWindow>

//----------------------------------------------------------------------------------

namespace Ui {
    class BSB_MainWindow;
}

//----------------------------------------------------------------------------------

class BSB_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! ctor/ dtor
    explicit BSB_MainWindow(QWidget *parent = nullptr);
    ~BSB_MainWindow();

private:
    //! the UI
    Ui::BSB_MainWindow *ui;

    std::unique_ptr<BSB_Controller> m_controller = nullptr;
};

//----------------------------------------------------------------------------------
