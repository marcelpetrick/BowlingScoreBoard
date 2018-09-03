#include "BSB_MainWindow.h"
#include "ui_BSB_MainWindow.h"

BSB_MainWindow::BSB_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BSB_MainWindow)
{
    ui->setupUi(this);

    // testwise create some items and add them to the widget
    //GameStepWidget* step = new GameStepWidget();
    //ui->verticalLayout_f1->addItem(step);
}

BSB_MainWindow::~BSB_MainWindow()
{
    delete ui;
}
