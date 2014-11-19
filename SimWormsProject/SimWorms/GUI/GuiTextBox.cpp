#include "GuiTextBox.h"

GuiTextBox::GuiTextBox(/*int Size, sdl::Color Color*/){
	Text.setFont("Arial.ttf");
	//Text.setCharacterSize(Size);
	//Text.setColor(Color);
	Text.setString(" ");
	TextBox.setTexture(&AssetsManager::getInstance().getTexture("TextBox.png"));
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
	target.draw(&Text);
	target.draw(&TextBox);
}

void GuiTextBox::update(sdl::Window &target){
	if (GuiTextBox::isClicked()){
		if (GuiTextBox::isOver()){
			if (sdl::Keyboard::isKeyPressed(SDLK_a)){
				Text.setString(GuiTextBox::getString() + "a");
			}
		}
	}
}