#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"

class GuiPauseMenu{
protected:
	sdl::Sprite PauseBg;
	sdl::Text ResumeText, OptionsText, BackToMenuText;
public:
	GuiPauseMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};