#include "multiplayergamemanager.h"

#include <QDebug>

MultiplayerGameManager::MultiplayerGameManager(QWidget *parent)
{
    gameLoseClose = 0; // 0 - false
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

    scorePoints = 0;
    maxScorePoints = map->getScore_point_number();
}

MultiplayerGameManager::~MultiplayerGameManager()
{
    //delete lose_window;
}

QTimer *MultiplayerGameManager::getTimer_game() const
{
    return timer_game;
}

int MultiplayerGameManager::getPinkGhostPositionY() const
{
    return pinkGhostPositionY;
}

void MultiplayerGameManager::setPinkGhostPositionY(int value)
{
    pinkGhostPositionY = value;
}

int MultiplayerGameManager::getOtherPacmanPositionX() const
{
    return otherPacmanPositionX;
}

void MultiplayerGameManager::setOtherPacmanPositionX(int value)
{
    otherPacmanPositionX = value;
}

int MultiplayerGameManager::getOtherPacmanPositionY() const
{
    return otherPacmanPositionY;
}

void MultiplayerGameManager::setOtherPacmanPositionY(int value)
{
    otherPacmanPositionY = value;
}

int MultiplayerGameManager::getPacmanPositionX() const
{
    return pacmanPositionX;
}

void MultiplayerGameManager::setPacmanPositionX(int value)
{
    pacmanPositionX = value;
}

int MultiplayerGameManager::getPacmanPositionY() const
{
    return pacmanPositionY;
}

void MultiplayerGameManager::setPacmanPositionY(int value)
{
    pacmanPositionY = value;
}

int MultiplayerGameManager::getScorePoints() const
{
    return scorePoints;
}

void MultiplayerGameManager::setScorePoints(int value)
{
    scorePoints = value;
}

void MultiplayerGameManager::closeGame()
{
    this->close();
    lose_window = new CloseWindow(pacman->getScore(), false, this);
    lose_window->setModal(true);
    lose_window->exec();
}

int MultiplayerGameManager::getPinkGhostPositionX() const
{
    return pinkGhostPositionX;
}

void MultiplayerGameManager::setPinkGhostPositionX(int value)
{
    pinkGhostPositionX = value;
}

int MultiplayerGameManager::getBlueGhostPositionY() const
{
    return blueGhostPositionY;
}

void MultiplayerGameManager::setBlueGhostPositionY(int value)
{
    blueGhostPositionY = value;
}

int MultiplayerGameManager::getBlueGhostPositionX() const
{
    return blueGhostPositionX;
}

void MultiplayerGameManager::setBlueGhostPositionX(int value)
{
    blueGhostPositionX = value;
}

int MultiplayerGameManager::getOrangeGhostPositionY() const
{
    return orangeGhostPositionY;
}

void MultiplayerGameManager::setOrangeGhostPositionY(int value)
{
    orangeGhostPositionY = value;
}

int MultiplayerGameManager::getOrangeGhostPositionX() const
{
    return orangeGhostPositionX;
}

void MultiplayerGameManager::setOrangeGhostPositionX(int value)
{
    orangeGhostPositionX = value;
}

int MultiplayerGameManager::getRedGhostPositionY() const
{
    return redGhostPositionY;
}

void MultiplayerGameManager::setRedGhostPositionY(int value)
{
    redGhostPositionY = value;
}

int MultiplayerGameManager::getRedGhostPositionX() const
{
    return redGhostPositionX;
}

void MultiplayerGameManager::setRedGhostPositionX(int value)
{
    redGhostPositionX = value;
}

bool MultiplayerGameManager::checkWinningConditions()
{
    if (maxScorePoints == scorePoints) {
        return true;
    } else {
        return false;
    }
}

void MultiplayerGameManager::gameLose()
{
   gameLoseClose = 1; // 1 - true
}

int MultiplayerGameManager::getGameLoseClose() const
{
    return gameLoseClose;
}

