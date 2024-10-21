#include <iostream>

#include "brick_game/tetris/tetris.h"
#include "brick_game/BrickGame.h"
#include "gui/cli/gui.h"

int main(){
    GameInfo_t g = init_new_game(); 
    initNcurces();
    while (1) {
        UserAction_t action;
        render(g, &action);
        userInput(action, '2');
        g = updateCurrentState();
    }
    endNcurces();
    return 1;
}