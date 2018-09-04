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

#pragma once

// Qt includes
#include <QtCore/QVector>
#include <QtCore/QString>

//----------------------------------------------------------------------------------

//! @class  BSB_FrameData
//! @brief  Helper-class for the vector of the frames.
class BSB_FrameData
{
public:
    BSB_FrameData() {}

    // values for the first, second and - if possible - third throw
    int first = -1;
    int second = -1;
    int third = -1;
    bool hasThird = false; // in case of the last frame, allow three throws if the former ones are Strike/Spare
    //! @todo add member checks if "wasStrike" or "wasSpare"

    //! Returns the value for the current frame.
    int getTotal() { return (first >= 0 ? first : 0) + (second >= 0 ? second : 0) + (third >= 0 ? third : 0); } // since all are initialized with -1; just sum the positive values up
};

//----------------------------------------------------------------------------------

class BSB_GameData
{
public:
    BSB_GameData();

private:
    //! contains the player-name
    QString m_playerName;

    //! Contains the data of throws for all ten frames
    QVector<BSB_GameData> m_gameData;
};
