#include "PyramidBoard.h"

GameManager_FIVE_X_O::GameManager_FIVE_X_O(Board* bPtr, Player* playerPtr[2]) {
  boardPtr = bPtr;
  players[0] = playerPtr[0];
  players[1] = playerPtr[1];
}

void GameManager_FIVE_X_O::run() {
  int x, y;
  int turns{};

  boardPtr->display_board();

  while (turns != 24) {
    for (int i:{0,1}) {
      players[i]->get_move(x, y);
      while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
        players[i]->get_move(x, y);
      }
      boardPtr->display_board();
      turns++;
    }

  }
  boardPtr->is_winner();
}
