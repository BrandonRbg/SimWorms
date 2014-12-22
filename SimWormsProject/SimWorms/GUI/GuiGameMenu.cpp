#include "GuiGameMenu.h"
#include <list>
#include "../MapManager.h"
#include "../ScreenStateManager.h"
#include "../MainMenuState.h"
#include "../GameState.h"

GuiGameMenu::GuiGameMenu(){
	ArrowCoolDown.restart();
	First = true;
	ArrowR.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowR.png"));
	ArrowL.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ArrowL.png"));
	ArrowR.setScale(sdl::Vector2Float(0.7, 1));
	ArrowL.setScale(sdl::Vector2Float(0.7, 1));
	ArrowR.setTextureRect(sdl::RectFloat(0, 0, 48, 75));
	ArrowL.setTextureRect(sdl::RectFloat(0, 0, 48, 75));

	MapBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/MapBox.png"));
	MapBigBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/BigBox.png"));

	Minus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Minus.png"));
	Plus.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Plus.png"));

	BG.setTexture(&AssetsManager::getInstance().getTexture("data/textures/BGtemp.jpg"));

	TextMapName.setFont("data/fonts/BMSpace.ttf");
	TextMapName.setCharacterSize(25);
	TextMapName.setColor(sdl::Color::White);

	MapBigBox.setScale(1.09,1.09);

	TextGravity.setFont("data/fonts/BMSpace.ttf");
	TextGravity.setCharacterSize(25);
	TextGravity.setColor(sdl::Color::White);

	TextWind.setFont("data/fonts/BMSpace.ttf");
	TextWind.setCharacterSize(25);
	TextWind.setColor(sdl::Color::White);

	Back.setFont("data/fonts/BMSpace.ttf");
	Back.setString("Back");
	Back.setCharacterSize(40);
	Back.setColor(sdl::Color::White);

	TextMine.setFont("data/fonts/BMSpace.ttf");
	TextMine.setCharacterSize(25);
	TextMine.setColor(sdl::Color::White);

	/*TextMapInfo.setFont("data/fonts/BMSpace.ttf");
	TextMapInfo.setCharacterSize(25);
	TextMapInfo.setColor(sdl::Color::White);*/

	TextStartButton.setFont("data/fonts/BMSpace.ttf");
	TextStartButton.setString("Start");
	TextStartButton.setCharacterSize(40);
	TextStartButton.setColor(sdl::Color::White);

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
	target.draw(&BG);
	if (First){
		TextTeamOne = new sdl::Text("Team 1", "data/fonts/BMSpace.ttf");
		TextTeamOne->setPosition(0.524 *target.getView().getSize().x, 0.093 * target.getView().getSize().y);
		TextTeamOne->setColor(sdl::Color::White);
		TextTeamTwo = new sdl::Text("Team 2", "data/fonts/BMSpace.ttf");
		TextTeamTwo->setPosition(0.524 *target.getView().getSize().x, (0.093 + 0.0675) * target.getView().getSize().y);
		TextTeamTwo->setColor(sdl::Color::White);
		TeamOne = new GuiTextBox();
		TeamTwo = new GuiTextBox();
		TeamOne->setPos(sdl::Vector2Float(0.624 * target.getView().getSize().x, 0.093 * target.getView().getSize().y));
		TeamTwo->setPos(sdl::Vector2Float(0.624 * target.getView().getSize().x, (0.093 + 0.0675) * target.getView().getSize().y));
		TeamList.push_back(std::make_tuple(TextTeamOne, TeamOne));
		TeamList.push_back(std::make_tuple(TextTeamTwo, TeamTwo));
		First = false;
	}
	TextMapName.setString(MapManager::getInstance().getMap(i)->name);
	char Table[30];
	std::string Text = SDL_itoa(MapManager::getInstance().getMap(i)->gravityForce, Table, 10);
	TextGravity.setString("Max gravity : " + Text);
	std::string Text2 = SDL_itoa(MapManager::getInstance().getMap(i)->maxWindForce, Table, 10);
	TextWind.setString("Max wind : " + Text2);
	std::string Text3 = SDL_itoa(MapManager::getInstance().getMap(i)->landMinesCount, Table, 10);
	TextMine.setString("Max nbr mines : " + Text3);
	//TextMapInfo.setString("Map infos : " + MapManager::getInstance().getMap(i).description);
	TeamOne->draw(target);
	TeamTwo->draw(target);
	target.draw(&Back);
	target.draw(&MapBigBox);
	target.draw(&ArrowR);
	target.draw(&ArrowL);
	target.draw(&MapBox);
	target.draw(&TextMapName);
	target.draw(&TextGravity);
	target.draw(&TextWind);
	target.draw(&TextMine);
	//target.draw(&TextMapInfo);
	target.draw(&TextStartButton);
	thumbnail = MapManager::getInstance().getMap(i)->thumbnail;
	thumbnail.setPosition(sdl::Vector2Float(MapBox.getBounds().x, MapBox.getBounds().y));
	target.draw(&thumbnail);
	if (TeamList.size() > 2)
		target.draw(&Minus);
	if (TeamList.size() < 4){
		target.draw(&Plus);
	}
	for (auto& it : TeamList){
		target.draw(std::get<0>(it));
		std::get<1>(it)->draw(target);
	}
} 

void GuiGameMenu::update(sdl::Window &target){
	Back.setPosition(0.01 * target.getView().getSize().x, 0.05 * target.getView().getSize().y);
	MapBigBox.setPosition(0.174 * target.getView().getSize().x, 0.058 * target.getView().getSize().y);
	TextMapName.setPosition(0.215 * target.getView().getSize().x, 0.076 * target.getView().getSize().y);
	MapBox.setPosition(0.181 * target.getView().getSize().x, 0.106 * target.getView().getSize().y);
	//TextMapInfo.setPosition(0.198 * target.getView().getSize().x, 0.470 * target.getView().getSize().y);
	TextGravity.setPosition(0.198 * target.getView().getSize().x, 0.629 * target.getView().getSize().y);
	TextWind.setPosition(0.198 * target.getView().getSize().x, 0.662 * target.getView().getSize().y);
	TextMine.setPosition(0.198 * target.getView().getSize().x, 0.694 * target.getView().getSize().y);
	TextStartButton.setPosition(0.9 * target.getView().getSize().x, 0.883 * target.getView().getSize().y);

	ArrowL.setPosition(0.185 * target.getView().getSize().x, 0.853 * target.getView().getSize().y);
	ArrowR.setPosition(0.44 * target.getView().getSize().x, 0.853 * target.getView().getSize().y);

	Plus.setPosition(0.6 * target.getView().getSize().x, (0.22 + (0.0675 * (TeamList.size() - 2))) * target.getView().getSize().y);
	if (!First){
		TeamOne->update(target);
		TeamTwo->update(target);
	}
	for (auto& it : TeamList){
		std::get<1>(it)->update(target);
	}
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
				if (TeamList.size() < 4){
					PlusClick = true;
					char buffer[30];
					sdl::Text* TempText = new sdl::Text("Team ", "data/fonts/BMSpace.ttf");
					TempText->setColor(sdl::Color::White);
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
			MapManager::getInstance().setActualMap(i);
			std::vector<Team> teams;
			for (auto& team : TeamList){
				Team tmp(std::get<1>(team)->getString(), sdl::Color::Black);
				teams.push_back(tmp);
			}
			ScreenStateManager::getInstance().popScreenState();
			ScreenStateManager::getInstance().pushScreenState(new GameState(target, teams));
		}

		if (Back.getBounds().contains(sdl::Mouse::getPosition())){
			ScreenStateManager::getInstance().popScreenState();
			ScreenStateManager::getInstance().pushScreenState(new MainMenuState());
			return;
		}
	}

	if (TextStartButton.getBounds().contains(sdl::Mouse::getPosition())){
		TextStartButton.setColor(sdl::Color::Red);
	}
	else
		TextStartButton.setColor(sdl::Color::White);

	if (Back.getBounds().contains(sdl::Mouse::getPosition())){
		Back.setColor(sdl::Color::Red);
	}
	else
		Back.setColor(sdl::Color::White);

	if (sdl::Mouse::isButtonReleased(SDL_BUTTON_LEFT)){
		PlusClick = false;
	}

	if (ArrowL.getBounds().contains(sdl::Mouse::getPosition()))
		ArrowL.setTextureRect(sdl::RectFloat(48, 0, 48, 75));
	else
		ArrowL.setTextureRect(sdl::RectFloat(0, 0, 48, 75));

	if (ArrowR.getBounds().contains(sdl::Mouse::getPosition()))
		ArrowR.setTextureRect(sdl::RectFloat(48, 0, 48, 75));
	else
		ArrowR.setTextureRect(sdl::RectFloat(0, 0, 48, 75));

}