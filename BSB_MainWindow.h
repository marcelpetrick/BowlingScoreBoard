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

#pragma once

// Qt includes
#include <QtWidgets/QMainWindow>

//----------------------------------------------------------------------------------

namespace Ui {
class BSB_MainWindow;
class BSB_GameStepWidget; // element for the "turns"
}

//----------------------------------------------------------------------------------

class BSB_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BSB_MainWindow(QWidget *parent = nullptr);
    ~BSB_MainWindow();

public slots:
    void slotFake(QString const message);

private:
    Ui::BSB_MainWindow *ui;
};

