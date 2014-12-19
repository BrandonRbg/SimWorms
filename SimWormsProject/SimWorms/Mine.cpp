#include "Mine.h"
#include "ProjectilePhysicsComponents.h"

Mine::Mine(sdl::Vector2Float &position) {
	this->position = position;
	this->sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/40px-Mineicon.png"));
	this->sprite.setPosition(position);
	this->physics = new ProjectilePhysicsComponents;
	sprite.setOrigin(sprite.getTextureRect().w / 2, sprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	this->health = 1;
}

Mine::~Mine() {
	delete physics;
}

void Mine::draw(sdl::Window &target) {
	target.draw(&sprite);
}

void Mine::update(float frametime, Terrain& terrain){
	physics->update(this, terrain, frametime);
	for (auto& it : EntityManager::getInstance().getEntities()) {
		Player* tmp = dynamic_cast<Player*>(it);
		if (tmp != 0) {
			if (it->getBounds().intersects(sprite.getBounds())) {
				EntityManager::getInstance().addEntity(new Explosion(sprite.getPosition(), terrain, 50, frametime));
			}
		}
	}
}

bool Mine::isDead() {
	return health != 1;
}
