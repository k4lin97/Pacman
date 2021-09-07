/**
 * @file gamemanager.h
 * @author Paweł Kalinowski
 * @brief Pacman game manager.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QDialog>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>

#include "Player/pacman.h"
#include "Ghosts/redghost.h"
#include "Ghosts/blueghost.h"
#include "Ghosts/orangeghost.h"
#include "Ghosts/pinkghost.h"
#include "SinglePlayer/map.h"
#include "Drawing/gamedrawer.h"
#include "SinglePlayer/closewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GameManager;
}
QT_END_NAMESPACE

class GameManager : public QDialog {
    Q_OBJECT

   public:
    /**
     * @brief Construct a new Game Manager object.
     *
     * @param parent QDialog parent.
     */
    GameManager(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Game Manager object.
     *
     */
    virtual ~GameManager();

    /**
     * @brief Reads the input from keyboard.
     *
     * Sets pacman's move direction and pause/resumes game.
     * @param event Qt event.
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief Get Is Game Paused.
     *
     * @return true if game is paused.
     * @return false if game is not paused.
     */
    bool getIsGamePaused() const;
    /**
     * @brief Set the Is Game Paused.
     *
     * @param value is the game paused?
     */
    void setIsGamePaused(bool value);

   protected slots:
    /**
     * @brief Game engine.
     *
     * Function refreshed according to gameTimer. It is responsible for the
     * whole game - logic and drawing.
     */
    virtual void gameEngine();

    /**
     * @brief Changes ghosts' stages.
     *
     */
    void changeGhostsStage();

    /**
     * @brief Function that is called after the ghost dies. It causes the ghosts
     * to move again.
     *
     */
    void afterGhostDeath();

    /**
     * @brief Function called after pacman dies. It causes the ghosts to move
     * again.
     *
     */
    void afterPacmanDeath();

   protected:
    /**
     * @brief Pacman interaction with every ghost.
     *
     * The function checks the position of pacman and the ghost. There are three
     * types of interaction: eating a ghost, eating a pacman, and game over.
     */
    virtual void ghostPlayerInteraction();

    /**
     * @brief Opens a window when user loses.
     *
     */
    virtual void gameLose();

    /**
     * @brief Opens a window when user wins.
     *
     */
    void gameWin();

    /**
     * @brief Checks if the user wins.
     *
     * @return true if user wins.
     * @return false if user not wins (does not mean loses!).
     */
    virtual bool checkWinningConditions();

    /**
     * @brief Function called when the pacman is eaten but is not dead.
     *
     *Decrements pacmans health and moves him to starting position. Also moves
     *ghosts to theirs starting positions. Waits specified time and calls
     *afterPacmanDeath() function.
     */
    virtual void pacmanEatenButNotDead();

    /**
     * @brief Function called when the pacman eats ghost.
     *
     * Moves eaten ghost to its starting position. Waits specified time and
     *calls afterGhostDeath() function.
     * @param ghost eaten ghost.
     */
    virtual void pacmanEatsGhost(Ghost *ghost);

    Ui::GameManager *ui;

    bool isGamePaused;  // game paused

    const int timerGameMiliseconds;         // game refreshes every period
    const int timerGhostDeathMiliseconds;   // ghost is not able to move during
                                            // this time
    const int timerPacmanDeathMiliseconds;  // all ghosts are not able to move
                                            // during this time
    const int timerStageMiliseconds;  // Ghosts change their stage every period

    Map *map;
    GameDrawer *gameDrawer;

    Pacman *pacman;
    Ghost *redGhost;
    Ghost *pinkGhost;
    Ghost *orangeGhost;
    Ghost *blueGhost;

    QTimer *timerGame;
    QTimer *timerStage;
    QTimer *timerGhostDeath;
    QTimer *timerPacmanDeath;

    QPixmap *mapPixmap;

    QLabel *mapLabel;
    QLabel *scoreLabel;
    QLabel *healthLabel;
    QLabel *timerStageLabel;
    QLabel *gamePlayingLabel;

    CloseWindow *closeWindow;
};
#endif  // GAMEMANAGER_H
