#include "PyramidBoard.h"

Player4::Player4(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player4::Player4(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player4::get_move(int& x, int& y) {
    cout << "\nPlease enter your move y (0 to 3) separated by spaces: "; // We don't x input
    cin >> y;
    x = 3; // make x = 3
}

// Give player info as a string
string Player4::to_string() {
    return "Player: " + name;
}

// Get symbol used by player
char Player4::get_symbol() {
    return symbol;
}
