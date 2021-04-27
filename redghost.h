#ifndef REDGHOST_H
#define REDGHOST_H

#include "ghost.h"

class RedGhost : public Ghost
{
public:
    RedGhost();
    ~RedGhost();

    virtual void calculateTarget(Player *pacman) override;
};

#endif // REDGHOST_H
