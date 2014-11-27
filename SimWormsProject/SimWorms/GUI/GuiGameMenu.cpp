#include "GuiGameMenu.h"
#include <list>

GuiGameMenu::GuiGameMenu(){
	First = true;
	ArrowR.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowR.png"));
	ArrowL.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowL.png"));
	MapBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/MapBox.png"));
	MapBigBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/BigBox.png"));
	Minus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Minus.png"));
	Plus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Plus.png"));
	TeamOne.setPos(sdl::Vector2Float(1100,100));
	TeamTwo.setPos(sdl::Vector2Float(1100, 175));
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

GuiGameMenu::~GuiGameMenu(){
	for (auto& it : TextList)
		delete it;
	for (auto& it : TextBoxList)
		delete it;
}

void GuiGameMenu::draw(sdl::Window &target){
	TextTeamOne = new sdl::Text("Team 1", "data/fonts/Arial.ttf");
	TextTeamOne->setPosition(0.524 *target.getView().getSize().x, 100);
	TextTeamTwo = new sdl::Text("Team 2", "data/fonts/Arial.ttf");
	TextTeamTwo->setPosition(0.524 *target.getView().getSize().x, 175);
	if (First){
		TextList.push_back(TextTeamOne);
		TextList.push_back(TextTeamTwo);
		First = false;
	}
	TeamOne.draw(target);
	TeamTwo.draw(target);
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
	if (TextList.size() < 13){
		target.draw(&Plus);
	}
	target.draw(&Minus);
	for (auto& it : TextList){
		target.draw(it);
	}
	/*for (auto& it : TextBoxList){ //wat
		target.draw(it);
	}*/
}

void GuiGameMenu::update(sdl::Window &target){
	ArrowR.setPosition(0.37 * target.getView().getSize().x, 0.5 * target.getView().getSize().y);
	Plus.setPosition(0.7 * target.getView().getSize().x, 0.22 * target.getView().getSize().y);
	//Minus.setPosition(0.8 * target.getView().getSize().x, 0.17  * target.getView().getSize().y);
	TeamOne.update(target);
	TeamTwo.update(target);
	TextStartButton.setCharacterSize(40);
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (ArrowR.getBounds().contains(sdl::Mouse::getPosition())){

		}
		if (ArrowL.getBounds().contains(sdl::Mouse::getPosition())){

		}
		if (Plus.getBounds().contains(sdl::Mouse::getPosition())){ // Add teams
			if (!PlusClick){
				if (TextList.size() < 13){
					PlusClick = true;
					char buffer[30];
					sdl::Text* TempText = new sdl::Text("Team ", "data/fonts/Arial.ttf");
					TempText->setString(TempText->getString() + SDL_itoa(TextList.size() + 1, buffer, 10));
					TempText->setPosition(0.524 * target.getView().getSize().x, /*0.230*//*0.1625*/(0.093 + (0.0675 * TextList.size())) * target.getView().getSize().y);
					TextList.push_back(TempText);
					GuiTextBox* TempBox = new GuiTextBox();
					TempBox->setPos(sdl::Vector2Float(0.624 * target.getView().getSize().x, (0.093 + (0.0675 * TextList.size())) * target.getView().getSize().y));
					TextBoxList.push_back(TempBox);
				}
			}
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
	if (sdl::Mouse::isButtonReleased(SDL_BUTTON_LEFT)){
		PlusClick = false;
	}

}