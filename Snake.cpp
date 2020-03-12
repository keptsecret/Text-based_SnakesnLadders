#include "Snake.h"
#include "Player.h"
#include <string>
#include <ctime>

Snake::Snake(int l, int p)
{
    length = l;
    mouth_position = p;
}

// moves the Player back |length| tiles if they land on tile with
// |mouth_position|
void Snake::affectPlayer(Player p) { p.move(length, 's'); }

// returns true if a Player is on the tile
bool Snake::checkPosition(int tile) { return tile == mouth_position; }

// sets the position of the Snake's mouth
void Snake::setPosition(int tile) { mouth_position = tile; }

std::string Snake::testHello() { return "Hello"; }
