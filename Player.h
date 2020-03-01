#include <string>
#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:

    std::string name;
    int player_id;
    int position;
    bool win;

    public:

    Player(std::string n, int pid, int p);
    void move(int dice_faces);
    int getPosition();
};

#endif