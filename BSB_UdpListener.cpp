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

#include "BSB_UdpListener.h"

// Qt includes
//#include <QtCore/QDebug> //todoM remove: just for debugging
//#include <QtCore/QDateTime> //todoM remove: just for debugging
//qDebug() << QDateTime::currentDateTime().toString("mm:ss:z") << "nonsense"; // todoM remove

//----------------------------------------------------------------------------------

BSB_UdpListener::BSB_UdpListener(const QString receiverInterface, const quint16 receiverPort, QObject *parent)
    : QObject (parent)
{
    m_udpSocket = std::unique_ptr<QUdpSocket>(new QUdpSocket(this));
    // check if ip:port is valid is done via bind.
    // if wrongly or not configured, then ... bad luck!
    bool const result = m_udpSocket->bind(QHostAddress(receiverInterface),
                                          static_cast<quint16>(receiverPort),
                                          QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint); // this is the ip:port-combo which is also used by the regular ShipSensorSim for sending the tickets out
    if(result)
    {
        qDebug() << "Connected to" << receiverInterface << "on port" << receiverPort;
    }
    else
    {
        qDebug() << "UdpListener::UdpListener: ERROR: binding to configured combination of \"ip:port\" did not work! ip=" << receiverInterface << "port=" << receiverPort;
    }

    connect(m_udpSocket.get(), &QUdpSocket::readyRead, this, &BSB_UdpListener::onIncomingData);
}

//----------------------------------------------------------------------------------

void BSB_UdpListener::onIncomingData()
{
    qDebug() << "BSB_UdpListener::onIncomingData()";

    while (m_udpSocket->hasPendingDatagrams())
    {
        // prepare a buffer for the content
        QByteArray datagram;
        datagram.resize(m_udpSocket->pendingDatagramSize());

        // prepare containers for additional information
        QHostAddress sender;
        quint16 senderPort;
        m_udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        QString const inputMessage(QString::fromLatin1(datagram));

        qDebug() << "got message: " << inputMessage;
        emit signalIncomingMessage(inputMessage); // forward to mainwindow

        //! @todo add here more code for the handling of the incoming data
        if(inputMessage.contains("newGame"))
        {
            qDebug() << "ok trigger now a new game :)";
        }
        else
        {
            qDebug() << ":'("; // should be never visible!
        }
    }
}

//----------------------------------------------------------------------------------
