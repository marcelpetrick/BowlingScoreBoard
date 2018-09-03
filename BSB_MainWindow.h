#pragma once

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

private:
    Ui::BSB_MainWindow *ui;
};

