#include "GuiCheckBox.h"

GuiCheckBox::GuiCheckBox(){
	Checked = false;
	CheckSprite.setTexture(&AssetsManager::getInstance().getTexture("checkmark.png"));
	BoxSprite.setTexture(&AssetsManager::getInstance().getTexture("Box.png"));
}

void GuiCheckBox::setPos(sdl::Vector2Float &Position){
	Pos = Position;
	BoxSprite.setPosition(Pos);
	CheckSprite.setPosition(Pos);
}

void GuiCheckBox::setSize(sdl::Vector2Float &Scale){
	BoxSprite.setScale(Scale);
	CheckSprite.setScale(Scale);
}

sdl::Vector2Float GuiCheckBox::getPos(){
	return Pos;
}

sdl::Vector2Float GuiCheckBox::getSize(){
	return BoxSprite.getScale();
}

bool GuiCheckBox::isClicked(){
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (BoxSprite.getBounds().contains(sdl::Mouse::getPosition())){
			return true;
		}
		else
			return false;
	}
}

bool GuiCheckBox::isOver(){
	if (BoxSprite.getBounds().contains(sdl::Mouse::getPosition()))
		return true;
	else
		return false;
}

void GuiCheckBox::draw(sdl::Window &target){
	target.draw(&BoxSprite);
	if (Checked)
		target.draw(&BoxSprite);
}

/*void GuiCheckBox::update(){
}*/