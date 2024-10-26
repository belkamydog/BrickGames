#ifndef BRICK_GAME_SRC_CONTROLLER_CONTROLLER_H
#define BRICK_GAME_SRC_CONTROLLER_CONTROLLER_H

#include "../brick_game/snake/Snake.h"
#include "../brick_game/tetris/tetris.h"
#include "../brick_game/BrickData.h"

namespace s21{
    class BrickGameController{
        public:
            BrickGameController();
            ~BrickGameController();
            GameInfo_t sendDataToGui();
            void getUserActionFromGui(UserAction_t action);
            void setCurrentGame(GamesList_t game);
            void resetGames();
            GameInfo_t getGameInfo();
        private: 
            GamesList_t current_game_ = TetrisGame;
            Snake snake_;
            GameInfo_t game_;
            TetrisGameInfo_t tetris_game_;
            void updateGameState();
    };
};

#endif // BRICK_GAME_SRC_CONTROLLER_CONTROLLER_H