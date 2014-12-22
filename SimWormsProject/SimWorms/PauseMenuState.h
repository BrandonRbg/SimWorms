#pragma once
#include "ScreenState.h"
#include "GUI\GuiPauseMenu.h"

class PauseMenuState  : public ScreenState
{
public:
	PauseMenuState();
	void update(sdl::Window &target, float frametime);
	void draw(sdl::Window &target);
private:
	GuiPauseMenu pause;
};

