/**
 * @file ghost.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of ghost.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "ghost.h"

Ghost::Ghost(int _firstX, int _firstY) : Player(_firstX, _firstY) {
    // Empty on purpose.
}

Ghost::~Ghost() {
    // Empty on purpose.
}

Ghost::stage Ghost::getGhostStage() const { return ghostStage; }

void Ghost::setGhostStage(const stage &value) { ghostStage = value; }

void Ghost::changeStage() {
    if (getGhostStage() == Ghost::scatter) {
        if (getMoveDirection() == Ghost::right) {
            setMoveDirection(Ghost::left);
        } else if (getMoveDirection() == Ghost::left) {
            setMoveDirection(Ghost::right);
        } else if (getMoveDirection() == Ghost::up) {
            setMoveDirection(Ghost::down);
        } else if (getMoveDirection() == Ghost::down) {
            setMoveDirection(Ghost::up);
        }
        setGhostStage(Ghost::chase);
    } else if (getGhostStage() == Ghost::chase) {
        setGhostStage(Ghost::scatter);
    }
}

void Ghost::move() {
    // The ghost cannot go back.
    // Priority: up, left, down, and right.
    if (getMoveDirection() == Ghost::right) {
        if ((!getRightWall()) && (!getUpWall()) && (!getDownWall())) {
            // There is no wall anywhere
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if ((distanceUp <= distanceDown) && (distanceUp <= distanceRight)) {
                // Up has priority
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else if ((distanceDown <= distanceUp) &&
                       (distanceDown <= distanceRight)) {
                if (distanceDown == distanceUp) {
                    // Up has priority
                    setMoveDirection(Ghost::up);
                    setY(getY() - 1);
                } else if (distanceDown == distanceRight) {
                    // Down has priority
                    setMoveDirection(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMoveDirection(Ghost::down);
                    setY(getY() + 1);
                }
            } else if ((distanceRight <= distanceUp) &&
                       (distanceRight <= distanceDown)) {
                if (distanceRight == distanceUp) {
                    // Up has priority
                    setMoveDirection(Ghost::up);
                    setY(getY() - 1);
                } else if (distanceRight == distanceDown) {
                    // Down has priority
                    setMoveDirection(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMoveDirection(Ghost::right);
                    setX(getX() + 1);
                }
            }
        } else if ((getRightWall()) && (getUpWall()) && (!getDownWall())) {
            // There is a wall up and from right
            setMoveDirection(Ghost::down);
            setY(getY() + 1);
        } else if ((getRightWall()) && (getDownWall()) && (!getUpWall())) {
            // There is a wall down and from right
            setMoveDirection(Ghost::up);
            setY(getY() - 1);
        } else if ((getUpWall()) && (getDownWall()) && (!getRightWall())) {
            // There is a wall up and down
            setMoveDirection(Ghost::right);
            setX(getX() + 1);
        } else if ((getUpWall()) && (!getRightWall()) && (!getDownWall())) {
            // There is a wall up
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if (distanceDown <= distanceRight) {
                setMoveDirection(Ghost::down);
                setY(getY() + 1);
            } else {
                setMoveDirection(Ghost::right);
                setX(getX() + 1);
            }
        } else if ((!getUpWall()) && (getRightWall()) && (!getDownWall())) {
            // There is a wall from right
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            if (distanceUp <= distanceDown) {
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else {
                setMoveDirection(Ghost::down);
                setY(getY() + 1);
            }
        } else if ((!getUpWall()) && (!getRightWall()) && (getDownWall())) {
            // There is a wall down
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if (distanceUp <= distanceRight) {
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else {
                setMoveDirection(Ghost::right);
                setX(getX() + 1);
            }
        }
    } else if (getMoveDirection() == Ghost::left) {
        if ((!getDownWall()) && (!getUpWall()) && (!getLeftWall())) {
            // There is no wall anywhere
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            if ((distanceUp <= distanceLeft) && (distanceUp <= distanceDown)) {
                // Up has priority
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else if ((distanceLeft <= distanceUp) &&
                       (distanceLeft <= distanceDown)) {
                if (distanceLeft == distanceUp) {
                    // Up has priority
                    setMoveDirection(Ghost::up);
                    setY(getY() - 1);
                } else if (distanceLeft == distanceDown) {
                    // Left has priority
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                }
            } else if ((distanceDown <= distanceUp) &&
                       (distanceDown <= distanceLeft)) {
                if (distanceDown == distanceUp) {
                    // Up has priority
                    setMoveDirection(Ghost::up);
                    setY(getY() - 1);
                } else if (distanceDown == distanceLeft) {
                    // Left has priority
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMoveDirection(Ghost::down);
                    setY(getY() + 1);
                }
            }
        } else if ((!getDownWall()) && (getUpWall()) && (getLeftWall())) {
            // There is a wall up and from left
            setMoveDirection(Ghost::down);
            setY(getY() + 1);
        } else if ((getDownWall()) && (getUpWall()) && (!getLeftWall())) {
            // There is a wall up and down
            setMoveDirection(Ghost::left);
            setX(getX() - 1);
        } else if ((getDownWall()) && (!getUpWall()) && (getLeftWall())) {
            // There is a wall down and from left
            setMoveDirection(Ghost::up);
            setY(getY() - 1);
        } else if ((!getDownWall()) && (getUpWall()) && (!getLeftWall())) {
            // There is a wall up
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            if (distanceLeft <= distanceDown) {
                setMoveDirection(Ghost::left);
                setX(getX() - 1);
            } else {
                setMoveDirection(Ghost::down);
                setY(getY() + 1);
            }
        } else if ((getDownWall()) && (!getUpWall()) && (!getLeftWall())) {
            // There is a wall down
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            if (distanceUp <= distanceLeft) {
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else {
                setMoveDirection(Ghost::left);
                setX(getX() - 1);
            }
        } else if ((!getDownWall()) && (!getUpWall()) && (getLeftWall())) {
            // There is a wall from left
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            if (distanceUp <= distanceDown) {
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else {
                setMoveDirection(Ghost::down);
                setY(getY() + 1);
            }
        }
    } else if (getMoveDirection() == Ghost::up) {
        if ((!getRightWall()) && (!getUpWall()) && (!getLeftWall())) {
            // There is no wall anywhere
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if ((distanceUp <= distanceLeft) && (distanceUp <= distanceRight)) {
                // Up has priority
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else if ((distanceLeft <= distanceUp) &&
                       (distanceLeft <= distanceRight)) {
                if (distanceLeft == distanceUp) {
                    // Up has priority
                    setMoveDirection(Ghost::up);
                    setY(getY() - 1);
                } else if (distanceLeft == distanceRight) {
                    // Left has priority
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                }
            } else if ((distanceRight <= distanceUp) &&
                       (distanceRight <= distanceLeft)) {
                if (distanceRight == distanceUp) {
                    // Up has priority
                    setMoveDirection(Ghost::up);
                    setY(getY() - 1);
                } else if (distanceRight == distanceLeft) {
                    // Down has priority
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMoveDirection(Ghost::right);
                    setX(getX() + 1);
                }
            }
        } else if ((getRightWall()) && (getUpWall()) && (!getLeftWall())) {
            // There is a wall up and from right
            setMoveDirection(Ghost::left);
            setX(getX() - 1);
        } else if ((getRightWall()) && (!getUpWall()) && (getLeftWall())) {
            // There is a wall from right and left
            setMoveDirection(Ghost::up);
            setY(getY() - 1);
        } else if ((!getRightWall()) && (getUpWall()) && (getLeftWall())) {
            // There is a wall up and from left
            setMoveDirection(Ghost::right);
            setX(getX() + 1);
        } else if ((!getRightWall()) && (getUpWall()) && (!getLeftWall())) {
            // There is a wall up
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if (distanceLeft <= distanceRight) {
                setMoveDirection(Ghost::left);
                setX(getX() - 1);
            } else {
                setMoveDirection(Ghost::right);
                setX(getX() + 1);
            }
        } else if ((getRightWall()) && (!getUpWall()) && (!getLeftWall())) {
            // There is a wall from right
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            if (distanceUp <= distanceLeft) {
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else {
                setMoveDirection(Ghost::left);
                setX(getX() - 1);
            }
        } else if ((!getRightWall()) && (!getUpWall()) && (getLeftWall())) {
            // There is a wall from left
            int distanceUp = pow((getTargetX() - getX()), 2) +
                             pow((getTargetY() - (getY() - 1)), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if (distanceUp <= distanceRight) {
                setMoveDirection(Ghost::up);
                setY(getY() - 1);
            } else {
                setMoveDirection(Ghost::right);
                setX(getX() + 1);
            }
        }
    } else if (getMoveDirection() == Ghost::down) {
        if ((!getRightWall()) && (!getLeftWall()) && (!getDownWall())) {
            // There is no wall anywhere
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if ((distanceLeft <= distanceDown) &&
                (distanceLeft <= distanceRight)) {
                // Left has prioryty
                setMoveDirection(Ghost::left);
                setX(getX() - 1);
            } else if ((distanceDown <= distanceLeft) &&
                       (distanceDown <= distanceRight)) {
                if (distanceDown == distanceLeft) {
                    // Left has priority
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                } else if (distanceDown == distanceRight) {
                    // Down has priority
                    setMoveDirection(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMoveDirection(Ghost::down);
                    setY(getY() + 1);
                }
            } else if ((distanceRight <= distanceLeft) &&
                       (distanceRight <= distanceDown)) {
                if (distanceRight == distanceLeft) {
                    // Left has priority
                    setMoveDirection(Ghost::left);
                    setX(getX() - 1);
                } else if (distanceRight == distanceDown) {
                    // Down has priority
                    setMoveDirection(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMoveDirection(Ghost::right);
                    setX(getX() + 1);
                }
            }
        } else if ((!getRightWall()) && (getLeftWall()) && (getDownWall())) {
            // There is a wall down and from left
            setMoveDirection(Ghost::right);
            setX(getX() + 1);
        } else if ((getRightWall()) && (getLeftWall()) && (!getDownWall())) {
            // There is a wall from right and left
            setMoveDirection(Ghost::down);
            setY(getY() + 1);
        } else if ((getRightWall()) && (!getLeftWall()) && (getDownWall())) {
            // There is a wall down and from right
            setMoveDirection(Ghost::left);
            setX(getX() - 1);
        } else if ((!getRightWall()) && (getLeftWall()) && (!getDownWall())) {
            // There is a wall from left
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if (distanceDown <= distanceRight) {
                setMoveDirection(Ghost::down);
                setY(getY() + 1);
            } else {
                setMoveDirection(Ghost::right);
                setX(getX() + 1);
            }
        } else if ((getRightWall()) && (!getLeftWall()) && (!getDownWall())) {
            // There is a wall from right
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            int distanceDown = pow((getTargetX() - getX()), 2) +
                               pow((getTargetY() - (getY() + 1)), 2);
            if (distanceLeft <= distanceDown) {
                setMoveDirection(Ghost::left);
                setX(getX() - 1);
            } else {
                setMoveDirection(Ghost::down);
                setY(getY() + 1);
            }
        } else if ((!getRightWall()) && (!getLeftWall()) && (getDownWall())) {
            // There is a wall down
            int distanceLeft = pow((getTargetX() - (getX() - 1)), 2) +
                               pow((getTargetY() - getY()), 2);
            int distanceRight = pow((getTargetX() - (getX() + 1)), 2) +
                                pow((getTargetY() - (getY())), 2);
            if (distanceLeft <= distanceRight) {
                setMoveDirection(Ghost::left);
                setX(getX() - 1);
            } else {
                setMoveDirection(Ghost::right);
                setX(getX() + 1);
            }
        }
    } else if (getMoveDirection() == Ghost::none) {
        // Ghost does not move
    }
}
