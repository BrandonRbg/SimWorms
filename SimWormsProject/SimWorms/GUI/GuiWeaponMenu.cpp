#include "GuiWeaponMenu.h"

GuiWeaponMenu::GuiWeaponMenu(sdl::Window &target){
	Clicked = false;
	ReverseClick = false;
	First = true;

	ArrowU.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowU.png"));
	ArrowU.setScale(0.7, 0.7);
	ArrowU.setPosition(sdl::Vector2Float(0.95 * target.getView().getSize().x, 0.94 * target.getView().getSize().y));

	ArrowD.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowD.png"));
	ArrowD.setScale(0.7, 0.7);
	ArrowD.setPosition(sdl::Vector2Float(0,0/*0.95 * target.getView().getSize().x, 0.94 * target.getView().getSize().y)*/));

	WeaponBack.setTexture(&AssetsManager::getInstance().getTexture("data/textures/WeaponBack.png"));
	WeaponBack.setPosition(sdl::Vector2Float(0.68 * target.getView().getSize().x, 1 * target.getView().getSize().y));
}

void GuiWeaponMenu::draw(sdl::Window &target){
	if (!Clicked)
		target.draw(&ArrowU);
	if ((Clicked) || (ReverseClick))
		target.draw(&WeaponBack);
	if (Clicked)
		target.draw(&ArrowD);
}

void GuiWeaponMenu::update(sdl::Window &target){
	if ((WeaponBack.getPosition().y != (target.getView().getSize().y - 280)) && (Clicked)){
		if ((Clock.getElapsedTime().asMilliseconds() >= 0.01) || (First)){
			First = false;
			Clock.restart();
			WeaponBack.setPosition(sdl::Vector2Float(WeaponBack.getPosition().x, WeaponBack.getPosition().y - 10));
			ArrowD.setPosition(sdl::Vector2Float(ArrowD.getPosition().x, ArrowD.getPosition().y - 10));
			ArrowU.setPosition(sdl::Vector2Float(0, 0));
		}
	}
	if ((WeaponBack.getPosition().y == (target.getView().getSize().y - 280)) && (ReverseClick)){
		if ((Clock.getElapsedTime().asMilliseconds() >= 0.01) || (First)){
			First = false;
			Clock.restart();
			WeaponBack.setPosition(sdl::Vector2Float(WeaponBack.getPosition().x, WeaponBack.getPosition().y + 10));
			ArrowU.setPosition(sdl::Vector2Float(ArrowU.getPosition().x, ArrowU.getPosition().y + 10));
			ArrowD.setPosition(sdl::Vector2Float(0, 0));
		}
	}
	if (WeaponBack.getPosition().y == (target.getView().getSize().y - 280)){
		First = true;
	}
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (ArrowU.getBounds().contains(sdl::Mouse::getPosition())){
			if ((ClickClock.getElapsedTime().asSeconds() > 0.25) || (First)){
				if (!ReverseClick){
					ArrowD.setPosition(sdl::Vector2Float(ArrowU.getPosition().x, ArrowU.getPosition().y));
					ClickClock.restart();
					ReverseClick = false;
					Clicked = true;
				}
			}
		}
		if (ArrowD.getBounds().contains(sdl::Mouse::getPosition())){
			if (ClickClock.getElapsedTime().asSeconds() > 0.25){
				ArrowU.setPosition(sdl::Vector2Float(ArrowD.getPosition().x, ArrowD.getPosition().y));
				ClickClock.restart();
				Clicked = false;
				ReverseClick = true;
			}
		}
	}
}