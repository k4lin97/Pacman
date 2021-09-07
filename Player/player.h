/**
 * @file player.h
 * @author Paweł Kalinowski
 * @brief Class describing a player.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "SinglePlayer/map.h"

class Player {
   public:
    /**
     * @brief Construct a new Player object.
     *
     * @param _firstX First X position of a player.
     * @param _firstY First X position of a player.
     */
    Player(int _firstX, int _firstY);

    /**
     * @brief Destroy the Player object.
     *
     */
    virtual ~Player();

    /**
     * @brief Get the Left Wall.
     *
     * @return true If there is a wall on left.
     * @return false If there is no wall on left.
     */
    bool getLeftWall() const;
    /**
     * @brief Set the Left Wall object.
     *
     * @param value Left wall.
     */
    void setLeftWall(bool value);

    /**
     * @brief Get the Right Wall.
     *
     * @return true If there is a wall on right.
     * @return false If there is no wall on right.
     */
    bool getRightWall() const;
    /**
     * @brief Set the Right Wall.
     *
     * @param value Right wall.
     */
    void setRightWall(bool value);

    /**
     * @brief Get the Up Wall.
     *
     * @return true If there is a wall up.
     * @return false If there is no wall up.
     */
    bool getUpWall() const;
    /**
     * @brief Set the Up Wall.
     *
     * @param value Up wall.
     */
    void setUpWall(bool value);

    /**
     * @brief Get the Down Wall.
     *
     * @return true If there is a wall down.
     * @return false If there is no wall down.
     */
    bool getDownWall() const;
    /**
     * @brief Set the Down Wall.
     *
     * @param value Down wall.
     */
    void setDownWall(bool value);

    /**
     * @brief Get X position of a player.
     *
     * @return int X position of a player.
     */
    int getX() const;
    /**
     * @brief Set X position of a player.
     *
     * @param value X position of a player.
     */
    void setX(int value);

    /**
     * @brief Get Y position of a player.
     *
     * @return int Y position of a player.
     */
    int getY() const;
    /**
     * @brief Set Y position of a player.
     *
     * @param value Y position of a player.
     */
    void setY(int value);

    /**
     * @brief Get first X position of a player.
     *
     * @return int first X position of a player.
     */
    int getFirstX() const;
    /**
     * @brief Get first Y position of a player.
     *
     * @return int first Y position of a player.
     */
    int getFirstY() const;

    /**
     * @brief Get player's target X position.
     *
     * @return int player's target X position.
     */
    int getTargetX() const;
    /**
     * @brief Set player's target X position.
     *
     * @param value player's target X position.
     */
    void setTargetX(int value);

    /**
     * @brief Get player's target Y position.
     *
     * @return int player's target Y position.
     */
    int getTargetY() const;
    /**
     * @brief Set player's target Y position.
     *
     * @param value player's target Y position.
     */
    void setTargetY(int value);

    enum direction {
        left,
        right,
        up,
        down,
        none
    };  // Directions a player can go

    /**
     * @brief Get the player's direction.
     *
     * @return Player::direction player's direction.
     */
    Player::direction getMoveDirection() const;
    /**
     * @brief Set the player's direction.
     *
     * @param value player's direction.
     */
    void setMoveDirection(const Player::direction value);

    /**
     * @brief Checks walls around player.
     *
     * @param map map object.
     */
    void checkWalls(Map *map);

   private:
    bool leftWall;   // Is there a wall on left
    bool rightWall;  // Is there a wall on right
    bool upWall;     // Is there a wall up
    bool downWall;   // Is there a wall down

    int x;             // X position of a player
    int y;             // Y position of a player
    const int firstX;  // first X position of a player
    const int firstY;  // first Y position of a player

    // Pacman does not need target - in future there will be option to play as a
    // ghost
    int targetX;  // player's target X position
    int targetY;  // player's target Y position

    direction moveDirection;
};

#endif  // PLAYER_H
