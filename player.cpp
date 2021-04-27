#include "player.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::getLeft_wall() const
{
    return left_wall;
}

void Player::setLeft_wall(bool value)
{
    left_wall = value;
}

bool Player::getRight_wall() const
{
    return right_wall;
}

void Player::setRight_wall(bool value)
{
    right_wall = value;
}

bool Player::getUp_wall() const
{
    return up_wall;
}

void Player::setUp_wall(bool value)
{
    up_wall = value;
}

bool Player::getDown_wall() const
{
    return down_wall;
}

void Player::setDown_wall(bool value)
{
    down_wall = value;
}

int Player::getX() const
{
    return x;
}

void Player::setX(int value)
{
    x = value;
}

int Player::getY() const
{
    return y;
}

void Player::setY(int value)
{
    y = value;
}

int Player::getFirst_y() const
{
    return first_y;
}

int Player::getTarget_x() const
{
    return target_x;
}

void Player::setTarget_x(int value)
{
    target_x = value;
}

int Player::getTarget_y() const
{
    return target_y;
}

void Player::setTarget_y(int value)
{
    target_y = value;
}

int Player::getFirst_x() const
{
    return first_x;
}

Player::direction Player::getMove_direction() const
{
    return move_direction;
}

void Player::setMove_direction(const Player::direction &value)
{
    move_direction = value;
}

void Player::checkWalls(Map *map)
{
    if (map->getMapAtPosition(getX() + 1, getY()) == Map::wall) {
        setRight_wall(true);
    } else {
        setRight_wall(false);
    }
    if (map->getMapAtPosition(getX() - 1, getY()) == Map::wall) {
        setLeft_wall(true);
    } else {
        setLeft_wall(false);
    }
    if (map->getMapAtPosition(getX(), getY() + 1) == Map::wall) {
        setDown_wall(true);
    } else {
        setDown_wall(false);
    }
    if (map->getMapAtPosition(getX(), getY() - 1) == Map::wall) {
        setUp_wall(true);
    } else {
        setUp_wall(false);
    }
}
