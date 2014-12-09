#include "SplashScreenState.h"
#include "AssetsManager.h"
#include "ScreenStateManager.h"
#include "MainMenuState.h"

SplashScreenState::SplashScreenState(){
	splashScreenSprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/SplashScreen.png"));
}

void SplashScreenState::update(sdl::Window &target, float frametime){
	if (splashScreenClock.getElapsedTime().asSeconds() >= 3.0 || sdl::Keyboard::isKeyPressed(SDLK_RETURN)){
		ScreenStateManager::getInstance().clear();
		ScreenStateManager::getInstance().pushScreenState(new MainMenuState());
	}
}

void SplashScreenState::draw(sdl::Window& target){
	target.draw(&splashScreenSprite);
}