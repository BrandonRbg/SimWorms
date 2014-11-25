#pragma once
#include "PhysicsComponent.h"
#include "OOSDL\AnimatedSprite.h"
#include "Terrain.h"
#include "AssetsManager.h"

class Projectile {
protected:
	PhysicsComponent physics;
	sdl::Sprite* sprite;
	sdl::Vector2Float velociy;
	bool orientation; // true = droite et false = gauche
public:
	Projectile(sdl::Vector2Float &position, sdl::Vector2Float &direction, float puissance, bool orientation);
	~Projectile();

	void draw(sdl::Window& window);

	bool isExplode(Terrain& terrain);

	void update(float FrameTime, Terrain& terrain);

	void setVelocity(sdl::Vector2Float velocity) { this->velociy = velocity; }

	sdl::Vector2Float getVelocity() { return velociy; }
};