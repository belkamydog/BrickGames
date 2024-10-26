#include "tetris.h"

  void init_new_game(TetrisGameInfo_t *tetris_game) {
  tetris_game->game.score = 0;
  tetris_game->game.high_score = 0;
  read_record(tetris_game);
  tetris_game->game.pause = 0;
  tetris_game->game.level = 1;
  tetris_game->game.status = 1;
  tetris_game->game.next = get_random_figure();
  tetris_game->speed_boost = SPEED_BOOST;
  tetris_game->game.speed = START_SPEED;
  tetris_game->current_figure = get_random_figure();
  tetris_game->game.field = create_matrix(ROW, COL);
  tetris_game->x_current_figure = 3;
  tetris_game->y_current_figure = 0;
  tetris_game->game_status = 1;
}

void end_and_clear_game(TetrisGameInfo_t *tetris_game) {
  if (tetris_game->current_figure != NULL)
    delete_matrix(tetris_game->current_figure);
  if (tetris_game->game.next != NULL)
    delete_matrix(tetris_game->game.next);
  if (tetris_game->game.field != NULL)
    delete_matrix(tetris_game->game.field);
}

void game_play(TetrisGameInfo_t *tetris_game) {
  tetris_game->game.speed *= tetris_game->speed_boost;
  insert_figure_to_field(tetris_game);
  if (stop_figure(tetris_game) == 0) {
    drop_figure(tetris_game);
  } else {
    start_new_figure(tetris_game);
  }
  pick_row(tetris_game);
}

void check_level(TetrisGameInfo_t *tetris_game) {
  if (tetris_game->game.score % TO_NEXT_LEVEL == 0) {
    tetris_game->game.level++;
    if (tetris_game->game.speed > 100)
      tetris_game->game.speed -= 100;
  }
}

void move_figuure_if_out_field(TetrisGameInfo_t *tetris_game) {
  int out = tetris_game->x_current_figure + tetris_game->current_figure->col - COL;
  tetris_game->temp = out;
  if (out > 0) {
    tetris_game->x_current_figure = tetris_game->x_current_figure - out;
  }
}


void start_new_figure(TetrisGameInfo_t *tetris_game) {
  delete_matrix(tetris_game->current_figure);
  tetris_game->current_figure = tetris_game->game.next;
  tetris_game->game.next = get_random_figure();
  tetris_game->x_current_figure = 3;
  tetris_game->y_current_figure = 0;
}

void move_right(TetrisGameInfo_t *tetris_game) {
  if ((tetris_game->current_figure->col + tetris_game->x_current_figure) < COL &&
      tetris_game->game.pause == 0) {
    if (check_move_right(tetris_game) == 1)
      tetris_game->x_current_figure++;
  }
}

void move_left(TetrisGameInfo_t *tetris_game) {
  if (tetris_game->x_current_figure > 0 && tetris_game->game.pause == 0) {
    if (check_move_left(tetris_game) == 1)
      tetris_game->x_current_figure--;
  }
}

char check_move_left(TetrisGameInfo_t *tetris_game) {
  char result = 1;
  size_t x_abs = tetris_game->x_current_figure;
  for (size_t i = 0; i < tetris_game->current_figure->row; i++) {
    if (tetris_game->current_figure->body[i][0] == 1) {
      size_t y_abs = tetris_game->y_current_figure + i;
      if (x_abs >= 1 && tetris_game->game.field->body[y_abs][x_abs - 1] == 7)
        result = 0;
    }
  }
  return result;
}

char check_move_right(TetrisGameInfo_t *tetris_game) {
  char result = 1;
  size_t x_abs = tetris_game->x_current_figure + tetris_game->current_figure->col - 1;
  for (size_t i = 0; i < tetris_game->current_figure->row; i++) {
    if (tetris_game->current_figure->body[i][tetris_game->current_figure->col - 1] == 1) {
      size_t y_abs = tetris_game->y_current_figure + i;
      if (x_abs < COL - 2 && tetris_game->game.field->body[y_abs][x_abs + 1] == 7)
        result = 0;
    }
  }
  return result;
}

void drop_figure(TetrisGameInfo_t *tetris_game) { tetris_game->y_current_figure++; }

void speed_drop(TetrisGameInfo_t *tetris_game) {
  if (tetris_game->game.pause == 0) {
    while (stop_figure(tetris_game) == 0) {
      drop_figure(tetris_game);
    }
  }
}

char stop_figure(TetrisGameInfo_t *tetris_game) {
  char result = 0;
  if (tetris_game->y_current_figure + tetris_game->current_figure->row > ROW - 1) {
    result = 1;
    monoliting_figure(tetris_game);
  } else if (contact_with_monolit(tetris_game) == 1) {
    result = 1;
    monoliting_figure(tetris_game);
  }
  return result;
}

char contact_with_monolit(TetrisGameInfo_t *tetris_game) {
  char result = 0;
  for (unsigned i = 0; i < tetris_game->current_figure->row; i++) {
    for (unsigned j = 0; j < tetris_game->current_figure->col; j++) {
      if (tetris_game->current_figure->body[i][j] == 1) {
        int y_abs = tetris_game->y_current_figure + i;
        int x_abs = tetris_game->x_current_figure + j;
        if (tetris_game->game.field->body[y_abs + 1][x_abs] == 7) {
          result = 1;
          break;
        }
      }
    }
  }
  return result;
}

void pick_row(TetrisGameInfo_t *tetris_game) {
  int crashed_rows_count = 0;
  for (size_t i = 0; i < tetris_game->game.field->row; i++) {
    if (check_row(i, tetris_game) == 1) {
      destroy_row(i, tetris_game);
      down_monolits(tetris_game);
      crashed_rows_count++;
    }
  }
  if (crashed_rows_count > 0) {
    add_points(crashed_rows_count, tetris_game);
    check_level(tetris_game);
  }
}

void add_points(int count_crashed_rows, TetrisGameInfo_t *tetris_game) {
  switch (count_crashed_rows) {
  case 1:
    tetris_game->game.score += 100;
    break;
  case 2:
    tetris_game->game.score += 300;
    break;
  case 3:
    tetris_game->game.score += 700;
    break;
  case 4:
    tetris_game->game.score += 1500;
    break;
  default:
    tetris_game->game.score+= 0;
    break;
  }
  if (tetris_game->game.high_score < tetris_game->game.score) {
    save_record(tetris_game);
  }
}

void destroy_row(int row, TetrisGameInfo_t *tetris_game) {
  for (size_t i = 0; i < tetris_game->game.field->col; i++) {
    tetris_game->game.field->body[row][i] = 0;
  }
}

void down_monolits(TetrisGameInfo_t *tetris_game) {
  for (size_t col = 0; col < COL; col++) {
    size_t monolits_count = get_count_monolits_in_col(col, tetris_game);
    for (size_t row = ROW - 1; row > 0; row--) {
      if (tetris_game->game.field->body[row][col] != 1) {
        if (monolits_count > 0) {
          tetris_game->game.field->body[row][col] = 7;
          monolits_count--;
        } else
          tetris_game->game.field->body[row][col] = 0;
      }
    }
  }
}

size_t get_count_monolits_in_col(size_t col, TetrisGameInfo_t *tetris_game) {
  size_t result = 0;
  for (size_t i = 0; i < ROW; i++) {
    if (tetris_game->game.field->body[i][col] == 7) {
      result++;
    }
  }
  return result;
}

char check_row(size_t row, TetrisGameInfo_t *tetris_game) {
  char result = 1;
  for (size_t j = 0; j < tetris_game->game.field->col; j++) {
    if (tetris_game->game.field->body[row][j] != 7) {
      result = 0;
      break;
    }
  }
  return result;
}

void monoliting_figure(TetrisGameInfo_t *tetris_game) {
  for (unsigned i = 0; i < tetris_game->current_figure->row; i++) {
    int y_abs = tetris_game->y_current_figure + i;
    for (unsigned j = 0; j < tetris_game->current_figure->col; j++) {
      int x_abs = tetris_game->x_current_figure + j;
      if (tetris_game->current_figure->body[i][j] != 0)
        tetris_game->game.field->body[y_abs][x_abs] = 7;
      if (y_abs < 1)
        tetris_game->game.status = 0;
    }
  }
}

void insert_figure_to_field(TetrisGameInfo_t *tetris_game) {
  for (size_t i = 0; i < ROW; i++) {
    for (size_t j = 0; j < COL; j++) {
      if (is_in_the_area(i, j, tetris_game) == 1) {
        tetris_game->game.field->body[i][j] = 1;
      } else if (tetris_game->game.field->body[i][j] != 7)
        tetris_game->game.field->body[i][j] = 0;
    }
  }
}

char is_in_the_area(size_t i, size_t j, TetrisGameInfo_t *tetris_game) {
  char result = 0;
  char a = 0;
  char b = 0;
  if (i >= tetris_game->y_current_figure &&
      i < tetris_game->y_current_figure + tetris_game->current_figure->row)
    a = 1;
  if (j >= tetris_game->x_current_figure &&
      j < tetris_game->x_current_figure + tetris_game->current_figure->col)
    b = 1;
  if (a == 1 && b == 1) {
    size_t shift_x = tetris_game->x_current_figure;
    size_t shift_y = tetris_game->y_current_figure;
    int x = j - shift_x;
    int y = i - shift_y;
    if (tetris_game->current_figure->body[y][x] == 1)
      result = 1;
  }
  return result;
}

void save_record(TetrisGameInfo_t *tetris_game) {
  tetris_game->game.high_score = tetris_game->game.score;
  FILE *file = fopen(RECORD_FILE_PATH, "w");
  if (file) {
    fwrite(&tetris_game->game.high_score, sizeof(int), 1, file);
  }
  fclose(file);
}

void read_record(TetrisGameInfo_t *tetris_game) {
  FILE *file = fopen(RECORD_FILE_PATH, "r");
  if (file) {
    fread(&tetris_game->game.high_score, sizeof(int), 1, file);
  }
  else save_record(tetris_game);
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

void updateCurrentState(TetrisGameInfo_t *tetris_game) {
  if (tetris_game->game.pause == 0)
  game_play(tetris_game);
}

void userInput(UserAction_t action, TetrisGameInfo_t *tetris_game) {
    Matrix *tmp = NULL;
    switch (action) {
    case Action:
      if (tetris_game->game.pause == 0) {
        tmp = rotate_matrix_90(tetris_game->current_figure, Clockwise);
        delete_matrix(tetris_game->current_figure);
        tetris_game->current_figure = tmp;
        move_figuure_if_out_field(tetris_game);
      }
      break;
    case Right:
      move_right(tetris_game);
      break;
    case Left:
      move_left(tetris_game);
      break;
    case Pause:
      if (tetris_game->game.pause == 0)
        tetris_game->game.pause = 1;
      else if (tetris_game->game.pause == 1)
        tetris_game->game.pause = 0;
      break;
    case Down:
      speed_drop(tetris_game);
      break;
    default:
      break;
    }
    tetris_game->speed_boost = SPEED_BOOST;
}