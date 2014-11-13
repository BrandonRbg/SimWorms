#pragma once
#include "Vector2.h"
#include "Rect.h"
#include "View.h"
namespace sdl{
	class Transformable
	{
	public:
		Transformable();
		~Transformable();
		virtual void setPosition(float x, float y);
		virtual void setPosition(sdl::Vector2Float &position);

		virtual void setScale(float factorX, float factorY);
		virtual void setScale(sdl::Vector2Float &factors);

		virtual void setRotation(float angle);

		virtual void setOrigin(float x, float y);
		virtual void setOrigin(sdl::Vector2Float &origin);

		virtual sdl::Vector2Float& getPosition();

		virtual float getRotation();

		virtual sdl::Vector2Float& getScale();
		virtual sdl::Vector2Float& getOrigin();

		virtual void move(float x, float y);
		virtual void move(sdl::Vector2Float &vect);

		virtual void rotate(float angle);

		virtual void scale(float factorX, float factorY);
		virtual void scale(sdl::Vector2Float &factors);

		virtual void flip(SDL_RendererFlip flip);

		virtual sdl::RectFloat getBounds() = 0;
	protected:
		sdl::RectFloat getRenderDestination(sdl::View& view);

		sdl::RectFloat bounds;
		sdl::Vector2Float position;
		sdl::Vector2Float origin;
		sdl::Vector2Float scaleFactors;
		float orientation;
		SDL_RendererFlip flipSide;
	};
}

