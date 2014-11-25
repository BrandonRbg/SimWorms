#pragma once
#include "ScreenState.h"
#include "GUI/GuiMainMenu.h"

class MainMenuState : public ScreenState
{
public:
	MainMenuState();
	void update(float frametime);
	void draw(sdl::Window &target);
private:
	GuiMainMenu menu;
};

