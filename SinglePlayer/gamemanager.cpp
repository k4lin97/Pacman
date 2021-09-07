/**
 * @file gamemanager.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of gamemanager.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "gamemanager.h"
#include "ui_gamemanager.h"

GameManager::GameManager(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::GameManager),
      timerGameMiliseconds(200),
      timerGhostDeathMiliseconds(5000),
      timerPacmanDeathMiliseconds(2000),
      timerStageMiliseconds(5000) {
    ui->setupUi(this);

    // Create game objects
    map = new Map();
    gameDrawer = new GameDrawer();

    pacman = new Pacman();
    redGhost = new RedGhost();
    pinkGhost = new PinkGhost();
    orangeGhost = new OrangeGhost();
    blueGhost = new BlueGhost();

    // Visualize
    this->setWindowTitle("Pacman");
    this->setFixedSize(
        map->getMapWidth() * gameDrawer->getDrawingScale(),
        map->getMapHeight() * gameDrawer->getDrawingScale() + 100);

    mapLabel = new QLabel(this);
    mapLabel->setGeometry(0, 100,
                          map->getMapWidth() * gameDrawer->getDrawingScale(),
                          map->getMapHeight() * gameDrawer->getDrawingScale());

    scoreLabel = new QLabel(this);
    scoreLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    scoreLabel->setAlignment(Qt::AlignCenter);
    scoreLabel->setGeometry(55, 50, 150, 20);

    healthLabel = new QLabel(this);
    healthLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    healthLabel->setAlignment(Qt::AlignCenter);
    healthLabel->setGeometry(205, 50, 150, 20);

    timerStageLabel = new QLabel(this);
    timerStageLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    timerStageLabel->setAlignment(Qt::AlignCenter);
    timerStageLabel->setGeometry(355, 50, 150, 20);

    gamePlayingLabel = new QLabel(this);
    gamePlayingLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    gamePlayingLabel->setAlignment(Qt::AlignCenter);
    gamePlayingLabel->setGeometry(205, 30, 150, 20);

    mapPixmap =
        new QPixmap(map->getMapWidth() * gameDrawer->getDrawingScale(),
                    map->getMapHeight() * gameDrawer->getDrawingScale());

    // Connect timers
    timerGame = new QTimer(this);
    connect(timerGame, SIGNAL(timeout()), this, SLOT(gameEngine()));
    timerGame->start(timerGameMiliseconds);

    timerStage = new QTimer(this);
    connect(timerStage, SIGNAL(timeout()), this, SLOT(changeGhostsStage()));
    timerStage->start(timerStageMiliseconds);

    setIsGamePaused(true);
}

GameManager::~GameManager() {
    delete ui;

    delete map;
    delete gameDrawer;

    delete pacman;
    delete redGhost;
    delete pinkGhost;
    delete orangeGhost;
    delete blueGhost;

    delete closeWindow;
}

void GameManager::keyPressEvent(QKeyEvent *event) {
    // Check as in pacman.cpp - but because of that pacman does not stop
    // when player wants to move into a wall
    if (event->key() == Qt::Key_Left) {
        if (map->getMapAtPosition(pacman->getX() - 1, pacman->getY()) !=
            Map::wall) {
            pacman->setMoveDirection(Player::left);
        }
    } else if (event->key() == Qt::Key_Right) {
        if (map->getMapAtPosition(pacman->getX() + 1, pacman->getY()) !=
            Map::wall) {
            pacman->setMoveDirection(Player::right);
        }
    } else if (event->key() == Qt::Key_Up) {
        if (map->getMapAtPosition(pacman->getX(), pacman->getY() - 1) !=
            Map::wall) {
            pacman->setMoveDirection(Player::up);
        }
    } else if (event->key() == Qt::Key_Down) {
        if (map->getMapAtPosition(pacman->getX(), pacman->getY() + 1) !=
            Map::wall) {
            pacman->setMoveDirection(Player::down);
        }
    } else if (event->key() == Qt::Key_Space) {
        if (getIsGamePaused()) {
            setIsGamePaused(false);
        } else {
            setIsGamePaused(true);
        }
    }
}

bool GameManager::getIsGamePaused() const { return isGamePaused; }

void GameManager::setIsGamePaused(bool value) { isGamePaused = value; }

void GameManager::gameEngine() {
    if (!getIsGamePaused()) {
        if (checkWinningConditions()) {
            gameWin();
        } else {
            // Move pacman
            pacman->checkWalls(map);
            pacman->move(map);

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

            // Interaction
            ghostPlayerInteraction();
        }
    } else {
        // Nothing because game is paused
    }

    // Draw game
    gameDrawer->drawMap(mapPixmap, map);
    gameDrawer->drawPlayer(mapPixmap, pacman);
    gameDrawer->drawRedGhost(mapPixmap, redGhost);
    gameDrawer->drawPinkGhost(mapPixmap, pinkGhost);
    gameDrawer->drawOrangeGhost(mapPixmap, orangeGhost);
    gameDrawer->drawBlueGhost(mapPixmap, blueGhost);

    // Set labels
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

void GameManager::changeGhostsStage() {
    redGhost->changeStage();
    blueGhost->changeStage();
    orangeGhost->changeStage();
    pinkGhost->changeStage();
}

void GameManager::afterGhostDeath() {
    if (redGhost->getMoveDirection() == Player::none) {
        redGhost->setMoveDirection(Player::left);
    } else if (blueGhost->getMoveDirection() == Player::none) {
        blueGhost->setMoveDirection(Player::down);
    } else if (orangeGhost->getMoveDirection() == Player::none) {
        orangeGhost->setMoveDirection(Player::down);
    } else if (pinkGhost->getMoveDirection() == Player::none) {
        pinkGhost->setMoveDirection(Player::right);
    }
}

void GameManager::afterPacmanDeath() {
    redGhost->setMoveDirection(Player::left);
    blueGhost->setMoveDirection(Player::down);
    orangeGhost->setMoveDirection(Player::down);
    pinkGhost->setMoveDirection(Player::right);
}

void GameManager::ghostPlayerInteraction() {
    // Pacman interaction with every ghost
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

void GameManager::gameLose() {
    this->close();
    closeWindow = new CloseWindow(pacman->getScore(), false, this);
    closeWindow->setModal(true);
    closeWindow->exec();
}

void GameManager::gameWin() {
    this->close();
    closeWindow = new CloseWindow(pacman->getScore(), true, this);
    closeWindow->setModal(true);
    closeWindow->exec();
}

bool GameManager::checkWinningConditions() {
    if (map->getScorePointNumber() == 0) {
        return true;
    } else {
        return false;
    }
}

void GameManager::pacmanEatenButNotDead() {
    timerPacmanDeath = new QTimer(this);
    timerPacmanDeath->setSingleShot(true);

    // Adjust pacman
    pacman->setHealth(pacman->getHealth() - 1);
    pacman->setX(pacman->getFirstX());
    pacman->setY(pacman->getFirstY());
    pacman->setMoveDirection(Player::none);

    // Adjust ghosts
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

    // Start timer
    connect(timerPacmanDeath, SIGNAL(timeout()), this,
            SLOT(afterPacmanDeath()));
    timerPacmanDeath->start(timerPacmanDeathMiliseconds);
}

void GameManager::pacmanEatsGhost(Ghost *ghost) {
    timerGhostDeath = new QTimer(this);
    timerGhostDeath->setSingleShot(true);

    // Adjust eaten ghost
    ghost->setX(ghost->getFirstX());
    ghost->setY(ghost->getFirstY());

    ghost->setMoveDirection(Ghost::none);
    pacman->setCanEat(false);

    // Start timer
    connect(timerGhostDeath, SIGNAL(timeout()), this, SLOT(afterGhostDeath()));
    timerGhostDeath->start(timerGhostDeathMiliseconds);
}
