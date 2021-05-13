#include "gamemanager.h"
#include "ui_gamemanager.h"

GameManager::GameManager(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameManager)
    , timer_ghost_death_miliseconds(5000)
    , timer_pacman_death_miliseconds(2000)
{
    ui->setupUi(this);    
    this->setAttribute(Qt::WA_DeleteOnClose);

    map = new Map();
    game_drawer = new GameDrawer();

    pacman = new Pacman();
    red_ghost = new RedGhost();
    pink_ghost = new PinkGhost();
    orange_ghost = new OrangeGhost();
    blue_ghost = new BlueGhost();

    this->setWindowTitle("Pacman");
    this->setFixedSize(map->getMap_width() * game_drawer->getDrawing_scale(), map->getMap_height() * game_drawer->getDrawing_scale() + 100);

    map_label = new QLabel(this);
    map_label->setGeometry(0, 100, map->getMap_width() * 20, map->getMap_height() * 20);

    score_label = new QLabel(this);
    score_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    score_label->setAlignment(Qt::AlignCenter);
    score_label->setGeometry(55, 50, 150, 20);

    health_label = new QLabel(this);
    health_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    health_label->setAlignment(Qt::AlignCenter);
    health_label->setGeometry(205, 50, 150, 20);

    timer_stage_label = new QLabel(this);
    timer_stage_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    timer_stage_label->setAlignment(Qt::AlignCenter);
    timer_stage_label->setGeometry(355, 50, 150, 20);

    game_playing_label = new QLabel(this);
    game_playing_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    game_playing_label->setAlignment(Qt::AlignCenter);
    game_playing_label->setGeometry(205, 30, 150, 20);

    mapPixmap = new QPixmap(map->getMap_width() * game_drawer->getDrawing_scale(), map->getMap_height() * game_drawer->getDrawing_scale());

    timer_ghost_death = new QTimer(this);
    timer_ghost_death->setSingleShot(true);

    timer_pacman_death = new QTimer(this);
    timer_pacman_death->setSingleShot(true);

    timer_game = new QTimer(this);
    connect(timer_game, SIGNAL(timeout()), this, SLOT(gameEngine()));
    timer_game->start(200);

    timer_stage_miliseconds = 5000;
    timer_stage = new QTimer(this);
    connect(timer_stage, SIGNAL(timeout()), this, SLOT(changeGhostsStage()));
    timer_stage->start(timer_stage_miliseconds);

    setIsGamePaused(true);
}

GameManager::~GameManager()
{
    delete ui;

    delete map;
    delete game_drawer;

    delete timer_game;
    delete timer_stage;
    delete timer_ghost_death;
    delete timer_pacman_death;

    delete mapPixmap;

    delete map_label;
    delete score_label;
    delete health_label;
    delete timer_stage_label;
    delete game_playing_label;
}

void GameManager::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (map->getMapAtPosition(pacman->getX() - 1, pacman->getY()) != Map::wall) {
            pacman->setMove_direction(Player::left);
        }
    } else if (event->key() == Qt::Key_Right) {
        if (map->getMapAtPosition(pacman->getX() + 1, pacman->getY()) != Map::wall) {
            pacman->setMove_direction(Player::right);
        }
    } else if (event->key() == Qt::Key_Up) {
        if (map->getMapAtPosition(pacman->getX(), pacman->getY() - 1) != Map::wall) {
            pacman->setMove_direction(Player::up);
        }
    } else if (event->key() == Qt::Key_Down) {
        if (map->getMapAtPosition(pacman->getX(), pacman->getY() + 1) != Map::wall) {
            pacman->setMove_direction(Player::down);
        }
    } else if (event->key() == Qt::Key_Space) {
        if (getIsGamePaused()) {
            setIsGamePaused(false);
        } else {
            setIsGamePaused(true);
        }
    }
}

bool GameManager::getIsGamePaused() const
{
    return isGamePaused;
}

void GameManager::setIsGamePaused(bool value)
{
    isGamePaused = value;
}

void GameManager::gameEngine()
{
    if (!getIsGamePaused()) {
        if (checkWinningConditions()) {
            gameWin();
        } else {
            pacman->checkWalls(map);
            pacman->move(map);

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

    game_drawer->drawMap(mapPixmap, map);
    game_drawer->drawPlayer(mapPixmap, pacman);
    game_drawer->drawRedGhost(mapPixmap, red_ghost);
    game_drawer->drawPinkGhost(mapPixmap, pink_ghost);
    game_drawer->drawOrangeGhost(mapPixmap, orange_ghost);
    game_drawer->drawBlueGhost(mapPixmap, blue_ghost);

    map_label->setPixmap(*mapPixmap);
    score_label->setText("Score: " + QString::number(pacman->getScore()));
    health_label->setText("Health: " + QString::number(pacman->getHealth()));
    QString timerText = timer_stage->remainingTime() == -1 ? QString::number(timer_stage_miliseconds) : QString::number(timer_stage->remainingTime());
    timer_stage_label->setText("Change stage in: " + timerText);
    QString boolText = getIsGamePaused() ? "Paused" : "Playing";
    game_playing_label->setText(boolText);
}

void GameManager::changeGhostsStage()
{
    red_ghost->changeStage();
    blue_ghost->changeStage();
    orange_ghost->changeStage();
    pink_ghost->changeStage();
}

void GameManager::afterRedGhostDeath()
{
    red_ghost->setMove_direction(Player::left);
}

void GameManager::afterBlueGhostDeath()
{
    blue_ghost->setMove_direction(Player::down);
}

void GameManager::afterOrangeGhostDeath()
{
    orange_ghost->setMove_direction(Player::down);
}

void GameManager::afterPinkGhostDeath()
{
    pink_ghost->setMove_direction(Player::right);
}

void GameManager::afterPacmanDeath()
{
    red_ghost->setMove_direction(Player::left);
    blue_ghost->setMove_direction(Player::down);
    orange_ghost->setMove_direction(Player::down);
    pink_ghost->setMove_direction(Player::right);
}

void GameManager::ghostPlayerInteraction()
{
    if ((red_ghost->getX() == pacman->getX()) && (red_ghost->getY() == pacman->getY())) {
        if (pacman->getCan_eat()) {
            red_ghost->setX(red_ghost->getFirst_x());
            red_ghost->setY(red_ghost->getFirst_y());

            red_ghost->setMove_direction(Ghost::none);
            pacman->setCan_eat(false);

            connect(timer_ghost_death, SIGNAL(timeout()), this, SLOT(afterRedGhostDeath()));
            timer_ghost_death->start(timer_ghost_death_miliseconds);
        } else {
            if (pacman->getHealth() > 1) {
                pacman->setHealth(pacman->getHealth() - 1);
                pacman->setX(pacman->getFirst_x());
                pacman->setY(pacman->getFirst_y());
                pacman->setMove_direction(Player::none);

                red_ghost->setX(red_ghost->getFirst_x());
                red_ghost->setY(red_ghost->getFirst_y());
                red_ghost->setMove_direction(Ghost::none);

                orange_ghost->setX(orange_ghost->getFirst_x());
                orange_ghost->setY(orange_ghost->getFirst_y());
                orange_ghost->setMove_direction(Ghost::none);

                blue_ghost->setX(blue_ghost->getFirst_x());
                blue_ghost->setY(blue_ghost->getFirst_y());
                blue_ghost->setMove_direction(Ghost::none);

                pink_ghost->setX(pink_ghost->getFirst_x());
                pink_ghost->setY(pink_ghost->getFirst_y());
                pink_ghost->setMove_direction(Ghost::none);

                connect(timer_pacman_death, SIGNAL(timeout()), this, SLOT(afterPacmanDeath()));
                timer_pacman_death->start(timer_pacman_death_miliseconds);
            } else {
                gameLose();
            }
        }
    } else if ((orange_ghost->getX() == pacman->getX()) && (orange_ghost->getY() == pacman->getY())) {
        if (pacman->getCan_eat()) {
            orange_ghost->setX(orange_ghost->getFirst_x());
            orange_ghost->setY(orange_ghost->getFirst_y());

            orange_ghost->setMove_direction(Ghost::none);
            pacman->setCan_eat(false);

            connect(timer_ghost_death, SIGNAL(timeout()), this, SLOT(afterOrangeGhostDeath()));
            timer_ghost_death->start(timer_ghost_death_miliseconds);
        } else {
            if (pacman->getHealth() > 1) {
                pacman->setHealth(pacman->getHealth() - 1);
                pacman->setX(pacman->getFirst_x());
                pacman->setY(pacman->getFirst_y());
                pacman->setMove_direction(Player::none);

                red_ghost->setX(red_ghost->getFirst_x());
                red_ghost->setY(red_ghost->getFirst_y());
                red_ghost->setMove_direction(Ghost::none);

                orange_ghost->setX(orange_ghost->getFirst_x());
                orange_ghost->setY(orange_ghost->getFirst_y());
                orange_ghost->setMove_direction(Ghost::none);

                blue_ghost->setX(blue_ghost->getFirst_x());
                blue_ghost->setY(blue_ghost->getFirst_y());
                blue_ghost->setMove_direction(Ghost::none);

                pink_ghost->setX(pink_ghost->getFirst_x());
                pink_ghost->setY(pink_ghost->getFirst_y());
                pink_ghost->setMove_direction(Ghost::none);

                connect(timer_pacman_death, SIGNAL(timeout()), this, SLOT(afterPacmanDeath()));
                timer_pacman_death->start(timer_pacman_death_miliseconds);
            } else {
                gameLose();
            }
        }
    } else if ((blue_ghost->getX() == pacman->getX()) && (blue_ghost->getY() == pacman->getY())) {
        if (pacman->getCan_eat()) {
            blue_ghost->setX(blue_ghost->getFirst_x());
            blue_ghost->setY(blue_ghost->getFirst_y());

            blue_ghost->setMove_direction(Ghost::none);
            pacman->setCan_eat(false);

            connect(timer_ghost_death, SIGNAL(timeout()), this, SLOT(afterBlueGhostDeath()));
            timer_ghost_death->start(timer_ghost_death_miliseconds);
        } else {
            if (pacman->getHealth() > 1) {
                pacman->setHealth(pacman->getHealth() - 1);
                pacman->setX(pacman->getFirst_x());
                pacman->setY(pacman->getFirst_y());
                pacman->setMove_direction(Player::none);

                red_ghost->setX(red_ghost->getFirst_x());
                red_ghost->setY(red_ghost->getFirst_y());
                red_ghost->setMove_direction(Ghost::none);

                orange_ghost->setX(orange_ghost->getFirst_x());
                orange_ghost->setY(orange_ghost->getFirst_y());
                orange_ghost->setMove_direction(Ghost::none);

                blue_ghost->setX(blue_ghost->getFirst_x());
                blue_ghost->setY(blue_ghost->getFirst_y());
                blue_ghost->setMove_direction(Ghost::none);

                pink_ghost->setX(pink_ghost->getFirst_x());
                pink_ghost->setY(pink_ghost->getFirst_y());
                pink_ghost->setMove_direction(Ghost::none);

                connect(timer_pacman_death, SIGNAL(timeout()), this, SLOT(afterPacmanDeath()));
                timer_pacman_death->start(timer_pacman_death_miliseconds);
            } else {
                gameLose();
            }
        }
    } else if ((pink_ghost->getX() == pacman->getX()) && (pink_ghost->getY() == pacman->getY())) {
        if (pacman->getCan_eat()) {
            pink_ghost->setX(pink_ghost->getFirst_x());
            pink_ghost->setY(pink_ghost->getFirst_y());

            pink_ghost->setMove_direction(Ghost::none);
            pacman->setCan_eat(false);

            connect(timer_ghost_death, SIGNAL(timeout()), this, SLOT(afterPinkGhostDeath()));
            timer_ghost_death->start(timer_ghost_death_miliseconds);
        } else {
            if (pacman->getHealth() > 1) {
                pacman->setHealth(pacman->getHealth() - 1);
                pacman->setX(pacman->getFirst_x());
                pacman->setY(pacman->getFirst_y());
                pacman->setMove_direction(Player::none);

                red_ghost->setX(red_ghost->getFirst_x());
                red_ghost->setY(red_ghost->getFirst_y());
                red_ghost->setMove_direction(Ghost::none);

                orange_ghost->setX(orange_ghost->getFirst_x());
                orange_ghost->setY(orange_ghost->getFirst_y());
                orange_ghost->setMove_direction(Ghost::none);

                blue_ghost->setX(blue_ghost->getFirst_x());
                blue_ghost->setY(blue_ghost->getFirst_y());
                blue_ghost->setMove_direction(Ghost::none);

                pink_ghost->setX(pink_ghost->getFirst_x());
                pink_ghost->setY(pink_ghost->getFirst_y());
                pink_ghost->setMove_direction(Ghost::none);

                connect(timer_pacman_death, SIGNAL(timeout()), this, SLOT(afterPacmanDeath()));
                timer_pacman_death->start(timer_pacman_death_miliseconds);
            } else {
                gameLose();
            }
        }
    }
}

void GameManager::gameLose()
{
    this->close();
    closeWindow = new CloseWindow(pacman->getScore(), false, this);
    closeWindow->setModal(true);
    closeWindow->exec();
}

void GameManager::gameWin()
{
    this->close();
    closeWindow = new CloseWindow(pacman->getScore(), true, this);
    closeWindow->setModal(true);
    closeWindow->exec();
}

bool GameManager::checkWinningConditions()
{
    if (map->getScore_point_number() == 0) {
        return true;
    } else {
        return false;
    }
}
