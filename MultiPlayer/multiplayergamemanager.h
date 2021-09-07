/**
 * @file multiplayergamemanager.h
 * @author Paweł Kalinowski
 * @brief Class that extends game manager in order to play in multiplayer.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef MULTIPLAYERGAMEMANAGER_H
#define MULTIPLAYERGAMEMANAGER_H

#include "SinglePlayer/gamemanager.h"
#include "SinglePlayer/closewindow.h"

class MultiplayerGameManager : public GameManager {
   public:
    /**
     * @brief Construct a new Multiplayer Game Manager object.
     *
     * @param parent QDialog parent.
     */
    MultiplayerGameManager(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Multiplayer Game Manager object.
     *
     */
    ~MultiplayerGameManager();

    /**
     * @brief Get the game timer.
     *
     * @return QTimer* pointer to game timer.
     */
    QTimer *getTimerGame() const;

    /**
     * @brief Get the Red Ghost Position X.
     *
     * @return int Red Ghost Position X.
     */
    int getRedGhostPositionX() const;
    /**
     * @brief Set the Red Ghost Position X.
     *
     * @param value Red Ghost Position X.
     */
    void setRedGhostPositionX(int value);

    /**
     * @brief Get the Red Ghost Position Y.
     *
     * @return int Red Ghost Position Y.
     */
    int getRedGhostPositionY() const;
    /**
     * @brief Set the Red Ghost Position Y.
     *
     * @param value Red Ghost Position Y.
     */
    void setRedGhostPositionY(int value);

    /**
     * @brief Get the Orange Ghost Position X.
     *
     * @return int Orange Ghost Position X.
     */
    int getOrangeGhostPositionX() const;
    /**
     * @brief Set the Orange Ghost Position X.
     *
     * @param value Orange Ghost Position X.
     */
    void setOrangeGhostPositionX(int value);

    /**
     * @brief Get the Orange Ghost Position Y.
     *
     * @return int Orange Ghost Position Y.
     */
    int getOrangeGhostPositionY() const;
    /**
     * @brief Set the Orange Ghost Position Y.
     *
     * @param value Orange Ghost Position Y.
     */
    void setOrangeGhostPositionY(int value);

    /**
     * @brief Get the Blue Ghost Position X.
     *
     * @return int Blue Ghost Position X.
     */
    int getBlueGhostPositionX() const;
    /**
     * @brief Set the Blue Ghost Position X.
     *
     * @param value Blue Ghost Position X.
     */
    void setBlueGhostPositionX(int value);

    /**
     * @brief Get the Blue Ghost Position Y.
     *
     * @return int Blue Ghost Position Y.
     */
    int getBlueGhostPositionY() const;
    /**
     * @brief Set the Blue Ghost Position Y.
     *
     * @param value Blue Ghost Position Y.
     */
    void setBlueGhostPositionY(int value);
    /**
     * @brief Get the Pink Ghost Position X.
     *
     * @return int Pink Ghost Position X.
     */
    int getPinkGhostPositionX() const;
    /**
     * @brief Set the Pink Ghost Position X.
     *
     * @param value Pink Ghost Position X.
     */
    void setPinkGhostPositionX(int value);

    /**
     * @brief Get the Pink Ghost Position Y.
     *
     * @return int Ghost Position Y.
     */
    int getPinkGhostPositionY() const;
    /**
     * @brief Set the Pink Ghost Position Y.
     *
     * @param value Ghost Position Y.
     */
    void setPinkGhostPositionY(int value);

    /**
     * @brief Get the Other Pacman Position X.
     *
     * @return int Other Pacman Position X.
     */
    int getOtherPacmanPositionX() const;
    /**
     * @brief Set the Other Pacman Position X.
     *
     * @param value Other Pacman Position X.
     */
    void setOtherPacmanPositionX(int value);

    /**
     * @brief Get the Other Pacman Position Y.
     *
     * @return int Other Pacman Position Y.
     */
    int getOtherPacmanPositionY() const;
    /**
     * @brief Set the Other Pacman Position Y.
     *
     * @param value Other Pacman Position Y.
     */
    void setOtherPacmanPositionY(int value);

    /**
     * @brief Get the Pacman Position X.
     *
     * @return int Pacman Position X.
     */
    int getPacmanPositionX() const;
    /**
     * @brief Set the Pacman Position X.
     *
     * @param value Pacman Position X.
     */
    void setPacmanPositionX(int value);

    /**
     * @brief Get the Pacman Position Y.
     *
     * @return int Pacman Position Y.
     */
    int getPacmanPositionY() const;
    /**
     * @brief Set the Pacman Position Y.
     *
     * @param value Pacman Position Y.
     */
    void setPacmanPositionY(int value);

    /**
     * @brief Get the Score Points.
     *
     * @return int Score Points.
     */
    int getScorePoints() const;
    /**
     * @brief Set the Score Points.
     *
     * @param value Score Points.
     */
    void setScorePoints(int value);

    /**
     * @brief Closes game when the player loses
     *
     */
    void closeGame();

    /**
     * @brief Get the Game Lose Close.
     *
     * @return int
     */
    int getGameLoseClose() const;

    /**
     * @brief Get the Score Points Received From Server.
     *
     * @return int Score Points Received From Server
     */
    int getScorePointsReceivedFromServer() const;
    /**
     * @brief Set the Score Points Received From Server.
     *
     * @param value Score Points Received From Server
     */
    void setScorePointsReceivedFromServer(int value);

    /**
     * @brief Get the Pacman Eaten But Not Dead.
     *
     * @return true pacman eaten but not dead.
     * @return false pacman not eaten.
     */
    bool getPacmanEatenButNotDeadBool() const;
    /**
     * @brief Set the Pacman Eaten But Not Dead.
     *
     * @param value Pacman Eaten But Not Dead.
     */
    void setPacmanEatenButNotDeadBool(bool value);

    /**
     * @brief Actions performed when pacman is eaten in second game.
     *
     */
    void pacmanEatenInSecondGame();

    /**
     * @brief Actions performed when ghost is eaten in second game.
     *
     * @param _x eaten ghost's X position.
     * @param _y eaten ghost's Y position.
     */
    void ghostEatenInSecondGame(int _x, int _y);

    /**
     * @brief Get the Ghost Eaten.
     *
     * @return true ghost was eaten.
     * @return false ghost wsa not eaten.
     */
    bool getGhostEaten() const;
    /**
     * @brief Set the Ghost Eaten.
     *
     * @param value was ghost eaten.
     */
    void setGhostEaten(bool value);

    /**
     * @brief Get the Eaten Ghost X.
     *
     * @return int Eaten Ghost X.
     */
    int getEatenGhostX() const;
    /**
     * @brief Set the Eaten Ghost X.
     *
     * @param value Eaten Ghost X.
     */
    void setEatenGhostX(int value);

    /**
     * @brief Get the Eaten Ghost Y.
     *
     * @return int Eaten Ghost Y.
     */
    int getEatenGhostY() const;
    /**
     * @brief Set the Eaten Ghost Y.
     *
     * @param value Eaten Ghost Y.
     */
    void setEatenGhostY(int value);

   protected:
    /**
     * @brief Close game when lose.
     *
     */
    void gameLose() override;

    /**
     * @brief Check winning conditions in multiplayer.
     *
     * @return true game was won.
     * @return false game was not won.
     */
    bool checkWinningConditions() override;

   private:
    // Fields used in multiplayer
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

    int scorePoints;  // Score points to visualize
    int maxScorePoints;
    int scorePointsReceivedFromServer;

    bool gameLoseClose;
    bool pacmanEatenButNotDeadBool;
    bool ghostEaten;

    int eatenGhostX;
    int eatenGhostY;

    CloseWindow *loseWindow;
};

#endif  // MULTIPLAYERGAMEMANAGER_H
