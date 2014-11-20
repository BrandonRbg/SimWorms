#pragma once
#include "PlayerPhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "AssetsManager.h"
class Player
{
private:
	sdl::Vector2Float position;
	sdl::Vector2Float velocity;
	sdl::Sprite playerSprite;
	PlayerInputComponent input;
	PlayerPhysicsComponent physics;
public:
	Player(sdl::Vector2Float &position);
	void moveLeft();
	void moveRight();
	void stop();
	void draw(sdl::Window &target);
	void update(float frametime, Terrain& terrain);
	sdl::Vector2Float& getPosition();
	sdl::Vector2Float& getVelocity();
	sdl::RectFloat& getBounds();
	void setPosition(sdl::Vector2Float& position);
	void setVelocity(sdl::Vector2Float& velocity);
	bool isPixelSolid(sdl::Vector2Float& position);
};

