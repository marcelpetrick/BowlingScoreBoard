
// own includes
#include "BSB_MainWindow.h"
#include "BSB_UdpListener.h" // just for testing

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // todo make unique; position somehwere else
    //! todo currently a leak until "end of program"
    //BSB_UdpListener* m_udpListener = new BSB_UdpListener("192.168.1.1", 6543, nullptr);
    BSB_UdpListener* m_udpListener = new BSB_UdpListener("localhost", 6543, nullptr);


    BSB_MainWindow w;
    w.show();
    int const result = a.exec();

    return result;
}
