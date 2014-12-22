#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"
#include "../GameManager.h"
#include <tuple>

class GuiWeaponMenu{
protected:
	sdl::StaticSprite ArrowU,ArrowD,WeaponBack;
	sdl::StaticSprite* WeaponBox;
	sdl::StaticSprite*  WeaponSprite;
	sdl::StaticText* TextWeapon;
	sdl::StaticText* Description;
	bool* Over;
	std::list<std::tuple<sdl::Text*, sdl::Sprite*, sdl::Sprite*, sdl::Text*,bool*>> WeaponList; // Text en over et affiche après une seconde de over.
	sdl::Clock Clock,ClickClock,TextClock;
	bool Clicked,First,ReverseClick,DrawClick,DrawReverse,DrawBack,FirstStart;
	void PlaceItem(sdl::Window &target, std::string WeaponName, std::string Description, std::string TexturePath);
	int WeaponSelect;

public:
	GuiWeaponMenu();
	~GuiWeaponMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
	int WeaponSelected();
};