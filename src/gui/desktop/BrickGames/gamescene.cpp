#include "gamescene.h"

GameScene::GameScene(size_t cell_size, Matrix &matrix)
{
    cell_size_ = cell_size;
    matrix_ = matrix;
}

void GameScene::initializeScene()
{
    cells_.resize(matrix_.row);
    QColor field_color;
    field_color.setRgb(158, 172, 136);
    QColor body;
    body.setRgb(40, 45, 20);
    for (size_t i = 0; i < matrix_.row; ++i) {
        cells_[i].resize(matrix_.col);
        for (size_t j = 0; j < matrix_.col; ++j) {
            QGraphicsRectItem *r = new QGraphicsRectItem(j*cell_size_, i*cell_size_, cell_size_, cell_size_);
            if (matrix_.body[i][j] > 0) r->setBrush(QBrush (body));
            else if (matrix_.body[i][j] == -1) r->setBrush(QBrush (body));
            r->setPen(QPen(field_color));
            this->addItem(r);
            cells_[i][j] = r;
        }
    }
}

void GameScene::updateScene()
{
    QColor body;
    body.setRgb(40, 45, 20);
    for (size_t i = 0; i < matrix_.row; ++i) {
        for (size_t j = 0; j < matrix_.col; ++j) {
            if (matrix_.body[i][j] > 0){
                cells_[i][j]->setBrush(QBrush(body));
            }
            else if (matrix_.body[i][j] == -1){
                cells_[i][j]->setBrush(QBrush(body));
            }
            else {
                QColor brush_color;
                brush_color.setRgb(158, 172, 136);
                cells_[i][j]->setBrush(QBrush(brush_color));
            }
        }
    }
}

void GameScene::updateData(Matrix &matrix)
{
    matrix_= matrix;
}

void GameScene::clearScene()
{
    QColor body;
    body.setRgb(40, 45, 20);
    for (size_t i = 0; i < matrix_.row; ++i) {
        for (size_t j = 0; j < matrix_.col; ++j) {
                QColor brush_color;
                brush_color.setRgb(158, 172, 136);
                cells_[i][j]->setBrush(QBrush(brush_color));
        }
    }
}

