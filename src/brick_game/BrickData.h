#ifndef BRICK_GAME_SRC_BRICK_GAME_BRICK_DATA_H
#define BRICK_GAME_SRC_BRICK_GAME_BRICK_DATA_H

#include "../auxilary/matrix/matrix.h"

typedef enum{
    TetrisGame,
    SnakeGame,
    Exit
} GamesList_t;

typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
} UserAction_t;

typedef struct {
    Matrix *field;
    Matrix *next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

#define START_SPEED 800
const size_t ROW = 20;
const size_t COL = 10;
const size_t STEP_LEVEL = 5;
const size_t STEP_SPEED = 10;
const size_t MAX_LEVEL = 10;

#endif // BRICK_GAME_SRC_BRICK_GAME_BRICK_DATA_H