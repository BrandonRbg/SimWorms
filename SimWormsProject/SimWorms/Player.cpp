#include "Player.h"
#include "OOSDL\Text.h"
#include "GameManager.h"
#include "HealPack.h"
#include <sstream>
#include "RadToDeg.h"

Player::Player(sdl::Vector2Float &position, int rank, Team &team){
	this->position = position;
	this->direction = false;
	this->lastDirection = false;
	this->sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/PlayerHead.png"));
	this->sprite.setPosition(position);

	PlayerTail = new sdl::AnimatedSprite(&AssetsManager::getInstance().getTexture("data/textures/PlayerTail.png"), 3, 48);
	PlayerTail->active = false;
	PlayerTail->setOrigin(0, (0 + (PlayerTail->getBounds().h / 2)));
	PlayerTail->setPosition(position - sdl::Vector2Float(32, 0));
	//PlayerEyes.setPosition();
	//PlayerMouth;
	//PlayerHand;
	//PlayerWeapon;
	//PlayerJetPack;

	this->physics = new PlayerPhysicsComponent;
	velocity = sdl::Vector2Float(0, 0);

	this->rank = rank;
	state = PlayerState::Default;
	this->team = team;

	this->moves = 0;
	this->finishedTurn = false;

	

	sprite.setOrigin(0, 0);
	name.setString(PersonNameGenerator::getInstance().generateFirstName("french", "M") + " " + PersonNameGenerator::getInstance().generateLastName("french"));
	name.setCharacterSize(20);
	name.setFont("data/fonts/Arial.ttf");
	name.setColor(this->team.getColor());
	health = 100;
	life.setFont("data/fonts/Arial.ttf");
	life.setCharacterSize(20);
	life.setColor(this->team.getColor());
	fuel = 100;
	jetPackfuel.setFont("data/fonts/Arial.ttf");
	jetPackfuel.setCharacterSize(15);
	jetPackfuel.setColor(sdl::Color(0, 100, 0));
	jetpack = false;
	clockJetPack = new sdl::Clock();


	dead = false;
}

void Player::draw(sdl::Window &target){
	target.draw(PlayerTail);
	target.draw(&sprite);
	target.draw(&life);
	target.draw(&name);
	if (jetpack)
		target.draw(&jetPackfuel);
}
void Player::update(float frametime, Terrain& terrain, Camera* cam){
	if (physics->getResultingVector().x != 0)
		PlayerTail->active = true;
	else
		PlayerTail->active = false;
	/*if (terrain.isPixelSolid(position)){
		PlayerTail->setRotation(180 + radToDeg(atan(terrain.getNormal(PlayerTail->getPosition()).y / terrain.getNormal(PlayerTail->getPosition()).x)));
	}*/
	if (direction){
		PlayerTail->setOrigin(PlayerTail->getBounds().w / 3, (0 + (PlayerTail->getBounds().h / 2)));
		sprite.flip(SDL_FLIP_NONE);
		PlayerTail->flip(SDL_FLIP_NONE);
		PlayerTail->setPosition(position - sdl::Vector2Float(10, 16));
	}
	else{
		PlayerTail->setOrigin(0, (0 + (PlayerTail->getBounds().h / 2)));
		sprite.flip(SDL_FLIP_HORIZONTAL);
		PlayerTail->flip(SDL_FLIP_HORIZONTAL);
		PlayerTail->setPosition(position - sdl::Vector2Float(10, 16));
	}
	
	if (getHealth() <= 0) {
		EntityManager::getInstance().addEntity(new HealPack(sdl::Vector2Float(position.x, 0)));
		dead = true;
		finishedTurn = true;
	}

	if (state == PlayerState::Default){
		
	}

	if (state == PlayerState::JetPack){
		if (fuel <= 0){
			finishedTurn = true;
			jetpack = false;
			physics->stopMovingY(this);
		}
		if (sdl::Keyboard::isKeyPressed(SDLK_SPACE)){
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
				this->addConstraint(sdl::Vector2Float(0, -125), frametime);
				if (clockJetPack->getElapsedTime().asSeconds() > 0.1) {
					fuel--;
					clockJetPack->restart();
				}
			}
		}
		else{
			jetpack = false;
			physics->stopMovingY(this);
		}

		jetPackfuel.setPosition(this->sprite.getBounds().x - 15 + jetPackfuel.getBounds().w, this->sprite.getBounds().y);

		std::stringstream stjp;
		stjp << fuel;
		if (fuel < 10) {
			jetPackfuel.setString(" " + stjp.str() + "%");
		}
		else
			jetPackfuel.setString(stjp.str() + "%");

	}
	if (state != PlayerState::JetPack && jetpack) {
		physics->stopMovingY(this);
		jetpack = false;
	}

	if (state == PlayerState::Grenade){
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
			sdl::Vector2Float orientation(sdl::Mouse::getPosition(cam->getView()) - position);
			orientation.normalize();
			EntityManager::getInstance().addEntity(new Grenade(position, orientation, 725, 5));
			state = PlayerState::Default;
		}
	}

	if (state == PlayerState::RocketLauncher){
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
			sdl::Vector2Float orientation(sdl::Mouse::getPosition(cam->getView()) - position);
			orientation.normalize();
			EntityManager::getInstance().addEntity(new Rocket(position, orientation, 700));
			state = PlayerState::Default;
		}
	}

	if (state == PlayerState::Melee){
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)) {
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
			finishedTurn = true;
		}
	}
	

	physics->update(this, terrain, frametime);

	life.setPosition(this->sprite.getBounds().x - 10, this->sprite.getBounds().y + life.getBounds().h - this->sprite.getBounds().h - 40);

	std::stringstream str;
	str << health;
	life.setString(str.str());
	name.setPosition(life.getBounds().x, life.getBounds().y - name.getBounds().h);

	

	if (GameManager::getInstance().getActualTurn() == rank) {
		input.update(this, frametime);
	}

	if (moves > 100){
		finishedTurn = true;
		moves = 0;
	}
}
void Player::useJetpack(){
	state = PlayerState::JetPack;
}

void Player::useRocket() {
	state = PlayerState::RocketLauncher;
}

void Player::useGrenade() {
	state = PlayerState::Grenade;
}

void Player::useMelee() {
	state = PlayerState::Melee;
}

bool Player::hasFinishedTurn(){
	return finishedTurn;
}

void Player::resetTurn(){
	finishedTurn = false;
	moves = 0;
}

void Player::resetState(){
	state = PlayerState::Default;
}