#include "ScreenStateManager.h"


ScreenStateManager::ScreenStateManager(){
}
ScreenStateManager::~ScreenStateManager(){
	for (auto& it : screenStates)
		delete it;
}

void ScreenStateManager::addScreenState(ScreenState* screenState){
	screenStates.push_back(screenState);
}

void ScreenStateManager::clear(){
	screenStates.clear();
}

void ScreenStateManager::update(float frametime){
	for (auto& it : screenStates)
		it->update(frametime);
}

void ScreenStateManager::draw(sdl::Window &target){
	for (auto& it : screenStates)
		it->draw(target);
}