

#include "Thing.h"
#include "Globals.h"
#include "Map.h"

#include <iostream>

Thing::Thing() {

}

Thing::Thing(int wX, int wY, Collider col, sf::Texture &texture, Map& map, AnimationSystem::AnimatedType thingType) {
	worldX = wX;
	worldY = wY;
	collider = col;
	sf::Vector2i loc = NormalizeWorldSpaceToGridSpace();
	map.SetOccupant(*this, loc.x, loc.y);
	
	graphicalRepresentation.Setup(texture, thingType, loc.x, loc.y);
	
}


sf::Vector2i Thing::NormalizeWorldSpaceToGridSpace() {
	gridX = worldX / TILEsIZE;
	gridY = worldY / TILEsIZE;
	//printf("worldX: %d GridX: %d worldY: %d gridY: %d \n", worldX, gridX, worldY, gridY);
	return sf::Vector2i(gridX, gridY);
}



void Thing::SetCollider(Collider col) {
	collider = col;
}

Thing::Collider Thing::GetCollider() {
	return collider;
}

int Thing::GetWorldX() {
	return worldX;
}
int Thing::GetWorldY() {
	return worldY;
}

void Thing::ThingUpdate(int playerX, int playerY, sf::Vector2i playerScreenSpace) {
	graphicalRepresentation.setPosition((worldX - playerX) + playerScreenSpace.x, (worldY - playerY) + playerScreenSpace.y);
}

