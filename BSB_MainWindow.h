#pragma once

#include "BSB_UdpListener.h" // just for testing

#include <QMainWindow>

namespace Ui {
class BSB_MainWindow;
class BSB_GameStepWidget; // element for the "turns"
}

class BSB_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BSB_MainWindow(QWidget *parent = nullptr);
    ~BSB_MainWindow();

public slots:
    void slotFake(QString const message);

private:
    Ui::BSB_MainWindow *ui;

    BSB_UdpListener* m_udpListener;
};

