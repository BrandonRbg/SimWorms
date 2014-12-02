#pragma once
#include "../OOSDL/OOSDL.h"
#include "../AssetsManager.h"
#include <tuple>

class GuiWeaponMenu{
protected:
	sdl::Sprite ArrowU,ArrowD;
	sdl::Sprite* WeaponBoxe;
	sdl::Sprite*  WeaponSprite;
	sdl::Text* TextWeapon;
	std::list<std::tuple<sdl::Text*, sdl::Sprite*, sdl::Sprite*>> WeaponList;

public:
	GuiWeaponMenu(sdl::Window &target);
	~GuiWeaponMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};