#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Transformable.h"
#include "Drawable.h"
#include "Color.h"
namespace sdl{
	class Text : public Drawable, public Transformable
	{
	public:
		enum Style{
			Normal = 0,
			Bold = 1 << 0,
			Italic = 1 << 1,
			Underlined = 1 << 2,
			Strikethrough = 2 << 2
		};
		Text(const std::string &text, const std::string &fontPath, int characterSize = 25);
		Text() : Text("", ""){}
		~Text();
		void setString(const std::string &text);
		void setFont(const std::string &fontPath);
		void setCharacterSize(int size);
		void setStyle(Uint32 style);
		void setColor(sdl::Color &color);

		std::string& getString();
		int getCharacterSize();
		Uint32 getStyle();
		sdl::Color& getColor();

		sdl::RectFloat getBounds();

		void draw(SDL_Renderer* renderer, sdl::View &view);

		static int instances;
	private:
		sdl::RectFloat getRenderDestination(sdl::View& view);
		void update();

		std::string text;
		std::string fontPath;

		Uint32 style;

		int characterSize;

		sdl::Color color;

		SDL_Surface* textSurface;
		TTF_Font* font;

	};
}

