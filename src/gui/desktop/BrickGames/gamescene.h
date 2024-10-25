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
        GameScene(size_t cell_size, Matrix &matrix);
        void initializeScene();
        void updateScene();
        void updateData(Matrix &matrix);
        void clearScene();

private:
        size_t cell_size_;
        Matrix matrix_;
        QVector<QVector<QGraphicsRectItem*>> cells_;
};

#endif // GAMESCENE_H
