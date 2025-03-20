#pragma once
#include <vector>
#include <string>

class Board{
public:
Board();
std::vector<std::vector<std::string>> board;
bool winstate();

private:

const int row=3;
const int column = 3;
void print_board ();
void play_turn (int row, int column, const char xo);

};