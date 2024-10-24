#include "gamescene.h"

void GameScene::initializeScene()
{
    size_t cell = CELL_SIZE;
    cells_.resize(ROW);
    for (size_t i = 0; i < ROW; ++i) {
        cells_[i].resize(COL);
        for (size_t j = 0; j < COL; ++j) {
            QGraphicsRectItem *r = new QGraphicsRectItem(j*cell, i*cell, cell, cell);
            if (game_.field->body[i][j] > 0) r->setBrush(QBrush (Qt::black));
            else if (game_.field->body[i][j] == -1) r->setBrush(QBrush (Qt::red));
            else r->setPen(QPen(Qt::black));
            this->addItem(r);
            cells_[i][j] = r;
        }
    }
}

void GameScene::updateScene()
{
    for (size_t i = 0; i < ROW; ++i) {
        for (size_t j = 0; j < COL; ++j) {
            if (game_.field->body[i][j] > 0){
                cells_[i][j]->setBrush(QBrush(Qt::black));
            }
            else if (game_.field->body[i][j] == -1){
                cells_[i][j]->setBrush(QBrush(Qt::red));
            }
            else {
                QColor brush_color;
                brush_color.setRgb(158, 172, 136);
                cells_[i][j]->setBrush(QBrush(brush_color));
            }
        }
    }
}

void GameScene::setGame(const GameInfo_t &newGame)
{
    game_ = newGame;
}
