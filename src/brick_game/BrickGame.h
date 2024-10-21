#ifndef SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H
#define SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "BrickData.h"
#include "../auxilary/matrix/matrix.h"

namespace s21 {
    class BrickGame {
        public:
            static void userInput(UserAction_t action, bool hold);
            virtual GameInfo_t updateCurrentState();
            virtual void updateCurrentState(GameInfo_t *game);
        protected:
            GameInfo_t game_info_;
            void loadGameRecord(std::string filename);
            void updateGameRecord(std::string filename);
            void goToTheNextLevel();
        private:
            void resetFileHighScore(std::string filename);
    };
};

#endif // SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H