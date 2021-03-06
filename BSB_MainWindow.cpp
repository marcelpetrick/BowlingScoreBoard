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
//! @brief  Handles the state of the ui and owns the background-logic (the controller).
//!----------------------------------------------------------------------------------

// own includes
#include "BSB_MainWindow.h"
#include "ui_BSB_MainWindow.h"

// Qt includes
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QHBoxLayout>

//----------------------------------------------------------------------------------

BSB_MainWindow::BSB_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BSB_MainWindow)
{
    ui->setupUi(this);

    // create the menu
    createActions();
    createMenus();

    // create the game-board
    setupGameBoard();

    // we need to create our controller
    m_controller.reset(new BSB_Controller);

    // connections for handling game-state and player-name
    connect(m_controller.get(), &BSB_Controller::signalCurrentSituation, this, &BSB_MainWindow::slotUpdateBoard);
    connect(m_controller.get(), &BSB_Controller::signalSetName, this, &BSB_MainWindow::slotUpdateName);
}

//----------------------------------------------------------------------------------

BSB_MainWindow::~BSB_MainWindow()
{
    delete ui;
}

//----------------------------------------------------------------------------------

void BSB_MainWindow::slotUpdateBoard(QVector<std::tuple<QString, QString, QString> > state)
{
    // print current state to stdout until the ui works
//    for(auto const& elem : state)
//    {
//        // print them straightforward ..
//        qDebug() << std::get<0>(elem) << "," << std::get<1>(elem) << "," << std::get<2>(elem); //todom remove
//    }

    // forward the data to the ui
    int counter = 0;
    for(auto const& elem : state)
    {
        // construct some appealing layout for each frame
        QString text;
        text.append(std::get<0>(elem));
        text.append("  ");
        text.append(std::get<1>(elem));
        text.append("\n--\n");
        text.append(std::get<2>(elem));

        // assign to the corresponding label
        m_labelFrame[counter]->setText(text);
        // prepare for next frame
        counter++;
    }
}

//----------------------------------------------------------------------------------

void BSB_MainWindow::slotUpdateName(QString const& name)
{
    if(m_labelPlayerName)
    {
        m_labelPlayerName->setText(QString("name\n--\n").append(name));
    }
}

//----------------------------------------------------------------------------------

void BSB_MainWindow::createActions()
{
    // about BSB
    m_aboutAction = new QAction(tr("About BowlingScoreBoard"), this);
    m_aboutAction->setStatusTip(tr("Show this application's About box"));
    m_aboutAction->setShortcut(Qt::CTRL + Qt::Key_A);
    connect(m_aboutAction, &QAction::triggered, this, &BSB_MainWindow::slotAboutBsb);

    // about Qt
    m_aboutQtAction = new QAction(tr("About Qt"), this);
    m_aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    m_aboutQtAction->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(m_aboutQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);
    // replaced the slot-call with a lambda :)
    connect(m_aboutQtAction, &QAction::triggered, this, [=] () { printStatus(tr("Invoked Help|About Qt")); });
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

void BSB_MainWindow::slotAboutBsb()
{
    printStatus(tr("Invoked Help|About BowlingScoreBoard"));

    QMessageBox mBox(QMessageBox::Information, tr("About BowlingScoreBoard"),
                     tr("Small coding-challenge in C++/Qt/CMake. Works cross-platform.<br>"
                        "<br>"
                        "Initially visible state is a \"new game\".<br>"
                        "The BowlingScoreBoard reacts to UDP-input on localhost:6543.<br>"
                        "<br>"
                        "message \"game:reset\" would reset the game.<br>"
                        "message \"name:Klaus\" would set the player-name to Klaus.<br>"
                        "message \"throw:3\" would insert a simulated throw which fell 3 pins.<br>"
                        "Other incoming messages are ignored. The input's validity is checked to a certain extent.<br>"
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

void BSB_MainWindow::setupGameBoard()
{
    // add a style via QSS
    setStyleSheet("QLabel{ background-color : rgba( 128, 128, 128, 255); border-radius : 4px; border: 1px solid black; padding: 2px 2px 2px 2px }");

    QHBoxLayout* newLayout = new QHBoxLayout;

    // add the first cell, which contains the player-name
    m_labelPlayerName = new QLabel(this);
    m_labelPlayerName->setToolTip(tr("Displays the current players name.\nInitially not set."));
    m_labelPlayerName->setText("name\n--\n "); // initially not set
    m_labelPlayerName->setWordWrap(false);
    m_labelPlayerName->setAlignment(Qt::AlignCenter);
    newLayout->addWidget(m_labelPlayerName);

    // add cells for the frames
    for (int i = 0; i < 10; ++i)
    {
        QLabel* const label = new QLabel(this);
        label->setToolTip(tr("Displays the value of this frame."));
        label->setText(" \n--\n "); // initially not set
        label->setWordWrap(false);
        label->setAlignment(Qt::AlignCenter);
        m_labelFrame.append(label);
        newLayout->addWidget(m_labelFrame[i]);
    }

    ui->centralWidget->setLayout(newLayout);

    // enforce minimal view initially
    ui->centralWidget->resize(minimumSizeHint());
}

//----------------------------------------------------------------------------
