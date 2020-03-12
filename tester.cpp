#include "Board.h"

int main(int argc, char const *argv[])
{
    Board* board = new Board(100, 6);
    board->initialize();
    return 0;
}