/**
 * @file redghost.h
 * @author Paweł Kalinowski
 * @brief Class describing red ghost.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef REDGHOST_H
#define REDGHOST_H

#include "ghost.h"

class RedGhost : public Ghost {
   public:
    /**
     * @brief Construct a new Red Ghost object.
     *
     */
    RedGhost();

    /**
     * @brief Destroy the Red Ghost object.
     *
     */
    ~RedGhost();

    /**
     * @brief Implementation of the abstract class to calculate the red ghost's
     * target.
     *
     * A function that calculates the red ghost's target. If the ghost is in
     * scatter stage its target is fixed to X = 27, Y = 0. However when the
     * ghost is in chase stage its target is set to be the pacman's position.
     * @param pacman Pacman against which the target is calculated.
     */
    virtual void calculateTarget(Player *pacman) override;
};

#endif  // REDGHOST_H
