#pragma once
#include <vector>
#include <string>

#define DEBUG 1;

class Board{
public:
Board();
std::vector<std::vector<std::string>> board;
void play_turn (int row, int column, std::string xo);
bool winstate(int row, int column, std::string xo);
private:

const int m_row=3;
const int m_column = 3;
void print_board ();
void rec_winstate(int row, int column, std::string xo, int count, bool win,int start_row, int start_column);



};