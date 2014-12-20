#include "Player.h"
#include "OOSDL\Text.h"
#include "GameManager.h"
#include "HealPack.h"
#include <sstream>

Player::Player(sdl::Vector2Float &position, int rank){
	this->position = position;
	this->direction = false;
	this->sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/player.png"));
	this->sprite.setPosition(position);
	this->physics = new PlayerPhysicsComponent;
	velocity = sdl::Vector2Float(0, 0);
	sprite.setOrigin(0, 0);
	name.setString(PersonNameGenerator::getInstance().generateFirstName("french", "M") + " " + PersonNameGenerator::getInstance().generateLastName("english"));
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
	useJetpack = false;
	this->rank = rank;
}

void Player::draw(sdl::Window &target){
	target.draw(&sprite);
	target.draw(&life);
	target.draw(&name);
	if (jetpack)
		target.draw(&jetPackfuel);
}
void Player::update(float frametime, Terrain& terrain){
	if (useJetpack) {
		if (fuel > 0) {
			jetpack = true;
			isOnGround = false;
		}
		else {
			jetpack = false;
			stop();
			physics->stopMovingY(this);
		}
		if (jetpack) {
			physics->stopMovingY(this);
			this->addConstraint(sdl::Vector2Float(0, -250), frametime);
			if (clockJetPack->getElapsedTime().asSeconds() > 0.1) {
				fuel--;
				clockJetPack->restart();
			}
		}
	}
	if (!useJetpack && jetpack) {
		physics->stopMovingY(this);
		jetpack = false;
	}
	physics->update(this, terrain, frametime);
	if (GameManager::getInstance().getTour() == rank) {
		input.update(this, frametime);
	}
	life.setPosition(this->sprite.getBounds().x - 10, this->sprite.getBounds().y + life.getBounds().h - this->sprite.getBounds().h - 40);
	jetPackfuel.setPosition(this->sprite.getBounds().x - 15 + jetPackfuel.getBounds().w, this->sprite.getBounds().y);
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
	if (getHealth() <= 0) {
		GameManager::getInstance().setNumberPlayer(GameManager::getInstance().getNumberPlayer() - 1);
		EntityManager::getInstance().addEntity(new HealPack(sdl::Vector2Float(800, 200)));
		return true;
	}
}

bool Player::useRocket(float grametime) {

}

bool Player::useGrenage(float frametime) {
	
}

bool Player::useMelee(float frametime) {
	if (sdl::Mouse::isButtonReleased(SDL_BUTTON_LEFT)) {
		if (this->direction) {
			Melee shoot(sdl::Vector2Float(this->getBounds().x + this->getBounds().w + 5, this->getBounds().y + (this->getBounds().h / 2)));
			for (auto& it : EntityManager::getInstance().getEntities()) {
				Player* tmp = dynamic_cast<Player*>(it);
				if (tmp != 0) {
					if (shoot.checkPlayerTouch(tmp, frametime)) {
						continue;
					}
				}
			}
		}
		else {
			Melee shoot(sdl::Vector2Float(this->getBounds().x - 50, this->getBounds().y + (this->getBounds().h / 2)));
			for (auto& it : EntityManager::getInstance().getEntities()) {
				Player* tmp = dynamic_cast<Player*>(it);
				if (tmp != 0) {
					if (shoot.checkPlayerTouch(tmp, frametime)) {
						continue;
					}
				}
			}
		}
		return true;
	}
}