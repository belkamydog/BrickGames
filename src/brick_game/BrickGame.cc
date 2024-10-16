#include "BrickGame.h"

void s21::BrickGame::userInput(UserAction_t action, bool hold) {}

s21::BrickGame::GameInfo_t s21::BrickGame::updateCurrentState() { return GameInfo_t(); }

void s21::BrickGame::loadGameRecord(GameInfo_t *game_info,
                                    std::string filename) {
  std::ifstream in(filename);
  if (!in.is_open())
    resetFileHighScore(filename);
  else {
    std::string buffer;
    getline(in, buffer);
    if (!buffer.empty() &&
        std::regex_match(buffer, std::regex("[1-9][0-9]*"))) {
      try {
        game_info->high_score = std::stoi(buffer);
      } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
      }
    } else {
      game_info->high_score = 0;
      resetFileHighScore(filename);
    }
    in.close();
  }
}

void s21::BrickGame::updateGameRecord(GameInfo_t *game_info,
                                      std::string filename) {
    if (game_info->score > game_info->high_score){
        std::ofstream out;
        out.open(filename);
        if (!out){
            resetFileHighScore(filename);
        }
        out << game_info->high_score;
        out.close();
    }
}

void s21::BrickGame::resetFileHighScore(std::string filename) {
    std::ofstream created_high_score_file (filename);
    created_high_score_file << "0\n";
    created_high_score_file.close();
}
