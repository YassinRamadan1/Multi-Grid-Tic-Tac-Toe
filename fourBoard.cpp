#include "PyramidBoard.h"

char** Board4 ::getBoard() {
  return board;
}
Board4::Board4() {
  n_rows = n_cols = 4;
  board = new char* [n_rows];
  for (int i = 0; i < n_rows; i++) {
    board[i] = new char[n_cols];
    for (int j = 0; j < n_cols; j++)
      board[i][j] = 0;
  }
}

bool Board4::update_board(int x, int y, char mark) {
  // Only update if move is valid
  if (!(y < 0 || y > 3)) {
    x = 3; //Make sure we begin with the bottom cell
    while (board[x][y] != 0)
    {
      x--;
      if (x < 0)
        return false;
    }
    board[x][y] = mark;
    n_moves++;
    return true;
  }
  else
    return false;
}

void Board4::display_board() {
  for (int i : {0, 1, 2, 3}) {
    cout << "\n| ";
    for (int j : {0, 1, 2, 3}) {
      cout << "(" << i << "," << j << ")";
      cout << setw(2) << board[i][j] << " |";
    }
    cout << "\n-----------------------------";
  }
  cout << endl;
}

bool Board4::is_winner() {
  bool row_win [4], column_win [4], diag_win [2];
  diag_win [0] = (board [0] [0] && board [0] [0] == board [1] [1]  && board [0] [0] == board [2] [2] && board [0] [0] == board [3] [3]);
  diag_win [1] = (board [0] [3] && board [0] [3] == board [1] [2] && board [0] [3] == board [2] [1] && board [0] [3] == board [3] [0]);
  if(diag_win [0] || diag_win [1])
    return true;
  for(int i {0};i < 4;i++){
    row_win [i] = (board [i] [0] && board [i] [0] == board [i] [1] && board [i] [0] == board [i] [2] && board [i] [0] == board [i] [3]);
    column_win [i] = (board [0] [i] && board [0] [i] == board [1] [i] && board [0] [i] == board [2] [i] && board [0] [i] == board [3] [i]);
    if(column_win [i] || row_win [i])
      return true;
  }
  return false;
}

bool Board4::is_draw() {
  return (n_moves == 16 && !is_winner());
}

bool Board4::game_is_over() {
  return n_moves >= 16;
}
