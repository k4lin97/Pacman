/**
 * @file pinkghost.h
 * @author Paweł Kalinowski.
 * @brief Class describing pink ghost.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PINKGHOST_H
#define PINKGHOST_H

#include "ghost.h"

class PinkGhost : public Ghost {
   public:
    /**
     * @brief Construct a new Pink Ghost object.
     *
     */
    PinkGhost();

    /**
     * @brief Destroy the Pink Ghost object.
     *
     */
    ~PinkGhost();

    /**
     * @brief Implementation of the abstract class to calculate the pink ghost's
     * target.
     *
     * A function that calculates the pink ghost's target. If the ghost is in
     * scatter stage its target is fixed to X = 0, Y = 0. However when the
     * ghost is in chase stage its target is set to be always four positions
     * ahead of pacman.
     * @param pacman Pacman against which the target is calculated.
     */
    virtual void calculateTarget(Player *pacman) override;
};

#endif  // PINKGHOST_H
