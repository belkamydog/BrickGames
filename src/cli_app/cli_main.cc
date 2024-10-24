#include "../gui/cli/cli_menu.h"
#include "../brick_game/tetris/tetris.h"

#include "../brick_game/snake/Snake.h"
#include "../brick_game/BrickGame.h"
#include "../gui/cli/gui.h"


int main(){
    Games game;
    while (game != Exit) {
        print_menu();
        game = choose_game();
        if (game == Tetris_game){
            initNcurces();
            GameInfo_t g = init_new_game(); 
            UserAction_t action = Start;
            while (action != Terminate) {
                    render(g, &action);
                    userInput(action, '2');
                    g = updateCurrentState();
            }
            end_and_clear_game();
            endNcurces();
        }
        else if (game == Snake_game){    
            initNcurces();
            s21::Snake snake;
            UserAction_t action;
            while (action != Terminate) {
                render(snake.getGameInfo(), &action);
                snake.userInput(action, false);
                snake.updateCurrentState();
            }
            endNcurces();
        }
        else printf("Неверный ввод\n");
    }
    
    return 0;
}