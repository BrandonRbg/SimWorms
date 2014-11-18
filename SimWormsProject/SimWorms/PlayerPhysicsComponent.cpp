#include "PlayerPhysicsComponent.h"
#include "Player.h"

void PlayerPhysicsComponent::update(Player &player, Terrain &terrain, float frametime){
<<<<<<< HEAD
	addConstraint(sdl::Vector2Float(0, 10)* frametime);
=======
	addConstraint(sdl::Vector2Float(0, 10) * frametime);
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
	checkCollision(player, terrain, frametime);
}

void PlayerPhysicsComponent::checkCollision(Player &player, Terrain &terrain, float frametime){
	sdl::Vector2Float playerVelocity = player.getVelocity() + resultingVector;
	sdl::Vector2Float finalPos = player.getPosition() + resultingVector;
<<<<<<< HEAD
	// is going left...
	if (playerVelocity.x < 0){
		sdl::Vector2Float finalPosLeft(finalPos.x, finalPos.y + (player.getBounds().h / 2));
		while (terrain.isPixelSolid(finalPosLeft)){
			finalPos.x++;
			if (terrain.isPixelSolid(finalPosLeft)) {
				player.setVelocity(sdl::Vector2Float(0, player.getVelocity().y));
				stopMovingX(player);
				break;
			}
		}
	}
	// is going right...
	else if (playerVelocity.x > 0){
		sdl::Vector2Float finalPosRight(finalPos.x + player.getBounds().w, finalPos.y + (player.getBounds().h / 2));
		while (terrain.isPixelSolid(finalPosRight)){
			finalPos.x--;
			if (terrain.isPixelSolid(finalPosRight)) {
				player.setVelocity(sdl::Vector2Float(0, player.getVelocity().y));
				stopMovingX(player);
				break;
			}
		}
	}
	// is going up...
	if (playerVelocity.y <= 0){
		sdl::Vector2Float finalPosUp(finalPos.x + (player.getBounds().w / 2), finalPos.y);
		while (terrain.isPixelSolid(finalPosUp)){
			finalPos.y++;
			if (terrain.isPixelSolid(finalPosUp)) {
				player.setVelocity(sdl::Vector2Float(player.getVelocity().x, 0));
				resultingVector = 0;
				break;
			}
		}
	}
	// is going down...
	else if (playerVelocity.y >= 0){
		sdl::Vector2Float finalPosDown(finalPos.x + (player.getBounds().w / 2), finalPos.y + player.getBounds().h);
		while (terrain.isPixelSolid(finalPosDown)){
			finalPos.y--;
			if (terrain.isPixelSolid(finalPosDown)) {
				player.setVelocity(sdl::Vector2Float(player.getVelocity().x, 0));
				resultingVector = 0;
				break;
			}
		}
	}
	player.setPosition(finalPos);
}
void PlayerPhysicsComponent::stopMovingX(Player &player){
	resultingVector = sdl::Vector2Float(0, resultingVector.y);
	player.setVelocity(sdl::Vector2Float(0, player.getVelocity().y));
}

bool PlayerPhysicsComponent::isInMidAir(){
	if (resultingVector.y == 0)
		return false;
	else
		return true;
=======
	// is not moving in x...
	if (playerVelocity.x == 0){
		for (float y = finalPos.y + player.getBounds().h; y >= finalPos.y; y--){
			for (float x = finalPos.x; x <= finalPos.x + player.getBounds().w; x++){
				if (player.isPixelSolid(sdl::Vector2Float(x, y) - finalPos) && terrain.isPixelSolid(sdl::Vector2Float(x, y))){
					stopMovingY(player);
					if (playerVelocity != sdl::Vector2Float()){
						player.setVelocity(resultingVector + player.getVelocity());
						player.setPosition(player.getPosition() + player.getVelocity());
						return;
					}
				}
			}
		}
	}
	// is going left...
	else if (playerVelocity.x < 0){
		for (float x = finalPos.x; x <= finalPos.x + player.getBounds().w; x++){
			// is going up...
			if (playerVelocity.y < 0){
				for (float y = finalPos.y; y <= finalPos.y + player.getBounds().h; y++){
					if (player.isPixelSolid(sdl::Vector2Float(x, y) - finalPos) && terrain.isPixelSolid(sdl::Vector2Float(x, y))){
						stopMovingX(player);
						if (playerVelocity != sdl::Vector2Float()){
							player.setVelocity(resultingVector + player.getVelocity());
							player.setPosition(player.getPosition() + player.getVelocity());
							return;
						}
					}
				}
			}
			// is going down...
			else {
				for (float y = finalPos.y + player.getBounds().h; y <= finalPos.y; y--){
					if (player.isPixelSolid(sdl::Vector2Float(x, y) - finalPos) && terrain.isPixelSolid(sdl::Vector2Float(x, y))){
						stopMovingX(player);
						if (playerVelocity != sdl::Vector2Float()){
							player.setVelocity(resultingVector + player.getVelocity());
							player.setPosition(player.getPosition() + player.getVelocity());
							return;
						}
					}
				}
			}
		}
	}
	// is going right...
	else if (playerVelocity.x > 0){
		for (float x = finalPos.x + player.getBounds().w; x <= finalPos.x; x--){
			// is going up...
			if (playerVelocity.y < 0){
				for (float y = finalPos.y; y <= finalPos.y + player.getBounds().h; y++){
					if (player.isPixelSolid(sdl::Vector2Float(x, y) - finalPos) && terrain.isPixelSolid(sdl::Vector2Float(x, y))){
						stopMovingX(player);
						if (playerVelocity != sdl::Vector2Float()){
							player.setVelocity(resultingVector + player.getVelocity());
							player.setPosition(player.getPosition() + player.getVelocity());
							return;
						}
					}
				}
			}
			// is going down...
			else {
				for (float y = finalPos.y + player.getBounds().h; y <= finalPos.y; y--){
					if (player.isPixelSolid(sdl::Vector2Float(x, y) - finalPos) && terrain.isPixelSolid(sdl::Vector2Float(x, y))){
						stopMovingX(player);
						if (playerVelocity != sdl::Vector2Float()){
							player.setVelocity(resultingVector + player.getVelocity());
							player.setPosition(player.getPosition() + player.getVelocity());
							return;
						}
					}
				}
			}
		}
	}
	player.setVelocity(resultingVector + player.getVelocity());
	player.setPosition(player.getPosition() + player.getVelocity());
	// is going up...
	//if (playerVelocity.y <= 0){
	//	// is going left...
	//	if (playerVelocity.x <= 0){
	//		for (float x = finalPos.x; x <= finalPos.x + player.getBounds().w; x++){
	//			for (float y = finalPos.y; y <= finalPos.y + player.getBounds().h; y++){
	//				if (player.isPixelSolid(sdl::Vector2Float(x, y)) && terrain.isPixelSolid(sdl::Vector2Float(x, y)))
	//					stopMovingX(player);
	//			}
	//		}
	//	}
	//	// is going right...
	//	else if (playerVelocity.x > 0){
	//		for (float x = finalPos.x + player.getBounds().w; x <= finalPos.x; x--){
	//			for (float y = finalPos.y; y <= finalPos.y + player.getBounds().h; y++){
	//				if (player.isPixelSolid(sdl::Vector2Float(x, y)) && terrain.isPixelSolid(sdl::Vector2Float(x, y)))
	//					stopMovingX(player);
	//			}
	//		}
	//	}
	//}
	//// is going down...
	//else if (playerVelocity.y > 0){
	//	// is going left...
	//	if (playerVelocity.x <= 0){
	//		for (float x = finalPos.x; x <= finalPos.x + player.getBounds().w; x++){
	//			for (float y = finalPos.y + player.getBounds().h; y >= finalPos.y; y--) {
	//				if (player.isPixelSolid(sdl::Vector2Float(x, y)) && terrain.isPixelSolid(sdl::Vector2Float(x, y)))
	//					stopMovingY(player);
	//			}
	//		}
	//	}
	//	// is going right...
	//	else if (playerVelocity.x > 0){
	//		for (float x = finalPos.x + player.getBounds().w; x <= finalPos.x; x--){
	//			for (float y = finalPos.y + player.getBounds().h; y >= finalPos.y; y--){
	//				if (player.isPixelSolid(sdl::Vector2Float(x, y)) && terrain.isPixelSolid(sdl::Vector2Float(x, y)))
	//					stopMovingY(player);
	//			}
	//		}
	//	}
	//}
}
void PlayerPhysicsComponent::stopMovingX(Player &player){
	resultingVector = sdl::Vector2Float(0, resultingVector.y);
	player.setVelocity(resultingVector);
}
void PlayerPhysicsComponent::stopMovingY(Player &player){
	resultingVector = sdl::Vector2Float(resultingVector.x, 0);
	player.setVelocity(resultingVector);
}
bool PlayerPhysicsComponent::isInMidAir(Player &player){
	return player.getVelocity().y != 0;
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
}