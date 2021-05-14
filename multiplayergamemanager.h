#ifndef MULTIPLAYERGAMEMANAGER_H
#define MULTIPLAYERGAMEMANAGER_H

#include "gamemanager.h"
#include "closewindow.h"

class MultiplayerGameManager : public GameManager
{
public:
    MultiplayerGameManager(QWidget *parent = nullptr);
    ~MultiplayerGameManager();

    QTimer *getTimer_game() const;

    int getRedGhostPositionX() const;
    void setRedGhostPositionX(int value);

    int getRedGhostPositionY() const;
    void setRedGhostPositionY(int value);

    int getOrangeGhostPositionX() const;
    void setOrangeGhostPositionX(int value);

    int getOrangeGhostPositionY() const;
    void setOrangeGhostPositionY(int value);

    int getBlueGhostPositionX() const;
    void setBlueGhostPositionX(int value);

    int getBlueGhostPositionY() const;
    void setBlueGhostPositionY(int value);

    int getPinkGhostPositionX() const;
    void setPinkGhostPositionX(int value);

    int getPinkGhostPositionY() const;
    void setPinkGhostPositionY(int value);

    int getOtherPacmanPositionX() const;
    void setOtherPacmanPositionX(int value);

    int getOtherPacmanPositionY() const;
    void setOtherPacmanPositionY(int value);

    int getPacmanPositionX() const;
    void setPacmanPositionX(int value);

    int getPacmanPositionY() const;
    void setPacmanPositionY(int value);

    int getScorePoints() const;
    void setScorePoints(int value);

    void closeGame();

    int getGameLoseClose() const;

protected:
    void gameLose() override;

    bool checkWinningConditions() override;

private:
    int redGhostPositionX;
    int redGhostPositionY;

    int orangeGhostPositionX;
    int orangeGhostPositionY;

    int blueGhostPositionX;
    int blueGhostPositionY;

    int pinkGhostPositionX;
    int pinkGhostPositionY;

    int pacmanPositionX;
    int pacmanPositionY;

    int otherPacmanPositionX;
    int otherPacmanPositionY;

    int scorePoints;
    int maxScorePoints;

    int gameLoseClose;

    CloseWindow *lose_window;
};

#endif // MULTIPLAYERGAMEMANAGER_H
