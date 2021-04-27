#ifndef BLUEGHOST_H
#define BLUEGHOST_H

#include "ghost.h"

class BlueGhost : public Ghost
{
public:
    BlueGhost();
    ~BlueGhost();

    virtual void calculateTarget(Player *pacman) override;
};

#endif // BLUEGHOST_H
