//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180903
//!
//! Coding challenge with C++/Qt/Cmake.
//! Create a score-board which computes the score and displays it to the player.
//!
//! @class  BSB_GameData
//! @brief  todo
//!----------------------------------------------------------------------------------

// own includes
#include "BSB_GameData.h"

//----------------------------------------------------------------------------------

BSB_GameData::BSB_GameData()
{
    //! Resize the container with ten frames.
    m_frameData.resize(10);
}

//----------------------------------------------------------------------------------

void BSB_GameData::setName(const QString &input)
{
    m_playerName = input;
}

//----------------------------------------------------------------------------------

const QString BSB_GameData::getName()
{
    return m_playerName;
}

//----------------------------------------------------------------------------------

bool BSB_GameData::insertThrow()
{
    bool returnValue = false;

    //! @todo write the function to insert the value

    return returnValue;
}

//----------------------------------------------------------------------------------

void BSB_GameData::resetGame()
{
    // reset whole game-data by iterating all frames
    for(auto element : m_frameData)
    {
        element.reset();
    }
}

//----------------------------------------------------------------------------------
