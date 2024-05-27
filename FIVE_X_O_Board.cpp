#include "PyramidBoard.h"

char** FIVE_X_O_Board ::getBoard() {
  return board;
}

FIVE_X_O_Board::FIVE_X_O_Board(){
  n_rows = n_cols = 5;
  board = new char*[n_rows];
  for (int i = 0; i < n_rows; i++) {
    board [i] = new char[n_cols];
    for (int j = 0; j < n_cols; j++)
      board[i][j] = 0;
  }

}

bool FIVE_X_O_Board:: update_board (int x, int y, char mark){

  if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
    board[x][y] = mark;
    n_moves++;
    return true;
  }
  else
    return false;


}
void FIVE_X_O_Board::display_board(){
  for (int i: {0,1,2,3,4}) {
    cout << "\n| ";
    for (int j: {0,1,2,3,4}) {
      cout << "(" << i << "," << j << ")";
      cout << setw(2) << board [i][j] << " |";
    }
    cout << "\n------------------------------------------";
  }
  cout << endl;

}
bool FIVE_X_O_Board::is_winner(){
  int Xscore{},Oscore{};
  for(int i = 1; i < n_rows-1; i++) { // checks the 5 spaces at middle of board
    for (int j = 1; j < n_cols-1; j++) {
      if (board[i][j] == 'X' && board[i - 1][j] == 'X' && board[i + 1][j] == 'X') //checks right and left for Xscore
        Xscore++;
      else if (board[i][j] == 'O' && board[i - 1][j] == 'O' &&
               board[i][j - 1] == 'O') //checks right and left for Oscore
        Oscore++;
      else if (board[i][j] == 'X' && board[i][j - 1] == 'X' && board[i][j + 1] == 'X') //above and below for Xscore
        Xscore++;
      else if (board[i][j] == 'O' && board[i][j - 1] == 'O' && board[i][j + 1] == 'O') //above and below for Oscore
        Oscore++;
      else if (board[i][j] == 'X' && board[i - 1][j - 1] == 'X' &&
               board[i + 1][j + 1] == 'X') //upper left and lower right diagonal for Xscore
        Xscore++;
      else if (board[i][j] == 'O' && board[i - 1][j - 1] == 'O' &&
               board[i + 1][j + 1] == 'O') //upper left and lower right diagonal for Oscore
        Oscore++;
      else if (board[i][j] == 'X' && board[i - 1][j + 1] == 'X' &&
               board[i + 1][j - 1] == 'X') //lower left and upper right diagonal for Xscore
        Xscore++;
      else if (board[i][j] == 'O' && board[i - 1][j + 1] == 'O' &&
               board[i + 1][j - 1] == 'O') //lower left and upper right diagonal for Xscore
        Oscore++;
    }
  }

  for(int i = 0; i < 3; i++){ //checks the outer sides
    if(board[i][0] == 'X' && board[i + 1][0] == 'X' && board[i + 2][0] == 'X')
      Xscore++;
    if(board[i][0] == 'O' && board[i + 1][0] == 'O' && board[i + 2][0] == 'O')
      Oscore++;
    if(board[0][i] == 'X' && board[0][i+1] == 'X' && board[0][i+2] == 'X')
      Xscore++;
    if(board[0][i] == 'O' && board[0][i+1] == 'O' && board[0][i+2] == 'O')
      Oscore++;
  }

  if (Xscore > Oscore)
    cout<<"X is the winner\n";
  else if(Oscore > Xscore)
    cout<<"O is the winner\n";
  else
    cout<<"its a draw !\n";
  return true;
};


bool FIVE_X_O_Board::is_draw(){
  return 1; //dont need it
}

bool FIVE_X_O_Board::game_is_over(){
  return n_moves >= 24;
}
