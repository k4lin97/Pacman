/**
 * @file maingamemanager.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of maingamemanager.h.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "maingamemanager.h"

MainGameManager::MainGameManager(QWidget *parent) {
    // Set position of second pacman
    setOtherPacmanPositionX(pacman->getX() + 1);
    setOtherPacmanPositionY(pacman->getY());
}

MainGameManager::~MainGameManager() {
    // Empty on purpose
}

void MainGameManager::gameEngine() {
    if (!getIsGamePaused()) {
        // Winning condition are slightly different in multiplayer
        if (MultiplayerGameManager::checkWinningConditions()) {
            // Check if player wins game
            gameWin();
        } else {
            // Move pacman
            pacman->checkWalls(map);
            pacman->move(map);

            // Set score points
            setScorePoints(pacman->getScore());

            // Move ghosts
            redGhost->checkWalls(map);
            redGhost->calculateTarget(pacman);
            redGhost->move();

            pinkGhost->checkWalls(map);
            pinkGhost->calculateTarget(pacman);
            pinkGhost->move();

            orangeGhost->checkWalls(map);
            orangeGhost->calculateTarget(pacman);
            orangeGhost->move();

            blueGhost->checkWalls(map);
            blueGhost->calculateTarget(pacman);
            blueGhost->move();

            // Check ghosts and player interaction
            ghostPlayerInteraction();
        }
    } else {
        // Ignore
    }

    // Set positions - this data is being sent to second game
    setRedGhostPositionX(redGhost->getX());
    setRedGhostPositionY(redGhost->getY());

    setOrangeGhostPositionX(orangeGhost->getX());
    setOrangeGhostPositionY(orangeGhost->getY());

    setBlueGhostPositionX(blueGhost->getX());
    setBlueGhostPositionY(blueGhost->getY());

    setPinkGhostPositionX(pinkGhost->getX());
    setPinkGhostPositionY(pinkGhost->getY());

    setPacmanPositionX(pacman->getX());
    setPacmanPositionY(pacman->getY());

    // Adjust map where second pacman goes
    map->setMapAtPosition(getOtherPacmanPositionX(), getOtherPacmanPositionY(),
                          Map::none);

    // Draw map
    gameDrawer->drawMap(mapPixmap, map);
    gameDrawer->drawPlayer(mapPixmap, pacman);
    gameDrawer->drawRedGhost(mapPixmap, redGhost);
    gameDrawer->drawPinkGhost(mapPixmap, pinkGhost);
    gameDrawer->drawOrangeGhost(mapPixmap, orangeGhost);
    gameDrawer->drawBlueGhost(mapPixmap, blueGhost);

    gameDrawer->drawOtherPacman(mapPixmap, getOtherPacmanPositionX(),
                                getOtherPacmanPositionY());

    // Adjust labels
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
