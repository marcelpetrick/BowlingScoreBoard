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

// Qt includes
#include <QtWidgets/QMessageBox>

//----------------------------------------------------------------------------------

BSB_MainWindow::BSB_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BSB_MainWindow)
{
    ui->setupUi(this);

    // we need to create our controller
    m_controller.reset(new BSB_Controller);    

    // create the menu
    createActions();
    createMenus();
}

//----------------------------------------------------------------------------------

BSB_MainWindow::~BSB_MainWindow()
{
    delete ui;
}

//----------------------------------------------------------------------------------

void BSB_MainWindow::createActions()
{
    // about BSB
    m_aboutAction = new QAction(tr("About BowlingScoreBoard"), this);
    m_aboutAction->setStatusTip(tr("Show this application's About box"));
    m_aboutAction->setShortcut(Qt::CTRL + Qt::Key_A);
    connect(m_aboutAction, &QAction::triggered, this, &BSB_MainWindow::slotAbout);

    // about Qt
    m_aboutQtAction = new QAction(tr("About Qt"), this);
    m_aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    m_aboutQtAction->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(m_aboutQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);
    // replaced the slot-call with a lambda :)
    connect(m_aboutQtAction, &QAction::triggered, this, [=] () { printStatus(tr("Invoked <b>Help|About Qt</b>")); });
}

//----------------------------------------------------------------------------------

void BSB_MainWindow::createMenus()
{
    // help menu
    m_helpMenu = menuBar()->addMenu(tr("Help")); //! @todo localize strings
    m_helpMenu->addAction(m_aboutAction);
    m_helpMenu->addAction(m_aboutQtAction);
}

//----------------------------------------------------------------------------------

void BSB_MainWindow::slotAbout()
{
    printStatus(tr("Invoked Help|About BowlingScoreBoard"));

    QMessageBox mBox(QMessageBox::Information, tr("About BowlingScoreBoard"),
                     tr("Small coding-challenge in C++/Qt.<br>"
                        "Should work cross-platform.<br>"
                        "<br>"
                        "Developed by <a href='mail@marcelpetrick.it'>mail@marcelpetrick.it</a><br>"));
    mBox.setTextFormat(Qt::RichText);
    mBox.exec();
}

//----------------------------------------------------------------------------

void BSB_MainWindow::printStatus(const QString& message)
{
    // messages shall disappear after five seconds
    ui->statusBar->showMessage(message, c_StatusBarDelay);
}

//----------------------------------------------------------------------------
