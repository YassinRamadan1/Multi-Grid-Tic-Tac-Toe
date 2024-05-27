#include "PyramidBoard.h"

pyramidBoard::pyramidBoard () {
  n_rows = 3, n_cols = 5;
  board = new char*[n_rows];
  for (int i = 0; i < n_rows; i++) {
    board[i] = new char[n_cols];
    for (int j = 0; j < n_cols; j++)
      board[i][j] = ' ';
  }
}

bool pyramidBoard::update_board (int x, int y, char mark){
  bool inBoundaries = ((x == 0 && y == 2) || (x == 1 && y > 0 && y < 4) || (x == 2 && y > -1 && y < 5));
  if (inBoundaries && (board[x][y] == ' ')){
    board[x][y] = toupper(mark);
    n_moves++;
    return true;
  }
  else
    return false;
}

void pyramidBoard::display_board() {
  for (int i: {0, 1, 2}) {
    cout << "\n";
    if(i == 0)
      cout << "\t\t";
    else if(i == 1)
      cout << '\t';
    cout << "| ";
    for (int j: {0, 1, 2, 3, 4}) {
      if(i == 0 && j == 2 || i == 1 && (j == 1 || j == 2 || j == 3) || i == 2){
        cout << "(" << i << "," << j << ")";
        cout << setw(2) << board [i] [j] << " |";
      }
    }
    cout << "\n-----------------------------";
  }
  cout << endl;
}

bool pyramidBoard::is_winner() {
  char row_win[4], col_win , diag_win[2];
  row_win[3] = (board[1][1] != ' ' && board[1][1] == board[1][2] && board[1][1] == board[1][3]);
  col_win = (board[0][2] != ' ' && board[0][2] == board[1][2] && board[0][2] == board[2][2]);
  diag_win[0] = (board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2]);
  diag_win[1] = (board[2][4] != ' ' && board[2][4] == board[1][3] && board[2][4] == board[0][2]);
  if(col_win || diag_win[0] || diag_win[1] || row_win[3])
    return true;
  for (int i {0};i < 3;i++){
    row_win[i] = (board[2][i] != ' ' && board[2][i] == board[2][i + 1] && board[2][i + 1] == board[2][i + 2]);
    if(row_win[i])
      return true;
  }
  return false;
}

bool pyramidBoard::is_draw() {
  return (n_moves == 9 && !is_winner());
}

bool pyramidBoard::game_is_over () {
  return n_moves >= 9;
}

char** pyramidBoard :: getBoard(){
  return board;
}
