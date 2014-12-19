#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"
#include "GuiTextBox.h"
#include <tuple>

class GuiGameMenu{
protected:
	sdl::Text TextMapName, TextGravity, TextWind, TextMine, TextStartButton, TextMapInfo,SampleText;
	sdl::Text*  TextTeamOne;
	sdl::Text* TextTeamTwo;
	sdl::Sprite ArrowR, ArrowL, MapBox, TeamBox, MapBigBox, Plus, Minus,thumbnail;
	GuiTextBox* TeamOne;
	GuiTextBox* TeamTwo;
	std::list<std::tuple<sdl::Text*, GuiTextBox*>> TeamList;
	bool PlusClick, First,Clicked; 
	void LoadMaps(std::string Map, std::string MapBg);
	int i;
	sdl::Clock ArrowCoolDown;
public:
	GuiGameMenu(sdl::Window &target);
	~GuiGameMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};