#include "tetris.h"

GameInfo_t init_new_game() {
  game_.score = 0;
  read_record();
  game_.level = 1;
  tetris_.speed_boost = SPEED_BOOST;
  game_.speed = START_SPEED;
  game_.next = get_random_figure();
  tetris_.current_figure = get_random_figure();
  game_.field = create_matrix(ROW, COL);
  tetris_.x_current_figure = 3;
  tetris_.y_current_figure = 0;
  game_.status = 1;
  tetris_.game_status = 1;
  return game_;
}

void end_and_clear_game() {
  if (tetris_.current_figure != NULL)
    delete_matrix(tetris_.current_figure);
  if (game_.next != NULL)
    delete_matrix(game_.next);
  if (game_.field != NULL)
    delete_matrix(game_.field);
}

void game_play() {
  game_.speed *= tetris_.speed_boost;
  insert_figure_to_field();
  if (stop_figure() == 0) {
    drop_figure();
  } else {
    start_new_figure();
  }
  pick_row();
  game_.status = tetris_.game_status;
}

void check_level() {
  if (game_.score % TO_NEXT_LEVEL == 0) {
    game_.level++;
    if (game_.speed > 100)
      game_.speed -= 100;
  }
}

void move_figuure_if_out_field() {
  int out = tetris_.x_current_figure + tetris_.current_figure->col - COL;
  tetris_.temp = out;
  if (out > 0) {
    tetris_.x_current_figure = tetris_.x_current_figure - out;
  }
}

void user_inputs(UserAction_t action) {
  Matrix *tmp = NULL;
  switch (action) {
  case Action:
    if (game_.pause == 0) {
      tmp = rotate_matrix_90(tetris_.current_figure, Clockwise);
      delete_matrix(tetris_.current_figure);
      tetris_.current_figure = tmp;
      move_figuure_if_out_field();
    }
    break;
  case Right:
    move_right();
    break;
  case Left:
    move_left();
    break;
  case Pause:
    if (game_.pause == 0)
      game_.pause = 1;
    else if (game_.pause == 1)
      game_.pause = 0;
    break;
  case Down:
    speed_drop();
    break;
  default:
    break;
  }
  tetris_.speed_boost = SPEED_BOOST;
}

void start_new_figure() {
  delete_matrix(tetris_.current_figure);
  tetris_.current_figure = game_.next;
  game_.next = get_random_figure();
  tetris_.x_current_figure = 3;
  tetris_.y_current_figure = 0;
}

void move_right() {
  if ((tetris_.current_figure->col + tetris_.x_current_figure) < COL &&
      game_.pause == 0) {
    if (check_move_right() == 1)
      tetris_.x_current_figure++;
  }
}

void move_left() {
  if (tetris_.x_current_figure > 0 && game_.pause == 0) {
    if (check_move_left() == 1)
      tetris_.x_current_figure--;
  }
}

char check_move_left() {
  char result = 1;
  size_t x_abs = tetris_.x_current_figure;
  for (size_t i = 0; i < tetris_.current_figure->row; i++) {
    if (tetris_.current_figure->body[i][0] == 1) {
      size_t y_abs = tetris_.y_current_figure + i;
      if (x_abs >= 1 && game_.field->body[y_abs][x_abs - 1] == 7)
        result = 0;
    }
  }
  return result;
}

char check_move_right() {
  char result = 1;
  size_t x_abs = tetris_.x_current_figure + tetris_.current_figure->col - 1;
  for (size_t i = 0; i < tetris_.current_figure->row; i++) {
    if (tetris_.current_figure->body[i][tetris_.current_figure->col - 1] == 1) {
      size_t y_abs = tetris_.y_current_figure + i;
      if (x_abs < COL - 2 && game_.field->body[y_abs][x_abs + 1] == 7)
        result = 0;
    }
  }
  return result;
}

void drop_figure() { tetris_.y_current_figure++; }

void speed_drop() {
  if (game_.pause == 0) {
    while (stop_figure() == 0) {
      drop_figure();
    }
  }
}

char stop_figure() {
  char result = 0;
  if (tetris_.y_current_figure + tetris_.current_figure->row > ROW - 1) {
    result = 1;
    monoliting_figure();
  } else if (contact_with_monolit() == 1) {
    result = 1;
    monoliting_figure();
  }
  return result;
}

char contact_with_monolit() {
  char result = 0;
  for (unsigned i = 0; i < tetris_.current_figure->row; i++) {
    for (unsigned j = 0; j < tetris_.current_figure->col; j++) {
      if (tetris_.current_figure->body[i][j] == 1) {
        int y_abs = tetris_.y_current_figure + i;
        int x_abs = tetris_.x_current_figure + j;
        if (game_.field->body[y_abs + 1][x_abs] == 7) {
          result = 1;
          break;
        }
      }
    }
  }
  return result;
}

void pick_row() {
  int crashed_rows_count = 0;
  for (size_t i = 0; i < game_.field->row; i++) {
    if (check_row(i) == 1) {
      destroy_row(i);
      down_monolits();
      crashed_rows_count++;
    }
  }
  if (crashed_rows_count > 0) {
    add_points(crashed_rows_count);
    check_level();
  }
}

void add_points(int count_crashed_rows) {
  switch (count_crashed_rows) {
  case 1:
    game_.score += 100;
    break;
  case 2:
    game_.score += 300;
    break;
  case 3:
    game_.score += 700;
    break;
  case 4:
    game_.score += 1500;
    break;
  default:
    game_.score += 0;
    break;
  }
  if (game_.high_score < game_.score) {
    save_record();
  }
}

void destroy_row(int row) {
  for (size_t i = 0; i < game_.field->col; i++) {
    game_.field->body[row][i] = 0;
  }
}

void down_monolits() {
  for (size_t col = 0; col < COL; col++) {
    size_t monolits_count = get_count_monolits_in_col(col);
    for (size_t row = ROW - 1; row > 0; row--) {
      if (game_.field->body[row][col] != 1) {
        if (monolits_count > 0) {
          game_.field->body[row][col] = 7;
          monolits_count--;
        } else
          game_.field->body[row][col] = 0;
      }
    }
  }
}

size_t get_count_monolits_in_col(size_t col) {
  size_t result = 0;
  for (size_t i = 0; i < ROW; i++) {
    if (game_.field->body[i][col] == 7) {
      result++;
    }
  }
  return result;
}

char check_row(size_t row) {
  char result = 1;
  for (size_t j = 0; j < game_.field->col; j++) {
    if (game_.field->body[row][j] != 7) {
      result = 0;
      break;
    }
  }
  return result;
}

void monoliting_figure() {
  for (unsigned i = 0; i < tetris_.current_figure->row; i++) {
    int y_abs = tetris_.y_current_figure + i;
    for (unsigned j = 0; j < tetris_.current_figure->col; j++) {
      int x_abs = tetris_.x_current_figure + j;
      if (tetris_.current_figure->body[i][j] != 0)
        game_.field->body[y_abs][x_abs] = 7;
      if (y_abs < 1)
        tetris_.game_status = 0;
    }
  }
}

void insert_figure_to_field() {
  for (size_t i = 0; i < ROW; i++) {
    for (size_t j = 0; j < COL; j++) {
      if (is_in_the_area(i, j) == 1) {
        game_.field->body[i][j] = 1;
      } else if (game_.field->body[i][j] != 7)
        game_.field->body[i][j] = 0;
    }
  }
}

char is_in_the_area(unsigned i, unsigned j) {
  char result = 0;
  char a = 0;
  char b = 0;
  if (i >= tetris_.y_current_figure &&
      i < tetris_.y_current_figure + tetris_.current_figure->row)
    a = 1;
  if (j >= tetris_.x_current_figure &&
      j < tetris_.x_current_figure + tetris_.current_figure->col)
    b = 1;
  if (a == 1 && b == 1) {
    size_t shift_x = tetris_.x_current_figure;
    size_t shift_y = tetris_.y_current_figure;
    int x = j - shift_x;
    int y = i - shift_y;
    if (tetris_.current_figure->body[y][x] == 1)
      result = 1;
  }
  return result;
}

void save_record() {
  game_.high_score = game_.score;
  FILE *file = fopen(RECORD_FILE_PATH, "w");
  if (file) {
    char buffer[100];
    game_.high_score = atoi(buffer);
    fputs(buffer, file);
  }
  fclose(file);
}

void read_record() {
  FILE *file = fopen(RECORD_FILE_PATH, "r");
  if (file) {
    char buffer[50];
    fgets(buffer, 50, file);
    game_.high_score = atoi(buffer);
  }
  fclose(file);
}

Matrix *get_random_figure() {
  Matrix *result = NULL;
  int choice = rand() / (RAND_MAX / (6 + 1) + 1);
  switch (choice) {
  case I:
    result = i_get_from_memory_figure();
    break;
  case J:
    result = j_get_from_memory_figure();
    break;
  case L:
    result = l_get_from_memory_figure();
    break;
  case O:
    result = o_get_from_memory_figure();
    break;
  case S:
    result = s_get_from_memory_figure();
    break;
  case T:
    result = t_get_from_memory_figure();
    break;
  case Z:
    result = z_get_from_memory_figure();
    break;
  default:
    break;
  }
  return result;
}

Matrix *i_get_from_memory_figure() {
  Matrix *result = create_matrix(1, 4);
  if (result) {
    result->body[0][0] = 1;
    result->body[0][1] = 1;
    result->body[0][2] = 1;
    result->body[0][3] = 1;
  }
  return result;
}

Matrix *j_get_from_memory_figure() {
  Matrix *result = create_matrix(3, 2);
  if (result) {
    result->body[0][1] = 1;
    result->body[1][1] = 1;
    result->body[2][0] = 1;
    result->body[2][1] = 1;
  }
  return result;
}

Matrix *l_get_from_memory_figure() {
  Matrix *result = create_matrix(3, 2);
  if (result) {
    result->body[0][0] = 1;
    result->body[1][0] = 1;
    result->body[2][0] = 1;
    result->body[2][1] = 1;
  }
  return result;
}

Matrix *o_get_from_memory_figure() {
  Matrix *result = create_matrix(2, 2);
  if (result) {
    result->body[0][0] = 1;
    result->body[0][1] = 1;
    result->body[1][0] = 1;
    result->body[1][1] = 1;
  }
  return result;
}

Matrix *s_get_from_memory_figure() {
  Matrix *result = create_matrix(2, 3);
  if (result) {
    result->body[0][1] = 1;
    result->body[0][2] = 1;
    result->body[1][0] = 1;
    result->body[1][1] = 1;
  }
  return result;
}

Matrix *t_get_from_memory_figure() {
  Matrix *result = create_matrix(2, 3);
  if (result) {
    result->body[0][0] = 1;
    result->body[0][1] = 1;
    result->body[0][2] = 1;
    result->body[1][1] = 1;
  }
  return result;
}

Matrix *z_get_from_memory_figure() {
  Matrix *result = create_matrix(2, 3);
  if (result) {
    result->body[0][0] = 1;
    result->body[0][1] = 1;
    result->body[1][1] = 1;
    result->body[1][2] = 1;
  }
  return result;
}

GameInfo_t updateCurrentState() {
  if (game_.pause == 0)
    game_play();
  return game_;
}

void userInput(UserAction_t action) { user_inputs(action); }