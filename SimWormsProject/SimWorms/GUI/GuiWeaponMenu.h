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
	sdl::Text* Description;
	bool* Over;
	std::list<std::tuple<sdl::Text*, sdl::Sprite*, sdl::Sprite*, sdl::Text*,bool*>> WeaponList; // Text en over et affiche après une seconde de over.
	sdl::Clock Clock,ClickClock,TextClock;
	bool Clicked,First,ReverseClick,DrawClick,DrawReverse,DrawBack;
	void PlaceItem(sdl::Window &target, std::string WeaponName, std::string Description, std::string TexturePath);

public:
	GuiWeaponMenu(sdl::Window &target);
	~GuiWeaponMenu();
	void draw(sdl::Window &target);
	void update(sdl::Window &target);
};