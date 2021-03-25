#pragma once
#include <memory>
//#include "Thing.h"
class Thing;

class Tile{
public:
	Tile(int xArg, int yArg);
	Tile();
	int x;
	int y;
	bool GetHasOccupant();
	Thing * occupant;
	Thing * background;
};