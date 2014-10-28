#pragma once

#include <SDL2/SDL_rect.h>

#include "Texture.h"
#include "Clock.h"
#include "Sprite.h"

namespace sdl {
	class AnimatedSprite : public sdl::Sprite
	{
	public:
		AnimatedSprite(sdl::Texture* texture, int numberOfFrames, int delay);

		void reset();

		void draw(SDL_Renderer* renderer, sdl::View &view);

		bool looping;
		int delay;
	private:
		sdl::RectFloat getRenderDestination(sdl::View& view);

		void nextFrame();
		void updateFrame();

		sdl::Clock clock;

		unsigned int currentFrame;
		unsigned int numberOfFrames;

		bool active;
	};
}