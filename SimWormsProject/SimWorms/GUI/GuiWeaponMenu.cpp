#include "GuiWeaponMenu.h"

GuiWeaponMenu::GuiWeaponMenu(){
	Clicked = false;
	ReverseClick = false;
	First = true;
	DrawClick = true;
	DrawReverse = false;
	DrawBack = false;
	FirstStart = true;

	ArrowU.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowU.png"));
	ArrowU.setScale(0.7, 0.7);

	ArrowD.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowD.png"));
	ArrowD.setScale(0.7, 0.7);

	WeaponBack.setTexture(&AssetsManager::getInstance().getTexture("data/textures/WeaponBack.png"));
}

void GuiWeaponMenu::PlaceItem(sdl::Window &target, std::string WeaponName, std::string Desc, std::string TexturePath){
	if (FirstStart){
		ArrowU.setPosition(sdl::Vector2Float(0.95 * target.getView().getSize().x, 0.94 * target.getView().getSize().y));

		ArrowD.setPosition(sdl::Vector2Float(0.95 * target.getView().getSize().x, 0.94 * target.getView().getSize().y - 280));

		WeaponBack.setPosition(sdl::Vector2Float(0.68 * target.getView().getSize().x, 1 * target.getView().getSize().y));
		FirstStart = false;
	}
	WeaponBox = new sdl::Sprite();
	WeaponBox->setTexture(&AssetsManager::getInstance().getTexture("data/textures/TinyBox.png"));
	WeaponSprite = new sdl::Sprite();
	WeaponSprite->setTexture(&AssetsManager::getInstance().getTexture(TexturePath));
	TextWeapon = new sdl::Text(WeaponName, "data/fonts/BMSpace.TTF");
	Description = new sdl::Text(Desc, "data/fonts/BMSpace.TTF");
	Over = new bool(false);
	if (WeaponList.size() < 5){
		WeaponBox->setPosition(sdl::Vector2Float(0.68 * target.getView().getSize().x + (70 * WeaponList.size()), 1 * target.getView().getSize().y + (70 * (WeaponList.size() / 5))));
	}
	if (WeaponList.size() > 5){
		WeaponBox->setPosition(sdl::Vector2Float(0.68 * target.getView().getSize().x + (70 * (((WeaponList.size() / (5 * (WeaponList.size() / 5))) - 1) + (WeaponList.size() - (5 * (WeaponList.size() / 5))))), 1 * target.getView().getSize().y + (70 * (WeaponList.size() / 5))));
	}
	TextWeapon->setPosition(sdl::Vector2Float(0.24 * target.getView().getSize().x, 0.70 * target.getView().getSize().y));
	Description->setPosition(sdl::Vector2Float(0.08 * target.getView().getSize().x, 0.75 * target.getView().getSize().y));
	WeaponList.push_back(std::make_tuple(TextWeapon, WeaponBox, WeaponSprite, Description, Over));
}

void GuiWeaponMenu::draw(sdl::Window &target){
	if (DrawClick)
		target.draw(&ArrowU);
	if (DrawBack){
		target.draw(&WeaponBack);
		for (auto& it : WeaponList){
			target.draw(std::get<2>(it));
			target.draw(std::get<1>(it));
			if (*(std::get<4>(it)) == true){
				target.draw(std::get<0>(it));
				target.draw(std::get<3>(it));
				*(std::get<4>(it)) = false;
			}
		}
	}
	if (DrawReverse)
		target.draw(&ArrowD);
}

GuiWeaponMenu::~GuiWeaponMenu(){
		for (auto& it : WeaponList){
			delete std::get<0>(it);
			delete std::get<1>(it);
			delete std::get<2>(it);
			delete std::get<3>(it);
			delete std::get<4>(it);
		}
}

int GuiWeaponMenu::WeaponSelected(){
	for (auto& it : WeaponList){
		if (std::get<1>(it)->getBounds().contains(sdl::Mouse::getPosition())){
			return WeaponSelect;
		}
		else
			WeaponSelect++;
	}
}

void GuiWeaponMenu::update(sdl::Window &target){
	WeaponSelect = 1;

	if (FirstStart){
		PlaceItem(target, "Rocket Launcher", "Explodes on contact and curves.", "data/textures/Rocket.png");
		PlaceItem(target, "Grenade", "Explodes after a certain time and bounces.", "data/textures/Grenade.png");
		PlaceItem(target, "Melee", "Weapon used for short distance combat.", "data/textures/Knife.png");
		PlaceItem(target, "JetPack", "Used to travel by flying.", "data/textures/JetPack.png");
	}

	if ((WeaponBack.getPosition().y != (target.getView().getSize().y - 280)) && (Clicked)){
		if ((Clock.getElapsedTime().asMilliseconds() >= 0.01)){
			First = false;
			Clock.restart();
			WeaponBack.setPosition(sdl::Vector2Float(WeaponBack.getPosition().x, WeaponBack.getPosition().y - 10));
			for (auto& it : WeaponList){
				std::get<1>(it)->setPosition(std::get<1>(it)->getPosition().x, std::get<1>(it)->getPosition().y - 10);
				std::get<2>(it)->setPosition(std::get<1>(it)->getPosition().x, std::get<1>(it)->getPosition().y - 10);
			}
		}
	}

	if ((WeaponBack.getPosition().y != (target.getView().getSize().y + 280)) && (ReverseClick)){
		if ((Clock.getElapsedTime().asMilliseconds() >= 0.01) || (First)){
			First = false;
			Clock.restart();
			WeaponBack.setPosition(sdl::Vector2Float(WeaponBack.getPosition().x, WeaponBack.getPosition().y + 10));
			for (auto& it : WeaponList){
				std::get<1>(it)->setPosition(std::get<1>(it)->getPosition().x, std::get<1>(it)->getPosition().y + 10);
				std::get<2>(it)->setPosition(std::get<1>(it)->getPosition().x, std::get<1>(it)->getPosition().y + 10);
			}
		}
	}

	for (auto& it : WeaponList){
		if (std::get<1>(it)->getBounds().contains(sdl::Mouse::getPosition())){
			*(std::get<4>(it)) = true;
		}
		else
			*(std::get<4>(it)) = false;
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