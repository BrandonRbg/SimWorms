#pragma once
#include "Drawable.h"
#include "Transformable.h"
#include "Texture.h"
#include "Window.h"
#include "Rect.h"

namespace sdl{
	class Sprite : public Drawable, public Transformable
	{
	public:
		Sprite();
		~Sprite();
		
		void setTexture(sdl::Texture *texture);
		void setTexture(sdl::Texture *texture, sdl::RectFloat& textureRect);
		void setTextureRect(sdl::RectFloat& rect);
		
		sdl::Texture* getTexture();
		sdl::RectFloat& getTextureRect();

		void draw(SDL_Renderer* renderer, sdl::View &view);
	protected:
		sdl::RectFloat getRenderDestination(sdl::View& view);

		sdl::Texture* texture;
		sdl::RectFloat textureRect;
	};
}
