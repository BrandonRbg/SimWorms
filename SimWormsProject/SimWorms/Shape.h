#pragma once
#include <SDL2/SDL_gfxPrimitives.h>
#include "Transformable.h"
#include "Drawable.h"
#include "Color.h"
#include "Texture.h"
float degreeToRadian(float degree){
	return degree * (M_PI / 180);
}
namespace sdl{
	class Shape : public Transformable, public Drawable
	{
	public:
		void setFillColor(sdl::Color &color);

		void setOutlineColor(sdl::Color &color);
		void setOutlineThickness(float thickness);

		sdl::Color getFillColor();
		sdl::Color getOutlineColor();
		float getOutlineThickness();
		
		virtual unsigned int getPointCount() = 0;
		sdl::Vector2Float getPoint(int index);
	protected:
		sdl::Color fillColor;

		sdl::Color outlineColor;
		float outlineThickness;

		std::vector<sdl::Vector2Float> points;
	};
}
