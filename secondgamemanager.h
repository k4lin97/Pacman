#ifndef SECONDGAMEMANAGER_H
#define SECONDGAMEMANAGER_H

#include "multiplayergamemanager.h"

class SecondGameManager : public MultiplayerGameManager
{
public:
    SecondGameManager(QWidget *parent = nullptr);

private slots:
    virtual void gameEngine() override;

};

#endif // SECONDGAMEMANAGER_H
