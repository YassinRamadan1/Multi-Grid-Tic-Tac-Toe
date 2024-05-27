#include "PyramidBoard.h"
AIPlayer :: AIPlayer(char symbol, char** bd) : Player(symbol){
  this->name = "AI Computer Player";
  cout << "My names is " << name << endl;
  board = bd;
  if(symbol == 'X')
    moves = 0, s = 'O';
  else
    moves = 1, s = 'X';
}

bool AIPlayer::isFree(int i, int j){
   bool outBoundary = (i == 0 && j != 2 || i == 1 && (j < 1 || j > 3) || i == 2 && (j > 4 || j < 0));
   if(outBoundary || board [i] [j] == s || board [i] [j] == symbol)
     return false;
  return true;
}
int AIPlayer::isWinner(char symbol){
  bool row_win[4], col_win , diag_win[2];
  row_win[3] = (board[1][1] == symbol && board[1][1] == board[1][2] && board[1][1] == board[1][3]);
  col_win = (board[0][2] == symbol && board[0][2] == board[1][2] && board[0][2] == board[2][2]);
  diag_win[0] = (board[2][0] == symbol && board[2][0] == board[1][1] && board[2][0] == board[0][2]);
  diag_win[1] = (board[2][4] == symbol && board[2][4] == board[1][3] && board[2][4] == board[0][2]);
  if(col_win || diag_win[0] || diag_win[1] || row_win[3])
    return true;
  for(int i {0};i < 3;i++){
    row_win[i] = (board[2][i] == symbol && board[2][i] == board[2][i + 1] && board[2][i] == board[2][i + 2]);
    if(row_win[i])
      return true;
  }
  return false;
}
bool AIPlayer::gameOver(){
  return (moves >= 9);
}
void AIPlayer::get_move(int &x, int &y) {
  int result {-2}, val, mx, my;
  for(int i {0};i < 3;i++)
    for(int j {0};j < 5;j++){
      if(isFree(i, j)){
        board [i] [j] = symbol, moves++;
        val = minimax(false);
        board [i] [j] = ' ', moves--;
        if(result < val)
          result = val, mx = i, my = j;
      }
    }
  x = mx, y = my, moves += 2;
}
int AIPlayer::minimax(bool playerState){
  if(isWinner(symbol))
    return 1;
  else if(isWinner(s))
    return -1;
  else if(gameOver())
    return 0;
  if(playerState){
    int maxi {-2};
    for(int i {0};i < 3;i++)
      for(int j {0};j < 5;j++)
        if(isFree(i, j)){
          board [i] [j] = symbol, moves++;
          maxi = max(maxi, minimax(false));
          board [i] [j] = ' ', moves--;
        }
    return maxi;
  }
  else{
    int mini {2};
    for(int i {0};i < 3;i++)
      for(int j {0};j < 5;j++)
        if(isFree(i, j)){
          board [i] [j] = s, moves++;
          mini = min(mini, minimax(true));
          board [i] [j] = ' ', moves--;
        }
    return mini;
  }
}

