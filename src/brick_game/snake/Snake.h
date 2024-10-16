#ifndef SNAKE_BRICK_GAME_SRC_BRICK_GAME_SNAKE_SNAKE_H
#define SNAKE_BRICK_GAME_SRC_BRICK_GAME_SNAKE_SNAKE_H

#include "../BrickGame.h"

namespace s21{
    class Snake:public BrickGame {
        public:
            Snake();
            ~Snake();
            void userInput(UserAction_t action, bool hold);
            GameInfo_t updateCurrentState();
    };
}



#endif // SNAKE_BRICK_GAME_SRC_BRICK_GAME_SNAKE_SNAKE_H