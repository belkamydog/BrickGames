#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWidget>
#include <QVector>

#include "../../../brick_game/BrickData.h"

class GameScene: public QGraphicsScene
{
    public:
        void initializeScene();
        void updateScene();
        void setGame(const GameInfo_t &newGame);

private:
        const size_t CELL_SIZE = 12;
        GameInfo_t game_;
        QVector<QVector<QGraphicsRectItem*>> cells_;
};

#endif // GAMESCENE_H
