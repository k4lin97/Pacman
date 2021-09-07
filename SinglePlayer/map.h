/**
 * @file map.h
 * @author Paweł Kalinowski
 * @brief Game map.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef MAP_H
#define MAP_H

class Map {
   public:
    /**
     * @brief Construct a new Map object.
     *
     */
    Map();

    /**
     * @brief Destroy the Map object.
     *
     */
    ~Map();

    enum mapFields { wall, scorePoint, fruit, none };  // Map fields

    /**
     * @brief Get the Map Height.
     *
     * @return int map height.
     */
    int getMapHeight() const;
    /**
     * @brief Get the Map Width.
     *
     * @return int map width.
     */
    int getMapWidth() const;
    /**
     * @brief Get the Score Point Number.
     *
     * @return int score point number.
     */
    int getScorePointNumber() const;

    /**
     * @brief Decrements score points number.
     *
     */
    void scorePointNumberDecrement();

    /**
     * @brief Get the Map At Position.
     *
     * @param x x position.
     * @param y y position.
     * @return mapFields map field at (x, y) position.
     */
    mapFields getMapAtPosition(int x, int y) const;
    /**
     * @brief Set the Map At Position.
     *
     * @param x x position.
     * @param y y position.
     * @param value map field at (x, y) position.
     */
    void setMapAtPosition(int x, int y, mapFields value);

   private:
    const int mapHeight;
    const int mapWidth;
    int scorePointNumber;  // Number of scorePoints in map

    mapFields** map;
};

#endif  // MAP_H
