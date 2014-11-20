#include "Melee.h"
#include "PlayerPhysicsComponent.h"

bool Melee::isPlayerTouch(Player Cible) {
	if (((Cible.getBounds().x > MeleeHitBox.x) && (Cible.getBounds().y > MeleeHitBox.y) && (Cible.getBounds().x < (MeleeHitBox.x + MeleeHitBox.w)) && (Cible.getBounds().y < (MeleeHitBox.y + MeleeHitBox.h))) || (((Cible.getBounds().x + Cible.getBounds().w) > MeleeHitBox.x) && ((Cible.getBounds().y + Cible.getBounds().h) > MeleeHitBox.y) && ((Cible.getBounds().x + Cible.getBounds().w) < (MeleeHitBox.x + MeleeHitBox.w)) && ((Cible.getBounds().y + Cible.getBounds().h) < (MeleeHitBox.y + MeleeHitBox.h)))) { // Vérification si le Rect du player recherché se trouve dans la hitbox du corp à corp
		Cible.setHeal(Cible.getHeal() - 20);
		// Une conditon sur la direction que le player faisant le corp à corp doit être ajouté
		Cible.setVelocity(sdl::Vector2Float(5.0, 5.0));
		Cible.setVelocity(sdl::Vector2Float(-5.0, 5.0));
	}
}