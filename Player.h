#include <string>
#include <random>
#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:

    std::string name;
    std::mt19937 rng;
    int player_id;
    int position;
    bool win;

    public:

    Player(std::string n, int pid, int p);
    void move(int dice_faces);
    void move(int affector, char sl);
    int getPosition();
    std::string getName();
};

#endif