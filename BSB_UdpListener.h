//!----------------------------------------------------------------------------------
//! Part of the project "BowlingScoreBoard"
//!
//! @author mail@marcelpetrick.it
//! @date   20180905
//!
//! Coding challenge with C++/Qt/Cmake.
//! Create a score-board which computes the score and displays it to the player.
//!
//! @class  BSB_UdpListener
//! @brief  todo
//!----------------------------------------------------------------------------------

#pragma once

// Qt includes
#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>

// std includes
#include <memory>

//----------------------------------------------------------------------------------

// constants for the udp-socket. Potential improvement: be moved to some dynamic config-file.
namespace {
    QString const c_interface = "localhost";
    quint16 const c_port = 6543;
}

//----------------------------------------------------------------------------------

class BSB_UdpListener : public QObject
{
    Q_OBJECT

public:
    explicit BSB_UdpListener(QString const receiverInterface, quint16 const receiverPort, QObject* parent = nullptr);

signals:
    //! Used to forward the data from incoming packets to the controller. No filtering is applied!
    void signalIncomingMessage(QString const message);

private slots:
    //! In case the readRead-signal is fired, handle the data. Means: fetch all incoming datagrams.
    void onIncomingData();

private:
    //! Socket which will be used.
    std::unique_ptr<QUdpSocket> m_udpSocket;
};
