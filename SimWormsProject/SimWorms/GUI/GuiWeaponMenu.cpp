#include "GuiWeaponMenu.h"

GuiWeaponMenu::GuiWeaponMenu(sdl::Window &target){
	Clicked = false;
	ReverseClick = false;
	First = true;
	DrawClick = true;
	DrawReverse = false;
	DrawBack = false;

	ArrowU.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowU.png"));
	ArrowU.setScale(0.7, 0.7);
	ArrowU.setPosition(sdl::Vector2Float(0.95 * target.getView().getSize().x, 0.94 * target.getView().getSize().y));

	ArrowD.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowD.png"));
	ArrowD.setScale(0.7, 0.7);
	ArrowD.setPosition(sdl::Vector2Float(0.95 * target.getView().getSize().x, 0.94 * target.getView().getSize().y - 280));

	WeaponBack.setTexture(&AssetsManager::getInstance().getTexture("data/textures/WeaponBack.png"));
	WeaponBack.setPosition(sdl::Vector2Float(0.68 * target.getView().getSize().x, 1 * target.getView().getSize().y));
}

void GuiWeaponMenu::draw(sdl::Window &target){
	if (DrawClick)
		target.draw(&ArrowU);
	if (DrawBack)
		target.draw(&WeaponBack);
	if (DrawReverse)
		target.draw(&ArrowD);
}

void GuiWeaponMenu::update(sdl::Window &target){
	if ((WeaponBack.getPosition().y != (target.getView().getSize().y - 280)) && (Clicked)){
		if ((Clock.getElapsedTime().asMilliseconds() >= 0.01)){
			First = false;
			Clock.restart();
			WeaponBack.setPosition(sdl::Vector2Float(WeaponBack.getPosition().x, WeaponBack.getPosition().y - 10));
		}
	}
	if ((WeaponBack.getPosition().y != (target.getView().getSize().y + 280)) && (ReverseClick)){
		if ((Clock.getElapsedTime().asMilliseconds() >= 0.01) || (First)){
			First = false;
			Clock.restart();
			WeaponBack.setPosition(sdl::Vector2Float(WeaponBack.getPosition().x, WeaponBack.getPosition().y + 10));
		}
	}
	if (WeaponBack.getPosition().y == (target.getView().getSize().y - 280)){
		Clicked = false;
		DrawReverse = true;
	}
	if (WeaponBack.getPosition().y == (target.getView().getSize().y + 280)){
		ReverseClick = false;
		DrawBack = false;
		DrawClick = true;
	}
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (ArrowU.getBounds().contains(sdl::Mouse::getPosition())){
			if (((ClickClock.getElapsedTime().asSeconds() >= 0.1) && (ReverseClick == false)) || (First)){
				First = false;
				ClickClock.restart();
				Clicked = true;
				ReverseClick = false;
				DrawClick = false;
				DrawBack = true;
			}
		}
		if (ArrowD.getBounds().contains(sdl::Mouse::getPosition())){
			if ((ClickClock.getElapsedTime().asSeconds() >= 0.1) && (Clicked == false)){
				ClickClock.restart();
				ReverseClick = true;
				Clicked = false;
				DrawReverse = false;
				DrawBack = true;
			}
		}
	}
}