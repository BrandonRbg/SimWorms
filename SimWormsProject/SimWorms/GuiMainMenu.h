#pragma once
#include "OOSDL/OOSDL.h"

class GuiMainMenu {
protected:
	sdl::Text TextNameGame;
	sdl::Text TextOptions;
	sdl::Sprite SpriteLogo;
	sdl::Sprite SpriteBG;
public:
	GuiMainMenu();
	void draw(sdl::Window &target);
	void update();
};

