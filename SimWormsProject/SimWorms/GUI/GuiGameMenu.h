#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"
#include "GuiTextBox.h"

class GuiGameMenu{
protected:
	sdl::Text TextMapName, TextGravity, TextWind, TextMine, TextTeamOne, TextTeamTwo, TextStartButton, TextMapInfo;
	sdl::Sprite ArrowR, ArrowL, MapBox, TeamBox, MapBigBox, Minus, Plus;
	GuiTextBox TeamOne, TeamTwo;
public:
	GuiGameMenu();
	void draw(sdl::Window &target);
	void update();
};