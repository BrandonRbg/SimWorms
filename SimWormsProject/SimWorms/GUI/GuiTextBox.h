#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"
#include "../EventManager.h"

class GuiTextBox{
protected:
	sdl::Text Text;
	sdl::Sprite TextBox;
	sdl::Vector2Float Pos;
	bool Clicked;
	std::string ActualText;
	sdl::Clock Time;

	sdl::Text cursorText;
	sdl::Clock cursorClock;
	bool cursorActivated;
public:
	GuiTextBox(/*int Size, sdl::Color Color*/);
	void setString(const std::string& string);
	const std::string getString();
	void setPos(sdl::Vector2Float &Position);
	void setSize(sdl::Vector2Float &Scale);
	sdl::Vector2Float getPos();
	sdl::Vector2Float getSize();
	bool isClicked();
	bool isOver();
	void onTextEntered(SDL_Event Event);
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};