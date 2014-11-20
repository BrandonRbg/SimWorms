#pragma once
#include "PhysicsComponent.h"
#include "OOSDL\AnimatedSprite.h"

class Projectile {
protected:
	PhysicsComponent physics;
	sdl::AnimatedSprite sprite;
	sdl::Vector2Float velociy;
public:
	void update();

	void setVelocity(sdl::Vector2Float velocity) { this->velociy = velocity; }

	sdl::Vector2Float getVelocity() { return velociy; }
};