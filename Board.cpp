//#include <new>
//#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include "Snake.h"
//#include "Player.h"
//#include "Ladder.h"
#include "Board.h"

Board::Board(int s, int d) 
{
    std::cout << "Creating board of size " << s << " and playing with a " << d << "-sided die..." << std::endl;
    size = s;
    dice = d;
}

void Board::initialize()
{
    using namespace std;

    std::cout << "Initializing... ";
    srand(time(nullptr));
    snake_list.reserve(5);
    for (int i = 0; i < snake_list.size(); i++)
    {
        int pos = rand() % 100 + 1;
        snake_list.push_back(Snake(pos, pos + rand() % (size - pos)));
    }

    ladder_list.reserve(5);
    for (int i = 0; i < ladder_list.size(); i++)
    {
        int pos = rand() % 100 + 1;
        ladder_list.push_back(Ladder(pos, pos + rand() % (size - pos)));
    }
    std::cout << "Done" << std::endl;
    std::cout << "There are " << snake_list.size() << " snakes and " << ladder_list.size() << " ladders." << std::endl;
}

void Board::checkBoardStatus()
{
    for (Snake s : snake_list)
    {
        std::cout << "There is a snake at " << s.getPosition() << std::endl;
    }
    for (Ladder l : ladder_list)
    {
        std::cout << "There is a ladder at " << l.getPosition() << std::endl;
    }
}

int Board::getSize() { return size; }

/*
int main(int argc, char const *argv[])
{
    Board board = Board(100, 6);
    board.initialize();
    board.checkBoardStatus();
    return 0;
}
*/