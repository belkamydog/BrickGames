#include <iostream>

#include "brick_game/snake/Snake.h"
#include "brick_game/BrickGame.h"
#include "gui/cli/gui.h"

using namespace s21;

int main(){
    Snake snake;
    initNcurces();
    while (1) {
        UserAction_t action;
        render(snake.getGameInfo(), &action);
        snake.userInput(action, false);
        snake.updateCurrentState();
    }
    endNcurces();
    return 1;
}