//#include <new>
#include <vector>
#include "Snake.h"
#include "Ladder.h"
#ifndef BOARD_H
#define BOARD_H

class Board {
    private:
    
    int size;
    int dice_sides;
    std::vector<Snake> snake_list;
    std::vector<Ladder> ladder_list;

    public:

    Board(int s, int d);
    int getSize();
    int getDice();
    void initialize(int ns, int nl);
    bool update(Player &p);
    void checkBoardStatus();
};

#endif