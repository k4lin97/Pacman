#include "blueghost.h"

BlueGhost::BlueGhost()
{
    setLeft_wall(false);
    setRight_wall(false);
    setUp_wall(false);
    setDown_wall(false);

    first_x = 18;
    first_y = 17;
    setX(first_x);
    setY(first_y);

    setTarget_x(0);
    setTarget_y(0);

    setMove_direction(Player::down);

    setGhost_stage(Ghost::scatter);
}

BlueGhost::~BlueGhost()
{

}

void BlueGhost::calculateTarget(Player *pacman)
{
    if (getGhost_stage() == Ghost::scatter) {
        setTarget_x(27);
        setTarget_y(30);
    } else if (getGhost_stage() == Ghost::chase) {
        int temp_x = 0;
        int temp_y = 0;
        if (pacman->getMove_direction() == Player::right) {
            temp_x = (pacman->getX() + 2);
            temp_y = (pacman->getY());
        } else if (pacman->getMove_direction() == Player::left) {
            temp_x = (pacman->getX() - 2);
            temp_y = (pacman->getY());
        } else if (pacman->getMove_direction() == Player::up) {
            temp_x = (pacman->getX());
            temp_y = (pacman->getY() - 2);
        } else if (pacman->getMove_direction() == Player::down) {
            temp_x = (pacman->getX());
            temp_y = (pacman->getY() + 2);
        }
        setTarget_x(temp_x + (temp_x - pacman->getX()));
        //dla y minus poniewaz w dol ida wieksze wartosci
        setTarget_y(temp_y - (temp_y - pacman->getY()));
    }
}
