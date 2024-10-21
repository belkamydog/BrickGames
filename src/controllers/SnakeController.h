#ifndef BRICK_GAME_SRC_CONTROLLER_CONTROLLER_H
#define BRICK_GAME_SRC_CONTROLLER_CONTROLLER_H

#include "../brick_game/snake/Snake.h"

using namespace s21;

class SnakeController{
    public:
        void update();
    private:
        Snake Snake_;
};

#endif // BRICK_GAME_SRC_CONTROLLER_CONTROLLER_H