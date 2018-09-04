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
    m_gameData.resize(10);
}
