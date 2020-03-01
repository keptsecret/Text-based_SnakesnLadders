#include <new>
#include <string>
#include <iostream>
#include "Snake.h"
#include "Player.h"
#include "Ladder.h"
#include "Board.h"

Board::Board(int s, int d) 
{
    size = s;
    dice = d;
}

void Board::initialize()
{

}