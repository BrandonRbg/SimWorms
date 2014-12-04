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
	std::list<std::tuple<sdl::Text*, sdl::Sprite*, sdl::Sprite*>> WeaponList;
	sdl::Clock Clock,ClickClock;
	bool Clicked,First,ReverseClick;

public:
	GuiWeaponMenu(sdl::Window &target);
	//~GuiWeaponMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};