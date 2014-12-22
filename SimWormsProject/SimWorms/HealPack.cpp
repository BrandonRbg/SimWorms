#include "HealPack.h"
#include "ProjectilePhysicsComponents.h"

HealPack::HealPack(sdl::Vector2Float &position) {
	this->position = position;
	this->sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/med-kit-512.png"));
	this->sprite.setPosition(position);
	this->physics = new ProjectilePhysicsComponents;
	sprite.setOrigin(sprite.getTextureRect().w / 2, sprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	this->health = 1;
}

HealPack::~HealPack() {
	delete physics;
}

void HealPack::draw(sdl::Window &target) {
	target.draw(&sprite);
}

void HealPack::update(float frametime, Terrain& terrain, Camera* cam){
	if (!isOnGround)
		physics->update(this, terrain, frametime);
	for (auto& it : EntityManager::getInstance().getEntities()) {
		Player* tmp = dynamic_cast<Player*>(it);
		if (tmp != 0) {
			if (it->getBounds().intersects(sprite.getBounds())) {
				it->setHealth(it->getHealth() + 25);
				this->health = 0;
			}
		}
	}
}

bool HealPack::isDead() {
	return health != 1;
}