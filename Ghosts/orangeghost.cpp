/**
 * @file orangeghost.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of orangeghost.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "orangeghost.h"

OrangeGhost::OrangeGhost() : Ghost(9, 17) {
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

OrangeGhost::~OrangeGhost() {
    // Empty on purpose
}

void OrangeGhost::calculateTarget(Player *pacman) {
    if (getGhostStage() == Ghost::scatter) {
        // If the ghost is in scatter stage target cooridnates are fixed
        setTargetX(0);
        setTargetY(30);
    } else if (getGhostStage() == Ghost::chase) {
        // Circle radius is 8
        int circleRadius =
            pow(pacman->getX() - getX(), 2) + pow(pacman->getY() - getY(), 2);
        if (circleRadius > 64) {
            setTargetX(pacman->getX());
            setTargetY(pacman->getY());
        } else {
            setTargetX(0);
            setTargetY(30);
        }
    }
}
