#include <new>
#include "Snake.h"
#include "Ladder.h"
#ifndef BOARD_H
#define BOARD_H

class Board {
    private:
    
    int size;
    int dice;
    Snake* snake_list;
    Ladder* ladder_list;

    public:

    Board(int s, int d);
    int getSize();
    void initialize();
};

#endif