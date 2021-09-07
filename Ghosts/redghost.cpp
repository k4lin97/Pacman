/**
 * @file redghost.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of redghost.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "redghost.h"

RedGhost::RedGhost() : Ghost(18, 11) {
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

    // Set first move direction to left and stage to sctter
    setMoveDirection(Player::left);
    setGhostStage(Ghost::scatter);
}

RedGhost::~RedGhost() {
    // Empty on purpose
}

void RedGhost::calculateTarget(Player *pacman) {
    if (getGhostStage() == Ghost::scatter) {
        // If the ghost is in scatter stage target cooridnates are fixed
        setTargetX(27);
        setTargetY(0);
    } else if (getGhostStage() == Ghost::chase) {
        // Calculate the target
        setTargetX(pacman->getX());
        setTargetY(pacman->getY());
    }
}
