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
#define RECORD_FILE_PATH "tetris_record.txt"

typedef struct {
  int temp;
  size_t temp_speed;
  float speed_boost;
  Matrix *current_figure;
  unsigned x_current_figure;
  unsigned y_current_figure;
  char game_status;
} Game;

typedef enum { I, J, L, O, S, T, Z } Figures;

static GameInfo_t game_;
static Game tetris_;

GameInfo_t updateCurrentState();
void userInput(UserAction_t action);

GameInfo_t init_new_game();
void game_play();
void end_and_clear_game();

void check_level();
char side_rotate();
void move_figuure_if_out_field();
void user_inputs(UserAction_t action);
void start_new_figure();
void move_right();
void move_left();
char check_move_right();
char check_move_left();
void drop_figure();
void speed_drop();
char stop_figure();
char contact_with_monolit();
void pick_row();
void add_points(int count_crashed_rows);
void destroy_row(int row);
void down_monolits();
size_t get_count_monolits_in_col(size_t col);
char check_row(size_t row);
void monoliting_figure();
void insert_figure_to_field();
char is_in_the_area(unsigned i, unsigned j);
Matrix *get_random_figure();

void save_record();
void read_record();

Matrix *i_get_from_memory_figure();
Matrix *j_get_from_memory_figure();
Matrix *l_get_from_memory_figure();
Matrix *o_get_from_memory_figure();
Matrix *s_get_from_memory_figure();
Matrix *t_get_from_memory_figure();
Matrix *z_get_from_memory_figure();

#endif // TETRIS_SRC_BACKEND_GAME_TETRIS_H