#ifndef PACMAN_H
#define PACMAN_H

#include "player.h"

class Pacman : public Player
{
public:
    Pacman();
    ~Pacman();

    int getHealth() const;
    void setHealth(int value);

    int getScore() const;
    void setScore(int value);

    bool getCan_eat() const;
    void setCan_eat(bool value);

    void setFirst_x(int value);
    void setFirst_y(int value);

    void move(Map *map);

private:
    int health;
    int score;
    bool can_eat;
};

#endif // PACMAN_H
