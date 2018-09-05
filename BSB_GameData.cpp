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

// own includes
#include "BSB_GameData.h"

//#include <QtCore/QDebug>

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
    //qDebug() << "setName:" << input; // todom remove
}

//----------------------------------------------------------------------------------

const QString BSB_GameData::getName()
{
    return m_playerName;
}

//----------------------------------------------------------------------------------

bool BSB_GameData::insertThrow(size_t pins)
{
    bool returnValue = false;

    //! @todo write the function to insert the value - handle it more correct!
    m_frameData[m_currentField++].first = static_cast<int>(pins);

    //! @attention Also check if more "inserts" are possible! Like: already ten frames done!

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

    m_currentField = 0;
}

//----------------------------------------------------------------------------------

//! todo evaluate if maybe QChar is better suited, because all entries are just one character wide
QVector<std::tuple<QString, QString, QString> > BSB_GameData::getCurrentSituation()
{
    //! Plan is to return a vector of a triple (first throw, second throw, current frame).
    //!
    //! Strike is marked with X,
    //! Spare with /,
    //! not initalized values with " ",
    //! 0 pins with -.

    QVector<std::tuple<QString, QString, QString> > returnValue;

    for(auto & elem : m_frameData)
    {
        QString firstItem = " ";
        if (elem.first == 10)
        {
            firstItem = "X";
        }
        else if (elem.first == 0)
        {
            firstItem = "-";
        }
        else if (elem.first > 0  && elem.first < 10)
        {
             firstItem = QString::number(elem.first);
        } // default case is " " via the initialization

        //! todo
        QString secondItem = "ö"; //placeholder
        QString thirdItem = "x"; //placeholder

        // pack all together
        auto tuple = std::make_tuple(firstItem, secondItem, thirdItem);

        returnValue.append(tuple);
    }

    return returnValue;
}

//----------------------------------------------------------------------------------
