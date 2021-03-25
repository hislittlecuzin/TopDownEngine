#include "Tile.h"
#include "Thing.h"

Tile::Tile(int xArg, int yArg) {
	x = xArg;
	y = yArg;
	occupant = nullptr;
}

Tile::Tile() {
	x = -1;
	y = -1;
	occupant = nullptr;
}

bool Tile::GetHasOccupant() {
	if (occupant == nullptr)
		return false;
	return true;
}