#ifndef MAINGAMEMANAGER_H
#define MAINGAMEMANAGER_H

#include "multiplayergamemanager.h"

class MainGameManager : public MultiplayerGameManager
{
public:
    MainGameManager(QWidget *parent = nullptr);
    ~MainGameManager();

private slots:
    void gameEngine() override;
};

#endif // MAINGAMEMANAGER_H
