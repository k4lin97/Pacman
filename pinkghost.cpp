#include "pinkghost.h"

PinkGhost::PinkGhost()
{
    setLeft_wall(false);
    setRight_wall(false);
    setUp_wall(false);
    setDown_wall(false);

    first_x = 9;
    first_y = 11;
    setX(first_x);
    setY(first_y);

    setTarget_x(0);
    setTarget_y(0);

    setMove_direction(Player::right);

    setGhost_stage(Ghost::scatter);
}

PinkGhost::~PinkGhost()
{

}

void PinkGhost::calculateTarget(Player *pacman)
{
    if (getGhost_stage() == Ghost::scatter) {
        setTarget_x(0);
        setTarget_y(0);
    } else if (getGhost_stage() == Ghost::chase) {
        if (pacman->getMove_direction() == Player::right) {
            pacman->setTarget_x(pacman->getX() + 4);
            pacman->setTarget_y(pacman->getY());
        } else if (pacman->getMove_direction() == Player::left) {
            setTarget_x(pacman->getX() - 4);
            setTarget_y(pacman->getY());
        } else if (pacman->getMove_direction() == Player::up) {
            setTarget_x(pacman->getX());
            setTarget_y(pacman->getY() - 4);
        } else if (pacman->getMove_direction() == Player::down) {
            setTarget_x(pacman->getX());
            setTarget_y(pacman->getY() + 4);
        }
    }
}
