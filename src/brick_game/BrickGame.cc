#include "BrickGame.h"

void s21::BrickGame::userInput(UserAction_t action, bool hold) {
  std::cerr << hold << action;
}

GameInfo_t s21::BrickGame::updateCurrentState() {
  return GameInfo_t();
}

void s21::BrickGame::updateCurrentState(GameInfo_t *game) {}

void s21::BrickGame::loadGameRecord(std::string filename) {
  std::ifstream in(filename);
  if (!in.is_open())
    resetFileHighScore(filename);
  else {
    std::string buffer;
    getline(in, buffer);
    if (!buffer.empty() &&
        std::regex_match(buffer, std::regex("[1-9][0-9]*"))) {
      try {
        game_info_.high_score = std::stoi(buffer);
      } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
      }
    } else {
      game_info_.high_score = 0;
      resetFileHighScore(filename);
    }
    in.close();
  }
}

void s21::BrickGame::updateGameRecord(std::string filename) {
  if (game_info_.score > game_info_.high_score) {
    game_info_.high_score = game_info_.score;
    std::ofstream out;
    out.open(filename);
    if (!out) {
      resetFileHighScore(filename);
    }
    out << game_info_.high_score;
    out.close();
  }
}

void s21::BrickGame::goToTheNextLevel() {
  if (game_info_.score % STEP_LEVEL == 0 && game_info_.level < (int) MAX_LEVEL){
    game_info_.level++;
    game_info_.speed += STEP_SPEED;
  }
}


void s21::BrickGame::resetFileHighScore(std::string filename) {
  std::ofstream created_high_score_file(filename);
  created_high_score_file << "0\n";
  created_high_score_file.close();
}
