#pragma once
#include "OOSDL/AnimatedSprite.h"
#include "AssetsManager.h"
class Explosion
{
public:
	Explosion(sdl::Vector2Float &position, float radius);
	~Explosion();
	void draw(sdl::Window& target);
	bool isEnded();
private:
	int numberOfFrames;
	int delay;
	float radius;
	sdl::Clock explosionClock;
	sdl::AnimatedSprite* explosionSprite;

};

