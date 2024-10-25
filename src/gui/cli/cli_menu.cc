#include "cli_menu.h"

void print_menu() {
  printw("Choose the game: \n");
  printw("1. Tetris\n");
  printw("2. Snake\n");
  printw("q For exit\n");
}

GamesList_t choose_game() {
  GamesList_t result;
  switch (getch()) {
  case '1':
    result = TetrisGame;
    break;
  case '2':
    result = SnakeGame;
    break;
  case 'q':
    result = Exit;
    break;
  default:
    result = TetrisGame;
    break;
  }
  return result;
}
