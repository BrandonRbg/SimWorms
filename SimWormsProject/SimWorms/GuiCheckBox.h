#pragma once
#include "OOSDL/OOSDL.h"
#include "AssetsManager.h"

class GuiCheckBox{
protected:
	sdl::Vector2Float Pos;
	sdl::Sprite BoxSprite;
	sdl::Sprite CheckSprite;
	bool Checked;
public:
	GuiCheckBox();
	void setPos(sdl::Vector2Float &Position);
	void setSize(sdl::Vector2Float &Scale);
	sdl::Vector2Float getPos();
	sdl::Vector2Float getSize();
	bool isClicked();
	bool isOver();
	void draw(sdl::Window &target);
	//void update();
};