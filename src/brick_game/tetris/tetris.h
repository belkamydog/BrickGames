#ifndef TETRIS_SRC_BACKEND_GAME_TETRIS_H
#define TETRIS_SRC_BACKEND_GAME_TETRIS_H

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../../auxilary/matrix/matrix.h"
#include "../BrickData.h"

#define TO_NEXT_LEVEL 600
#define SPEED_BOOST 1
#define RECORD_FILE_PATH "tetris.highscore"

typedef struct {
  int temp;
  GameInfo_t game;
  Matrix *current_figure;
  unsigned x_current_figure;
  unsigned y_current_figure;
  size_t temp_speed;
  float speed_boost;
  char game_status;
} TetrisGameInfo_t;

typedef enum { I, J, L, O, S, T, Z } Figures;

void updateCurrentState(TetrisGameInfo_t *tetris_game);
void userInput(UserAction_t action, TetrisGameInfo_t *tetris_game);

void init_new_game(TetrisGameInfo_t *tetris_game);
void end_and_clear_game(TetrisGameInfo_t *tetris_game);
void game_play(TetrisGameInfo_t *tetris_game);
void check_level(TetrisGameInfo_t *tetris_game);
void move_figuure_if_out_field(TetrisGameInfo_t *tetris_game);
void start_new_figure(TetrisGameInfo_t *tetris_game);
void move_right(TetrisGameInfo_t *tetris_game);
void move_left(TetrisGameInfo_t *tetris_game);
char check_move_left(TetrisGameInfo_t *tetris_game);
char check_move_right(TetrisGameInfo_t *tetris_game);
void drop_figure(TetrisGameInfo_t *tetris_game);
void speed_drop(TetrisGameInfo_t *tetris_game);
char stop_figure(TetrisGameInfo_t *tetris_game);
char contact_with_monolit(TetrisGameInfo_t *tetris_game);
void add_points(int count_crashed_rows, TetrisGameInfo_t *tetris_game);
void destroy_row(int row, TetrisGameInfo_t *tetris_game);
void down_monolits(TetrisGameInfo_t *tetris_game);
size_t get_count_monolits_in_col(size_t col, TetrisGameInfo_t *tetris_game);
char check_row(size_t row, TetrisGameInfo_t *tetris_game);
void monoliting_figure(TetrisGameInfo_t *tetris_game);
void insert_figure_to_field(TetrisGameInfo_t *tetris_game);
char is_in_the_area(size_t i, size_t j, TetrisGameInfo_t *tetris_game);
void save_record(TetrisGameInfo_t *tetris_game);
void read_record(TetrisGameInfo_t *tetris_game);
void pick_row(TetrisGameInfo_t *tetris_game);
Matrix *get_random_figure();

Matrix *i_get_from_memory_figure();
Matrix *j_get_from_memory_figure();
Matrix *l_get_from_memory_figure();
Matrix *o_get_from_memory_figure();
Matrix *s_get_from_memory_figure();
Matrix *t_get_from_memory_figure();
Matrix *z_get_from_memory_figure();

#endif // TETRIS_SRC_BACKEND_GAME_TETRIS_H