#include "PauseMenuState.h"


PauseMenuState::PauseMenuState(){

}

void PauseMenuState::update(sdl::Window &target, float frametime){
	pause.update(target);
}

void PauseMenuState::draw(sdl::Window &target){
	pause.draw(target);
}