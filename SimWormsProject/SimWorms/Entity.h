#pragma once
#include "PhysicsComponent.h"
#include "OOSDL\AnimatedSprite.h"
#include "Terrain.h"
#include "AssetsManager.h"

class Entity {
protected:
	sdl::Vector2Float position;
	sdl::Vector2Float velocity;
	sdl::Sprite sprite;
	PhysicsComponent physics;
	// besoin d'un inputComponent
public:
	virtual void update(float frametime, Terrain &terrain) = 0;

	virtual void draw(sdl::Window &target) = 0;

	virtual bool isDead() = 0;
};