#include "test.h"

TEST(MatrixTests, rotateClockwise){
  Matrix *matrix = create_matrix(3, 3);
  matrix->body[0][1] = 1;
  matrix->body[1][1] = 1;
  matrix->body[2][1] = 1;
  Matrix *rot = rotate_matrix_90(matrix, Clockwise);
  ASSERT_EQ(rot->body[1][0], 1);
  ASSERT_EQ(rot->body[1][1], 1);
  ASSERT_EQ(rot->body[1][2], 1);
  delete_matrix(matrix);
  delete_matrix(rot);
}

TEST(MatrixTests, rotateCounterClockwise){
  Matrix *matrix = create_matrix(3, 3);
  matrix->body[0][1] = 1;
  matrix->body[1][1] = 1;
  matrix->body[2][1] = 1;
  Matrix *rot = rotate_matrix_90(matrix, Counterclockwise);
  ASSERT_EQ(rot->body[1][0], 1);
  ASSERT_EQ(rot->body[1][1], 1);
  ASSERT_EQ(rot->body[1][2], 1);
  delete_matrix(matrix);
  delete_matrix(rot);
}

TEST(Initialisation, before_start) {
  s21::Snake snake;
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

TEST(Initialisation, initNewGame) {
  s21::Snake snake;
  snake.initNewGame();
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
  ASSERT_TRUE(snake.isAlive());
}

TEST(Actions, move_right) {
  s21::Snake snake;
  GameInfo_t game = snake.getGameInfo();
  snake.userInput(Right);
  snake.updateCurrentState();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

TEST(Actions, move_left) {
  s21::Snake snake;
  GameInfo_t game = snake.getGameInfo();
  snake.userInput(Left);
  snake.updateCurrentState();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

TEST(GameRecord, update) {
  s21::Snake snake;
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.level, 1);
  ASSERT_EQ(game.score, 0);
}

TEST(EatGoal, goal1) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Left);
  snake.updateCurrentState();
  snake.userInput(Right);
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.level, 1);
}

TEST(EatGoal, pause) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Left);
  snake.updateCurrentState();
  snake.userInput(Right);
  snake.userInput(Pause);
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.pause, 1);
}

TEST(EatGoal, RightRight) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Right);
  snake.updateCurrentState();
  snake.userInput(Right);
  snake.userInput(Pause);
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.pause, 1);
}

TEST(EatGoal,LeftLeft) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Left);
  snake.updateCurrentState();
  snake.userInput(Left);
  snake.userInput(Pause);
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.pause, 1);
}

TEST(EatGoal,RightLeft) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Right);
  snake.updateCurrentState();
  snake.userInput(Left);
  snake.userInput(Pause);
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.pause, 1);
}

TEST(EatGoal,UnPause) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Right);
  snake.updateCurrentState();
  snake.userInput(Pause);
  snake.userInput(Pause);
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.pause, 0);
}

TEST(Snake,GameOver_border_rx) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Right);
  for (size_t i = 0; i < 5; i++)
  {
    snake.updateCurrentState();
  }
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.status, 0);
}

TEST(Snake,GameOver_border_lx) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Left);
  for (size_t i = 0; i < 8; i++)
  {
    snake.updateCurrentState();
  }
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.status, 0);
}

TEST(Snake,GameOver_body) {
  s21::Snake snake;
  snake.updateCurrentState();
  snake.userInput(Right);
  for (size_t i = 0; i < 3; i++)
  {
    snake.userInput(Right);
    snake.updateCurrentState();
  }
  GameInfo_t game = snake.getGameInfo();
  ASSERT_EQ(game.status, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
  return 1;
}
