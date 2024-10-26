#include "../brick_game/BrickData.h"
#include "../controllers/BrickGameController.h"
#include "../gui/cli/cli_menu.h"
#include "../gui/cli/gui.h"

int main() {
  s21::BrickGameController controller;
  GamesList_t current_game;
  initNcurces();
  print_menu();
  current_game = choose_game();
  controller.setCurrentGame(current_game);
  GameInfo_t g = controller.getGameInfo();
  UserAction_t action = Start;
  while (action != Terminate && g.status != 0) {
    render(g, &action);
    controller.getUserActionFromGui(action);
    g = controller.sendDataToGui();
  }
  endNcurces();
  return 0;
}