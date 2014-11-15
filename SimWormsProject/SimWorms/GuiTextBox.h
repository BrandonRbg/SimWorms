#pragma once
#include "OOSDL/OOSDL.h"
#include "AssetsManager.h"

class GuiTextBox{
protected:
	sdl::Text Text;
	sdl::Sprite TextBox;
	sdl::Vector2Float Pos;
public:
	GuiTextBox(const std::string& string, int Size, sdl::Color Color,int PosX,int PosY);
	void setString(const std::string& string);
	const std::string getString();
	void setPos(sdl::Vector2Float &Position);
	void setSize(sdl::Vector2Float &Scale);
	sdl::Vector2Float getPos();
	sdl::Vector2Float getSize();
	bool isClicked();
	bool isOver();
	void draw(sdl::Window &target);
};