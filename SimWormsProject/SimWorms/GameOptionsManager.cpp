#include "GameOptionsManager.h"

GameOptionsManager::GameOptionsManager(){
	setVideoMode();
	setFullScreen(false);

	// To do later : Serialize controls data.

	//// Keyboard controls setup.

	//controls["jump"][0] = SDLK_w;
	//controls["left"][0] = SDLK_a;
	//controls["right"][0] = SDLK_d;

	//controls["toolMenu"][0] = SDLK_e;

	//controls["jetpackThrottle"][0] = SDLK_SPACE;	
	//
	//controls["weaponAimDown"][1] = SDLK_DOWN;
	//controls["weaponAimUp"][1] = SDLK_UP;
	//controls["weaponLaunch"][1] = SDLK_RETURN;

	////// Mouse controls setup. 

	//controls["jump"][1] = 0;
	//controls["left"][1] = 0;
	//controls["right"][1] = 0;

	//controls["toolMenu"][1] = 0;

	//controls["jetpackThrottle"][1] = 0;

	//controls["weaponAimDown"][1] = 0;
	//controls["weaponAimUp"][1] = 0;
	//controls["weaponLaunch"][1] = 0;
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

void GameOptionsManager::setKeyControl(std::string& control, Uint32 key){
	controls[control][0] = key;
}

void GameOptionsManager::setMouseControl(std::string& control, Uint32 button){
	controls[control][1] = button;
}

Uint32 GameOptionsManager::getKeyControl(std::string& control){
	return controls[control][0];
}

Uint32 GameOptionsManager::getMouseControl(std::string& control){
	return controls[control][1];
}