#include "GuiWeaponMenu.h"

GuiWeaponMenu::GuiWeaponMenu(sdl::Window &target){
	ArrowU.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowU.png"));
	ArrowU.setScale(0.7, 0.7);
	ArrowU.setPosition(sdl::Vector2Float(1867, 1027));

	ArrowD.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowD.png"));
	ArrowD.setScale(0.7, 0.7);
}

void GuiWeaponMenu::draw(sdl::Window &target){
	target.draw(&ArrowU);
}