#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"
#include "GuiTextBox.h"

class GuiGameMenu{
protected:
	sdl::Text TextMapName, TextGravity, TextWind, TextMine, TextStartButton, TextMapInfo,SampleText;
	sdl::Text*  TextTeamOne;
	sdl::Text* TextTeamTwo;
	sdl::Sprite ArrowR, ArrowL, MapBox, TeamBox, MapBigBox, Minus, Plus;
	GuiTextBox TeamOne;
	GuiTextBox TeamTwo;
	std::list<sdl::Text*> TextList;
	std::list<GuiTextBox> TextBoxList;
	bool PlusClick, First;
public:
	GuiGameMenu();
	~GuiGameMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};