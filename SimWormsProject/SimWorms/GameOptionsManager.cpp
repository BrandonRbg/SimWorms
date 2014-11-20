#include "GameOptionsManager.h"

GameOptionsManager::GameOptionsManager(){
	setVideoMode();
	setFullScreen(false);

	// To do later : Serialize controls data.

	// Keyboard controls setup.

	controls["jump"].push_back(SDLK_w);
	controls["left"].push_back(SDLK_LEFT);
	controls["right"].push_back(SDLK_RIGHT);

	controls["toolMenu"].push_back(SDLK_e);

	controls["jetpackThrottle"].push_back(SDLK_SPACE);
	
	controls["weaponAimDown"].push_back(SDLK_DOWN);
	controls["weaponAimUp"].push_back(SDLK_UP);
	controls["weaponLaunch"].push_back(SDLK_RETURN);

	//// Mouse controls setup. 

	controls["jump"].push_back(0);
	controls["left"].push_back(0);
	controls["right"].push_back(0);

	controls["toolMenu"].push_back(0);

	controls["jetpackThrottle"].push_back(0);

	controls["weaponAimDown"].push_back(0);
	controls["weaponAimUp"].push_back(0);
	controls["weaponLaunch"].push_back(0);
}

void GameOptionsManager::setVideoMode(sdl::VideoMode& vm){
	this->videoMode = vm;
}

sdl::VideoMode& GameOptionsManager::getVideoMode(){
	return this->videoMode;
}

void GameOptionsManager::setFullScreen(bool fs){
	this->fullScreen = fs;
}
bool GameOptionsManager::isFullScreen(){
	return fullScreen;
}

void GameOptionsManager::update(sdl::Window& window){
	window.setFullScreen(fullScreen);
	window.setVideoMode(videoMode);
}

void GameOptionsManager::setKeyControl(const std::string& control, Uint32 key){
	controls[control][0] = key;
}

void GameOptionsManager::setMouseControl(const std::string& control, Uint32 button){
	controls[control][1] = button;
}

Uint32 GameOptionsManager::getKeyControl(const std::string& control){
	return controls[control][0];
}

Uint32 GameOptionsManager::getMouseControl(const std::string& control){
	return controls[control][1];
}