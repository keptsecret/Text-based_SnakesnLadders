#include "Player.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>



Player::Player(std::string n, int pid, int p) 
{
    name = n;
    player_id = pid;
    position = p;
    rng.seed(time(0));
}

// does a dice roll and move accordingly
void Player::move(int dice_faces) 
{
    //srand(time(0));
    std::uniform_int_distribution<> dice(1,dice_faces);
    //int dice_roll = rand() % dice_faces + 1;
    int dice_roll = dice(rng);
    position += dice_roll;
    if (position > 100) { position = position - (position - 100); }
    std::cout << "Player " << name << " rolled a " << dice_roll << std::endl;
}

void Player::move(int affector, char sl)
{
    switch (sl)
    {
        case 'l':
            position += affector;
            std::cout << "Player " << name << " reaches a ladder and moves up " << affector << " steps!" << std::endl;
            if (position > 100) { position = position - (position - 100); }
            break;
        case 's':
            position -= affector;
            std::cout << "Player " << name << " runs into a snake and runs back " << affector << " steps!" << std::endl;
            if (position < 0) { position = 0; }
            break;
        default:
            break;
    }
}

int Player::getPosition() { return position; }

std::string Player::getName() { return name; }