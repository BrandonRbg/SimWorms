#include "GuiCheckBox.h"

GuiCheckBox::GuiCheckBox(/*sdl::Vector2Float &Position*/){
	//Pos = Position;
	CheckSprite.setTexture(&AssetsManager::getInstance().getTexture("checkmark.png"));
}

void GuiCheckBox::setPos(sdl::Vector2Float &Position){
	Pos = Position;
}

void GuiCheckBox::setSize(sdl::Vector2Float &Scale){
	//
}
sdl::Vector2Float GuiCheckBox::getPos(){
	return Pos;
}

sdl::Vector2Float GuiCheckBox::getSize(){
	//
	return 0; 
}

bool GuiCheckBox::isClicked(){
	//
	return 0;
}

bool GuiCheckBox::isOver(){
	//
	return 0;
}

void GuiCheckBox::draw(sdl::Window &target){
	target.draw(&CheckSprite);
}

void GuiCheckBox::update(){
	//
}