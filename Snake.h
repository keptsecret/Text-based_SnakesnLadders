#include "Player.h"
//#include "Board.h"
#include <string>
#ifndef SNAKE_H
#define SNAKE_H

class Snake {
    private:

    int length;
    int mouth_position;

    public:

    Snake(int l, int p);

    void affectPlayer(Player p);
    bool checkPosition(int tile);
    void setPosition(int tile);
    int getPosition();
    std::string testHello();
};

#endif