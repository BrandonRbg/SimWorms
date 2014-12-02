#include "Player.h"
#include "OOSDL\Text.h"

Player::Player(sdl::Vector2Float &position){
	this->position = position;
	this->direction = false;
	this->sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/player.png"));
	this->sprite.setPosition(position);
	this->physics = new PlayerPhysicsComponent;
	sprite.setOrigin(sprite.getTextureRect().w / 2, sprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	sprite.setOrigin(0, 0);
	name.setString("Roger");
	name.setCharacterSize(20);
	name.setFont("data/fonts/Arial.ttf");
	name.setColor(sdl::Color::Black);
	health = 100;
	life.setFont("data/fonts/Arial.ttf");
	life.setCharacterSize(20);
	life.setColor(sdl::Color::Black);
}

void Player::draw(sdl::Window &target){
	target.draw(&sprite);
	target.draw(&life);
	target.draw(&name);
}
void Player::update(float frametime, Terrain& terrain){
	input.update(this, frametime);
	physics->update(this, terrain, frametime);
	life.setPosition(this->sprite.getBounds().x, this->sprite.getBounds().y + life.getBounds().h - this->sprite.getBounds().h - 10);
	life.setString("100");
	name.setPosition(life.getBounds().x, life.getBounds().y - name.getBounds().h);
}
bool Player::isDead(){
	return getHealth() <= 0;
}