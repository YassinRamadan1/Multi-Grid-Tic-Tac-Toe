#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;


#ifndef PYRAMIDBOARD_H
#define PYRAMIDBOARD_H


class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;
public:
    virtual bool update_board (int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
    virtual char** getBoard() = 0;
};

class X_O_Board:public Board {
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    char** getBoard();
};


class pyramidBoard : public Board {
public:
    pyramidBoard ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    char** getBoard();
};

class Board4 :public Board {
public:
    Board4();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    char** getBoard();
};


class FIVE_X_O_Board : public Board{
public:
    FIVE_X_O_Board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    char** getBoard();
};


class Player {
protected:
    string name;
    char symbol;
public:
    Player (char symbol);
    Player (int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};

class Player4 {
protected:
    string name;
    char symbol;
public:

    Player4(char symbol);
    Player4(int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};

class RandomPlayer: public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};

class RandomPlayer4 : public Player4 {
protected:
    int dimension;
public:
    RandomPlayer4(char symbol, int dimension);
    void get_move(int& x, int& y);
};

class AIPlayer5 : public Player{
private:
    int moves;
    char** board;
    char s;
    bool isFree(int i, int j);
    int isWinner();
    bool gameOver();
    int minimax(bool playerState);
public:
    AIPlayer5(char symbol, char**);
    void get_move(int& x, int& y);

};

class AIPlayer : public Player{
private:
    int moves;
    char** board;
    char s;
    bool isFree(int i, int j);
    int isWinner(char symbol);
    bool gameOver();
    int minimax(bool playerState);
public:
    AIPlayer (char symbol, char**);
    void get_move(int& x, int& y);

};
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
};

class GameManager4 {
private:
    Board* boardPtr;
    Player4* players[2];
public:
    GameManager4(Board*, Player4* playerPtr[2]);
    void run();
};

class GameManager_FIVE_X_O {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager_FIVE_X_O(Board*, Player* playerPtr[2]);
    void run();
};



#endif
