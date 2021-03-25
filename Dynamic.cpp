#include "Dynamic.h"
#include "Map.h"
#include <iostream>
#include "Tile.h"
#include "Globals.h"

void Dynamic::PlanMoveDirection(Map& map) {
	//bool moveX = false;
	//bool moveY = false;
	Direction xDir = notMoving;
	Direction yDir = notMoving;
	if (moveRight)
		xDir = positive;
	else if (moveLeft)
		xDir = negative;

	if (moveUp)
		yDir = positive;
	else if (moveDown)
		yDir = negative;

	//RequestMove(map, gridX, gridY, xDir, yDir);
	switch (xDir) {
	case positive:
		RequestMove(map, gridX + 1, gridY, xDir, yDir);
		break;
	case negative:
		RequestMove(map, gridX - 1, gridY, xDir, yDir);
		break;
	}
	switch (yDir) {
	case Thing::negative:
		RequestMove(map, gridX, gridY + 1, xDir, yDir);
		if (xDir == positive)
			RequestMove(map, gridX + 1, gridY + 1, xDir, yDir);
		if (xDir == negative)
			RequestMove(map, gridX - 1, gridY + 1, xDir, yDir);
		break;
	case Thing::positive:
		RequestMove(map, gridX, gridY - 1, xDir, yDir);
		if (xDir == positive)
			RequestMove(map, gridX + 1, gridY - 1, xDir, yDir);
		if (xDir == negative)
			RequestMove(map, gridX - 1, gridY - 1, xDir, yDir);
		break;
	}

	return;
}

void Dynamic::RequestMove(Map& map, int width, int height, Thing::Direction dirX, Thing::Direction dirY) {
	if (dirX == notMoving && dirY == notMoving)
		return;
	//If trying to walk out of bounds, stop. 
	if (width < 0 || height < 0 || width >= map.GetMaxX() || height >= map.GetMaxY()) {
		printf("GRID X: %d  GRID Y: %d   ", worldX, worldY);
		std::cout << "ERROR! Moved out of bounds of map.\n";
		moveUp = false;
		moveDown = false;
		moveLeft = false;
		moveRight = false;
		return;
	}
	Thing* occupant;
	if (map.GetHasOccupant(width, height)) {
		occupant = map.AccessIndex(width, height).occupant;
		//hlc COLLISION BUGGGGFSDLHJGLKFJDHGDFGL:FDG
		

		printf("\n\nLocation X world %d\n", occupant->GetWorldX);
		printf("my X world %d\n", worldX);
		switch (dirX)
		{
		case Thing::negative:
			printf("\nX NEGATIVE XXXXX!\n");
			if (occupant->GetWorldX() < worldX)
				if (occupant->GetWorldX() + COLrADIUS > worldX - COLrADIUS) {
					moveLeft = false;
					printf("HERE!");
				}
			break;
		case Thing::positive:
			moveRight = false;
			if (occupant->worldX > worldX)
				if (occupant->worldX - COLrADIUS < worldX + COLrADIUS) {
					moveRight = false;
					
				}
			break;
		default:
			break;
		}

		switch (dirY)
		{
		case Thing::negative:
			moveDown = false;
			if (occupant->worldY < worldY)
				if (occupant->worldY + COLrADIUS > worldY - COLrADIUS)
					moveDown = false;
			break;
		case Thing::positive:
			moveUp = false;
			if (occupant->worldY > worldY)
				if (occupant->worldY - COLrADIUS < worldY + COLrADIUS)
					moveUp = false;
			break;
		default:
			break;
		}

	}
	else {
		//printf("\nNo occupant: X: %d Y: %d \n", width, height);
	}
	return;
}



#pragma region Get/Set moves
void Dynamic::SetMoveRight(bool val) {
	moveRight = val;
}
void Dynamic::SetMoveLeft(bool val) {
	moveLeft = val;
}
void Dynamic::SetMoveUp(bool val) {
	moveUp = val;
}
void Dynamic::SetMoveDown(bool val) {
	moveDown = val;
}

bool Dynamic::GetMoveRight() {
	return moveRight;
}
bool Dynamic::GetMoveLeft() {
	return moveLeft;
}
bool Dynamic::GetMoveUp() {
	return moveUp;
}
bool Dynamic::GetMoveDown() {
	return moveDown;
}

#pragma endregion