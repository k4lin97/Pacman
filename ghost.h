#ifndef GHOST_H
#define GHOST_H

#include "player.h"

class Ghost : public Player
{
public:
    Ghost();
    ~Ghost();

    enum stage {
        scatter,
        chase
    };

    stage getGhost_stage() const;
    void setGhost_stage(const stage &value);

    void changeStage();

    void move();

    virtual void calculateTarget(Player *pacman) = 0;

protected:
    stage ghost_stage;
};

#endif // GHOST_H
