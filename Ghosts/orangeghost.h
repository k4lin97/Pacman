/**
 * @file orangeghost.h
 * @author Paweł Kalinowski
 * @brief Class describing orange ghost.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef ORANGEGHOST_H
#define ORANGEGHOST_H

#include "ghost.h"

class OrangeGhost : public Ghost {
   public:
    /**
     * @brief Construct a new Orange Ghost object.
     *
     */
    OrangeGhost();

    /**
     * @brief Destroy the Orange Ghost object.
     *
     */
    ~OrangeGhost();

    /**
     * @brief Implementation of the abstract class to calculate the orange
     * ghost's target.
     *
     * A function that calculates the orange ghost's target. If the ghost is in
     * scatter stage its target is fixed to X = 0, Y = 30. However when the
     * ghost is in chase stage its target is calculated depending on a circle
     * around pacman with a radius 8. If the ghost is in that circle its target
     * is set to be pacman's position, if it is not inside target is set to X =
     * 0, Y = 30.
     * @param pacman Pacman against which the target is calculated.
     */
    virtual void calculateTarget(Player *pacman) override;
};

#endif  // ORANGEGHOST_H
