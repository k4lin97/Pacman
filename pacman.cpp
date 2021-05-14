#include "pacman.h"

Pacman::Pacman()
{
    setLeft_wall(false);
    setRight_wall(false);
    setUp_wall(false);
    setDown_wall(false);

    first_x = 13;
    first_y = 23;
    setX(first_x);
    setY(first_y);

    setTarget_x(0);
    setTarget_y(0);

    setMove_direction(Player::none);

    setHealth(3);
    setScore(0);
    setCan_eat(false);
}

Pacman::~Pacman()
{

}

int Pacman::getHealth() const
{
    return health;
}

void Pacman::setHealth(int value)
{
    health = value;
}

int Pacman::getScore() const
{
    return score;
}

void Pacman::setScore(int value)
{
    score = value;
}

bool Pacman::getCan_eat() const
{
    return can_eat;
}

void Pacman::setCan_eat(bool value)
{
    can_eat = value;
}

void Pacman::setFirst_x(int value)
{
    first_x = value;
}

void Pacman::setFirst_y(int value)
{
    first_y = value;
}

void Pacman::move(Map *map)
{
    if (getMove_direction() == Player::left) {
        if (!left_wall) {
            if (map->getMapAtPosition(getX() - 1, getY()) == Map::score_point) {
                setScore(getScore() + 1);
                map->score_point_number_decrement();
                map->setMapAtPosition(getX() - 1, getY(), Map::none);
            } else if (map->getMapAtPosition(getX() - 1, getY()) == Map::fruit) {
                setCan_eat(true);
                map->setMapAtPosition(getX() - 1, getY(), Map::none);
            }
            setX(getX() - 1);
        } else {
            //ignore
        }
    } else if (getMove_direction() == Player::right) {
        if (!right_wall) {
            if (map->getMapAtPosition(getX() + 1, getY()) == Map::score_point) {
                setScore(getScore() + 1);
                map->score_point_number_decrement();
                map->setMapAtPosition(getX() + 1, getY(), Map::none);
            } else if (map->getMapAtPosition(getX() + 1, getY()) == Map::fruit) {
                setCan_eat(true);
                map->setMapAtPosition(getX() + 1, getY(), Map::none);
            }
            setX(getX() + 1);
        } else {
            //ignore
        }
    } else if (getMove_direction() == Player::up) {
        if (!up_wall) {
            if (map->getMapAtPosition(getX(), getY() - 1) == Map::score_point) {
                setScore(getScore() + 1);
                map->score_point_number_decrement();
                map->setMapAtPosition(getX(), getY() - 1, Map::none);
            } else if (map->getMapAtPosition(getX(), getY() - 1) == Map::fruit) {
                setCan_eat(true);
                map->setMapAtPosition(getX(), getY() - 1, Map::none);
            }
            setY(getY() - 1);
        } else {
            //ignore
        }
    } else if (getMove_direction() == Player::down) {
        if (!down_wall) {
            if (map->getMapAtPosition(getX(), getY() + 1) == Map::score_point) {
                setScore(getScore() + 1);
                map->score_point_number_decrement();
                map->setMapAtPosition(getX(), getY() + 1, Map::none);
            } else if (map->getMapAtPosition(getX(), getY() + 1) == Map::fruit) {
                setCan_eat(true);
                map->setMapAtPosition(getX(), getY() + 1, Map::none);
            }
            setY(getY() + 1);
        } else {
            //ignore
        }
    } else if (getMove_direction() == Player::none) {
        //ingore
    }
}
