#ifndef SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H
#define SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

namespace s21 {
    class BrickGame {
        public:
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
                int **field;
                int **next;
                int score;
                int high_score;
                int level;
                int speed;
                int pause;
            } GameInfo_t;
            const size_t ROW = 20;
            const size_t COL = 20;
            const size_t STEP_LEVEL = 5;
            const size_t STEP_SPEED = 10;
            const size_t MAX_LEVEL = 10;
            virtual void userInput(UserAction_t action, bool hold);
            virtual GameInfo_t updateCurrentState();
        protected:
            GameInfo_t game_info_;
            void loadGameRecord(std::string filename);
            void updateGameRecord(std::string filename);
            void goToTheNextLevel();
            static int **createMatrix(int row, int col);
            static int **copyMatrix(int row, int col, int **matrix);
            static void deleteMatrix(int **matrix, int row);
        private:
            void resetFileHighScore(std::string filename);
    };
};

#endif // SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H