#include "gamedrawer.h"

#include <QPainter>

GameDrawer::GameDrawer() : drawing_scale(20)
{

}

GameDrawer::~GameDrawer()
{

}

void GameDrawer::drawMap(QPixmap *mapPixmap, Map *map)
{
    QPainter painter(mapPixmap);
    for (int i = 0; i < map->getMap_width(); i++) {
        for (int j = 0; j< map->getMap_height(); j++) {
            if (map->getMapAtPosition(i, j) == Map::wall) {
                painter.setBrush(Qt::darkBlue);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawing_scale, j * drawing_scale, drawing_scale, drawing_scale);
            } else if (map->getMapAtPosition(i, j) == Map::score_point) {
                painter.setBrush(Qt::blue);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawing_scale, j * drawing_scale, drawing_scale, drawing_scale);
                painter.setBrush(Qt::yellow);
                painter.drawEllipse(i * drawing_scale + (drawing_scale / 4), j * drawing_scale + (drawing_scale / 4), (drawing_scale / 2), (drawing_scale / 2));
            }
            else if (map->getMapAtPosition(i, j) == Map::fruit) {
                painter.setBrush(Qt::green);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawing_scale, j * drawing_scale, drawing_scale, drawing_scale);
            }
            else {
                painter.setBrush(Qt::blue);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawing_scale, j * drawing_scale, drawing_scale, drawing_scale);
            }
        }
    }
    painter.end();
}

void GameDrawer::drawPlayer(QPixmap *mapPixmap, Player *player)
{
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::NoPen);
    painter.drawRect(player->getX() * drawing_scale, player->getY() * drawing_scale, drawing_scale, drawing_scale);
    painter.end();
}

void GameDrawer::drawBlueGhost(QPixmap *mapPixmap, Player *ghost)
{
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::cyan);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawing_scale, ghost->getY() * drawing_scale, drawing_scale, drawing_scale);
    painter.end();
}

void GameDrawer::drawOrangeGhost(QPixmap *mapPixmap, Player *ghost)
{
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::darkYellow);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawing_scale, ghost->getY() * drawing_scale, drawing_scale, drawing_scale);
    painter.end();
}

void GameDrawer::drawPinkGhost(QPixmap *mapPixmap, Player *ghost)
{
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::magenta);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawing_scale, ghost->getY() * drawing_scale, drawing_scale, drawing_scale);
    painter.end();
}

void GameDrawer::drawRedGhost(QPixmap *mapPixmap, Player *ghost)
{
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::red);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawing_scale, ghost->getY() * drawing_scale, drawing_scale, drawing_scale);
    painter.end();
}

int GameDrawer::getDrawing_scale() const
{
    return drawing_scale;
}
