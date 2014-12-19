#pragma once
#include "../OOSDL/OOSDL.h"

class GuiComponents {
protected:
	sdl::Vector2Float pos;
public:
	virtual void setPos(sdl::Vector2Float &Position) = 0;
	virtual void setSize(sdl::Vector2Float &Scale) = 0;
	virtual sdl::Vector2Float getPos() = 0;
	virtual sdl::Vector2Float getSize() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool isClicked() = 0;
	virtual bool isOver() = 0;
};