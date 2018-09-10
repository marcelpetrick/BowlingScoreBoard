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
//! @brief  Handles and contains all the data which is necessary to describe the current
//!         game-situation.
//!----------------------------------------------------------------------------------

// own includes
#include "BSB_GameData.h"

//----------------------------------------------------------------------------------

BSB_GameData::BSB_GameData()
{
    // resize the container with ten frames.
    m_frameData.resize(c_maxFrames);

    // init the array
    for(int & m_frameTotalsAccordingToRule : m_frameTotalsAccordingToRules)
    {
        m_frameTotalsAccordingToRule = 0;
    }
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

bool BSB_GameData::insertThrow(size_t pins)
{
    bool returnValue = false;

    // prevent invalid access
    if(0 <= m_currentField && m_currentField < 10)
    {
        bool advanceFrame = false;

        if(m_frameData[m_currentField].first == -1)
        {
            m_frameData[m_currentField].first = static_cast<int>(pins);

            // if it was a strike: advance immediately
            if(m_frameData[m_currentField].first == 10)
            {
                m_frameData[m_currentField].second = 0;
                advanceFrame = true; // because it is "full"
            }

            returnValue = true;
        }
        else
        {
            if(m_frameData[m_currentField].second == -1)
            {
                m_frameData[m_currentField].second = static_cast<int>(pins);
                advanceFrame = true; // because it is "full"
                returnValue = true;
            }
        }

        if(advanceFrame || m_frameData[m_currentField].getTotal() == 10)
        {
            // increase the next insertion
            m_currentField++;
        }
    }

    // if something has changed (== successful insertion), re-evaluate the board
    if(returnValue)
    {
        computerFrameTotalsAccordingToTheRules();
    }

    return returnValue;
}

//----------------------------------------------------------------------------------

void BSB_GameData::resetGame()
{
    // reset whole game-data by iterating all frames
    for(auto & element : m_frameData)
    {
        element.reset();
    }

    m_currentField = 0;

    // re-initialize the array
    for(int & m_frameTotalsAccordingToRule : m_frameTotalsAccordingToRules)
    {
        m_frameTotalsAccordingToRule = 0;
    }
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

    int currentPosition = 0;
    for(auto & elem : m_frameData)
    {
        // the first throw of a frame
        QString firstItem = " ";
        if (elem.first == 10)
        {
            firstItem = "X"; // strike!
        }
        else if (elem.first == 0)
        {
            firstItem = "-";
        }
        else if (elem.first > 0  && elem.first < 10)
        {
            firstItem = QString::number(elem.first);
        } // default case is " " via the initialization

        // the second throw of a frame
        QString secondItem = " ";
        if (elem.getTotal() == 10)
        {
            secondItem = elem.first != 10 ? "/" : " "; // spare!
        }
        else if (elem.second == 0)
        {
            secondItem = "-";
        }
        else if (elem.second > 0 && elem.second < 10)
        {
            secondItem = QString::number(elem.second);
        } // default case is " " via the initialization

        // the total value for that frame (together with the added ones because of strike or spare)
        //! @todo! is just a placeholder! fix this!
        int const total = m_frameTotalsAccordingToRules[currentPosition];
        // prevent to show the -1; also just for items which exist
        QString thirdItem = (total > 0 && currentPosition < m_currentField) ? QString::number(total) : " ";

        // pack all together
        auto tuple = std::make_tuple(firstItem, secondItem, thirdItem);

        returnValue.append(tuple);
        currentPosition++;
    }

    return returnValue;
}

//----------------------------------------------------------------------------------

void BSB_GameData::computerFrameTotalsAccordingToTheRules()
{
    int previousFrameTotal = 0;

    for(int frameToCompute = 0; frameToCompute < c_maxFrames; frameToCompute++)
    {
        int frameTotal = m_frameData[frameToCompute].getTotal();
        // if it was spare or strike: add the next roll
        if(frameTotal == 10)
        {
            // spare or strike: get next frame
            int const nextFrame = frameToCompute + 1;
            if(nextFrame < c_maxFrames)
            {
                // the value for the first ball
                frameTotal += std::max(0, m_frameData[nextFrame].first); // prevent adding the -1 from the init-state

                // the value for the second ball, in case of strike
                if(m_frameData[frameToCompute].first == 10)
                {
                    // strike: get next frame
                    if(m_frameData[nextFrame].first == 10)
                    {
                        // next-next frame
                        int const nextNextFrame = nextFrame + 1;
                        if(nextNextFrame < c_maxFrames)
                        {
                            // the value for the first ball
                            frameTotal += std::max(0, m_frameData[nextNextFrame].first); // prevent adding the -1 from the init-state
                        }
                    }
                    else
                    {
                        frameTotal += std::max(0, m_frameData[nextFrame].second); // prevent adding the -1 from the init-state
                    }
                }
            }
        }

        // assign to the current one
        m_frameTotalsAccordingToRules[frameToCompute] = frameTotal + previousFrameTotal;
        // store the current value for the next element
        previousFrameTotal = m_frameTotalsAccordingToRules[frameToCompute];
    }
}

//----------------------------------------------------------------------------------
