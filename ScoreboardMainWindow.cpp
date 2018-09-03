#include "ScoreboardMainWindow.h"
#include "ui_scoreboardmainwindow.h"

ScoreboardMainWindow::ScoreboardMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreboardMainWindow)
{
    ui->setupUi(this);

    // testwise create some items and add them to the widget
    GameStepWidget* step = new GameStepWidget();
    ui->verticalLayout_f1->addItem(step);
}

ScoreboardMainWindow::~ScoreboardMainWindow()
{
    delete ui;
}
