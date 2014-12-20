#include "Melee.h"
#include "PlayerPhysicsComponent.h"
#include "EntityManager.h"

bool Melee::checkPlayerTouch(Player* cible,float frametime) {
	if (((cible->getBounds().x > MeleeHitBox.x) && (cible->getBounds().y > MeleeHitBox.y) && (cible->getBounds().x < (MeleeHitBox.x + MeleeHitBox.w)) && (cible->getBounds().y < (MeleeHitBox.y + MeleeHitBox.h))) || (((cible->getBounds().x + cible->getBounds().w) > MeleeHitBox.x) && ((cible->getBounds().y + cible->getBounds().h) > MeleeHitBox.y) && ((cible->getBounds().x + cible->getBounds().w) < (MeleeHitBox.x + MeleeHitBox.w)) && ((cible->getBounds().y + cible->getBounds().h) < (MeleeHitBox.y + MeleeHitBox.h)))) {
		cible->setHealth(cible->getHealth() - 50);
		if (cible->getDirection() == true) {
			cible->addConstraint(sdl::Vector2Float(250, -250), frametime);
		}
		else {
			cible->addConstraint(sdl::Vector2Float(-250, -250), frametime);
		}
		return true;
	}
	return false;
}