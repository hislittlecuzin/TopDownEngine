#include "Map.h"
#include "Tile.h"
#include <iostream>

Map::Map() {}

Map::Map(int x, int y) {
	mapX = x;
	mapY = y;
	map = std::make_unique<std::vector<Tile>>();

	for (int newY = 0; newY < y; newY++) {	
		for (int newX = 0; newX < x; newX++) {
			map->push_back(Tile(newX, newY));
			printf("Mapx: %d Mapy: %d \n", newX, newY);
		}
	}
}


Tile& Map::AccessIndex(int x, int y) {
	int index = 0;
	for (int i = 0; i < y; i++) {
		index += mapX;
	}
	index += x;

	//printf("\n Access Index: X %d Y %d \n", map->at(index).x, map->at(index).y);
	return map->at(index);
}

bool Map::GetHasOccupant(int x, int y) {
	return AccessIndex(x, y).GetHasOccupant();
}

void Map::SetOccupant(Thing& newOccupant, int x, int y) {
	AccessIndex(x, y).occupant = &newOccupant;
	std::cout << "HERE!!";
}

int Map::GetMaxX() {
	return mapX;
}

int Map::GetMaxY() {
	return mapY;
}