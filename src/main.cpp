#include <iostream>
#include <string>
#include "board.hpp"



int main()
{
    Board b;
    bool game_over = false;
    std::string intro = "Welcome to tic-tac-toe. \n start by entering where you want to place your char";
    int row =0;
    int column=0;  
    std::string xo = "x";

    std::cout<<intro<<std::endl;
    while(!game_over){
        
        std::cin>>row>>column>>xo;
        b.play_turn(row, column, xo);
        game_over = b.winstate(row, column,xo);
    }
    return 0;
}

