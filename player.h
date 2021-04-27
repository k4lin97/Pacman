#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"

class Player
{
public:
    Player();
    virtual ~Player();

    bool getLeft_wall() const;
    void setLeft_wall(bool value);

    bool getRight_wall() const;
    void setRight_wall(bool value);

    bool getUp_wall() const;
    void setUp_wall(bool value);

    bool getDown_wall() const;
    void setDown_wall(bool value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getFirst_x() const;

    int getFirst_y() const;

    int getTarget_x() const;
    void setTarget_x(int value);

    int getTarget_y() const;
    void setTarget_y(int value);

    enum direction {
        left,
        right,
        up,
        down,
        none
    };

    Player::direction getMove_direction() const;
    void setMove_direction(const Player::direction &value);

    void checkWalls(Map *map);

protected:
    bool left_wall;
    bool right_wall;
    bool up_wall;
    bool down_wall;

    int x;
    int y;
    int first_x;
    int first_y;
    int target_x;
    int target_y;

    direction move_direction;
};

#endif // PLAYER_H
