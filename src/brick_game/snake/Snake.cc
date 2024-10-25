#include "Snake.h"

s21::Snake::Snake() {
  loadGameRecord(FILE_HIGHSCORE);
  game_info_.next = nullptr;
  game_info_.pause = 0;
  game_info_.score = 0;
  game_info_.speed = START_SPEED;
  game_info_.level = 1;
  game_info_.field = create_matrix(ROW, COL);
  game_info_.status = 1;
  snake_data_.direction = 'y';
  snake_data_.vector_direction = -1;
  snake_data_.snake_size = START_LENGTH;
  snake_data_.is_allive = true;
  initaliseSnakeInTheField();
  goalRandomCoordinateGenerator();
}

s21::Snake::~Snake() { delete_matrix(game_info_.field); }

void s21::Snake::initNewGame() {
  loadGameRecord(FILE_HIGHSCORE);
  game_info_.next = nullptr;
  game_info_.pause = 0;
  game_info_.score = 0;
  game_info_.speed = START_SPEED;
  game_info_.level = 1;
  for (size_t i = 0; i < ROW; i++) {
    for (size_t j = 0; j < COL; j++) {
      game_info_.field->body[i][j] = 0;
    }
  }

  snake_data_.direction = 'y';
  snake_data_.vector_direction = -1;
  snake_data_.snake_size = START_LENGTH;
  snake_data_.is_allive = true;
  initaliseSnakeInTheField();
  goalRandomCoordinateGenerator();
}

GameInfo_t s21::Snake::getGameInfo() { return game_info_; }

bool s21::Snake::isAlive() { return snake_data_.is_allive; }

void s21::Snake::userInput(UserAction_t action, bool hold) {
  if (action == Pause && game_info_.pause == 0)
    game_info_.pause = 1;
  else if (action == Pause && game_info_.pause == 1){
    game_info_.pause = 0;
  }
  if (game_info_.pause == 0) {
    if (snake_data_.direction == 'x' && snake_data_.vector_direction == -1) {
      if (action == Right) {
        snake_data_.vector_direction = -1;
        snake_data_.direction = 'y';
      } else if (action == Left) {
        snake_data_.vector_direction = 1;
        snake_data_.direction = 'y';
      }
    } else if (snake_data_.direction == 'x' &&
               snake_data_.vector_direction == 1) {
      if (action == Left) {
        snake_data_.vector_direction = -1;
        snake_data_.direction = 'y';
      } else if (action == Right) {
        snake_data_.vector_direction = 1;
        snake_data_.direction = 'y';
      }
    } else if (snake_data_.direction == 'y') {
      if (action == Right) {
        snake_data_.vector_direction = 1;
        snake_data_.direction = 'x';
      } else if (action == Left) {
        snake_data_.vector_direction = -1;
        snake_data_.direction = 'x';
      }
    }
  }

  std::cerr << hold;
}

GameInfo_t s21::Snake::updateCurrentState() {
  if (game_info_.pause == 0) {
    if (snake_data_.direction == 'x') {
      snake_data_.x_head += snake_data_.vector_direction;
    } else if (snake_data_.direction == 'y') {
      snake_data_.y_head += snake_data_.vector_direction;
    }
    borderControl();
    if (snake_data_.is_allive)
      snakeMooving();
    snakeEatingGoal();
  }
  game_info_.status = snake_data_.is_allive;
  return game_info_;
}

void s21::Snake::initaliseSnakeInTheField() {
  snake_data_.x_head = COL / 2;
  snake_data_.y_head = ROW / 2;
  game_info_.field->body[snake_data_.y_head][snake_data_.x_head] = 1;
  snake_data_.x_apple = 5;
  snake_data_.y_apple = 2;
  int next_ceil = 2;
  for (size_t i = snake_data_.y_head + 1; i < snake_data_.y_head + START_LENGTH;
       i++) {
    game_info_.field->body[i][snake_data_.x_head] = next_ceil;
    next_ceil++;
  }
}

void s21::Snake::snakeMooving() {
  Matrix *previous_field = create_matrix(ROW, COL);
  copy_matrix(game_info_.field, previous_field);
  for (size_t i = 0; i < ROW; i++) {
    for (size_t j = 0; j < COL; j++) {
      if (previous_field->body[i][j] == (int)snake_data_.snake_size) {
        game_info_.field->body[i][j] = 0;
      } else if (previous_field->body[i][j] > 0) {
        game_info_.field->body[i][j]++;
      }
    }
  }
  if (game_info_.field->body[snake_data_.y_head][snake_data_.x_head] > 0)
    snake_data_.is_allive = false;
  game_info_.field->body[snake_data_.y_head][snake_data_.x_head] = 1;
  delete_matrix(previous_field);
}

void s21::Snake::borderControl() {
  if (snake_data_.x_head < 0 || snake_data_.x_head > COL - 1)
    snake_data_.is_allive = false;
  else if (snake_data_.y_head < 0 || snake_data_.y_head > ROW - 1)
    snake_data_.is_allive = false;
}

void s21::Snake::goalRandomCoordinateGenerator() {
  size_t free_cells_count = ROW * COL - snake_data_.snake_size;
  int choice = rand() % free_cells_count;
  size_t point_counter = 0;
  for (size_t i = 0; i < ROW; i++) {
    for (size_t j = 0; j < COL; j++) {
      if (game_info_.field->body[i][j] == 0)
        point_counter++;
      if (game_info_.field->body[i][j] == 0 && (int)point_counter == choice) {
        snake_data_.x_apple = j;
        snake_data_.y_apple = i;
      }
    }
  }
  game_info_.field->body[snake_data_.y_apple][snake_data_.x_apple] = -1;
}

void s21::Snake::snakeEatingGoal() {
  if (snake_data_.x_apple == snake_data_.x_head &&
      snake_data_.y_apple == snake_data_.y_head) {
    snake_data_.snake_size++;
    game_info_.score++;
    updateGameRecord(FILE_HIGHSCORE);
    goToTheNextLevel();
    if (snake_data_.snake_size < MAX_LENGTH)
      goalRandomCoordinateGenerator();
    else
      snake_data_.is_allive = false;
  }
}
