#ifndef SECONDGAMEMANAGER_H
#define SECONDGAMEMANAGER_H

#include "multiplayergamemanager.h"

class SecondGameManager : public MultiplayerGameManager
{
public:
    SecondGameManager(QWidget *parent = nullptr);
    ~SecondGameManager();

private slots:
    void gameEngine() override;

private:
    void ghostPlayerInteraction() override;
};

#endif // SECONDGAMEMANAGER_H
