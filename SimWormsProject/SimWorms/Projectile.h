#pragma once
#include "PhysicsComponent.h"
#include "OOSDL\AnimatedSprite.h"
#include "Terrain.h"

class Projectile {
protected:
	PhysicsComponent physics;
	sdl::AnimatedSprite sprite;
	sdl::Vector2Float velociy;
public:
	Projectile(sdl::Vector2Float position, sdl::Vector2Float direction, float puissance);
	~Projectile();

	void draw(sdl::Window& window);

	void update(float FrameTime, Terrain& terrain);

	void setVelocity(sdl::Vector2Float velocity) { this->velociy = velocity; }

	sdl::Vector2Float getVelocity() { return velociy; }
};