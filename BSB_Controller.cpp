//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180905
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

void BSB_Controller::slotIncomingMessage(const QString& message)
{
    qDebug() << "BSB_MainWindow::slotIncomingMessage: " << message; // todom remove

    //! Check for valid data and handle it
    // game-status related messages (right now just "game:reset")
    if(message.startsWith(c_game))
    {
        QString const suffix = message.right(message.size() - c_game.size());
        qDebug() << "game rest is:" << suffix;
        if(suffix == "reset")
        {
            qDebug() << "resetGame!!!";
            m_gameData->resetGame();
        }
    }
    // name-related messages (right now just "name:XYZ" for setting the name of the player)
    if(message.startsWith(c_name))
    {
        QString const suffix = message.right(message.size() - c_name.size());
        // just allow alphanumeric strings as names
        QRegExp const justAlphanumericCharacters("^[a-zA-Z0-9]*$");
        if(justAlphanumericCharacters.exactMatch(suffix))
        {
            // .. and cut them to the leftmost 10 characters
            m_gameData->setName(suffix.left(10));
        }
    }

    //! @todo add here some checks for valid messages
    // push into the gamedata
    m_gameData->insertThrow(9); // fake!

    auto foo = m_gameData->getCurrentSituation();
    for(auto const& elem : foo)
    {
        // print straight forward ..
        qDebug() << std::get<0>(elem) << "," << std::get<1>(elem) << "," << std::get<2>(elem);
    }
}

//----------------------------------------------------------------------------------

void BSB_Controller::createListener()
{
    // try to create an working udp-listener: reset with a new item
    m_udpListener.reset(new BSB_UdpListener(c_interface, c_port, nullptr)); // hardcoded configuration

    // source can be just a real ptr; shared or unqiue are not loved by the linker
    connect(m_udpListener.get(), &BSB_UdpListener::signalIncomingMessage, this, &BSB_Controller::slotIncomingMessage);
}

//----------------------------------------------------------------------------------
