#include "PyramidBoard.h"

RandomPlayer4::RandomPlayer4(char symbol, int dimension) :Player4(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer4::get_move(int& x, int& y) {
    x = 3;
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}
