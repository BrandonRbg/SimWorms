#pragma once
#include "PlayerPhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "AssetsManager.h"
#include "Entity.h"
#include "PersonNameGenerator.h"
class Player : public Entity
{
private:
	PlayerInputComponent input;
	sdl::Text life;
	sdl::Text name;
	std::string vie;
	sdl::Text jetPackfuel;
	std::string pourcentageFuel;
	int fuel;
	sdl::Clock* clockJetPack;
	int rank;
	bool useJetpack;
public:
	Player(sdl::Vector2Float &position, int rank);
	~Player() { delete physics; }
	void draw(sdl::Window &target);
	void update(float frametime, Terrain& terrain);
	bool isDead();
	void explode(float frametime, Terrain &terrain) { return; }
	void setFuel(int fuel) { this->fuel = fuel; }
	int getFuel() { return this->fuel; }
	int getRank() { return rank; }
	bool getUseJetpack() { return useJetpack; }
	void setUseJetpack(bool useJetpack) { this->useJetpack = useJetpack; }
};

