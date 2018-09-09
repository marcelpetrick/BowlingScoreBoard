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

//Qt includes
#include <QtCore/QDebug>

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
        if(suffix == "reset")
        {
            m_gameData->resetGame();
        }
    }
    else
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
            emit signalSetName(m_gameData->getName());
        }
    }
    else
    // throw-related messages (right now just "throw:n", where n is [0..10])
    if(message.startsWith(c_throw))
    {
        QString const suffix = message.right(message.size() - c_throw.size());
        // Just allow values between 0..10.
        // First parse to int ..
        bool ok;
        int const value = suffix.toInt(&ok, 10);
        // .. conversion worked?
        if(ok)
        {
            // also: check range
            if(value >= 0 && value <= 10)
            {
                bool const success = m_gameData->insertThrow(static_cast<size_t>(value));
                if(!success)
                {
                    qDebug() << "ERROR: throw was not accepted!";
                }
            }
        }
    }

    // update the situation of the gaming-board.
    // Is called now each time a message (valid or invalid); but this can be
    // moved into the previous inner if-cases.
    auto const currentSituation = m_gameData->getCurrentSituation();
    emit signalCurrentSituation(currentSituation);
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
