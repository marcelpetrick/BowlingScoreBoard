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
    // initialize
    m_gameData.reset(new BSB_GameData);

    // create the listener: the order matters; first we need some valid "container", then some reacting instance
    createListener();
}

//----------------------------------------------------------------------------------

void BSB_Controller::slotIncomingMessage(const QString message)
{
    qDebug() << "BSB_MainWindow::slotIncomingMessage: " << message;

    // todo add here some checks for valid messages
}

//----------------------------------------------------------------------------------

void BSB_Controller::createListener()
{
    // try to create an working udp-listener: reset with a new item
    m_udpListener.reset(new BSB_UdpListener("localhost", 6543, nullptr)); // hardcoded by now, but shall be thrown into unnamed namespace

    // source can be just a real ptr; shared or unqiue are not loved by the linker
    connect(m_udpListener.get(), &BSB_UdpListener::signalIncomingMessage, this, &BSB_Controller::slotIncomingMessage);
}

//----------------------------------------------------------------------------------
