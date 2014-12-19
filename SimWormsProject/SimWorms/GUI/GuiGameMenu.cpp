#include "GuiGameMenu.h"
#include <list>
#include "../MapManager.h"

GuiGameMenu::GuiGameMenu(sdl::Window &target){
	ArrowCoolDown.restart();
	First = true;
	ArrowR.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowR.png"));
	ArrowL.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowL.png"));
	MapBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/MapBox.png"));
	MapBigBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/BigBox.png"));
	Minus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Minus.png"));
	Plus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Plus.png"));

	TextMapName.setFont("data/fonts/Arial.ttf");
	TextMapName.setCharacterSize(25);
	TextMapName.setColor(sdl::Color::Black);
	TextMapName.setPosition(0.225 * target.getView().getSize().x, 0.009 * target.getView().getSize().y);

	MapBigBox.setPosition(0.054 * target.getView().getSize().x, 0.008 * target.getView().getSize().y);
	MapBigBox.setScale(1.09,1.09);

	ArrowL.setPosition(0.013 * target.getView().getSize().x, 0.5 * target.getView().getSize().y);
	ArrowL.setScale(0.7, 0.7);

	ArrowR.setPosition(0.52 * target.getView().getSize().x, 0.5 * target.getView().getSize().y);
	ArrowR.setScale(0.7, 0.7);

	MapBox.setPosition(0.065 * target.getView().getSize().x, 0.046 * target.getView().getSize().y);

	TextGravity.setFont("data/fonts/Arial.ttf");
	TextGravity.setCharacterSize(25);
	TextGravity.setColor(sdl::Color::Black);
	TextGravity.setPosition(0.078 * target.getView().getSize().x, 0.40 * target.getView().getSize().y);

	TextWind.setFont("data/fonts/Arial.ttf");
	TextWind.setCharacterSize(25);
	TextWind.setColor(sdl::Color::Black);
	TextWind.setPosition(0.078 * target.getView().getSize().x, 0.432 * target.getView().getSize().y);

	TextMine.setFont("data/fonts/Arial.ttf");
	TextMine.setCharacterSize(25);
	TextMine.setColor(sdl::Color::Black);
	TextMine.setPosition(0.078 * target.getView().getSize().x, 0.464 * target.getView().getSize().y);

	TextMapInfo.setFont("data/fonts/Arial.ttf");
	TextMapInfo.setCharacterSize(25);
	TextMapInfo.setColor(sdl::Color::Black);
	TextMapInfo.setPosition(0.078 * target.getView().getSize().x, 0.496 * target.getView().getSize().y);

	TextStartButton.setFont("data/fonts/Arial.ttf");
	TextStartButton.setString("Commencer La Partie");
	TextStartButton.setCharacterSize(40);
	TextStartButton.setColor(sdl::Color::Black);
	TextStartButton.setPosition(0.104 * target.getView().getSize().x, 0.833 * target.getView().getSize().y);

	MapManager::getInstance().loadMapsFromFolder("data/maps");
	i = 0;

}

GuiGameMenu::~GuiGameMenu(){
	for (auto& it : TeamList){
		delete std::get<0>(it);
		delete std::get<1>(it);
	}
}

void GuiGameMenu::draw(sdl::Window &target){
	TextTeamOne = new sdl::Text("Team 1", "data/fonts/Arial.ttf");
	TextTeamOne->setPosition(0.524 *target.getView().getSize().x, 0.093 * target.getView().getSize().y);
	TextTeamTwo = new sdl::Text("Team 2", "data/fonts/Arial.ttf");
	TextTeamTwo->setPosition(0.524 *target.getView().getSize().x, (0.093 + 0.0675) * target.getView().getSize().y);
	TeamOne = new GuiTextBox();
	TeamTwo = new GuiTextBox();
	TeamOne->setPos(sdl::Vector2Float(0.624 * target.getView().getSize().x, 0.093 * target.getView().getSize().y));
	TeamTwo->setPos(sdl::Vector2Float(0.624 * target.getView().getSize().x, (0.093 + 0.0675) * target.getView().getSize().y));
	if (First){
		TeamList.push_back(std::make_tuple(TextTeamOne, TeamOne));
		TeamList.push_back(std::make_tuple(TextTeamTwo, TeamTwo));
		First = false;
	}
	TextMapName.setString(MapManager::getInstance().getMap(i).name);
	char Table[30];
	std::string Text = SDL_itoa(MapManager::getInstance().getMap(i).gravityForce, Table, 10);
	TextGravity.setString("Max gravity : " + Text);
	std::string Text2 = SDL_itoa(MapManager::getInstance().getMap(i).maxWindForce, Table, 10);
	TextWind.setString("Max wind : " + Text2);
	std::string Text3 = SDL_itoa(MapManager::getInstance().getMap(i).landMinesCount, Table, 10);
	TextMine.setString("Max nbr mines : " + Text3);
	TextMapInfo.setString("Map infos : " + MapManager::getInstance().getMap(i).description);
	TeamOne->draw(target);
	TeamTwo->draw(target);
	target.draw(&ArrowR);
	target.draw(&ArrowL);
	target.draw(&TextMapName);
	target.draw(&TextGravity);
	target.draw(&TextWind);
	target.draw(&TextMine);
	target.draw(&MapBigBox);
	target.draw(&TextMapInfo);
	target.draw(&TextStartButton);
	thumbnail = MapManager::getInstance().getMap(i).thumbnail;
	thumbnail.setPosition(sdl::Vector2Float(MapBox.getBounds().x, MapBox.getBounds().y));
	target.draw(&thumbnail);
	target.draw(&MapBox);
	if (TeamList.size() > 2)
		target.draw(&Minus);
	if (TeamList.size() < 12){
		target.draw(&Plus);
	}
	for (auto& it : TeamList){ // Draws text
		target.draw(std::get<0>(it));
	}
	for (auto& it : TeamList){ // Draws sprites
		std::get<1>(it)->draw(target);
	}
}

void GuiGameMenu::update(sdl::Window &target){
	Plus.setPosition(0.7 * target.getView().getSize().x, (0.22 + (0.0675 * (TeamList.size() - 2))) * target.getView().getSize().y);
	if (!First){
		TeamOne->update(target);
		TeamTwo->update(target);
	}
	for (auto& it : TeamList){
		std::get<1>(it)->update(target);
	}
	TextStartButton.setCharacterSize(40);
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (ArrowCoolDown.getElapsedTime().asMilliseconds() >= 100)
			Clicked = false;
		else
			Clicked = true;
		if (ArrowR.getBounds().contains(sdl::Mouse::getPosition())){
			if (Clicked == false){
				ArrowCoolDown.restart();
				if (i == 3){
					i = 0;
				}
				else
					i++;
			}
		}
		if (ArrowL.getBounds().contains(sdl::Mouse::getPosition())){
			if (Clicked == false){
				ArrowCoolDown.restart();
				if (i == 0){
					i = 3;
				}
				else
					i--;
			}
		}
		if (Plus.getBounds().contains(sdl::Mouse::getPosition())){
			if (!PlusClick){
				if (TeamList.size() < 13){
					PlusClick = true;
					char buffer[30];
					sdl::Text* TempText = new sdl::Text("Team ", "data/fonts/Arial.ttf");
					TempText->setString(TempText->getString() + SDL_itoa(TeamList.size() + 1, buffer, 10));
					TempText->setPosition(0.524 * target.getView().getSize().x, (0.093 + (0.0675 * TeamList.size())) * target.getView().getSize().y);
					GuiTextBox* TempBox = new GuiTextBox();
					TempBox->setPos(sdl::Vector2Float(0.624 * target.getView().getSize().x, (0.093 + (0.0675 * (TeamList.size()))) * target.getView().getSize().y));
					sdl::Sprite* TempSprite = new sdl::Sprite();
					TeamList.push_back(std::make_tuple(TempText,TempBox));
					Minus.setPosition(0.9 * target.getView().getSize().x, (0.093 + (0.0675 * (TeamList.size() - 1))) * target.getView().getSize().y);
				}
			}
		}
		if (Minus.getBounds().contains(sdl::Mouse::getPosition())){
			if (!PlusClick){
				PlusClick = true;
				if (TeamList.size() == 2)
					return;
				delete std::get<0>(*(--TeamList.end()));
				delete std::get<1>(*(--TeamList.end()));
				TeamList.pop_back();
				Minus.setPosition(0.9 * target.getView().getSize().x, (0.093 + (0.0675 * (TeamList.size() - 1))) * target.getView().getSize().y);
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