#include "ScoreboardMainWindow.h"
#include "ui_scoreboardmainwindow.h"

ScoreboardMainWindow::ScoreboardMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreboardMainWindow)
{
    ui->setupUi(this);
}

ScoreboardMainWindow::~ScoreboardMainWindow()
{
    delete ui;
}
