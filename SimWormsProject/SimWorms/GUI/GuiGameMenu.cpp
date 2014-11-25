#include "GuiGameMenu.h"

GuiGameMenu::GuiGameMenu(){
	ArrowR.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowR.png"));
	ArrowL.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowL.png"));
	MapBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/MapBox.png"));
	MapBigBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/BigBox.png"));
	Minus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Minus.png"));
	Plus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Plus.png"));
	TeamOne.setPos();
	TextTeamOne.setFont("data/fonts/Arial.ttf");
	TextTeamTwo.setFont("data/fonts/Arial.ttf");
	TextTeamOne.setString("Team 1");
	TextTeamTwo.setString("Team 2");
	TextTeamOne.setCharacterSize(25);
	TextTeamTwo.setCharacterSize(25);
	TextTeamOne.setColor(sdl::Color::Black);
	TextTeamTwo.setColor(sdl::Color::Black);
	TextTeamOne.setPosition(1000, 100);
	TextTeamTwo.setPosition(1000, 175);
	TextMapInfo.setFont("data/fonts/Arial.ttf");
	TextMapInfo.setString("MapInfo :");
	TextMapInfo.setCharacterSize(25);
	TextMapInfo.setColor(sdl::Color::Black);
	TextMapInfo.setPosition(150,515);
	TextMapName.setFont("data/fonts/Arial.ttf");
	TextMapName.setString("MapName : ");
	TextMapName.setCharacterSize(25);
	TextMapName.setColor(sdl::Color::Black);
	MapBigBox.setPosition(105, 9);
	MapBigBox.setScale(1.1,1.1);
	ArrowL.setPosition(25, 450);
	ArrowR.setPosition(700, 450);
	MapBox.setPosition(125, 50);
	TextMapName.setPosition(300, 10);
	TextGravity.setFont("data/fonts/Arial.ttf");
	TextGravity.setString("GravityLevel :");
	TextGravity.setCharacterSize(25);
	TextGravity.setColor(sdl::Color::Black);
	TextGravity.setPosition(150, 410);
	TextWind.setFont("data/fonts/Arial.ttf");
	TextWind.setString("MaxWind :");
	TextWind.setCharacterSize(25);
	TextWind.setColor(sdl::Color::Black);
	TextWind.setPosition(150, 445);
	TextMine.setFont("data/fonts/Arial.ttf");
	TextMine.setString("NbrMines :");
	TextMine.setCharacterSize(25);
	TextMine.setColor(sdl::Color::Black);
	TextMine.setPosition(150, 480);
	TextStartButton.setFont("data/fonts/Arial.ttf");
	TextStartButton.setString("Commencer La Partie");
	TextStartButton.setCharacterSize(40);
	TextStartButton.setColor(sdl::Color::Black);
	TextStartButton.setPosition(200, 900);
}

void GuiGameMenu::draw(sdl::Window &target){
	target.draw(&ArrowR);
	target.draw(&ArrowL);
	target.draw(&MapBox);
	target.draw(&TextMapName);
	target.draw(&TextGravity);
	target.draw(&TextWind);
	target.draw(&TextMine);
	target.draw(&MapBigBox);
	target.draw(&TextMapInfo);
	target.draw(&TextStartButton);
	target.draw(&TextTeamOne);
	target.draw(&TextTeamTwo);
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
		TextStartButton.setColor(sdl::Color::Black);

}