#include "GuiTextBox.h"


GuiTextBox::GuiTextBox(/*int Size, sdl::Color Color*/){
	Text.setFont("data/fonts/Arial.ttf");
	//Text.setCharacterSize(Size);
	//Text.setColor(Color);
	Text.setString(" ");
	TextBox.setTexture(&AssetsManager::getInstance().getTexture("data/textures/TextBox.png"));
	Pos = Text.getPosition();
	EventManager::getInstance().addCallbackToID(SDL_TEXTINPUT, std::bind(&GuiTextBox::onTextEntered, this, std::placeholders::_1));
	ActualText = " ";
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

void GuiTextBox::onTextEntered(SDL_Event Event){
	if (Clicked){
		if ((int)Event.text.text == 8)
			ActualText.pop_back();
		ActualText.append(Event.text.text);
	}
}

void GuiTextBox::update(sdl::Window &target){
	if ((sdl::Keyboard::isKeyPressed(SDLK_BACKSPACE)) && (Time.getElapsedTime().asSeconds() > 0.1)){
		if (ActualText.length() > 0)
			ActualText.pop_back();
		Time.restart();
	}
	Text.setString(ActualText);
	if (GuiTextBox::isClicked()){
		Clicked = true;
	}
	else
		Clicked = false;
}