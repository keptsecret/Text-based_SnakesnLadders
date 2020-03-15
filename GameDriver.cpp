#include <iostream>
#include "Board.h"
#include "Player.h"

int getInt() {
    using namespace std;
    int x = 0;

    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
    }

    return x;
}

int main(int argc, char const *argv[])
{
    int num_players = 0;
    
    std::cout << "Starting program..." << std::endl;
    Board board = Board(100, 6);
    std::cout << "How many players?(1-4) ";
    do {
        num_players = getInt();
    } while (num_players < 0 || num_players > 5);
    board.initialize(3, 4);
    board.checkBoardStatus();
    return 0;
}