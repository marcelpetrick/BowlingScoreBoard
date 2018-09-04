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
#include "ui_BSB_MainWindow.h"

//----------------------------------------------------------------------------------

BSB_MainWindow::BSB_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BSB_MainWindow)
{
    ui->setupUi(this);

    if (m_udpListener != nullptr)
    {
        delete m_udpListener;
        m_udpListener = nullptr;
    }

    // try to create an working udp-listener
    BSB_UdpListener* m_udpListener = new BSB_UdpListener("localhost", 6543, nullptr);
    connect(m_udpListener, &BSB_UdpListener::signalIncomingCall, this, &BSB_MainWindow::slotFake);

    // testwise create some items and add them to the widget
    //GameStepWidget* step = new GameStepWidget();
    //ui->verticalLayout_f1->addItem(step);
}

//----------------------------------------------------------------------------------

BSB_MainWindow::~BSB_MainWindow()
{
    delete ui;
}

//----------------------------------------------------------------------------------

void BSB_MainWindow::slotFake(const QString message)
{
    qDebug() << "BSB_MainWindow::slotFake: " << message;
}

//----------------------------------------------------------------------------------
