#include "map.h"

Map::Map() : map_height(31), map_width(28)
{
    map = new map_fields *[map_width];
    for (int i = 0; i < map_width; i++) {
        map[i] = new map_fields[map_height];
    }

    score_point_number = 0;
    /*for (int i = 0; i < map_width; i++) {
        map[i][0] = wall;
        if ((i == 0) || (i == 13) || (i == 14) || (i == map_width - 1)) {
            map[i][1] = wall;
        } else {
            map[i][1] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) || (i == 19) || (i == 20)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][2] = wall;
            map[i][3] = wall;
            map[i][4] = wall;
        } else {
            map[i][2] = score_point;
            score_point_number++;
            map[i][3] = score_point;
            score_point_number++;
            map[i][4] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == map_width - 1)) {
            map[i][5] = wall;
        } else {
            map[i][5] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11)
                || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17) || (i == 19)
                || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][6] = wall;
            map[i][7] = wall;
        } else {
            map[i][6] = score_point;
            score_point_number++;
            map[i][7] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 7) || (i == 8) || (i == 13) || (i == 14) || (i == 19) || (i == 20) || (i == map_width - 1)) {
            map[i][8] = wall;
        } else {
            map[i][8] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) || (i == 19) || (i == 20)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][9] = wall;
            map[i][10] = wall;
        } else {
            map[i][9] = score_point;
            score_point_number++;
            map[i][10] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][11] = wall;
        } else {
            map[i][11] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][12] = wall;
        } else {
            map[i][12] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][13] = wall;
        } else {
            map[i][13] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][14] = wall;
        } else if ((i == 11) || (i == 12) || (i == 15) || (i == 16)) {
            map[i][14] = none;
        } else {
            map[i][14] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][15] = wall;
        } else {
            map[i][15] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][16] = wall;
        } else {
            map[i][16] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][17] = wall;
        } else {
            map[i][17] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][18] = wall;
            map[i][19] = wall;
        } else {
            map[i][18] = score_point;
            score_point_number++;
            map[i][19] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 13) || (i == 14) || (i == map_width - 1)) {
            map[i][20] = wall;
        } else {
            map[i][20] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) || (i == 19) || (i == 20)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][21] = wall;
            map[i][22] = wall;
        } else {
            map[i][21] = score_point;
            score_point_number++;
            map[i][22] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 4) || (i == 5) || (i == 22) || (i == 23) || (i == map_width - 1)) {
            map[i][23] = wall;
        } else {
            map[i][23] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][24] = wall;
            map[i][25] = wall;
        } else {
            map[i][24] = score_point;
            score_point_number++;
            map[i][25] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 7) || (i == 8) || (i == 13) || (i == 14)
                || (i == 19) || (i == 20) || (i == map_width - 1)) {
            map[i][26] = wall;
        } else {
            map[i][26] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == 3) || (i == 2) || (i == 4) || (i == 5) || (i == 6) || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18)
                || (i == 19) || (i == 20) || (i == 21) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][27] = wall;
            map[i][28] = wall;
        } else {
            map[i][27] = score_point;
            score_point_number++;
            map[i][28] = score_point;
            score_point_number++;
        }
        if ((i == 0) || (i == map_width - 1)) {
            map[i][29] = wall;
        } else {
            map[i][29] = score_point;
            score_point_number++;
        }
        map[i][30] = wall;
    }

    // Pacman
    map[13][23] = none;
    score_point_number--;

    // Fruits
    map[21][5] = fruit;
    score_point_number--;
    map[21][20] = fruit;
    score_point_number--;
    map[6][5] = fruit;
    score_point_number--;
    map[6][20] = fruit;
    score_point_number--;*/

    // Na potrzeby sprawdzania
    for (int i = 0; i < map_width; i++) {
        map[i][0] = wall;
        if ((i == 0) || (i == 13) || (i == 14) || (i == map_width - 1)) {
            map[i][1] = wall;
        } else {
            map[i][1] = none;

        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) || (i == 19) || (i == 20)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][2] = wall;
            map[i][3] = wall;
            map[i][4] = wall;
        } else {
            map[i][2] = none;

            map[i][3] = none;

            map[i][4] = none;

        }
        if ((i == 0) || (i == map_width - 1)) {
            map[i][5] = wall;
        } else {
            map[i][5] = none;

        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11)
                || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17) || (i == 19)
                || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][6] = wall;
            map[i][7] = wall;
        } else {
            map[i][6] = none;

            map[i][7] = none;

        }
        if ((i == 0) || (i == 7) || (i == 8) || (i == 13) || (i == 14) || (i == 19) || (i == 20) || (i == map_width - 1)) {
            map[i][8] = wall;
        } else {
            map[i][8] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5) || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) || (i == 19) || (i == 20)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][9] = wall;
            map[i][10] = wall;
        } else {
            map[i][9] = none;

            map[i][10] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][11] = wall;
        } else {
            map[i][11] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][12] = wall;
        } else {
            map[i][12] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][13] = wall;
        } else {
            map[i][13] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][14] = wall;
        } else if ((i == 11) || (i == 12) || (i == 15) || (i == 16)) {
            map[i][14] = none;
        } else {
            map[i][14] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][15] = wall;
        } else {
            map[i][15] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][16] = wall;
        } else {
            map[i][16] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][17] = wall;
        } else {
            map[i][17] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][18] = wall;
            map[i][19] = wall;
        } else {
            map[i][18] = none;

            map[i][19] = none;

        }
        if ((i == 0) || (i == 13) || (i == 14) || (i == map_width - 1)) {
            map[i][20] = wall;
        } else {
            map[i][20] = none;

        }
        if ((i == 0) || (i == 2) || (i == 3) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18) || (i == 19) || (i == 20)
                || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][21] = wall;
            map[i][22] = wall;
        } else {
            map[i][21] = none;

            map[i][22] = none;

        }
        if ((i == 0) || (i == 4) || (i == 5) || (i == 22) || (i == 23) || (i == map_width - 1)) {
            map[i][23] = wall;
        } else {
            map[i][23] = none;

        }
        if ((i == 0) || (i == 1) || (i == 2) || (i == 4) || (i == 5)
                || (i == 7) || (i == 8) || (i == 10) || (i == 11) || (i == 12) || (i == 13) || (i == 14) || (i == 15) || (i == 16) || (i == 17)
                || (i == 19) || (i == 20) || (i == 22) || (i == 23) || (i == 25) || (i == 26) || (i == map_width - 1)) {
            map[i][24] = wall;
            map[i][25] = wall;
        } else {
            map[i][24] = none;

            map[i][25] = none;

        }
        if ((i == 0) || (i == 7) || (i == 8) || (i == 13) || (i == 14)
                || (i == 19) || (i == 20) || (i == map_width - 1)) {
            map[i][26] = wall;
        } else {
            map[i][26] = none;

        }
        if ((i == 0) || (i == 3) || (i == 2) || (i == 4) || (i == 5) || (i == 6) || (i == 7) || (i == 8) || (i == 9) || (i == 10) || (i == 11)
                || (i == 13) || (i == 14) || (i == 16) || (i == 17) || (i == 18)
                || (i == 19) || (i == 20) || (i == 21) || (i == 22) || (i == 23) || (i == 24) || (i == 25) || (i == map_width - 1)) {
            map[i][27] = wall;
            map[i][28] = wall;
        } else {
            map[i][27] = none;

            map[i][28] = none;

        }
        if ((i == 0) || (i == map_width - 1)) {
            map[i][29] = wall;
        } else {
            map[i][29] = none;

        }
        map[i][30] = wall;
    }
    map[12][23] = score_point;
    score_point_number++;
    map[11][23] = score_point;
    score_point_number++;
    /*map[10][23] = score_point;
    score_point_number++;
    map[9][23] = score_point;
    score_point_number++;
    map[8][23] = score_point;
    score_point_number++;
    map[7][23] = score_point;
    score_point_number++;
    map[6][23] = score_point;
    score_point_number++;
    map[15][23] = score_point;
    score_point_number++;
    map[16][23] = score_point;
    score_point_number++;
    map[17][23] = score_point;
    score_point_number++;*/
}

Map::~Map()
{
    for (int i = 0; i < map_width; i++) {
        delete [] map[i];
    }
    delete [] map;
}

int Map::getMap_height() const
{
    return map_height;
}

int Map::getMap_width() const
{
    return map_width;
}

int Map::getScore_point_number() const
{
    return score_point_number;
}

void Map::score_point_number_decrement()
{
    score_point_number--;
}

Map::map_fields Map::getMapAtPosition(int x, int y) const
{
    return map[x][y];
}

void Map::setMapAtPosition(int x, int y, Map::map_fields value)
{
    map[x][y] = value;
}

