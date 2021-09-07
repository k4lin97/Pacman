/**
 * @file blueghost.h
 * @author Paweł Kalinowski
 * @brief Class describing blue ghost.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef BLUEGHOST_H
#define BLUEGHOST_H

#include "ghost.h"

class BlueGhost : public Ghost {
   public:
    /**
     * @brief Construct a new Blue Ghost object.
     *
     */
    BlueGhost();

    /**
     * @brief Destroy the Blue Ghost object.
     *
     */
    ~BlueGhost();

    /**
     * @brief Implementation of the abstract class to calculate the blue ghost's
     * target.
     *
     * A function that calculates the blue ghost's target. If the ghost is in
     * scatter stage its target is fixed to X = 27, Y = 30. However when the
     * ghost is in chase stage its target is set to be always two positions ahead
     * of pacman.
     * @param pacman Pacman against which the target is calculated.
     */
    virtual void calculateTarget(Player *pacman) override;
};

#endif  // BLUEGHOST_H
