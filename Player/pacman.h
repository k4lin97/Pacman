/**
 * @file pacman.h
 * @author Paweł Kalinowski
 * @brief Class describing pacman.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PACMAN_H
#define PACMAN_H

#include "player.h"

class Pacman : public Player {
   public:
    /**
     * @brief Construct a new Pacman object.
     *
     */
    Pacman();

    /**
     * @brief Construct a new Pacman object.
     *
     * Used only in multiplayer - in secondGameManager
     * @param _firstX first X position of a pacman
     * @param _firstY first Y position of a pacman
     */
    Pacman(int _firstX, int _firstY);

    /**
     * @brief Destroy the Pacman object.
     *
     */
    ~Pacman();

    /**
     * @brief Get the pacman's health.
     *
     * @return int pacman's health.
     */
    int getHealth() const;
    /**
     * @brief Set the pacman's health.
     *
     * @param value pacman's health.
     */
    void setHealth(int value);

    /**
     * @brief Get the pacman's score.
     *
     * @return int pacman's score.
     */
    int getScore() const;
    /**
     * @brief Set the pacman's score.
     *
     * @param value pacman's score.
     */
    void setScore(int value);

    /**
     * @brief Get the pacman's ability to eat a ghost.
     *
     * @return true if pacman can eat ghost.
     * @return false if pacman cannot eat ghost.
     */
    bool getCanEat() const;
    /**
     * @brief Set the pacman's ability to eat a ghost.
     *
     * @param value can pacman eat a ghost.
     */
    void setCanEat(bool value);

    /**
     * @brief Function that moves pacman.
     *
     * Function checks in which direction pacman wants to move. There are three
     * cases:
     * - wall - pacman cannot move there,
     * - scorePoint - pacman moves there and gets the point from map,
     * - fruit - pacman moves there, gets the point from map and his ability
     *           to eat a ghost is set to true,
     * If pacman moves number of score points on map is being deducted.
     * @param map map on which pacman moves.
     */
    void move(Map *map);

   private:
    int health;   // Pacman's health
    int score;    // Pacman's score
    bool canEat;  // Can pacman eat a ghost
};

#endif  // PACMAN_H
