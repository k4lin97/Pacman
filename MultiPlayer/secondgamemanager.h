/**
 * @file secondgamemanager.h
 * @author Paweł Kalinowski
 * @brief Class representing second game manager.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef SECONDGAMEMANAGER_H
#define SECONDGAMEMANAGER_H

#include "multiplayergamemanager.h"

class SecondGameManager : public MultiplayerGameManager {
   public:
    /**
     * @brief Construct a new Second Game Manager object.
     *
     * @param parent QDialog parent.
     */
    SecondGameManager(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Second Game Manager object.
     *
     */
    ~SecondGameManager();

   private slots:
    /**
     * @brief Game engine of second game.
     *
     */
    void gameEngine() override;

   private:
    /**
     * @brief Interaction of pacman and ghosts.
     *
     * It is the same as in single player. The only difference is the called
     * functions - they have to be the ones from this class.
     */
    void ghostPlayerInteraction() override;

    /**
     * @brief Function called when pacman is eaten but do not dies.
     *
     * It deducts pacman's health and sets it to its initial position.
     * It also sets pacman eaten but not dead bool which is used
     * in main game.
     */
    void pacmanEatenButNotDead() override;

    /**
     * @brief Function called when pacman eats ghost.
     *
     * It sets ghost to its initial position.
     * It also sets ghost eaten bool which is used in main game.
     * @param ghost eaten ghost.
     */
    void pacmanEatsGhost(Ghost *ghost) override;
};

#endif  // SECONDGAMEMANAGER_H
