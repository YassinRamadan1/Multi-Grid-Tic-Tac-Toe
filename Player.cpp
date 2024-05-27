#include "PyramidBoard.h"

Player::Player(char symbol) {
  this->symbol = symbol;
}

Player::Player (int order, char symbol) {
  cout << "Welcome player " << order << endl;
  cout << "Please enter your name: ";
  cin >> name;
  this->symbol = symbol;
}

void Player::get_move (int& x, int& y) {
  cout << "\nPlayer " << this->name << ", Please enter your move x and y within the shown range separated by spaces: ";
  cin >> x >> y;
}

string Player::to_string(){
  return "Player: " + name ;
}

char Player::get_symbol() {
  return symbol;
}
