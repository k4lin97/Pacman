#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>

#include "pacman.h"
#include "redghost.h"
#include "blueghost.h"
#include "orangeghost.h"
#include "pinkghost.h"
#include "map.h"
#include "gamedrawer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameManager; }
QT_END_NAMESPACE

class GameManager : public QMainWindow
{
    Q_OBJECT

public:
    GameManager(QWidget *parent = nullptr);
    ~GameManager();

    void keyPressEvent(QKeyEvent *event);

    bool getIsGamePaused() const;
    void setIsGamePaused(bool value);

private slots:
    void gameEngine();
    void changeGhostsStage();

    void afterRedGhostDeath();
    void afterBlueGhostDeath();
    void afterOrangeGhostDeath();
    void afterPinkGhostDeath();
    void afterPacmanDeath();

private:
    Ui::GameManager *ui;

    bool isGamePaused;

    const int timer_ghost_death_miliseconds;
    const int timer_pacman_death_miliseconds;
    int timer_stage_miliseconds;

    Map *map;
    GameDrawer *game_drawer;

    Pacman *pacman;
    Ghost *red_ghost;
    Ghost *pink_ghost;
    Ghost *orange_ghost;
    Ghost * blue_ghost;

    QTimer *timer_game;
    QTimer *timer_stage;
    QTimer *timer_ghost_death;
    QTimer *timer_pacman_death;

    QPixmap *mapPixmap;

    QLabel *map_label;
    QLabel *score_label;
    QLabel *health_label;
    QLabel *timer_stage_label;
    QLabel *game_playing_label;

    void ghostPlayerInteraction();
    void gameLose();
    void gameWin();

    bool checkWinningConditions();
};
#endif // GAMEMANAGER_H