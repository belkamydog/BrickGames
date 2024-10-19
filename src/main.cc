#include <iostream>

#include "brick_game/snake/Snake.h"
#include "brick_game/BrickGame.h"

using namespace s21;
using std::cout;
using std::endl;

int main(){
    Snake snake;
    BrickGame::GameInfo_t game = snake.getGameInfo();
    char ch = ' ';
    BrickGame::UserAction_t action;
    while (ch != 'q' && snake.isAlive()) {
        for (size_t i = 0; i < snake.ROW; i++) {
            for (size_t j = 0; j < snake.COL; j++) {
                if (game.field[i][j] > 0) printf("%2d", game.field[i][j]);
                else if (game.field[i][j] == -1) printf("%2c", '$');
                else printf("%2c", '.');
            }
            cout << endl;
        }
        cout << endl;
        printf("hs: %d sc:%d l: %d\n", game.high_score, game.score, game.level);
        ch = getchar();
        if (ch == 'a') {
            action = BrickGame::UserAction_t::Left;
            snake.userInput(action, true);
        }
        else if (ch == 'd') {
            action = BrickGame::UserAction_t::Right;
            snake.userInput(action, true);
        }
        game = snake.updateCurrentState();
    }
    

    return 1;
}