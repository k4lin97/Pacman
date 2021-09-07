/**
 * @file player.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of player.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "player.h"

Player::Player(int _firstX, int _firstY) : firstX(_firstX), firstY(_firstY) {
    // Empty on purpose
}

Player::~Player() {
    // Empty on purpose
}

bool Player::getLeftWall() const { return leftWall; }

void Player::setLeftWall(bool value) { leftWall = value; }

bool Player::getRightWall() const { return rightWall; }

void Player::setRightWall(bool value) { rightWall = value; }

bool Player::getUpWall() const { return upWall; }

void Player::setUpWall(bool value) { upWall = value; }

bool Player::getDownWall() const { return downWall; }

void Player::setDownWall(bool value) { downWall = value; }

int Player::getX() const { return x; }

void Player::setX(int value) { x = value; }

int Player::getY() const { return y; }

void Player::setY(int value) { y = value; }

int Player::getFirstY() const { return firstY; }

int Player::getTargetX() const { return targetX; }

void Player::setTargetX(int value) { targetX = value; }

int Player::getTargetY() const { return targetY; }

void Player::setTargetY(int value) { targetY = value; }

int Player::getFirstX() const { return firstX; }

Player::direction Player::getMoveDirection() const { return moveDirection; }

void Player::setMoveDirection(const Player::direction value) {
    moveDirection = value;
}

void Player::checkWalls(Map* map) {
    // Checks walls around player
    if (map->getMapAtPosition(getX() + 1, getY()) == Map::wall) {
        setRightWall(true);
    } else {
        setRightWall(false);
    }
    if (map->getMapAtPosition(getX() - 1, getY()) == Map::wall) {
        setLeftWall(true);
    } else {
        setLeftWall(false);
    }
    if (map->getMapAtPosition(getX(), getY() + 1) == Map::wall) {
        setDownWall(true);
    } else {
        setDownWall(false);
    }
    if (map->getMapAtPosition(getX(), getY() - 1) == Map::wall) {
        setUpWall(true);
    } else {
        setUpWall(false);
    }
}
