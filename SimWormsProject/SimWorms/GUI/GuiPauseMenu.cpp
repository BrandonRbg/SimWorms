#include "GuiPauseMenu.h"
#include "../MainMenuState.h"
#include "../ScreenStateManager.h"

GuiPauseMenu::GuiPauseMenu(){
	PauseBg.setTexture(&AssetsManager::getInstance().getTexture("data/textures/PauseBg.png"));

	ResumeText.setFont("data/fonts/BMSpace.ttf");
	ResumeText.setString("Resume");
	ResumeText.setCharacterSize(35);
	ResumeText.setColor(sdl::Color::White);
	

	OptionsText.setFont("data/fonts/BMSpace.ttf");
	OptionsText.setString("Options");
	OptionsText.setCharacterSize(35);
	OptionsText.setColor(sdl::Color::White);
	

	BackToMenuText.setFont("data/fonts/BMSpace.ttf");
	BackToMenuText.setString("Back To Main Menu");
	BackToMenuText.setCharacterSize(35);
	BackToMenuText.setColor(sdl::Color::White);
	
}

void GuiPauseMenu::draw(sdl::Window &target){
	BackToMenuText.setPosition(sdl::Vector2Float(0.35 * target.getView().getSize().x, 0.55 * target.getView().getSize().y));

	OptionsText.setPosition(sdl::Vector2Float(0.42 * target.getView().getSize().x, 0.50 * target.getView().getSize().y));

	ResumeText.setPosition(sdl::Vector2Float(0.42 * target.getView().getSize().x, 0.45 * target.getView().getSize().y));

	target.draw(&PauseBg);
	target.draw(&ResumeText);
	target.draw(&OptionsText);
	target.draw(&BackToMenuText);
}

void GuiPauseMenu::update(sdl::Window &target){
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (ResumeText.getBounds().contains(sdl::Mouse::getPosition())){
			ScreenStateManager::getInstance().getFirstScreenState()->pause(false);
			ScreenStateManager::getInstance().popScreenState();
			return;
		}
		if (OptionsText.getBounds().contains(sdl::Mouse::getPosition())){

		}
		if (BackToMenuText.getBounds().contains(sdl::Mouse::getPosition())){
			ScreenStateManager::getInstance().popScreenState();
			ScreenStateManager::getInstance().pushScreenState(new MainMenuState());
			return;
		}
	}
}