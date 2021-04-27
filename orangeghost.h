#ifndef ORANGEGHOST_H
#define ORANGEGHOST_H

#include "ghost.h"

class OrangeGhost : public Ghost
{
public:
    OrangeGhost();
    ~OrangeGhost();

    virtual void calculateTarget(Player *pacman) override;
};

#endif // ORANGEGHOST_H
