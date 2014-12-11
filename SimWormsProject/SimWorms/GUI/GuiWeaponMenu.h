#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"
#include <tuple>

class GuiWeaponMenu{
protected:
	sdl::Sprite ArrowU,ArrowD,WeaponBack;
	sdl::Sprite* WeaponBox;
	sdl::Sprite*  WeaponSprite;
	sdl::Text* TextWeapon;
	std::list<std::tuple<sdl::Text*, sdl::Sprite*, sdl::Sprite*>> WeaponList; // Text en over et affiche après une seconde de over.
	sdl::Clock Clock,ClickClock;
	bool Clicked,First,ReverseClick,DrawClick,DrawReverse,DrawBack;

public:
	GuiWeaponMenu(sdl::Window &target);
	~GuiWeaponMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};