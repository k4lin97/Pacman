#ifndef PINKGHOST_H
#define PINKGHOST_H

#include "ghost.h"

class PinkGhost : public Ghost
{
public:
    PinkGhost();
    ~PinkGhost();

    virtual void calculateTarget(Player *pacman) override;
};

#endif // PINKGHOST_H
