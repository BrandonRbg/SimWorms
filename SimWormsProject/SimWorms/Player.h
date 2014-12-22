#pragma once
#include "PlayerPhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "AssetsManager.h"
#include "Entity.h"
#include "PersonNameGenerator.h"
#include "Team.h"
enum class PlayerState {
	Default, JetPack, Grenade, RocketLauncher, Melee
};
class Player : public Entity
{
private:
	sdl::AnimatedSprite* PlayerTail;
	sdl::Sprite PlayerEyes;
	sdl::Sprite PlayerMouth;
	sdl::Sprite PlayerHand;
	sdl::Sprite PlayerWeapon;
	sdl::Sprite PlayerJetPack;

	PlayerInputComponent input;
	sdl::Text life;
	sdl::Text name;
	std::string vie;

	bool lastDirection;

	sdl::Text jetPackfuel;
	std::string pourcentageFuel;
	int fuel;
	sdl::Clock* clockJetPack;

	int rank;
	Team team;

	bool finishedTurn;

	

	PlayerState state;
public:
	Player(sdl::Vector2Float &position, int rank, Team &team);
	~Player() { delete physics; }
	void draw(sdl::Window &target);
	void update(float frametime, Terrain& terrain, Camera* cam);
	void explode(float frametime, Terrain &terrain) { return; }
	void setFuel(int fuel) { this->fuel = fuel; }
	int getFuel() { return this->fuel; }
	int getRank() { return rank; }
	Team getTeam() { return team; }
	PlayerState getState() { return state;  }

	bool hasFinishedTurn();

	void useJetpack();
	void useRocket();
	void useGrenade();
	void useMelee();

	void resetTurn();
	void resetState();
};

