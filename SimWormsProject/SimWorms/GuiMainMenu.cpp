#include "GuiMainMenu.h"
#include "GuiCheckBox.h"

GuiMainMenu Lawl;

GuiMainMenu::GuiMainMenu(){
	TextNameGame.setFont("Arial.ttf");
	TextNameGame.setString("Nouvelle Partie");
	TextNameGame.setCharacterSize(65);
	TextNameGame.setColor(sdl::Color::White);
	TextOptions.setFont("Arial.ttf"); 
	TextOptions.setString("Options");
	TextOptions.setCharacterSize(65);
	TextOptions.setColor(sdl::Color::White);
	SpriteLogo.setTexture(&AssetsManager::getInstance().getTexture("logotemp.png"));
	SpriteBG.setTexture(&AssetsManager::getInstance().getTexture("BGtemp.jpg"));
	SpriteRec.setTexture(&AssetsManager::getInstance().getTexture("MenuRec.png"));
	TextNameGame.setPosition(711, 496);
	TextOptions.setPosition(711, 696);
	SpriteLogo.setPosition(711,250);
	SpriteRec.setPosition(700,100);
}

void GuiMainMenu::draw(sdl::Window &target){
	target.draw(&SpriteBG);
	target.draw(&SpriteRec);
	target.draw(&SpriteLogo);
	target.draw(&TextOptions);
	target.draw(&TextNameGame);
}

void GuiMainMenu::update(sdl::Window &target){
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (TextNameGame.getBounds().contains(sdl::Mouse::getPosition())){
			Lawl.draw(target);
		}
		if (TextOptions.getBounds().contains(sdl::Mouse::getPosition())){
			//Code for clic on Options...
		}
	}
	if (TextNameGame.getBounds().contains(sdl::Mouse::getPosition())){
		TextNameGame.setColor(sdl::Color::Red);
	}
	else
		TextNameGame.setColor(sdl::Color::White);
	if (TextOptions.getBounds().contains(sdl::Mouse::getPosition())){
		TextOptions.setColor(sdl::Color::Red);
	}
	else
		TextOptions.setColor(sdl::Color::White);
}