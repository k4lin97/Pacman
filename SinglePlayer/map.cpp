/**
 * @file map.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of map.h.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "map.h"

Map::Map() : mapHeight(31), mapWidth(28) {
    // Create map
    map = new mapFields *[mapWidth];
    for (int i = 0; i < mapWidth; i++) {
        map[i] = new mapFields[mapHeight];
    }

    scorePointNumber = 283;  // Score points number in single player

    // Create map fields
    for (int i = 0; i < mapWidth; i++) {
        setMapAtPosition(i, 0, wall);
        if ((i == 0) || (i == 13) || (i == 14) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 1, wall);
        } else {
            setMapAtPosition(i, 1, scorePoint);
        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5) ||
            (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11) ||
            (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) ||
            (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) ||
            (i == 25) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 2, wall);
            setMapAtPosition(i, 3, wall);
            setMapAtPosition(i, 4, wall);
        } else {
            setMapAtPosition(i, 2, scorePoint);
            setMapAtPosition(i, 3, scorePoint);
            setMapAtPosition(i, 4, scorePoint);
        }
        if ((i == 0) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 5, wall);
        } else {
            setMapAtPosition(i, 5, scorePoint);
        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5) ||
            (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) ||
            (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17) ||
            (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) ||
            (i == 25) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 6, wall);
            setMapAtPosition(i, 7, wall);
        } else {
            setMapAtPosition(i, 6, scorePoint);
            setMapAtPosition(i, 7, scorePoint);
        }
        if ((i == 0) || (i == 7) || (i == 8) || (i == 13) || (i == 14) ||
            (i == 19) || (i == 20) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 8, wall);
        } else {
            setMapAtPosition(i, 8, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 9) || (i == 10) ||
            (i == 11) || (i == 13) || (i == 14) || (i == 16) || (i == 17) ||
            (i == 18) || (i == 19) || (i == 20) || (i == 22) || (i == 23) ||
            (i == 24) || (i == 25) || (i == 26) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 9, wall);
            setMapAtPosition(i, 10, wall);
        } else {
            setMapAtPosition(i, 9, scorePoint);
            setMapAtPosition(i, 10, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 19) || (i == 20) ||
            (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) ||
            (i == mapWidth - 1)) {
            setMapAtPosition(i, 11, wall);
        } else {
            setMapAtPosition(i, 11, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 11) ||
            (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) ||
            (i == 17) || (i == 19) || (i == 20) || (i == 22) || (i == 23) ||
            (i == 24) || (i == 25) || (i == 26) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 12, wall);
        } else {
            setMapAtPosition(i, 12, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 11) ||
            (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) ||
            (i == 17) || (i == 19) || (i == 20) || (i == 22) || (i == 23) ||
            (i == 24) || (i == 25) || (i == 26) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 13, wall);
        } else {
            setMapAtPosition(i, 13, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 10) || (i == 11) || (i == 12) || (i == 13) ||
            (i == 14) || (i == 15) || (i == 16) || (i == 17) || (i == 22) ||
            (i == 23) || (i == 24) || (i == 25) || (i == 26) ||
            (i == mapWidth - 1)) {
            setMapAtPosition(i, 14, wall);
        } else {
            setMapAtPosition(i, 14, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 11) ||
            (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) ||
            (i == 17) || (i == 19) || (i == 20) || (i == 22) || (i == 23) ||
            (i == 24) || (i == 25) || (i == 26) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 15, wall);
        } else {
            setMapAtPosition(i, 15, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 11) ||
            (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) ||
            (i == 17) || (i == 19) || (i == 20) || (i == 22) || (i == 23) ||
            (i == 24) || (i == 25) || (i == 26) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 16, wall);
        } else {
            setMapAtPosition(i, 16, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 19) || (i == 20) ||
            (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) ||
            (i == mapWidth - 1)) {
            setMapAtPosition(i, 17, wall);
        } else {
            setMapAtPosition(i, 17, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) ||
            (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 11) ||
            (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) ||
            (i == 17) || (i == 19) || (i == 20) || (i == 22) || (i == 23) ||
            (i == 24) || (i == 25) || (i == 26) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 18, wall);
            setMapAtPosition(i, 19, wall);
        } else {
            setMapAtPosition(i, 18, scorePoint);
            setMapAtPosition(i, 19, scorePoint);
        }
        if ((i == 0) || (i == 13) || (i == 14) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 20, wall);
        } else {
            setMapAtPosition(i, 20, scorePoint);
        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5) ||
            (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11) ||
            (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) ||
            (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) ||
            (i == 25) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 21, wall);
            setMapAtPosition(i, 22, wall);
        } else {
            setMapAtPosition(i, 21, scorePoint);
            setMapAtPosition(i, 22, scorePoint);
        }
        if ((i == 0) || (i == 4) || (i == 5) || (i == 22) || (i == 23) ||
            (i == mapWidth - 1)) {
            setMapAtPosition(i, 23, wall);
        } else {
            setMapAtPosition(i, 23, scorePoint);
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 4) || (i == 5) ||
            (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) ||
            (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17) ||
            (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 25) ||
            (i == 26) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 24, wall);
            setMapAtPosition(i, 25, wall);
        } else {
            setMapAtPosition(i, 24, scorePoint);
            setMapAtPosition(i, 25, scorePoint);
        }
        if ((i == 0) || (i == 7) || (i == 8) || (i == 13) || (i == 14) ||
            (i == 19) || (i == 20) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 26, wall);
        } else {
            setMapAtPosition(i, 26, scorePoint);
        }
        if ((i == 0) || (i == 3) || (i == 2) || (i == 4) || (i == 5) ||
            (i == 6) || (i == 7) || (i == 8) || (i == 9) || (i == 10) ||
            (i == 11) || (i == 13) || (i == 14) || (i == 16) || (i == 17) ||
            (i == 18) || (i == 19) || (i == 20) || (i == 21) || (i == 22) ||
            (i == 23) || (i == 24) || (i == 25) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 27, wall);
            setMapAtPosition(i, 28, wall);
        } else {
            setMapAtPosition(i, 27, scorePoint);
            setMapAtPosition(i, 28, scorePoint);
        }
        if ((i == 0) || (i == mapWidth - 1)) {
            setMapAtPosition(i, 29, wall);
        } else {
            setMapAtPosition(i, 29, scorePoint);
        }
        setMapAtPosition(i, 30, wall);
    }

    // Pacman
    setMapAtPosition(13, 23, none);

    // Fruits
    setMapAtPosition(6, 5, fruit);
    setMapAtPosition(6, 20, fruit);
    setMapAtPosition(21, 5, fruit);
    setMapAtPosition(21, 20, fruit);
}

Map::~Map() {
    // Delete map
    for (int i = 0; i < mapWidth; i++) {
        delete[] map[i];
    }
    delete[] map;
}

int Map::getMapHeight() const { return mapHeight; }

int Map::getMapWidth() const { return mapWidth; }

int Map::getScorePointNumber() const { return scorePointNumber; }

void Map::scorePointNumberDecrement() { scorePointNumber--; }

Map::mapFields Map::getMapAtPosition(int x, int y) const { return map[x][y]; }

void Map::setMapAtPosition(int x, int y, Map::mapFields value) {
    map[x][y] = value;
}
