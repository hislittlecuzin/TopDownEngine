#pragma once
#include "Globals.h"
#include <SFML/Graphics.hpp>

class AnimationSystem {

public:
	/// Used for Constructor to define what animations will exist. 
	enum AnimatedType { wall, person };

	enum Animations { inPlace, idle, walking, };


	void Setup(sf::Texture &texture, AnimatedType typeOfAnimated, int posX, int poY);

	void PlayAnimation();
	void SetAnimationFrame(int xCoordinate, int yCoordinate);
	void ChangeAnimation(Animations newAnimation);
	
	

#pragma region Getters Setters
	void setRotation(float rot) {
		sprite.setRotation(rot);
	}
	void setPosition(int posX, int posY) {
		sprite.setPosition(posX, posY);
	}
	sf::Sprite GetSprite() {
		return sprite;
	}
	Animations GetCurrentAnimation() {
		return currentAnimation;
	}
#pragma endregion

private:
	AnimatedType animationType;
	Animations currentAnimation;
	int frameChangeDelayCounter = 0;
	const int frameChangeDelay = 5;
	int animationFrame = 0;
	const int framesPerInPlace = 1;
	const int framesPerIdle = 10;
	const int framesPerWalking = 10;

	int DetermineFrame();

	sf::Sprite sprite;
};
