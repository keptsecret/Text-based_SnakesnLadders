#include <iostream>
#include "Board.h"

int main(int argc, char const *argv[])
{
    std::cout << "Starting program..." << std::endl;
    Board board = Board(100, 6);
    board.initialize();
    board.checkBoardStatus();
    return 0;
}