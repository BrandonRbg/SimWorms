#include "Player.h"
#include "OOSDL\Text.h"
#include <sstream>

Player::Player(sdl::Vector2Float &position){
	this->position = position;
	this->direction = false;
	this->sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/player.png"));
	this->sprite.setPosition(position);
	this->physics = new PlayerPhysicsComponent;
	sprite.setOrigin(sprite.getTextureRect().w / 2, sprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	name.setString("Roger");
	name.setCharacterSize(20);
	name.setFont("data/fonts/Arial.ttf");
	name.setColor(sdl::Color::Black);
	health = 100;
	life.setFont("data/fonts/Arial.ttf");
	life.setCharacterSize(20);
	life.setColor(sdl::Color::Black);
	fuel = 100;
	jetPackfuel.setFont("data/fonts/Arial.ttf");
	jetPackfuel.setCharacterSize(15);
	jetPackfuel.setColor(sdl::Color(0, 100, 0));
	jetpack = false;
	clockJetPack = new sdl::Clock();
}

void Player::draw(sdl::Window &target){
	target.draw(&sprite);
	target.draw(&life);
	target.draw(&name);
	if (jetpack)
		target.draw(&jetPackfuel);
}
void Player::update(float frametime, Terrain& terrain){
	if (sdl::Keyboard::isKeyPressed(SDLK_p)) {
		if (fuel > 0) {
			jetpack = true;
		}
		else
			jetpack = false;
		if (jetpack) {
			this->addConstraint(sdl::Vector2Float(0, 2500), frametime);
			if (clockJetPack->getElapsedTime().asSeconds() > 0.1) {
				fuel--;
				clockJetPack->restart();
			}
		}
	}
	if (sdl::Keyboard::isKeyReleased(SDLK_p)) {
		jetpack = false;
	}
	physics->update(this, terrain, frametime);
	input.update(this, frametime);
	life.setPosition(this->sprite.getBounds().x, this->sprite.getBounds().y + life.getBounds().h - this->sprite.getBounds().h - 15);
	jetPackfuel.setPosition(this->sprite.getBounds().x + jetPackfuel.getBounds().w, this->sprite.getBounds().y);
	std::stringstream ster;
	ster << health;
	life.setString(ster.str());
	name.setPosition(life.getBounds().x, life.getBounds().y - name.getBounds().h);
	std::stringstream stjp;
	stjp << fuel;
	if (fuel < 10) {
		jetPackfuel.setString(" " + stjp.str() + "%");
	}
	else
		jetPackfuel.setString(stjp.str() + "%");
}
bool Player::isDead(){
	return getHealth() <= 0;
}
void Player::useJetPack(bool use) {
	jetpack = use;
}