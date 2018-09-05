//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180905
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

// std includes
#include <tuple>

//----------------------------------------------------------------------------------

//! @class  BSB_FrameData
//! @brief  Helper-class for the vector of the frames.
class BSB_FrameData
{
public:
    //! Generic constructor. Nothing special. Resetting not needed, because done via initialization.
    explicit BSB_FrameData() {}

    //! Return the item to the initial state.
    void reset() { first = -1; second = -1; third = -1; hasThird = false; }

    //! Returns the value for the current frame.
    int getTotal() const { return (first >= 0 ? first : 0) + (second >= 0 ? second : 0) + (third >= 0 ? third : 0); } // since all are initialized with -1; just sum the positive values up

    //! values for the first, second and (if possible) third throw
    int first = -1;
    int second = -1;
    int third = -1;
    bool hasThird = false; // in case of the last frame, allow three throws if the former ones are Strike/Spare

    //! @todo add member checks if "wasStrike" or "wasSpare"
};

//----------------------------------------------------------------------------------

class BSB_GameData
{
public:
    //! default ctor - nothing special
    explicit BSB_GameData();

    //! Setter for the player-name.
    void setName(QString const& input);

    //! Getter for the player-name.
    QString const getName();

    //! Add at the "current" frame the given throw. In case no valid insertion was possible, return false.
    //! @todo could be as well handled by throwing an exception ..
    bool insertThrow(size_t pins);

    //! Resets the game: current data is deleted except the name.
    void resetGame();

    //! Get an overview of the current game-situation. Will be used for the graphical presentation.
    QVector<std::tuple<QString, QString, QString> > getCurrentSituation();

private:
    //! contains the player-name
    QString m_playerName;

    //! Contains the data of throws for all ten frames
    QVector<BSB_FrameData> m_frameData;

    //! States which frame is the current one. Will progress in case a frame is "full".
    //! Means: two throws or one strike.
    int m_currentField = 0; //! note: int and not size_t, because QVector relies on int. Else compiler warns: C4267.
};
