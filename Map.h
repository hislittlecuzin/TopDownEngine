#pragma once
#include <vector>
#include<memory>
class Tile;
class Thing;

class Map {
public:
	Map();
	Map(int x, int y);
	bool GetHasOccupant(int x, int y);
	void SetOccupant(Thing& newOccupant, int x, int y);
	int GetMaxX();
	int GetMaxY();
	Tile& AccessIndex(int x, int y);
private:
	//Tile map[10][10];
	std::unique_ptr<std::vector<Tile>> map;
	int mapX;
	int mapY;
	

};