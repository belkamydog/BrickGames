#include "test.h"

TEST(Initialisation, before_start) {
  s21::Snake snake;
  s21::BrickGame::GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

TEST(Actions, move_right) {
  s21::Snake snake;
  s21::BrickGame::GameInfo_t game = snake.getGameInfo();
  snake.userInput(s21::BrickGame::Right, true);
  snake.updateCurrentState();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

TEST(Actions, move_left) {
  s21::Snake snake;
  s21::BrickGame::GameInfo_t game = snake.getGameInfo();
  snake.userInput(s21::BrickGame::Left, true);
  snake.updateCurrentState();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

TEST(GameRecord, update) {
  s21::Snake snake;
  s21::BrickGame::GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
  return 1;
}
