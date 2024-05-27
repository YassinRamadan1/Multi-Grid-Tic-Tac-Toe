#include "PyramidBoard.h"

int main()
{
  bool op;
  int choice;
  cout << "Welcome to FCAI X-O Game press :)\n1) Three Board Game\t2) Pyramid Board Game\n3) Four Board Game\t4) Five Board Game\n";
  cin >> choice;
  if (choice == 1) {
    Player* players[2];
    players[0] = new Player(1, 'X');
    cout << "Press 0 for SinglePlayer or 1 for MultiPlayer :)\n";
    cin >> op;
    if (op)
      players[1] = new Player(2, 'O');
    else
      players[1] = new RandomPlayer('O', 3);
    Board* threeBoard = new X_O_Board();
    GameManager three(threeBoard, players);
    three.run();
  }
  else if (choice == 2) {
    Player* players[2];
    players[0] = new Player(1, 'X');
    Board* pyramid = new pyramidBoard();
    cout << "Press 0 for SinglePlayer or 1 for MultiPlayer :)\n";
    cin >> op;
    if (op)
      players[1] = new Player(2, 'O');
    else {
      cout << "Press 0 for Easy or 1 for Hard:)\n";
      cin >> op;
      if (op)
        players[1] = new AIPlayer('O', pyramid->getBoard());
      else
        players[1] = new RandomPlayer('O', 5);
    }
    GameManager Pyramid(pyramid, players);
    Pyramid.run();
  }
  else if (choice == 3) {
    Player4* players4[2];
    players4[0] = new Player4(1, 'X');
    cout << "Press 0 for SinglePlayer or 1 for MultiPlayer :)\n";
    cin >> op;
    if (op)
      players4[1] = new Player4(2, 'O');
    else
      players4[1] = new RandomPlayer4('O', 4);
    Board* fourBoard = new Board4();
    GameManager4 four(fourBoard, players4);
    four.run();
  }
  else if (choice == 4) {
    Player* players[2];
    players[0] = new Player(1, 'X');
    cout << "Press 0 for SinglePlayer or 1 for MultiPlayer :)\n";
    cin >> op;
    if (op)
      players[1] = new Player(2, 'O');
    else
      players[1] = new RandomPlayer('O', 5);
    Board* FiveBoard = new FIVE_X_O_Board();
    GameManager_FIVE_X_O five(FiveBoard, players);
    five.run();
  }
  return 0;
}