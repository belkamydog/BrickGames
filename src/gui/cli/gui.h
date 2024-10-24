#ifndef TETRIS_SRC_GUI_H
#define TETRIS_SRC_GUI_H

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "../../brick_game/BrickData.h"
#include "../../auxilary/matrix/matrix.h"

void render(GameInfo_t game, UserAction_t *action);
void initNcurces();
void endNcurces();
void user_action(UserAction_t *action);
void print_game_field(GameInfo_t game);
void print_end();
void print_info(GameInfo_t game);
void print_pause();
void print_game_over(GameInfo_t game);
void print_next(Matrix next);

#endif // TETRIS_SRC_GUI_H

