#include "ScreenStateManager.h"


ScreenStateManager::ScreenStateManager(){
	actualScreenState = nullptr;
}
ScreenStateManager::~ScreenStateManager(){
	delete this->actualScreenState;
}

void ScreenStateManager::setScreenState(ScreenState* screenState){
	delete actualScreenState;
	actualScreenState = screenState;
}

void ScreenStateManager::update(float frametime){
	if (actualScreenState != nullptr)
		actualScreenState->update(frametime);
}

void ScreenStateManager::draw(sdl::Window &target){
	if (actualScreenState != nullptr)
		actualScreenState->draw(target);
}