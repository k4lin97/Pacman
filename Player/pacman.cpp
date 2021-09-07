/**
 * @file pacman.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of pacman.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "pacman.h"

Pacman::Pacman() : Player(13, 23) {
    // Set the surrounding walls to false
    setLeftWall(false);
    setRightWall(false);
    setUpWall(false);
    setDownWall(false);

    // Set current position to first coordinates
    setX(getFirstX());
    setY(getFirstY());

    // Set target to zero
    setTargetX(0);
    setTargetY(0);

    // Set first move direction to none - pacman does not move
    setMoveDirection(Player::none);

    setHealth(3);
    setScore(0);
    setCanEat(false);
}

// Used only in multiplayer - second pacman has different first coordinates
Pacman::Pacman(int _firstX, int _firstY) : Player(_firstX, _firstY) {
    // Set the surrounding walls to false
    setLeftWall(false);
    setRightWall(false);
    setUpWall(false);
    setDownWall(false);

    // Set current position to first coordinates
    setX(getFirstX());
    setY(getFirstY());

    // Set target to zero
    setTargetX(0);
    setTargetY(0);

    // Set first move direction to none - pacman does not move
    setMoveDirection(Player::none);

    setHealth(3);
    setScore(0);
    setCanEat(false);
}

Pacman::~Pacman() {
    // Empty on purpose
}

int Pacman::getHealth() const { return health; }

void Pacman::setHealth(int value) { health = value; }

int Pacman::getScore() const { return score; }

void Pacman::setScore(int value) { score = value; }

bool Pacman::getCanEat() const { return canEat; }

void Pacman::setCanEat(bool value) { canEat = value; }

void Pacman::move(Map *map) {
    if (getMoveDirection() == Player::left) {
        if (!getLeftWall()) {
            if (map->getMapAtPosition(getX() - 1, getY()) == Map::scorePoint) {
                setScore(getScore() + 1);
                map->setMapAtPosition(getX() - 1, getY(), Map::none);
                map->scorePointNumberDecrement();
            } else if (map->getMapAtPosition(getX() - 1, getY()) ==
                       Map::fruit) {
                setCanEat(true);
                map->setMapAtPosition(getX() - 1, getY(), Map::none);
                setScore(getScore() + 1);
                map->scorePointNumberDecrement();
            }
            setX(getX() - 1);
        } else {
            // There is a wall - pacman cannot move
        }
    } else if (getMoveDirection() == Player::right) {
        if (!getRightWall()) {
            if (map->getMapAtPosition(getX() + 1, getY()) == Map::scorePoint) {
                setScore(getScore() + 1);
                map->setMapAtPosition(getX() + 1, getY(), Map::none);
                map->scorePointNumberDecrement();
            } else if (map->getMapAtPosition(getX() + 1, getY()) ==
                       Map::fruit) {
                setCanEat(true);
                map->setMapAtPosition(getX() + 1, getY(), Map::none);
                setScore(getScore() + 1);
                map->scorePointNumberDecrement();
            }
            setX(getX() + 1);
        } else {
            // There is a wall - pacman cannot move
        }
    } else if (getMoveDirection() == Player::up) {
        if (!getUpWall()) {
            if (map->getMapAtPosition(getX(), getY() - 1) == Map::scorePoint) {
                setScore(getScore() + 1);
                map->setMapAtPosition(getX(), getY() - 1, Map::none);
                map->scorePointNumberDecrement();
            } else if (map->getMapAtPosition(getX(), getY() - 1) ==
                       Map::fruit) {
                setCanEat(true);
                map->setMapAtPosition(getX(), getY() - 1, Map::none);
                setScore(getScore() + 1);
                map->scorePointNumberDecrement();
            }
            setY(getY() - 1);
        } else {
            // There is a wall - pacman cannot move
        }
    } else if (getMoveDirection() == Player::down) {
        if (!getDownWall()) {
            if (map->getMapAtPosition(getX(), getY() + 1) == Map::scorePoint) {
                setScore(getScore() + 1);
                map->setMapAtPosition(getX(), getY() + 1, Map::none);
                map->scorePointNumberDecrement();
            } else if (map->getMapAtPosition(getX(), getY() + 1) ==
                       Map::fruit) {
                setCanEat(true);
                map->setMapAtPosition(getX(), getY() + 1, Map::none);
                setScore(getScore() + 1);
                map->scorePointNumberDecrement();
            }
            setY(getY() + 1);
        } else {
            // There is a wall - pacman cannot move
        }
    } else if (getMoveDirection() == Player::none) {
        // Pacman does not move
    }
}
