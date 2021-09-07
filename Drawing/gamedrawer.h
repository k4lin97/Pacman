/**
 * @file gamedrawer.h
 * @author Paweł Kalinowski
 * @brief Class used to draw game and all its components.
 * @version 1.0
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef GAMEDRAWER_H
#define GAMEDRAWER_H

#include <QPixmap>

#include "SinglePlayer/map.h"
#include "Player/player.h"

class GameDrawer {
   public:
    /**
     * @brief Construct a new Game Drawer object.
     */
    GameDrawer();

    /**
     * @brief Destroy the Game Drawer object.
     */
    ~GameDrawer();

    /**
     * @brief Map drawing function.
     *
     *The function draws a map based on data from the Map object. The map is
     *drawn on a QPixmap object.
     * @param mapPixmap QPixmap object.
     * @param map Map object.
     */
    void drawMap(QPixmap *mapPixmap, Map *map);

    /**
     * @brief Player drawing function.
     *
     *The function draws the player, based on the data from the player object.
     * @param mapPixmap QPixmap object.
     * @param player Player object.
     */
    void drawPlayer(QPixmap *mapPixmap, Player *player);

    /**
     * @brief Blue ghost drawing function.
     *
     * The function draws the blue ghost, based on the data from the ghost
     * object.
     * @param mapPixmap QPixmap object.
     * @param ghost Blue ghost object.
     */
    void drawBlueGhost(QPixmap *mapPixmap, Player *ghost);

    /**
     * @brief Orange ghost drawing function.
     *
     * The function draws the orange ghost, based on the data from the ghost
     * object.
     * @param mapPixmap QPixmap object.
     * @param ghost Blue Orange object.
     */
    void drawOrangeGhost(QPixmap *mapPixmap, Player *ghost);

    /**
     * @brief Pink ghost drawing function.
     *
     * The function draws the pink ghost, based on the data from the ghost
     * object.
     * @param mapPixmap QPixmap object.
     * @param ghost Blue Pink object.
     */
    void drawPinkGhost(QPixmap *mapPixmap, Player *ghost);

    /**
     * @brief Red ghost drawing function.
     *
     * The function draws the red ghost, based on the data from the ghost
     * object.
     * @param mapPixmap QPixmap object.
     * @param ghost Red ghost object.
     */
    void drawRedGhost(QPixmap *mapPixmap, Player *ghost);

    /**
     * @brief Get the drawing scale.
     *
     * @return int constant - drawing scale.
     */
    int getDrawingScale() const;

    /**
     * @brief Function used for drawing other pacman in multiplayer mode.
     *
     * Used only in multiplayer.
     * @param mapPixmap QPixmap object.
     * @param x X position of the pacman.
     * @param y Y position of the pacman.
     */
    void drawOtherPacman(QPixmap *mapPixmap, int x, int y);

   private:
    // Constant - drawing scale.
    const int drawingScale;
};

#endif  // GAMEDRAWER_H
