#include "gui.h"

void render(GameInfo_t game, UserAction_t *action) {
  timeout(game.speed);
  usleep(100000);
  erase();
  print_game_field(game);
  print_end();
  print_info(game);
  user_action(action);
  printw("\n");
}

void initNcurces() {
  initscr();
  keypad(stdscr, true);
}

void endNcurces() { endwin(); }

void user_action(UserAction_t *action) {
  switch (getch()) {
  case KEY_LEFT:
    *action = Left;
    break;
  case KEY_RIGHT:
    *action = Right;
    break;
  case KEY_UP:
    *action = Up;
    break;
  case KEY_DOWN:
    *action = Down;
    break;
  case ' ':
    *action = Action;
    break;
  case 'q':
    *action = Terminate;
    break;
  case 'p':
    *action = Pause;
    break;
  case 's':
    *action = Start;
    break;
  default:
    *action = Start;
    break;
  }
}

void print_game_field(GameInfo_t game) {
  for (size_t i = 0; i < ROW; i++) {
    printw("<!");
    for (size_t j = 0; j < COL; j++) {
      if (game.field->body[i][j] == 0)
        printw("%3c", '.');
      else if (game.field->body[i][j] >= 1)
        printw("%3c", '#');
      else
        printw("%3c", '$');
    }
    printw("!>\n");
  }
}

void print_end() {
  printw("<!");
  for (size_t i = 0; i < COL; i++)
    printw("%3c", '=');
  printw("!>\n");
}

void print_info(GameInfo_t game) {
  if (game.pause != 1) {
    printw("SCORE : %u\n", game.score);
    printw("RECORD: %u\n", game.high_score);
    printw("LEVEL:  %u\n", game.level);
    printw("<    NEXT FIGURE:   >\n\n");
    if (game.next != NULL)
      print_next(*game.next);
  } else
    print_pause();
}

void print_pause() {
  printw("#####    ##   #    #  ####  ######\n");
  printw("#    #  #  #  #    # #      #     \n");
  printw("#    # #    # #    #  ####  ##### \n");
  printw("#####  ###### #    #      # #     \n");
  printw("#      #    # #    # #    # #     \n");
  printw("#      #    #  ####   ####  ######\n");
}

void print_game_over(GameInfo_t game) {
  printw(" #####     #    #     # #######    ####### #     # ####### ######    "
         "         ## \n");
  printw("#     #   # #   ##   ## #          #     # #     # #       #     #   "
         "        #   \n");
  printw("#        #   #  # # # # #          #     # #     # #       #     #   "
         " ##### #    \n");
  printw("#  #### #     # #  #  # #####      #     # #     # #####   ######    "
         "       #    \n");
  printw("#     # ####### #     # #          #     #  #   #  #       #   #     "
         " ##### #    \n");
  printw("#     # #     # #     # #          #     #   # #   #       #    #    "
         "        #   \n");
  printw(" #####  #     # #     # #######    #######    #    ####### #     #   "
         "         ## \n");
  printw("\n\n\t\t\tTOTAL SCORE: %u\n\n", game.score);
  printw("Press any key for continue to main menu... ");
  char any_key = 0;
  nodelay(stdscr, FALSE);
  any_key = getch();
  printw("%c", any_key);
  nodelay(stdscr, TRUE);
}

void print_next(Matrix next) {
  for (unsigned i = 0; i < next.row; i++) {
    for (unsigned j = 0; j < next.col; j++) {
      if (next.body[i][j] == 1)
        printw("%3c", '*');
      else
        printw("%3c", ' ');
    }
    printw("\n");
  }
}
