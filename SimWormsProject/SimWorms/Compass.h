#pragma once
#include "OOSDL/OOSDL.h"
#include "RadToDeg.h"

class Compass
{
public:
	Compass();
	void setWind(sdl::Vector2Float& wind);
	void update(float frametime);
	void draw(sdl::Window &target);
private:
	sdl::Vector2Float actualWind;
	float windModule;
	sdl::StaticSprite ring1;
	sdl::StaticSprite ring2;
	sdl::StaticSprite arrow;
	sdl::StaticSprite blur;

	sdl::StaticText windSpeed;

	sdl::Clock rotateClock;
};

