#pragma once
#include "Thing.h"
#include "Dynamic.h"

class Player : public Dynamic {
public:
	Player();
	Player(int wX, int wY, Collider col, sf::Texture &texture, Map &map, int screenX, int screenY, AnimationSystem::AnimatedType thingType);
	void PlayerSetup(int wX, int wY, Collider col, sf::Texture &texture, Map &map, int screenX, int screenY, AnimationSystem::AnimatedType thingType);

	void PlayerUpdate();
	void PlayerInput(sf::Event& event, sf::Vector2i mousePos, sf::Window& window);
	void MovementInput(sf::Event event);
	void MovementOutput();
	void Rotation(sf::Event& event, sf::Window& window);
	void Animate();
	
	

private:
	float angleToMouse;
	
};