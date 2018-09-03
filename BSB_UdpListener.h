#pragma once

// own includes

// std includes
#include <memory>

// Qt includes
#include <QtCore/QObject>
#include <QtNetwork/QUdpSocket>

class BSB_UdpListener : public QObject
{
    Q_OBJECT

public:
    explicit BSB_UdpListener(QString const receiverInterface, quint32 receiverPort, QObject* parent = nullptr);

signals:
    //! @todo add some other signals which are then relayed to the logic
    void signalIncomingCall(QString const message);

private slots:
    //! In case the readRead-signal is fired, handle the data. Means: fetch all incoming datagrams.
    void onIncomingData();

private:
    //!
    std::unique_ptr<QUdpSocket> m_udpSocket;

};
