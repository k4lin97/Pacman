#ifndef GAMEDRAWER_H
#define GAMEDRAWER_H

#include "map.h"
#include "player.h"

#include <QPixmap>

class GameDrawer
{
public:
    GameDrawer();
    ~GameDrawer();

    void drawMap(QPixmap *mapPixmap, Map *map);
    void drawPlayer(QPixmap *mapPixmap, Player *player);
    void drawBlueGhost(QPixmap *mapPixmap, Player *ghost);
    void drawOrangeGhost(QPixmap *mapPixmap, Player *ghost);
    void drawPinkGhost(QPixmap *mapPixmap, Player *ghost);
    void drawRedGhost(QPixmap *mapPixmap, Player *ghost);

    int getDrawing_scale() const;

private:
    const int drawing_scale;
};

#endif // GAMEDRAWER_H
