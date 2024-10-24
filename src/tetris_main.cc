#include <iostream>

#include "brick_game/tetris/tetris.h"
#include "brick_game/BrickGame.h"
#include "gui/cli/gui.h"

int main(){
    GameInfo_t g = init_new_game(); 
    initNcurces();
    UserAction_t action = Start;
    while (action != Terminate) {
            render(g, &action);
            userInput(action, '2');
            g = updateCurrentState();
    }
    end_and_clear_game();
    endNcurces();
    return 1;
}