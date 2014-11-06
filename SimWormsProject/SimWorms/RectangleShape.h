#pragma once
#include "Shape.h"
namespace sdl{
	class RectangleShape : public Shape
	{
	public:
		RectangleShape(sdl::RectFloat& rect = sdl::RectFloat());
		~RectangleShape();
		
		void setSize(sdl::Vector2Float &size);
		sdl::Vector2Float getSize();

		unsigned int getPointCount();
		sdl::RectFloat getBounds();

		void draw(SDL_Renderer* renderer, sdl::View& view);
	private:
		void update();
		sdl::RectFloat rect;
		SDL_Surface* surface;
	};
}