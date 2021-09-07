/**
 * @file secondgamemanager.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of secondgamemanager.h.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "secondgamemanager.h"

SecondGameManager::SecondGameManager(QWidget *parent) {
    // New pacman in second game
    pacman = new Pacman(14, 23);

    pacman->setX(pacman->getFirstX());
    pacman->setY(pacman->getFirstY());

    // Set position of pacman from main game
    setOtherPacmanPositionX(pacman->getX() - 1);
    setOtherPacmanPositionY(pacman->getY());

    map->setMapAtPosition(14, 23, Map::none);

    setPacmanEatenButNotDeadBool(false);
    setGhostEaten(false);
}

SecondGameManager::~SecondGameManager() {
    // Empty on purpose
}

void SecondGameManager::gameEngine() {
    if (!getIsGamePaused()) {
        if (MultiplayerGameManager::checkWinningConditions()) {
            gameWin();
        } else {
            // Move pacman
            pacman->checkWalls(map);
            pacman->move(map);

            setScorePoints(pacman->getScore());

            // Set ghosts position from main game
            redGhost->setX(getRedGhostPositionX());
            redGhost->setY(getRedGhostPositionY());

            orangeGhost->setX(getOrangeGhostPositionX());
            orangeGhost->setY(getOrangeGhostPositionY());

            blueGhost->setX(getBlueGhostPositionX());
            blueGhost->setY(getBlueGhostPositionY());

            pinkGhost->setX(getPinkGhostPositionX());
            pinkGhost->setY(getPinkGhostPositionY());

            ghostPlayerInteraction();
        }
    } else {
        // Ignore
    }

    setPacmanPositionX(pacman->getX());
    setPacmanPositionY(pacman->getY());

    // Only to visualize, max score points is being calculated by server
    map->setMapAtPosition(getOtherPacmanPositionX(), getOtherPacmanPositionY(),
                          Map::none);

    // Draw game
    gameDrawer->drawMap(mapPixmap, map);
    gameDrawer->drawPlayer(mapPixmap, pacman);
    gameDrawer->drawRedGhost(mapPixmap, redGhost);
    gameDrawer->drawPinkGhost(mapPixmap, pinkGhost);
    gameDrawer->drawOrangeGhost(mapPixmap, orangeGhost);
    gameDrawer->drawBlueGhost(mapPixmap, blueGhost);

    gameDrawer->drawOtherPacman(mapPixmap, getOtherPacmanPositionX(),
                                getOtherPacmanPositionY());

    mapLabel->setPixmap(*mapPixmap);
    scoreLabel->setText("Score: " + QString::number(pacman->getScore()));
    healthLabel->setText("Health: " + QString::number(pacman->getHealth()));
    QString timerText = timerStage->remainingTime() == -1
                            ? QString::number(timerStageMiliseconds)
                            : QString::number(timerStage->remainingTime());
    timerStageLabel->setText("Change stage in: " + timerText);
    QString boolText = getIsGamePaused() ? "Paused" : "Playing";
    gamePlayingLabel->setText(boolText);
}

void SecondGameManager::ghostPlayerInteraction() {
        if ((redGhost->getX() == pacman->getX()) &&
        (redGhost->getY() == pacman->getY())) {
        if (pacman->getCanEat()) {
            pacmanEatsGhost(redGhost);
        } else {
            if (pacman->getHealth() > 1) {
                pacmanEatenButNotDead();
            } else {
                gameLose();
            }
        }
    } else if ((orangeGhost->getX() == pacman->getX()) &&
               (orangeGhost->getY() == pacman->getY())) {
        if (pacman->getCanEat()) {
            pacmanEatsGhost(orangeGhost);
        } else {
            if (pacman->getHealth() > 1) {
                pacmanEatenButNotDead();
            } else {
                gameLose();
            }
        }
    } else if ((blueGhost->getX() == pacman->getX()) &&
               (blueGhost->getY() == pacman->getY())) {
        if (pacman->getCanEat()) {
            pacmanEatsGhost(blueGhost);
        } else {
            if (pacman->getHealth() > 1) {
                pacmanEatenButNotDead();
            } else {
                gameLose();
            }
        }
    } else if ((pinkGhost->getX() == pacman->getX()) &&
               (pinkGhost->getY() == pacman->getY())) {
        if (pacman->getCanEat()) {
            pacmanEatsGhost(pinkGhost);
        } else {
            if (pacman->getHealth() > 1) {
                pacmanEatenButNotDead();
            } else {
                gameLose();
            }
        }
    }
}

void SecondGameManager::pacmanEatenButNotDead() {
    setPacmanEatenButNotDeadBool(true);

    pacman->setHealth(pacman->getHealth() - 1);
    pacman->setX(pacman->getFirstX());
    pacman->setY(pacman->getFirstY());
    pacman->setMoveDirection(Player::none);

    setPacmanPositionX(pacman->getX());
    setPacmanPositionY(pacman->getY());
}

void SecondGameManager::pacmanEatsGhost(Ghost *ghost) {
    pacman->setCanEat(false);

    setEatenGhostX(ghost->getFirstX());
    setEatenGhostY(ghost->getFirstY());

    setGhostEaten(true);
}
