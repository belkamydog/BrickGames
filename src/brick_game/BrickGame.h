#ifndef SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H
#define SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "../auxilary/matrix/matrix.h"
#include "BrickData.h"

/**
 * Абстрактный класс игры содержит общие методы для всех игр
 */
namespace s21 {
class BrickGame {
public:
  virtual void userInput(UserAction_t action) = 0;
  virtual GameInfo_t updateCurrentState() = 0;

protected:
  GameInfo_t game_info_;
  void loadGameRecord(std::string filename);
  void updateGameRecord(std::string filename);
  void goToTheNextLevel();

private:
  void resetFileHighScore(std::string filename);
};
}; // namespace s21

#endif // SNAKE_BRICK_GAME_SRC_BRICK_GAME_BRICK_GAME_H