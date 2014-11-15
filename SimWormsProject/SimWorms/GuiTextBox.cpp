#include "GuiTextBox.h"

GuiTextBox::GuiTextBox(const std::string& string, int Size, sdl::Color Color, int PosX, int PosY){
	Text.setFont("Bit.ttf");
	Text.setString(string);
	Text.setCharacterSize(Size);
	Text.setColor(Color);
	Text.setPosition(PosX, PosY);
	TextBox.setPosition(PosX, PosY);
	Pos = Text.getPosition();
}
void GuiTextBox::setString(const std::string& string){
	Text.setString(string);
}

const std::string GuiTextBox::getString(){
	return Text.getString();
}

void GuiTextBox::setPos(sdl::Vector2Float  &Position){
	Pos = Position;
	Text.setPosition(Position);
	TextBox.setPosition(Position);
}

void GuiTextBox::setSize(sdl::Vector2Float &Scale){
	Text.setScale(Scale);
	TextBox.setScale(Scale);  
}

sdl::Vector2Float GuiTextBox::getPos(){
	return Pos;
}

sdl::Vector2Float GuiTextBox::getSize(){
	return Text.getScale();
}

bool GuiTextBox::isClicked(){
	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
		if (TextBox.getBounds().contains(sdl::Mouse::getPosition())){
			return true;
		}
	}
	else
		return false;
}

bool GuiTextBox::isOver(){
		if (TextBox.getBounds().contains(sdl::Mouse::getPosition())){
			return true;
		}
		else
			return false;
}

void GuiTextBox::draw(sdl::Window &target){

}