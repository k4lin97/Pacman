/**
 * @file multiplayergamemanager.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of multiplayergamemanager.h.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "multiplayergamemanager.h"

MultiplayerGameManager::MultiplayerGameManager(QWidget *parent) {
    gameLoseClose = false;

    // Set pacman and ghosts positions
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

    setScorePoints(0);  // 0 for main and second game

    // deduct 1, because in SecondGameManager constructor we are empting field
    // for second pacman
    maxScorePoints = map->getScorePointNumber() - 1;
}

MultiplayerGameManager::~MultiplayerGameManager() { delete loseWindow; }

QTimer *MultiplayerGameManager::getTimerGame() const { return timerGame; }

int MultiplayerGameManager::getPinkGhostPositionY() const {
    return pinkGhostPositionY;
}

void MultiplayerGameManager::setPinkGhostPositionY(int value) {
    pinkGhostPositionY = value;
}

int MultiplayerGameManager::getOtherPacmanPositionX() const {
    return otherPacmanPositionX;
}

void MultiplayerGameManager::setOtherPacmanPositionX(int value) {
    otherPacmanPositionX = value;
}

int MultiplayerGameManager::getOtherPacmanPositionY() const {
    return otherPacmanPositionY;
}

void MultiplayerGameManager::setOtherPacmanPositionY(int value) {
    otherPacmanPositionY = value;
}

int MultiplayerGameManager::getPacmanPositionX() const {
    return pacmanPositionX;
}

void MultiplayerGameManager::setPacmanPositionX(int value) {
    pacmanPositionX = value;
}

int MultiplayerGameManager::getPacmanPositionY() const {
    return pacmanPositionY;
}

void MultiplayerGameManager::setPacmanPositionY(int value) {
    pacmanPositionY = value;
}

int MultiplayerGameManager::getScorePoints() const { return scorePoints; }

void MultiplayerGameManager::setScorePoints(int value) { scorePoints = value; }

void MultiplayerGameManager::closeGame() {
    // Closes game when the player loses
    this->close();
    loseWindow = new CloseWindow(pacman->getScore(), false, this);
    loseWindow->setModal(true);
    loseWindow->exec();
}

int MultiplayerGameManager::getPinkGhostPositionX() const {
    return pinkGhostPositionX;
}

void MultiplayerGameManager::setPinkGhostPositionX(int value) {
    pinkGhostPositionX = value;
}

int MultiplayerGameManager::getBlueGhostPositionY() const {
    return blueGhostPositionY;
}

void MultiplayerGameManager::setBlueGhostPositionY(int value) {
    blueGhostPositionY = value;
}

int MultiplayerGameManager::getBlueGhostPositionX() const {
    return blueGhostPositionX;
}

void MultiplayerGameManager::setBlueGhostPositionX(int value) {
    blueGhostPositionX = value;
}

int MultiplayerGameManager::getOrangeGhostPositionY() const {
    return orangeGhostPositionY;
}

void MultiplayerGameManager::setOrangeGhostPositionY(int value) {
    orangeGhostPositionY = value;
}

int MultiplayerGameManager::getOrangeGhostPositionX() const {
    return orangeGhostPositionX;
}

void MultiplayerGameManager::setOrangeGhostPositionX(int value) {
    orangeGhostPositionX = value;
}

int MultiplayerGameManager::getRedGhostPositionY() const {
    return redGhostPositionY;
}

void MultiplayerGameManager::setRedGhostPositionY(int value) {
    redGhostPositionY = value;
}

int MultiplayerGameManager::getRedGhostPositionX() const {
    return redGhostPositionX;
}

void MultiplayerGameManager::setRedGhostPositionX(int value) {
    redGhostPositionX = value;
}

bool MultiplayerGameManager::checkWinningConditions() {
    // Check if the max score points are equall to player one and player two
    // points
    if (maxScorePoints == scorePointsReceivedFromServer) {
        return true;
    } else {
        return false;
    }
}

int MultiplayerGameManager::getEatenGhostY() const { return eatenGhostY; }

void MultiplayerGameManager::setEatenGhostY(int value) { eatenGhostY = value; }

int MultiplayerGameManager::getEatenGhostX() const { return eatenGhostX; }

void MultiplayerGameManager::setEatenGhostX(int value) { eatenGhostX = value; }

bool MultiplayerGameManager::getGhostEaten() const { return ghostEaten; }

void MultiplayerGameManager::setGhostEaten(bool value) { ghostEaten = value; }

int MultiplayerGameManager::getScorePointsReceivedFromServer() const {
    return scorePointsReceivedFromServer;
}

void MultiplayerGameManager::setScorePointsReceivedFromServer(int value) {
    scorePointsReceivedFromServer = value;
}

void MultiplayerGameManager::gameLose() {
    gameLoseClose = true;
    closeGame();
}

int MultiplayerGameManager::getGameLoseClose() const { return gameLoseClose; }

void MultiplayerGameManager::setPacmanEatenButNotDeadBool(bool value) {
    pacmanEatenButNotDeadBool = value;
}

bool MultiplayerGameManager::getPacmanEatenButNotDeadBool() const {
    return pacmanEatenButNotDeadBool;
}

void MultiplayerGameManager::pacmanEatenInSecondGame() {
    timerPacmanDeath = new QTimer(this);
    timerPacmanDeath->setSingleShot(true);

    redGhost->setX(redGhost->getFirstX());
    redGhost->setY(redGhost->getFirstY());
    redGhost->setMoveDirection(Ghost::none);

    orangeGhost->setX(orangeGhost->getFirstX());
    orangeGhost->setY(orangeGhost->getFirstY());
    orangeGhost->setMoveDirection(Ghost::none);

    blueGhost->setX(blueGhost->getFirstX());
    blueGhost->setY(blueGhost->getFirstY());
    blueGhost->setMoveDirection(Ghost::none);

    pinkGhost->setX(pinkGhost->getFirstX());
    pinkGhost->setY(pinkGhost->getFirstY());
    pinkGhost->setMoveDirection(Ghost::none);

    connect(timerPacmanDeath, SIGNAL(timeout()), this,
            SLOT(afterPacmanDeath()));
    timerPacmanDeath->start(timerPacmanDeathMiliseconds);
}

void MultiplayerGameManager::ghostEatenInSecondGame(int _x, int _y) {
    timerGhostDeath = new QTimer(this);
    timerGhostDeath->setSingleShot(true);

    if ((redGhost->getFirstX() == _x) && (redGhost->getFirstY() == _y)) {
        redGhost->setX(redGhost->getFirstX());
        redGhost->setY(redGhost->getFirstY());

        redGhost->setMoveDirection(Ghost::none);
    } else if ((orangeGhost->getFirstX() == _x) &&
               (orangeGhost->getFirstY() == _y)) {
        orangeGhost->setX(orangeGhost->getFirstX());
        orangeGhost->setY(orangeGhost->getFirstY());

        orangeGhost->setMoveDirection(Ghost::none);
    } else if ((blueGhost->getFirstX() == _x) &&
               (blueGhost->getFirstY() == _y)) {
        blueGhost->setX(blueGhost->getFirstX());
        blueGhost->setY(blueGhost->getFirstY());

        blueGhost->setMoveDirection(Ghost::none);
    } else if ((pinkGhost->getFirstX() == _x) &&
               (pinkGhost->getFirstY() == _y)) {
        pinkGhost->setX(pinkGhost->getFirstX());
        pinkGhost->setY(pinkGhost->getFirstY());

        pinkGhost->setMoveDirection(Ghost::none);
    }

    connect(timerGhostDeath, SIGNAL(timeout()), this, SLOT(afterGhostDeath()));
    timerGhostDeath->start(timerGhostDeathMiliseconds);
}
