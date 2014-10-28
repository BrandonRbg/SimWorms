#pragma once
#include "Window.h"
#include "Terrain.h"
#include "AssetsManager.h"
#include "PlayerInputComponent.h"

class Player{
private:
	float x, y;
	float velX, velY;

	bool goLeft;
	bool goRight;

	bool onGround; 
	bool topBlocked;

	int playerWidth, playerHeight;

	sdl::Sprite playerSprite;

	PlayerInputComponent input;

public:
	Player(int x, int y) {
		this->x = x; this->y = y;
		velX = 0; velY = 0;

		this->playerSprite.setTexture(&AssetsManager::getInstance().getTexture("player.png"));
		this->playerSprite.setPosition(x, y);
		playerWidth = playerSprite.getTextureRect().w;
		playerHeight = playerSprite.getTextureRect().h;
		playerSprite.setOrigin(playerSprite.getTextureRect().w / 2, playerSprite.getTextureRect().h / 2);
	}

	void jump() {
		if (onGround && !topBlocked && velY > -500)
			velY -= 500;
	}

	void moveLeft() {
		goLeft = true;
	}
	void moveRight() {
		goRight = true;
	}
	void stopLeft() {
		goLeft = false;
	}
	void stopRight() {
		goRight = false;
	}

	void draw(sdl::Window &target) {
		playerSprite.setPosition(x, y);
		target.draw(&playerSprite);
	}

	void checkConstraints(Terrain &terrain) {

		if (goLeft) {
			velX = -200;
		}
		else if (goRight) {
			velX = 200;
		}
		else
			velX = 0;

		onGround = false;
		for (int bottomX = (int)x - playerWidth / 2; bottomX <= (int)x + playerWidth / 2; bottomX++) {
			if (terrain.isPixelAtPositionSolid(sdl::Vector2Int(bottomX, (int)y + playerHeight / 2 + 1)) && (velY > 0)) {
				onGround = true;
				for (int yCheck = (int)y + playerHeight / 4; yCheck < (int)y + playerHeight / 2; yCheck++) {
					if (terrain.isPixelAtPositionSolid(sdl::Vector2Int(bottomX, yCheck))) {
						y = yCheck - playerHeight / 2;
						break;
					}
				}
				if (velY > 0)
					velY *= -0.25;
			}
		}

		topBlocked = false;
		for (int topX = (int)x - playerWidth / 2; topX <= (int)x + playerWidth / 2; topX++) {
			if (terrain.isPixelAtPositionSolid(sdl::Vector2Int(topX, (int)y - playerHeight / 2 - 1))) {
				topBlocked = true;
				if (velY < 0) {
					velY *= -0.5;
				}
			}
		}
		if (velX < 0) {
			for (int leftY = (int)y - playerHeight / 2; leftY <= (int)y + playerHeight / 2; leftY++) {
				if (terrain.isPixelAtPositionSolid(sdl::Vector2Int((int)x - playerWidth / 2, leftY))) {
					for (int xCheck = (int)x - playerWidth / 4; xCheck < (int)x - playerWidth / 2; xCheck--) {
						if (terrain.isPixelAtPositionSolid(sdl::Vector2Int(xCheck, leftY))) {
							x = xCheck + playerWidth / 2;
							break;
						}
					}
					if (leftY > y && !topBlocked) {
						y -= 1;
					}
					else {
						velX *= -0.4;
						x += 2;
					}
				}
			}
		}
		if (velX > 0) {
			for (int rightY = (int)y - playerHeight / 2; rightY <= (int)y + playerHeight / 2; rightY++) {
				if (terrain.isPixelAtPositionSolid(sdl::Vector2Int((int)x + playerWidth / 2, rightY))) {
					for (int xCheck = (int)x + playerWidth / 4; xCheck < (int)x + playerWidth / 2 + 1; xCheck++) {
						if (terrain.isPixelAtPositionSolid(sdl::Vector2Int(xCheck, rightY))) {
							x = xCheck - playerWidth / 2;
							break;
						}
					}
					if (rightY > y && !topBlocked) {
						y -= 1;
					}
					else {
						velX *= -0.4;
						x -= 2;
					}
				}
			}
		}

		if (x < 0 && velX < 0) {
			x -= x;
			velX *= -1;
		}
		if (y < 0 && velY < 0) {
			y -= y;
			velY *= -1;
		}
		if (x > terrain.getWidth() && velX > 0) {
			x += terrain.getWidth() - x;
			velX *= -1;
		}
		if (y + playerHeight / 2 > terrain.getHeight() && velY > 0) {
			y += terrain.getHeight() - y - playerHeight / 2;
			velY = 0;
			onGround = true;
		}
	}

	void update(float frametime){
		velY += 980 * frametime;

		setX(getX() + velX * frametime);

		if (!onGround && velY > 0)
			setY(getY() + velY * frametime);

		input.update(*this);

	}
	float getX() { return x; }
	float getY() { return y; }
	float getVX() { return velX; }
	float getVY() { return velY; }
	void setX(float pX) { x = pX;}
	void setY(float pY) { y = pY; }
	void setVX(float vX) { velX = vX; }
	void setVY(float vY) { velY = vY; }
};
