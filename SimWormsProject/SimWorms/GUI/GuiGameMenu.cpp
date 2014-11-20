#include "GuiGameMenu.h"

GuiGameMenu::GuiGameMenu(){
	ArrowR.setTexture(&AssetsManager::getInstance().getTexture("ArrowR.png"));
	ArrowL.setTexture(&AssetsManager::getInstance().getTexture("ArrowL.png"));
	MapBox.setTexture(&AssetsManager::getInstance().getTexture("MapBox.png"));
	TextMapName.setFont("Arial.ttf");
	TextMapName.setString("MapName");
	TextMapName.setCharacterSize(25);
	TextMapName.setColor(sdl::Color::White);
	ArrowL.setPosition(25, 175);
	ArrowR.setPosition(700, 175);
	MapBox.setPosition(125, 50);
	TextMapName.setPosition(300, 10);
	TextGravity.setFont("Arial.ttf");
	TextGravity.setString("GravityLevel ");
	TextGravity.setCharacterSize(25);
	TextGravity.setColor(sdl::Color::White);
	TextGravity.setPosition(150, 410);
	TextWind.setFont("Arial.ttf");
	TextWind.setString("MaxWind ");
	TextWind.setCharacterSize(25);
	TextWind.setColor(sdl::Color::White);
	TextWind.setPosition(150, 445);
	TextMine.setFont("Arial.ttf");
	TextMine.setString("NbrMines ");
	TextMine.setCharacterSize(25);
	TextMine.setColor(sdl::Color::White);
	TextMine.setPosition(150, 480);
	TextStartButton.setFont("Arial.ttf");
	TextStartButton.setString("Commencer La Partie");
	TextStartButton.setCharacterSize(40);
	TextStartButton.setColor(sdl::Color::White);
	TextStartButton.setPosition(400, 850);
}

void GuiGameMenu::draw(sdl::Window &target){
	target.draw(&ArrowR);
	target.draw(&ArrowL);
	target.draw(&MapBox);
	target.draw(&TextMapName);
	target.draw(&TextGravity);
	target.draw(&TextWind);
	target.draw(&TextMine);
	target.draw(&TextStartButton);
}

void GuiGameMenu::update(){
	TextStartButton.setCharacterSize(40);
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (ArrowR.getBounds().contains(sdl::Mouse::getPosition())){

		}
		if (ArrowL.getBounds().contains(sdl::Mouse::getPosition())){

		}
		if (TextStartButton.getBounds().contains(sdl::Mouse::getPosition())){
			TextStartButton.setCharacterSize(42);
		}
	}
	if (TextStartButton.getBounds().contains(sdl::Mouse::getPosition())){
		TextStartButton.setColor(sdl::Color::Red);
	}
	else
		TextStartButton.setColor(sdl::Color::White);
	/*if (ArrowR.getBounds().contains(sdl::Mouse::getPosition())){

	}
	else
	if (ArrowL.getBounds().contains(sdl::Mouse::getPosition())){

	}
	else*/

}