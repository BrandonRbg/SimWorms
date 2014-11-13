#include "GuiMainMenu.h"

GuiMainMenu::GuiMainMenu(){
	TextNameGame = sdl::Text("Nouvelle Partie","Arial.ttf",50);
	TextOptions = sdl::Text("Options", "Arial.ttf", 50);
	//SpriteLogo = sdl::Sprite();
	//SpriteBG = sdl::Sprite();
}

void GuiMainMenu::draw(sdl::Window &target){
	target.draw(&SpriteBG);
	target.draw(&SpriteLogo);
	target.draw(&TextOptions);
	target.draw(&TextNameGame);
}

void GuiMainMenu::update(){

}