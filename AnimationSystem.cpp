#include "AnimationSystem.h"

void AnimationSystem::Setup(sf::Texture &texture, AnimatedType typeOfAnimated, int posX, int posY) {
	sprite.setTexture(texture);

	animationType = typeOfAnimated;

	switch (animationType) {
	case wall:
		currentAnimation = inPlace;
		break;
	case person:
		currentAnimation = idle;
		break;
	default:
		currentAnimation = inPlace;
	}
	sprite.setPosition(posX, posY);
	SetAnimationFrame(0, 0);

	sprite.setOrigin(COLrADIUS, COLrADIUS);
}

void AnimationSystem::PlayAnimation() {

	frameChangeDelayCounter += 1;
	if (frameChangeDelayCounter < frameChangeDelay) {
		return;
	}
	else {
		frameChangeDelayCounter = 0;
	}


	int frame = 0;
	int frameSection = 0;

	switch (currentAnimation) {
	case inPlace:
		frameSection = 0;
		frame = 0;
		break;

	case idle:
		frameSection = 0;
		animationFrame += 1;
		frame = DetermineFrame();
	case walking:
		frameSection = 1;
		frame = DetermineFrame();
	}
	
	SetAnimationFrame(frame, frameSection);
}

void AnimationSystem::SetAnimationFrame(int xCoordinate, int yCoordinate) {
	sf::IntRect spriteRectangle(xCoordinate, yCoordinate, TILEsIZE, TILEsIZE);

	sprite.setTextureRect(spriteRectangle);
}

int AnimationSystem::DetermineFrame() {
	if (animationFrame < framesPerIdle) {
		return (animationFrame * TILEsIZE);
	}
	else {
		animationFrame = 0;
		return animationFrame;
	}
	
}

void AnimationSystem::ChangeAnimation(Animations newAnimation) {
	currentAnimation = newAnimation;
	animationFrame = 0;
}
