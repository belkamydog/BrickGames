#include "BrickGameController.h"

s21::BrickGameController::BrickGameController() {
    if (current_game_ == TetrisGame){
        init_new_game(&tetris_game_);
        game_ = tetris_game_.game;
    }
    // else{
    //     snake_.initNewGame();
    // }
}

s21::BrickGameController::~BrickGameController() {
    // end_and_clear_game(&tetris_game_);
}

GameInfo_t s21::BrickGameController::sendDataToGui() {
  updateGameState();
  return game_;
}

void s21::BrickGameController::getUserActionFromGui(UserAction_t action) {
    if (current_game_ == SnakeGame){
        snake_.userInput(action);
    }
    else {
        userInput(action, &tetris_game_);
        game_ = tetris_game_.game;
    }
}

void s21::BrickGameController::setCurrentGame(GamesList_t game) {
    current_game_ = game;
}

void s21::BrickGameController::resetGames() {
    if (current_game_ == TetrisGame){
        init_new_game(&tetris_game_);
        game_ = tetris_game_.game;
    }
    else{
        snake_.initNewGame();
    }
}

GameInfo_t s21::BrickGameController::getGameInfo() { return game_; }

void s21::BrickGameController::updateGameState() {
    if (current_game_ == SnakeGame) {
    game_ = snake_.updateCurrentState();
  } else {
    updateCurrentState(&tetris_game_);
    game_ = tetris_game_.game;
  }
}
