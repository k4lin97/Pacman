/**
 * @file pinkghost.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of pinkghost.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "pinkghost.h"

PinkGhost::PinkGhost() : Ghost(9, 11) {
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

    // Set first move direction to right and stage to sctter
    setMoveDirection(Player::right);
    setGhostStage(Ghost::scatter);
}

PinkGhost::~PinkGhost() {
    // Empty on purpose
}

void PinkGhost::calculateTarget(Player *pacman) {
    if (getGhostStage() == Ghost::scatter) {
        // If the ghost is in scatter stage target cooridnates are fixed
        setTargetX(0);
        setTargetY(0);
    } else if (getGhostStage() == Ghost::chase) {
        // Calculate the target
        if (pacman->getMoveDirection() == Player::right) {
            pacman->setTargetX(pacman->getX() + 4);
            pacman->setTargetY(pacman->getY());
        } else if (pacman->getMoveDirection() == Player::left) {
            setTargetX(pacman->getX() - 4);
            setTargetY(pacman->getY());
        } else if (pacman->getMoveDirection() == Player::up) {
            setTargetX(pacman->getX());
            setTargetY(pacman->getY() - 4);
        } else if (pacman->getMoveDirection() == Player::down) {
            setTargetX(pacman->getX());
            setTargetY(pacman->getY() + 4);
        }
    }
}
