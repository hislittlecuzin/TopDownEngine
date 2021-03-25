#pragma once
#include "AnimationSystem.h"

class Tile;
class Map;



class Thing {
public:

	enum Collider { circle, square };
	enum Direction { notMoving, negative, positive };
	

	struct xyDirection {
	public:
		Direction X;
		Direction y;
	};

	Thing(int wX, int wY, Collider col, sf::Texture &texture, Map &map, AnimationSystem::AnimatedType thingType);
	Thing();
	sf::Vector2i NormalizeWorldSpaceToGridSpace();
	bool RequestMove(Map& map, int width, int height);
	void SetCollider(Collider col);
	Collider GetCollider();
	void ThingUpdate(int playerX, int playerY, sf::Vector2i playerScreenSpace);

	//Direction PlanMoveDirectionX(int x, Map& map);
	

	sf::Sprite GetSprite() {
		return graphicalRepresentation.GetSprite();
	}

	//Location (NOT screenspace. Relative space.)
	int worldX;
	int worldY;
	int GetWorldX();
	int GetWorldY();

	//Physics (used for collisions.)
	int gridX;
	int gridY;

private:
	Collider collider;

protected:
	AnimationSystem graphicalRepresentation;
};
