#ifndef SCOREBOARDMAINWINDOW_H
#define SCOREBOARDMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ScoreboardMainWindow;
class GameStepWidget; // element for the "turns"
}

class ScoreboardMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScoreboardMainWindow(QWidget *parent = nullptr);
    ~ScoreboardMainWindow();

private:
    Ui::ScoreboardMainWindow *ui;
};

#endif // SCOREBOARDMAINWINDOW_H
