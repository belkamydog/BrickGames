#ifndef SNAKE_BRICK_GAME_SRC_BRICK_GAME_SNAKE_SNAKE_H
#define SNAKE_BRICK_GAME_SRC_BRICK_GAME_SNAKE_SNAKE_H

#include "../BrickGame.h"

namespace s21{
    class Snake:public BrickGame {
        public:
            Snake();
            ~Snake();
            void initNewGame();
            void userInput(UserAction_t action, bool hold);
            GameInfo_t updateCurrentState();
            GameInfo_t getGameInfo();
            bool isAlive();
        private:
            struct SnakeData {
                char direction;
                int vector_direction;
                size_t x_head;
                size_t y_head;
                size_t x_apple;
                size_t y_apple;
                size_t snake_size;
                bool is_allive;
            };

            SnakeData snake_data_;
            const std::string FILE_HIGHSCORE = "snake_record"; 
            const size_t START_LENGTH = 4;
            const size_t MAX_LENGTH = 200;
            void initaliseSnakeInTheField();
            void snakeMooving();
            void borderControl();
            void goalRandomCoordinateGenerator();
            void snakeEatingGoal();
    };
}



#endif // SNAKE_BRICK_GAME_SRC_BRICK_GAME_SNAKE_SNAKE_H