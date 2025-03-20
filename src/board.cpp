#include "board.hpp"
#include <iostream>

Board::Board()
{
    //populate board with empty chars
    board = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
}
void Board::play_turn (int row, int column, const char xo){
    this->board[row][column]= xo;
}
bool Board::winstate(){
    
}

void Board::print_board (){
    std::string cler ="\033[2J\033[1;1H"; 
    std::cout<<cler<<std::endl;
    std::cout<<"x|o|x\nx|o|x\nx|o|x\n";
}