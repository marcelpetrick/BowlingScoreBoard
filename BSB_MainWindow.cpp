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

// own includes
#include "BSB_MainWindow.h"
#include "ui_BSB_MainWindow.h"

//----------------------------------------------------------------------------------

BSB_MainWindow::BSB_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BSB_MainWindow)
{
    ui->setupUi(this);

    // we need to create our controller
    m_controller.reset(new BSB_Controller);
}

//----------------------------------------------------------------------------------

BSB_MainWindow::~BSB_MainWindow()
{
    delete ui;
}

//----------------------------------------------------------------------------------
