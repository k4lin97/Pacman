/**
 * @file maingamemanager.h
 * @author Paweł Kalinowski
 * @brief Class representing main game manager.
 * @version 1.0
 * @date 2021-09-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef MAINGAMEMANAGER_H
#define MAINGAMEMANAGER_H

#include "multiplayergamemanager.h"

class MainGameManager : public MultiplayerGameManager {
   public:
    /**
     * @brief Construct a new Main Game Manager object.
     *
     * @param parent QDialog parent.
     */
    MainGameManager(QWidget *parent = nullptr);

    /**
     * @brief Destroy the Main Game Manager object.
     *
     */
    ~MainGameManager();

   private slots:
    /**
     * @brief Game engine of main game.
     *
     */
    void gameEngine() override;
};

#endif  // MAINGAMEMANAGER_H
