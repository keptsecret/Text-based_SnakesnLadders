#include "Ladder.h"
#include "Player.h"

Ladder::Ladder(int l, int p)
{
    length = l;
    bottom_position = p;
}

// moves the Player forward |length| tiles if they land on |bottom_position|
void Ladder::affectPlayer(Player p) { p.move(length, 'l'); }

// returns true if a Player is on the tile
bool Ladder::checkPosition(int tile) { return tile == bottom_position; }

// sets the position of the Snake's mouth
void Ladder::setPosition(int tile) { bottom_position = tile; }