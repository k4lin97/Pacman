#include "orangeghost.h"

#include <math.h>

OrangeGhost::OrangeGhost()
{
    setLeft_wall(false);
    setRight_wall(false);
    setUp_wall(false);
    setDown_wall(false);

    first_x = 9;
    first_y = 17;
    setX(first_x);
    setY(first_y);

    setTarget_x(0);
    setTarget_y(0);

    setMove_direction(Player::down);

    setGhost_stage(Ghost::scatter);
}

OrangeGhost::~OrangeGhost()
{

}

void OrangeGhost::calculateTarget(Player *pacman)
{
    if (getGhost_stage() == Ghost::scatter) {
        setTarget_x(0);
        setTarget_y(30);
    } else if (getGhost_stage() == Ghost::chase) {
        //promien okregu wynosi 8
        int circle_radius = pow(pacman->getX() - getX(), 2) + pow(pacman->getY() - getY(), 2);
        if (circle_radius > 64) {
            setTarget_x(pacman->getX());
            setTarget_y(pacman->getY());
        } else {
            setTarget_x(0);
            setTarget_y(30);
        }
    }
}
