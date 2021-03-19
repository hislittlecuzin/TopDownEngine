#pragma once
#include "Thing.h"

class Dynamic : public Thing {

public:
	void PlanMoveDirection(Map& map);
	void RequestMove(Map& map, int width, int height, Thing::Direction dirX, Thing::Direction dirY);
	void RequestMoveY(Map& map, int width, int height, Thing::Direction dir);
	void SetMoveRight(bool val);
	void SetMoveLeft(bool val);
	void SetMoveUp(bool val);
	void SetMoveDown(bool val);
	void RequestMove();

	bool GetMoveRight();
	bool GetMoveLeft();
	bool GetMoveUp();
	bool GetMoveDown();

private:
	bool moveRight = false;
	bool moveLeft = false;
	bool moveUp = false;
	bool moveDown = false;
};