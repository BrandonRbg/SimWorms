#include "SplashScreenState.h"
#include "AssetsManager.h"
#include "ScreenStateManager.h"
#include "MainMenuState.h"

SplashScreenState::SplashScreenState(){
	loadingSprite = new sdl::AnimatedSprite(&AssetsManager::getInstance().getTexture("date/textures/loadingCircleOld.png"), 8, 1);
	splashScreenSprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/SplashScreen.png"));
	loadingSprite->setPosition(640, 512);
	loadingSprite->setOrigin(0, 0);
}

void SplashScreenState::update(sdl::Window &target, float frametime){
	loadingSprite->updateFrame();
	if (splashScreenClock.getElapsedTime().asSeconds() >= 3.0 || sdl::Keyboard::isKeyPressed(SDLK_RETURN)){
		ScreenStateManager::getInstance().clear();
		ScreenStateManager::getInstance().pushScreenState(new MainMenuState());
	}
}

void SplashScreenState::draw(sdl::Window& target){
	target.draw(loadingSprite);
	target.draw(&splashScreenSprite);
}

SplashScreenState::~SplashScreenState() {
	delete loadingSprite;
}