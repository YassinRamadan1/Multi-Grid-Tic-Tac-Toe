#include "PyramidBoard.h"


RandomPlayer::RandomPlayer (char symbol, int dimension) : Player(symbol)
{
  this->dimension = dimension;
  this->name = "Random Computer Player";
  cout << "My names is " << name << endl;
}

void RandomPlayer::get_move (int& x, int& y) {
  x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
  y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}