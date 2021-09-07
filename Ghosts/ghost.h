/**
 * @file ghost.h
 * @author Paweł Kalinowski
 * @brief Abstract class describing a ghost.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef GHOST_H
#define GHOST_H

#include "Player/player.h"

#include <math.h>

class Ghost : public Player {
   public:
    /**
     * @brief Construct a new Ghost object.
     *
     * Parameters are used to initialize first (and after death) ghost position.
     * @param _firstX First X position of a ghost.
     * @param _firstY First Y position of a ghost.
     */
    Ghost(int _firstX, int _firstY);

    /**
     * @brief Destroy the Ghost object
     *
     */
    ~Ghost();

    /**
     * @brief Ghost's stages.
     *
     * There are two states in which a ghost can be found - scatter and chase.
     */
    enum stage { scatter, chase };

    /**
     * @brief Get the Ghost Stage object.
     *
     * @return Ghost's stage.
     */
    stage getGhostStage() const;

    /**
     * @brief Set the Ghost Stage object.
     *
     * @param value Ghost's stage.
     */
    void setGhostStage(const stage &value);

    /**
     * @brief Changes ghost's stage.
     *
     * If the ghost is in scatter stage it changes its direction immediately.
     * If it is in chase stage it changes to scatter.
     */
    void changeStage();

    /**
     * @brief This function moves a ghost.
     *
     * The function imitates the movement of ghost from a real pacman. For a
     * ghost, the distance to its target (from its next position) is calculated.
     * The ghost cannot go back, and if the distance to the target is equal,
     * priority is given to: up, left, down, and right.
     */
    void move();

    /**
     * @brief A function to calculate the target of a ghost.
     *
     * The abstract function that calculates the target of a ghost.
     * Implementation varies according to the color of the ghost.
     * @param pacman Pacman against which the target is calculated.
     */
    virtual void calculateTarget(Player *pacman) = 0;

   private:
    stage ghostStage;  // Ghost's stage.
};

#endif  // GHOST_H
