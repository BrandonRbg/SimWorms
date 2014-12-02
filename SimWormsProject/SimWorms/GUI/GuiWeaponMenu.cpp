#include "GuiWeaponMenu.h"

GuiWeaponMenu::GuiWeaponMenu(sdl::Window &target){
	ArrowU.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowU.png"));

	ArrowD.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowD.png"));
}