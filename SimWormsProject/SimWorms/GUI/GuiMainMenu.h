#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"

class GuiMainMenu {
protected:
	sdl::Text TextSinglePlayer;
	sdl::Text TextMultiPlayer;
	sdl::Text TextOptions;
	sdl::Text TextQuit;
	sdl::Sprite SpriteLogo;
	sdl::Sprite SpriteBG;
	sdl::Sprite SpriteRec;
public:
	GuiMainMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};