#pragma once
#include "OOSDL\View.h"
#include "OOSDL\Window.h"

#include "Map.h"
#include "Entity.h"
class Camera
{
public:
	Camera(sdl::Window &target, Map* map);
	void goTo(sdl::Vector2Float& destination);
	void moveTo(sdl::Vector2Float& destination, float speed);
	void zoomTo(sdl::Vector2Float& size, float speed);

	void proceedZoom(int wheelDelta);

	void follow(Entity* entity);

	sdl::View& getView();

	void update(sdl::Window& target);

private:
	sdl::View view;
	sdl::RectFloat actualMapBounds;
	float top, bottom, left, right;
	
	bool dragged;
	sdl::Vector2Float dragOrigin;

	sdl::Vector2Float currentPosition;
	sdl::Vector2Float destination;
	sdl::Vector2Float movement;
	bool movementEnded;
	int moveFrames;

	sdl::Vector2Float currentSize;
	sdl::Vector2Float sizeDestination;
	sdl::Vector2Float sizeMovement;
	bool stoppedZooming;
	int zoomFrames;
};

