#include "redghost.h"

RedGhost::RedGhost()
{
    setLeft_wall(false);
    setRight_wall(false);
    setUp_wall(false);
    setDown_wall(false);

    first_x = 18;
    first_y = 11;
    setX(first_x);
    setY(first_y);

    setTarget_x(0);
    setTarget_y(0);

    setMove_direction(Player::left);

    setGhost_stage(Ghost::scatter);
}

RedGhost::~RedGhost()
{

}

void RedGhost::calculateTarget(Player *pacman)
{
    if (getGhost_stage() == Ghost::scatter) {
        setTarget_x(27);
        setTarget_y(0);
    } else if (getGhost_stage() == Ghost::chase) {
        setTarget_x(pacman->getX());
        setTarget_y(pacman->getY());
    }
}
