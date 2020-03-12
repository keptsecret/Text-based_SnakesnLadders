#include <new>
//#include <string>
#include <iostream>
#include <ctime>
#include "Snake.h"
//#include "Player.h"
#include "Ladder.h"
#include "Board.h"

Board::Board(int s, int d) 
{
    size = s;
    dice = d;
}

void Board::initialize()
{
    using namespace std;

    srand(time(nullptr));
    snake_list = new Snake[5];
    for (int i = 0; i < 5; i++)
    {
        int pos = rand() % 100 + 1;
        snake_list[i] = new Snake(pos, pos + rand() % (size - pos));
    }
    cout << snake_list[1].testHello();
}

int Board::getSize() { return size; }