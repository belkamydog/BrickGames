#include "../gui/cli/cli_menu.h"
#include "../gui/cli/gui.h"
#include "../controllers/BrickGameController.h"
#include "../brick_game/BrickData.h"


int main(){
    s21::BrickGameController controller;
    GamesList_t current_game;
    // while (current_game != Exit) {
    //     print_menu();
    //     current_game = choose_game();
        controller.setCurrentGame(SnakeGame);
        initNcurces();
        GameInfo_t g = controller.getGameInfo(); 
        UserAction_t action = Start;
        while (action != Terminate) {
                render(g, &action);
                controller.getUserActionFromGui(action);
                g = controller.sendDataToGui();
        }
        end_and_clear_game();
        endNcurces();
    // }
    
    return 0;
}