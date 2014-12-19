#include "GuiMainMenu.h"
#include "GuiCheckBox.h"
#include "../ScreenStateManager.h"
#include "../GameMenuState.h"

GuiMainMenu::GuiMainMenu(){
	TextSinglePlayer.setFont("data/fonts/BMSpace.ttf");
	TextSinglePlayer.setString("Singleplayer");
	TextSinglePlayer.setCharacterSize(35);
	TextSinglePlayer.setColor(sdl::Color::White);

	TextMultiPlayer.setFont("data/fonts/BMSpace.ttf");
	TextMultiPlayer.setString("Multiplayer");
	TextMultiPlayer.setCharacterSize(35);
	TextMultiPlayer.setColor(sdl::Color::White);

	TextOptions.setFont("data/fonts/BMSpace.ttf");
	TextOptions.setString("Options");
	TextOptions.setCharacterSize(35);
	TextOptions.setColor(sdl::Color::White);

	TextQuit.setFont("data/fonts/BMSpace.ttf");
	TextQuit.setString("Quit");
	TextQuit.setCharacterSize(35);
	TextQuit.setColor(sdl::Color::White);

	SpriteLogo.setTexture(&AssetsManager::getInstance().getTexture("data/textures/logo.png"));
	SpriteBG.setTexture(&AssetsManager::getInstance().getTexture("data/textures/BGtemp.jpg"));
	SpriteRec.setTexture(&AssetsManager::getInstance().getTexture("data/textures/MenuRec.png"));

	TextSinglePlayer.setPosition(725, 496);
	TextMultiPlayer.setPosition(725, 576);
	TextOptions.setPosition(725, 656);
	TextQuit.setPosition(725, 736);

	SpriteLogo.setPosition(575, 250);
	SpriteRec.setPosition(700, 450);
}

void GuiMainMenu::draw(sdl::Window &target){
	target.draw(&SpriteBG);
	target.draw(&SpriteRec);
	target.draw(&SpriteLogo);
	target.draw(&TextOptions);
	target.draw(&TextSinglePlayer);
	target.draw(&TextMultiPlayer);
	target.draw(&TextQuit);
}

void GuiMainMenu::update(sdl::Window &target){
	target.setView(target.getDefaultView());
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (TextSinglePlayer.getBounds().contains(sdl::Mouse::getPosition())){
			ScreenStateManager::getInstance().popScreenState();
			ScreenStateManager::getInstance().pushScreenState(new GameMenuState());
			return;
		}
		if (TextMultiPlayer.getBounds().contains(sdl::Mouse::getPosition())){
			//Lawl
		}
		if (TextQuit.getBounds().contains(sdl::Mouse::getPosition())){
			target.close();
		}
		if (TextOptions.getBounds().contains(sdl::Mouse::getPosition())){
			//Code for clic on Options...
		}
	}
	if (TextSinglePlayer.getBounds().contains(sdl::Mouse::getPosition())){
		TextSinglePlayer.setColor(sdl::Color::Blue);
	}
	else
		TextSinglePlayer.setColor(sdl::Color::White);
	if (TextMultiPlayer.getBounds().contains(sdl::Mouse::getPosition())){
		TextMultiPlayer.setColor(sdl::Color::Blue);
	}
	else
		TextMultiPlayer.setColor(sdl::Color::White);
	if (TextQuit.getBounds().contains(sdl::Mouse::getPosition())){
		TextQuit.setColor(sdl::Color::Blue);
	}
	else
		TextQuit.setColor(sdl::Color::White);
	if (TextOptions.getBounds().contains(sdl::Mouse::getPosition())){
		TextOptions.setColor(sdl::Color::Blue);
	}
	else
		TextOptions.setColor(sdl::Color::White);
}