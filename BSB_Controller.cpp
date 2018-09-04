//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180903
//!
//! Coding challenge with C++/Qt/Cmake.
//! Create a score-board which computes the score and displays it to the player.
//!
//! @class  BSB_Controller
//! @brief  todo
//!----------------------------------------------------------------------------------

// own includes
#include "BSB_Controller.h"

//----------------------------------------------------------------------------------

BSB_Controller::BSB_Controller()
{
    createListener();
}

//----------------------------------------------------------------------------------

void BSB_Controller::slotIncomingMessage(const QString message)
{
    qDebug() << "BSB_MainWindow::slotFake: " << message;
}

//----------------------------------------------------------------------------------

void BSB_Controller::createListener()
{
    // try to create an working udp-listener: reset with a new item
    m_udpListener.reset(new BSB_UdpListener("localhost", 6543, nullptr)); // hardcoded by now, but shall be thrown into unnamed namespace

    connect(m_udpListener, &BSB_UdpListener::signalIncomingMessage, this, &BSB_Controller::slotIncomingMessage);
}

//----------------------------------------------------------------------------------
