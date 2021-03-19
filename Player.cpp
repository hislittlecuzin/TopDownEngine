
#include "Player.h"
#include "Map.h"


Player::Player() {}
Player::Player(int wX, int wY, Collider col, sf::Texture &texture, Map &map, int screenX, int screenY, AnimationSystem::AnimatedType thingType) {
	PlayerSetup(wX, wY, col, texture, map, screenX, screenY, thingType);
}
void Player::PlayerSetup(int wX, int wY, Collider col, sf::Texture &texture, Map &map, int screenX, int screenY, AnimationSystem::AnimatedType thingType) {
	worldX = wX;
	worldY = wY;
	SetCollider(col);
	sf::Vector2i loc = NormalizeWorldSpaceToGridSpace();
	map.SetOccupant(*this, loc.x, loc.y);

	graphicalRepresentation.Setup(texture, thingType, screenX / 2, screenY / 2);

}


void Player::PlayerInput(sf::Event& event, sf::Vector2i mousePos, sf::Window& window) {
	Rotation(event, window);
	MovementInput(event);
}

void Player::PlayerUpdate() {
	graphicalRepresentation.GetSprite().setRotation(angleToMouse);
	MovementOutput();
	Animate();
}

void Player::MovementInput(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::A)
			SetMoveLeft(true);
		if (event.key.code == sf::Keyboard::D)
			SetMoveRight(true);
		if (event.key.code == sf::Keyboard::W)
			SetMoveUp(true);
		if (event.key.code == sf::Keyboard::S)
			SetMoveDown(true);
	}
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::A)
			SetMoveLeft(false);
		if (event.key.code == sf::Keyboard::D)
			SetMoveRight(false);
		if (event.key.code == sf::Keyboard::W)
			SetMoveUp(false);
		if (event.key.code == sf::Keyboard::S)
			SetMoveDown(false);
	}
}

void Player::MovementOutput() {
	if (GetMoveRight())
		worldX += 1;
	if (GetMoveLeft())
		worldX -= 1;
	if (GetMoveUp())
		worldY -= 1;
	if (GetMoveDown())
		worldY += 1;
	NormalizeWorldSpaceToGridSpace();
	//printf("X: %d, Y: %d\n", worldX, worldY);
}

void Player::Rotation(sf::Event& event, sf::Window& window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	int xDiff = graphicalRepresentation.GetSprite().getPosition().x - mousePos.x;
	int yDiff = graphicalRepresentation.GetSprite().getPosition().y - mousePos.y;

	int hypotonuse = sqrt((xDiff * xDiff) + (yDiff * yDiff));
	//printf("X: %d Y: %d Hypot: %d\n", xDiff, yDiff, hypotonuse);
	angleToMouse = (atan2(yDiff, xDiff) * 180 / 3.14159265f) - 90;
	
	graphicalRepresentation.setRotation(angleToMouse);
}

void Player::Animate() {

	if (GetMoveUp() || GetMoveDown() || GetMoveLeft() || GetMoveRight()) {
		if (graphicalRepresentation.GetCurrentAnimation() != AnimationSystem::idle) {
			printf("Change To Moving! \n");
			graphicalRepresentation.ChangeAnimation(AnimationSystem::idle);
		}
	}
	else {
		if (graphicalRepresentation.GetCurrentAnimation() != AnimationSystem::inPlace) {
			graphicalRepresentation.ChangeAnimation(AnimationSystem::inPlace);
		}
	}


	graphicalRepresentation.PlayAnimation();
	
}