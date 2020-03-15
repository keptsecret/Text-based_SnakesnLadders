#include "Player.h"
#include <string>
#include <time.h>

Player::Player(std::string n, int pid, int p) 
{
    name = n;
    player_id = pid;
    position = p;
}

// does a dice roll and move accordingly
void Player::move(int dice_faces) 
{
    srand(time(NULL));
    int dice_roll = rand() % dice_faces + 1;
    position += dice_roll;
}

void Player::move(int affector, char sl)
{
    switch (sl)
    {
        case 'l':
            position += affector;
            if (position > 100) { position = position - (position - 100); }
            break;
        case 's':
            position -= affector;
            if (position < 0) { position = 0; }
            break;
        default:
            break;
    }
}

int Player::getPosition() { return position; }