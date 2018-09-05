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
//! @brief  Handles the state of the ui and owns the background-logic: the controller.
//!----------------------------------------------------------------------------------

#pragma once

// own includes
#include "BSB_Controller.h"

// Qt includes
#include <QtWidgets/QMainWindow>

//----------------------------------------------------------------------------------

// for constants
namespace {
    //! Determines how long the status message is visible. After timer runs out, it is removed.
    unsigned int const c_StatusBarDelay = 5000;
}

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

private slots:
    //! Slot for the help-menu-entries
    void slotAbout();

private:
    //! create actions and fitting menues for the "help-menu"
    void createActions();
    void createMenus();

    //! Print the given string to the status-bar.
    void printStatus(QString const& message);

    //! Create the board with the ten frames.
    void setupGameBoard();

    //! the UI
    Ui::BSB_MainWindow *ui;

    //! the game-controller: the "logic" behind the UI
    std::unique_ptr<BSB_Controller> m_controller = nullptr;

    //! members for the "help"-menu
    QMenu* m_helpMenu = nullptr;
    QAction* m_aboutAction = nullptr;
    QAction* m_aboutQtAction = nullptr;
};

//----------------------------------------------------------------------------------
