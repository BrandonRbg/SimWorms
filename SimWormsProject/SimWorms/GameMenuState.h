#pragma once
#include "ScreenState.h"
#include "GUI\GuiGameMenu.h"

class GameMenuState : public ScreenState
{
public:
	GameMenuState();
	void update(sdl::Window &target, float frametime);
	void draw(sdl::Window &target);
private:
	GuiGameMenu menu;
};

