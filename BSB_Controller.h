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
//! @brief  Contains the state of the game and handles the input-listener. Forwards the current state to the main-window.
//!----------------------------------------------------------------------------------

// own includes
#include "BSB_UdpListener.h"

// Qt includes
#include <QObject>

// std-includes
#include <memory> // for unique_ptr

//----------------------------------------------------------------------------------

//! @todo add the big unit-test at least for this component

class BSB_Controller : public QObject
{
    Q_OBJECT

public:
    //! todo
    BSB_Controller();

public slots:
    //! todo
    void slotIncomingMessage(QString const message);

private:
    //! todo Create and
    void createListener();

    //! todo
    std::unique_ptr<BSB_UdpListener> m_udpListener = nullptr;
    //std::shared_ptr<BSB_UdpListener> m_udpListener = nullptr;
};

//----------------------------------------------------------------------------------
