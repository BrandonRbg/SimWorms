#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"

class GuiPauseMenu{
protected:
	sdl::StaticSprite PauseBg;
	sdl::StaticText ResumeText, OptionsText, BackToMenuText;
public:
	GuiPauseMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};