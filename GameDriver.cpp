#include <iostream>
#include <vector>
#include <string>
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
    bool end = false;
    int player_rotator = 0;
    std::vector<Player> player_list;
    
    std::cout << "Starting program..." << std::endl;
    Board board = Board(100, 6);
    std::cout << "How many players?(1-4) ";
    do {
        num_players = getInt();
    } while (num_players < 0 || num_players > 5);

    player_list.reserve(num_players);
    for (int i = 0; i < num_players; i++)
    {
        std::string n;
        std::cout << "Enter player " << i + 1 << " name: ";
        while (!(std::cin >> n)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        player_list.push_back(Player(n, i + 1, 0));
        std::cout << "Player created successfully" << std::endl;
    }

    board.initialize(3, 4);
    board.checkBoardStatus();

    while (!end)
    {
        player_list.at(player_rotator).move(board.getDice());
        end = board.update(player_list.at(player_rotator));
        player_rotator++;
        if (player_rotator >= num_players)
        {
            player_rotator %= num_players;
        }
    }

    std::cout << "Player " << player_rotator + 1 << " wins!" << std::endl;
    std::cout << "Game has ended" << std::endl;
    return 0;
}