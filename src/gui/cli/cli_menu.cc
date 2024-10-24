#include "cli_menu.h"

void print_menu() {
    printf("Выберите игру: \n");
    printf ("1. Tetris\n");
    printf ("2. Snake\n");
    printf("q For exit\n");
}

GamesList_t choose_game() {
    GamesList_t result;
    switch (getchar()) {
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
