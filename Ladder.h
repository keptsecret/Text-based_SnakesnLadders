#include "Player.h"
#ifndef LADDER_H
#define LADDER_H

class Ladder {
    private:

    int length;
    int bottom_position;

    public:

    Ladder(int l, int p);
    void affectPlayer(Player p);
    bool checkPosition(int tile);
    void setPosition(int tile);
    int getPosition();
};

#endif