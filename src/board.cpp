#include "board.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
Board::Board()
{
    //populate board with empty chars
    board = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
}
void Board::play_turn (int row, int column, std::string xo){
    if(row>=0 && row<m_row && column>=0 && column < m_column){
        this->board[row][column]= xo;
        print_board();
    }
    else
     std::cerr<<"invalid location, try again";

}
void Board::rec_winstate(int row, int column, std::string xo, int count, bool win, int start_row, int start_column){
    #ifdef DEBUG
    std::cout<<row<<column<<xo<<count<<win<<std::endl;
    #endif
    
    if(row>m_row || column>m_column ||row <0 || column <0){
        #ifdef DEBUG
        std::cout<<"edge\n";
        #endif
        return; //we reached the end
    }
        
    if (count ==2)
    {
        win = true;
        return;// winner!
    } 
    //else go around
    if((row!=start_row && column != start_column)&&(!board[row][column].compare(xo))){
        count = count +1;
        #ifdef DEBUG
        std::cout<<"Count"<<count<<std::endl;
        #endif
    
        rec_winstate(row -1, column, xo, count, win, start_row, start_column);
        rec_winstate(row, column-1, xo, count, win, start_row, start_column);
        rec_winstate(row, column+1, xo, count, win, start_row, start_column);
        rec_winstate(row, column-1, xo, count, win, start_row, start_column);
        rec_winstate(row+1, column+1, xo, count, win, start_row, start_column);
        rec_winstate(row-1, column-1, xo, count, win, start_row, start_column);
    }
    #ifdef DEBUG
    std::cout<<"returning empty\n";
    #endif
}
bool Board::winstate(int row, int column, std::string xo){
    // dfs to adjacent locations in each direction and find winner
    if(row<0 && row>=m_row && column<0 && column >= m_column)
        return false;
    int count = 0;
    bool win = false;
    rec_winstate(row, column, xo, count, win, row, column);
    return win;    
}

void Board::print_board (){
    #ifndef DEBUG
    std::string cler ="\033[2J\033[1;1H"; 
    std::cout<<cler<<std::endl;
    #endif
    for(int i =0; i<m_row; i++){
        for(int j=0; j<m_column; j++)
        {
            std::cout<<board[i][j];
        }
        std::cout<<std::endl;
    }

}