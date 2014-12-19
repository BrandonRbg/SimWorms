#include "GameMenuState.h"


GameMenuState::GameMenuState()
{

}

void GameMenuState::update(sdl::Window &target, float frametime){
	menu.update(target);
}

void GameMenuState::draw(sdl::Window &target){
	menu.draw(target);
}
