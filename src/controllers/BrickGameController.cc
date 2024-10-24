#include "BrickGameController.h"

s21::BrickGameController::BrickGameController() {
    if (current_game_ == TetrisGame){
        game_ = init_new_game();
    }
    else{
        snake_.initNewGame();
    }
}

s21::BrickGameController::~BrickGameController() {}

GameInfo_t s21::BrickGameController::sendDataToGui() {
  updateGameState();
  return game_;
}

void s21::BrickGameController::getUserActionFromGui(UserAction_t action) {
    if (current_game_ == SnakeGame){
        snake_.userInput(action, false);
    }
    else {
        userInput(action, ' '); // tetris
    }
}

void s21::BrickGameController::setCurrentGame(GamesList_t game) {
    current_game_ = game;
}

GameInfo_t s21::BrickGameController::getGameInfo() { return game_; }

void s21::BrickGameController::updateGameState() {
    if (current_game_ == SnakeGame) {
    game_ = snake_.updateCurrentState();
  } else {
    game_ = updateCurrentState();  // tetris
  }
}
