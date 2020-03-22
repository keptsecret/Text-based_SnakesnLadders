#include <random>
#include <vector>
#include <iostream>
#include <ctime>
#include "Board.h"

Board::Board(int s, int d) 
{
    std::cout << "Creating board of size " << s << " and playing with a " << d << "-sided die..." << std::endl;
    size = s;
    dice_sides = d;
}

void Board::initialize(int ns, int nl)
{
    using namespace std;
    int num_snake = ns;
    int num_ladder = nl;

    std::cout << "Initializing... ";
    // create the snakes
    srand(time(0));
    /*std::mt19937 rng;
    uint32_t seed_val;
    rng.seed(seed_val);
    std::uniform_int_distribution<int> dice(1, size / num_snake);*/
    snake_list.reserve(num_snake);
    for (int i = 0; i < num_snake; i++)
    {
        // calculate random position for the snake in chunks spaced equally apart
        // prevent snakes from spawning too close to start or end
        int pos;
        do 
        {
            pos = rand() % (size / num_snake) + (size / num_snake * i) + 1;
            //pos = dice(rng);
        } while (pos < 5 || pos > 90);
        snake_list.push_back(Snake(rand() % pos, pos));
    }

    // create the ladders
    ladder_list.reserve(num_ladder);
    for (int i = 0; i < num_ladder; i++)
    {
        // calculate random position for the ladder in chunks spaced equally apart
        // prevent ladders from spawning too close to start or end
        int pos;
        do 
        {
            pos = rand() % (size / num_ladder) + (size / num_ladder * i) + 1;
        } while (pos < 5 || pos > 90);
        ladder_list.push_back(Ladder(pos + rand() % (size - pos), pos));
    }
    std::cout << "Done" << std::endl;
    std::cout << "There are " << snake_list.size() << " snakes and " << ladder_list.size() << " ladders." << std::endl;
}

// to be used at the end of every round, updates the status of the board and Players
bool Board::update(Player &p)
{
    for (Snake &s : snake_list) 
    {
        if (s.checkPosition(p.getPosition()))
        {
            s.affectPlayer(p);
        }
    }

    for (Ladder &l : ladder_list)
    {
        if (l.checkPosition(p.getPosition()))
        {
            l.affectPlayer(p);
        }
    }

    return p.getPosition() == 100;
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

int Board::getDice() { return dice_sides; }