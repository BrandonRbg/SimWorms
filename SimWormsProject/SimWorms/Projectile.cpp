#include "Projectile.h"

Projectile::Projectile(sdl::Vector2Float &position, sdl::Vector2Float &direction, float puissance, bool orientation) {
	sprite = new sdl::Sprite(&AssetsManager::getInstance().getTexture("data/textures/Bullet_bill"));
	this->orientation = orientation;
}

bool Projectile::isExplode(Terrain &terrain) {
	if (!orientation) {
		if (terrain.isPixelSolid(sdl::Vector2Float(sprite->getBounds().x, (sprite->getBounds().y + sprite->getBounds().h)))) {
			return true;
		}
	}
	else {
		if (terrain.isPixelSolid(sdl::Vector2Float((sprite->getBounds().x + sprite->getBounds.w), (sprite->getBounds().y + (sprite->getBounds().h / 2))))) {
			return false;
		}
	}
}

Projectile::~Projectile() {
	delete sprite;
}
