#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"

class GuiGameMenu{
protected:
	sdl::Text TextMapName, TextGravity, TextWind, TextMine, TextTeamOne, TextTeamTwo, TextStartButton;
	sdl::Sprite ArrowR, ArrowL, MapBox, TeamBox, MapBigBox;
	//Add textboxes
public:
	GuiGameMenu();
	void draw(sdl::Window &target);
	void update();
};