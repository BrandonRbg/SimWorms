#include "MainMenuState.h"


MainMenuState::MainMenuState(){

}

void MainMenuState::update(sdl::Window &target, float frametime){
	menu.update(target);
}

void MainMenuState::draw(sdl::Window &target){
	menu.draw(target);
}