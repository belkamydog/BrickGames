#include "test.h"

TEST(HighScore, load_from_alvialiable_file) {
  s21::Snake snake;
  s21::BrickGame::GameInfo_t game_info;
  snake.loadGameRecord(&game_info, "tests/resources/snake_record");
  ASSERT_EQ(game_info.high_score, 100);
}

TEST(HighScore, load_from_unalvialiable_file) {
  s21::Snake snake;
  s21::BrickGame::GameInfo_t game_info;
  game_info.high_score = 0;
  snake.loadGameRecord(&game_info, "tests/resources/snake_record.need_delete");
  ASSERT_EQ(game_info.high_score, 0);
}

TEST(EmptyMatrix, initialize) {
  int row = 10, col = 20;
  int **matrix = s21::BrickGame::createMatrix(row, col);
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < ; j++) {
      ASSERT_EQ(0, matrix[i][j]);
    }
  }
  s21::BrickGame::deleteMatrix(matrix, 10);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
  return 1;
}
