/**
 * @file gamedrawer.cpp
 * @author Paweł Kalinowski
 * @brief Implementation of gamedrawer.h.
 * @version 1.0
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "gamedrawer.h"

#include <QPainter>

GameDrawer::GameDrawer() : drawingScale(20) {
    // Empty constructor
}
GameDrawer::~GameDrawer() {
    // Empty destructor
}

void GameDrawer::drawMap(QPixmap *mapPixmap, Map *map) {
    QPainter painter(mapPixmap);
    for (int i = 0; i < map->getMapWidth(); i++) {
        for (int j = 0; j < map->getMapHeight(); j++) {
            if (map->getMapAtPosition(i, j) == Map::wall) {
                painter.setBrush(Qt::darkBlue);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawingScale, j * drawingScale,
                                 drawingScale, drawingScale);
            } else if (map->getMapAtPosition(i, j) == Map::scorePoint) {
                painter.setBrush(Qt::blue);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawingScale, j * drawingScale,
                                 drawingScale, drawingScale);
                painter.setBrush(Qt::yellow);
                painter.drawEllipse(i * drawingScale + (drawingScale / 4),
                                    j * drawingScale + (drawingScale / 4),
                                    (drawingScale / 2), (drawingScale / 2));
            } else if (map->getMapAtPosition(i, j) == Map::fruit) {
                painter.setBrush(Qt::green);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawingScale, j * drawingScale,
                                 drawingScale, drawingScale);
            } else {
                painter.setBrush(Qt::blue);
                painter.setPen(Qt::NoPen);
                painter.drawRect(i * drawingScale, j * drawingScale,
                                 drawingScale, drawingScale);
            }
        }
    }
    painter.end();
}

void GameDrawer::drawPlayer(QPixmap *mapPixmap, Player *player) {
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::NoPen);
    painter.drawRect(player->getX() * drawingScale,
                     player->getY() * drawingScale, drawingScale, drawingScale);
    painter.end();
}

void GameDrawer::drawBlueGhost(QPixmap *mapPixmap, Player *ghost) {
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::cyan);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawingScale, ghost->getY() * drawingScale,
                     drawingScale, drawingScale);
    painter.end();
}

void GameDrawer::drawOrangeGhost(QPixmap *mapPixmap, Player *ghost) {
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::darkYellow);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawingScale, ghost->getY() * drawingScale,
                     drawingScale, drawingScale);
    painter.end();
}

void GameDrawer::drawPinkGhost(QPixmap *mapPixmap, Player *ghost) {
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::magenta);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawingScale, ghost->getY() * drawingScale,
                     drawingScale, drawingScale);
    painter.end();
}

void GameDrawer::drawRedGhost(QPixmap *mapPixmap, Player *ghost) {
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::red);
    painter.setPen(Qt::NoPen);
    painter.drawRect(ghost->getX() * drawingScale, ghost->getY() * drawingScale,
                     drawingScale, drawingScale);
    painter.end();
}

int GameDrawer::getDrawingScale() const { return drawingScale; }

void GameDrawer::drawOtherPacman(QPixmap *mapPixmap, int x, int y) {
    QPainter painter(mapPixmap);
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::NoPen);
    painter.drawRect(x * drawingScale, y * drawingScale, drawingScale,
                     drawingScale);
    painter.end();
}
