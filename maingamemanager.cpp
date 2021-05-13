#include "maingamemanager.h"

#include <QDebug>

MainGameManager::MainGameManager(QWidget *parent)
{
    setOtherPacmanPositionX(pacman->getX() + 1);
    setOtherPacmanPositionY(pacman->getY());
}

void MainGameManager::gameEngine()
{
    if (!getIsGamePaused()) {
        if (MultiplayerGameManager::checkWinningConditions()) {
            gameWin();
        } else {
            pacman->checkWalls(map);
            pacman->move(map);

            setScorePoints(pacman->getScore());

            red_ghost->checkWalls(map);
            red_ghost->calculateTarget(pacman);
            red_ghost->move();

            pink_ghost->checkWalls(map);
            pink_ghost->calculateTarget(pacman);
            pink_ghost->move();

            orange_ghost->checkWalls(map);
            orange_ghost->calculateTarget(pacman);
            orange_ghost->move();

            blue_ghost->checkWalls(map);
            blue_ghost->calculateTarget(pacman);
            blue_ghost->move();

            ghostPlayerInteraction();
        }
    } else {
        //ingore
    }

    setRedGhostPositionX(red_ghost->getX());
    setRedGhostPositionY(red_ghost->getY());

    setOrangeGhostPositionX(orange_ghost->getX());
    setOrangeGhostPositionY(orange_ghost->getY());

    setBlueGhostPositionX(blue_ghost->getX());
    setBlueGhostPositionY(blue_ghost->getY());

    setPinkGhostPositionX(pink_ghost->getX());
    setPinkGhostPositionY(pink_ghost->getY());

    setPacmanPositionX(pacman->getX());
    setPacmanPositionY(pacman->getY());

    map->setMapAtPosition(getOtherPacmanPositionX(), getOtherPacmanPositionY(), Map::none);

    game_drawer->drawMap(mapPixmap, map);
    game_drawer->drawPlayer(mapPixmap, pacman);
    game_drawer->drawRedGhost(mapPixmap, red_ghost);
    game_drawer->drawPinkGhost(mapPixmap, pink_ghost);
    game_drawer->drawOrangeGhost(mapPixmap, orange_ghost);
    game_drawer->drawBlueGhost(mapPixmap, blue_ghost);

    game_drawer->drawOtherPacman(mapPixmap, getOtherPacmanPositionX(), getOtherPacmanPositionY());

    map_label->setPixmap(*mapPixmap);
    score_label->setText("Score: " + QString::number(pacman->getScore()));
    health_label->setText("Health: " + QString::number(pacman->getHealth()));
    QString timerText = timer_stage->remainingTime() == -1 ? QString::number(timer_stage_miliseconds) : QString::number(timer_stage->remainingTime());
    timer_stage_label->setText("Change stage in: " + timerText);
    QString boolText = getIsGamePaused() ? "Paused" : "Playing";
    game_playing_label->setText(boolText);
}

