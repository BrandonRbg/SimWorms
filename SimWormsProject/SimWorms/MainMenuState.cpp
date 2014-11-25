#include "MainMenuState.h"


MainMenuState::MainMenuState(){

}

void MainMenuState::update(float frametime){
	//menu.update();
}

void MainMenuState::draw(sdl::Window &target){
	menu.draw(target);
}