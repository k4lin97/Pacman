/**
 * @file blueghost.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of blueghost.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "blueghost.h"

BlueGhost::BlueGhost() : Ghost(18, 17) {
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

    // Set first move direction to down and stage to sctter
    setMoveDirection(Player::down);
    setGhostStage(Ghost::scatter);
}

BlueGhost::~BlueGhost() {
    // Empty on purpose
}

void BlueGhost::calculateTarget(Player *pacman) {
    if (getGhostStage() == Ghost::scatter) {
        // If the ghost is in scatter stage target cooridnates are fixed
        setTargetX(27);
        setTargetY(30);
    } else if (getGhostStage() == Ghost::chase) {
        // Calculate the target
        int tempX = 0;
        int tempY = 0;
        if (pacman->getMoveDirection() == Player::right) {
            tempX = (pacman->getX() + 2);
            tempY = (pacman->getY());
        } else if (pacman->getMoveDirection() == Player::left) {
            tempX = (pacman->getX() - 2);
            tempY = (pacman->getY());
        } else if (pacman->getMoveDirection() == Player::up) {
            tempX = (pacman->getX());
            tempY = (pacman->getY() - 2);
        } else if (pacman->getMoveDirection() == Player::down) {
            tempX = (pacman->getX());
            tempY = (pacman->getY() + 2);
        }
        setTargetX(tempX + (tempX - pacman->getX()));
        // Deduct because Y coordinates increase downward
        setTargetY(tempY - (tempY - pacman->getY()));
    }
}
