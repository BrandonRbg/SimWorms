#include "ScreenStateManager.h"


ScreenStateManager::ScreenStateManager(){
}
ScreenStateManager::~ScreenStateManager(){
	for (auto& it : screenStates)
		delete it;
}

void ScreenStateManager::pushScreenState(ScreenState* screenState){
	screenStates.push_back(screenState);
}

void ScreenStateManager::popScreenState(){
	screenStates[screenStates.size() - 1];
	screenStates.pop_back();
}

void ScreenStateManager::update(sdl::Window &target, float frametime){
	for (int i = 0; i < screenStates.size(); i++)
		screenStates[i]->update(target, frametime);
}

void ScreenStateManager::draw(sdl::Window &target){
	for (auto& it : screenStates)
		it->draw(target);
}