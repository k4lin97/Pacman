#include "ghost.h"

#include <math.h>

Ghost::Ghost()
{

}

Ghost::~Ghost()
{

}

Ghost::stage Ghost::getGhost_stage() const
{
    return ghost_stage;
}

void Ghost::setGhost_stage(const stage &value)
{
    ghost_stage = value;
}

void Ghost::changeStage()
{
    if (getGhost_stage() == Ghost::scatter) {
        if (getMove_direction() == Ghost::right) {
            setMove_direction(Ghost::left);
        } else if (getMove_direction() == Ghost::left) {
            setMove_direction(Ghost::right);
        } else if (getMove_direction() == Ghost::up) {
            setMove_direction(Ghost::down);
        } else if (getMove_direction() == Ghost::down) {
            setMove_direction(Ghost::up);
        }
        setGhost_stage(Ghost::chase);
    } else if (getGhost_stage() == Ghost::chase) {
        setGhost_stage(Ghost::scatter);
    }
}

void Ghost::move()
{
    //duszek nie moze sie cofnac
    //priorytet: gora, lewo, dol, prawo
    if (getMove_direction() == Ghost::right) {
        if ((!right_wall) && (!up_wall) && (!down_wall)) {
            //nigdzie nie ma sciany
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if ((distance_up <= distance_down) && (distance_up <= distance_right)) {
                //przy rownych gora ma priorytet
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else if ((distance_down <= distance_up) && (distance_down <= distance_right)) {
                if (distance_down == distance_up) {
                    //gora ma priorytet
                    setMove_direction(Ghost::up);
                    setY(getY() - 1);
                } else if (distance_down == distance_right) {
                    //dol ma priorytet
                    setMove_direction(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMove_direction(Ghost::down);
                    setY(getY() + 1);
                }
            } else if ((distance_right <= distance_up) && (distance_right <= distance_down)) {
                if (distance_right == distance_up) {
                    //gora ma priorytet
                    setMove_direction(Ghost::up);
                    setY(getY() - 1);
                } else if (distance_right == distance_down) {
                    //dol ma priorytet
                    setMove_direction(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMove_direction(Ghost::right);
                    setX(getX() + 1);
                }
            }
        } else if ((right_wall) && (up_wall) && (!down_wall)) {
            //sciana jest u gory i z prawej
            setMove_direction(Ghost::down);
            setY(getY() + 1);
        } else if ((right_wall) && (down_wall) && (!up_wall)) {
            //sciana jest z prawej i z dolu
            setMove_direction(Ghost::up);
            setY(getY() - 1);
        } else if ((up_wall) && (down_wall) && (!right_wall)) {
            //sciana jest u gory i na dole
            setMove_direction(Ghost::right);
            setX(getX() + 1);
        } else if ((up_wall) && (!right_wall) && (!down_wall)) {
            //sciana jest u gory
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if (distance_down <= distance_right) {
                setMove_direction(Ghost::down);
                setY(getY() + 1);
            } else {
                setMove_direction(Ghost::right);
                setX(getX() + 1);
            }
        } else if ((!up_wall) && (right_wall) && (!down_wall)) {
            //sciana jest z prawej
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            if (distance_up <= distance_down) {
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else {
                setMove_direction(Ghost::down);
                setY(getY() + 1);
            }
        } else if ((!up_wall) && (!right_wall) && (down_wall)) {
            //sciana jest z dolu
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if (distance_up <= distance_right) {
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else {
                setMove_direction(Ghost::right);
                setX(getX() + 1);
            }
        }
    } else if (getMove_direction() == Ghost::left) {
        if ((!down_wall) && (!up_wall) && (!left_wall)) {
            //nigdzie nie ma sciany
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            if ((distance_up <= distance_left) && (distance_up <= distance_down)) {
                //przy rownych gora ma priorytet
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else if ((distance_left <= distance_up) && (distance_left <= distance_down)) {
                if (distance_left == distance_up) {
                    //gora ma priorytet
                    setMove_direction(Ghost::up);
                    setY(getY() - 1);
                } else if (distance_left == distance_down) {
                    //lewo ma priorytet
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                }
            } else if ((distance_down <= distance_up) && (distance_down <= distance_left)) {
                if (distance_down == distance_up) {
                    //gora ma priorytet
                    setMove_direction(Ghost::up);
                    setY(getY() - 1);
                } else if (distance_down == distance_left) {
                    //lewo ma priorytet
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMove_direction(Ghost::down);
                    setY(getY() + 1);
                }
            }
        } else if ((!down_wall) && (up_wall) && (left_wall)) {
            //sciana jest u gory i z lewej
            setMove_direction(Ghost::down);
            setY(getY() + 1);
        } else if ((down_wall) && (up_wall) && (!left_wall)) {
            //sciana jest u gory i na dole
            setMove_direction(Ghost::left);
            setX(getX() - 1);
        } else if ((down_wall) && (!up_wall) && (left_wall)) {
            //sciana jest z lewej i na dole
            setMove_direction(Ghost::up);
            setY(getY() - 1);
        } else if ((!down_wall) && (up_wall) && (!left_wall)) {
            //sciana jest u gory
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            if (distance_left <= distance_down) {
                setMove_direction(Ghost::left);
                setX(getX() - 1);
            } else {
                setMove_direction(Ghost::down);
                setY(getY() + 1);
            }
        } else if ((down_wall) && (!up_wall) && (!left_wall)) {
            //sciana jest na dole
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            if (distance_up <= distance_left) {
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else {
                setMove_direction(Ghost::left);
                setX(getX() - 1);
            }
        } else if ((!down_wall) && (!up_wall) && (left_wall)) {
            //sciana jest z lewej
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            if (distance_up <= distance_down) {
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else {
                setMove_direction(Ghost::down);
                setY(getY() + 1);
            }
        }
    } else if (getMove_direction() == Ghost::up) {
        if ((!right_wall) && (!up_wall) && (!left_wall)) {
            //nigdzie nie ma sciany
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if ((distance_up <= distance_left) && (distance_up <= distance_right)) {
                //przy rownych gora ma priorytet
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else if ((distance_left <= distance_up) && (distance_left <= distance_right)) {
                if (distance_left == distance_up) {
                    //gora ma priorytet
                    setMove_direction(Ghost::up);
                    setY(getY() - 1);
                } else if (distance_left == distance_right) {
                    //lewo ma priorytet
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                }
            } else if ((distance_right <= distance_up) && (distance_right <= distance_left)) {
                if (distance_right == distance_up) {
                    //gora ma priorytet
                    setMove_direction(Ghost::up);
                    setY(getY() - 1);
                } else if (distance_right == distance_left) {
                    //dol ma priorytet
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                } else {
                    setMove_direction(Ghost::right);
                    setX(getX() + 1);
                }
            }
        } else if ((right_wall) && (up_wall) && (!left_wall)) {
            //sciana jest u gory i z prawej
            setMove_direction(Ghost::left);
            setX(getX() - 1);
        } else if ((right_wall) && (!up_wall) && (left_wall)) {
            //sciana jest z prawej i z lewej
            setMove_direction(Ghost::up);
            setY(getY() - 1);
        } else if ((!right_wall) && (up_wall) && (left_wall)) {
            //sciana jest u gory i z lewej
            setMove_direction(Ghost::right);
            setX(getX() + 1);
        } else if ((!right_wall) && (up_wall) && (!left_wall)) {
            //sciana jest u gory
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if (distance_left <= distance_right) {
                setMove_direction(Ghost::left);
                setX(getX() - 1);
            } else {
                setMove_direction(Ghost::right);
                setX(getX() + 1);
            }
        } else if ((right_wall) && (!up_wall) && (!left_wall)) {
            //sciana jest z prawej
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            if (distance_up <= distance_left) {
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else {
                setMove_direction(Ghost::left);
                setX(getX() - 1);
            }
        } else if ((!right_wall) && (!up_wall) && (left_wall)) {
            //sciana jest z lewej
            int distance_up = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() - 1)), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if (distance_up <= distance_right) {
                setMove_direction(Ghost::up);
                setY(getY() - 1);
            } else {
                setMove_direction(Ghost::right);
                setX(getX() + 1);
            }
        }
    } else if (getMove_direction() == Ghost::down) {
        if ((!right_wall) && (!left_wall) && (!down_wall)) {
            //nigdzie nie ma sciany
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if ((distance_left <= distance_down) && (distance_left <= distance_right)) {
                //przy rownych lewo ma priorytet
                setMove_direction(Ghost::left);
                setX(getX() - 1);
            } else if ((distance_down <= distance_left) && (distance_down <= distance_right)) {
                if (distance_down == distance_left) {
                    //lewo ma priorytet
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                } else if (distance_down == distance_right) {
                    //dol ma priorytet
                    setMove_direction(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMove_direction(Ghost::down);
                    setY(getY() + 1);
                }
            } else if ((distance_right <= distance_left) && (distance_right <= distance_down)) {
                if (distance_right == distance_left) {
                    //lewo ma priorytet
                    setMove_direction(Ghost::left);
                    setX(getX() - 1);
                } else if (distance_right == distance_down) {
                    //dol ma priorytet
                    setMove_direction(Ghost::down);
                    setY(getY() + 1);
                } else {
                    setMove_direction(Ghost::right);
                    setX(getX() + 1);
                }
            }
        } else if ((!right_wall) && (left_wall) && (down_wall)) {
            //sciana jest z lewej i na dole
            setMove_direction(Ghost::right);
            setX(getX() + 1);
        } else if ((right_wall) && (left_wall) && (!down_wall)) {
            //sciana jest z lewej i prawej
            setMove_direction(Ghost::down);
            setY(getY() + 1);
        } else if ((right_wall) && (!left_wall) && (down_wall)) {
            //sciana jest na dole i z prawej
            setMove_direction(Ghost::left);
            setX(getX() - 1);
        } else if ((!right_wall) && (left_wall) && (!down_wall)) {
            //sciana jest z lewej
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if (distance_down <= distance_right) {
                setMove_direction(Ghost::down);
                setY(getY() + 1);
            } else {
                setMove_direction(Ghost::right);
                setX(getX() + 1);
            }
        } else if ((right_wall) && (!left_wall) && (!down_wall)) {
            //sciana jest z prawej
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            int distance_down = pow((getTarget_x() - getX()), 2) + pow((getTarget_y() - (getY() + 1)), 2);
            if (distance_left <= distance_down) {
                setMove_direction(Ghost::left);
                setX(getX() - 1);
            } else {
                setMove_direction(Ghost::down);
                setY(getY() + 1);
            }
        } else if ((!right_wall) && (!left_wall) && (down_wall)) {
            //sciana jest z dolu
            int distance_left = pow((getTarget_x() - (getX() - 1)), 2) + pow((getTarget_y() - getY()), 2);
            int distance_right = pow((getTarget_x() - (getX() + 1)), 2) + pow((getTarget_y() - (getY())), 2);
            if (distance_left <= distance_right) {
                setMove_direction(Ghost::left);
                setX(getX() - 1);
            } else {
                setMove_direction(Ghost::right);
                setX(getX() + 1);
            }
        }
    } else if (getMove_direction() == Ghost::none) {
        //nie rusza sie
    }
}
