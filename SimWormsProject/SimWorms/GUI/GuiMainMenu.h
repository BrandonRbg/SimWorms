#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"

class GuiMainMenu {
protected:
	sdl::Text TextNameGame;
	sdl::Text TextOptions;
	sdl::Sprite SpriteLogo;
	sdl::Sprite SpriteBG;
	sdl::Sprite SpriteRec;
public:
	GuiMainMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};

