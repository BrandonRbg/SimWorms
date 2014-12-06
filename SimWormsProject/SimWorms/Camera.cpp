#include "Camera.h"


Camera::Camera(sdl::Window& target, Map& map)
{
	view = target.getDefaultView();
	actualMapBounds = map.getBounds();

	currentPosition = view.getCenter();
	destination = view.getCenter();

	currentSize = view.getSize();
	sizeDestination = view.getSize();

	top = actualMapBounds.y;
	bottom = actualMapBounds.y + actualMapBounds.h;
	left = actualMapBounds.x; 
	right = actualMapBounds.x + actualMapBounds.w;

	movementEnded = true;
	stoppedZooming = true;

	moveFrames = 0;
	zoomFrames = 0;
}

void Camera::goTo(sdl::Vector2Float& destination){
	if (!actualMapBounds.contains(destination))
		return;
	currentPosition = destination;
	this->destination = currentPosition;
}

void Camera::moveTo(sdl::Vector2Float& destination, float speed){
	if (!actualMapBounds.contains(destination))
		return;
	this->destination = destination;
	sdl::Vector2Float delta = this->destination - currentPosition;
	this->movement.x = delta.x / speed;
	this->movement.y = delta.y / speed;
	movementEnded = false;
	moveFrames = speed;
}
void Camera::zoomTo(sdl::Vector2Float& size, float speed){
	if (size.x > actualMapBounds.w || size.y > actualMapBounds.h){
		currentSize = sdl::Vector2Float(actualMapBounds.w, actualMapBounds.h);
		return;
	}
	if (size.x < 1280 || size.y < 720){
		currentSize = sdl::Vector2Float(1280, 720);
		return;
	}
	this->sizeDestination = size;
	sdl::Vector2Float delta = this->sizeDestination - currentSize;
	this->sizeMovement.x = delta.x / speed;
	this->sizeMovement.y = delta.y / speed;
	stoppedZooming = false;
	zoomFrames = speed;
}

void Camera::proceedZoom(int wheelDelta){
	if (wheelDelta < 0)
		zoomTo(currentSize * 1.1, 1);
	if (wheelDelta > 0)
		zoomTo(currentSize * 0.9, 1);
	std::cout << currentSize.x << ", " << currentSize.y;
}

void Camera::follow(Entity* entity){
	currentPosition = entity->getPosition();
}

sdl::View& Camera::getView(){
	return this->view;
}

void Camera::update(sdl::Window& target){
	if (moveFrames-- > 0 && !movementEnded)
		currentPosition += movement;
	else
		movementEnded = true;

	if (zoomFrames-- > 0 && !stoppedZooming)
		currentSize += sizeMovement;
	else
		stoppedZooming = true;

	if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT) && !dragged){
		dragOrigin = sdl::Mouse::getPosition(view);
		dragged = true;
	}
	if (dragged){
		sdl::Vector2Float offSet = dragOrigin - sdl::Mouse::getPosition(view);
		goTo(currentPosition + offSet);
	}
	if (sdl::Mouse::isButtonReleased(SDL_BUTTON_LEFT))
		dragged = false;

	
	if (currentPosition.x - view.getSize().x / 2 < left)
		currentPosition.x -= currentPosition.x - view.getSize().x / 2 + left;
	if (currentPosition.x + view.getSize().x / 2 > right)
		currentPosition.x -= currentPosition.x + view.getSize().x / 2 - right;
	if (currentPosition.y - view.getSize().y / 2 < top)
		currentPosition.y -= currentPosition.y - view.getSize().y / 2 + top;
	if (currentPosition.y + view.getSize().y / 2 > bottom)
		currentPosition.y -= currentPosition.y + view.getSize().y / 2 - bottom;

	view.setSize(currentSize);
	view.setCenter(currentPosition);
	target.setView(view);
}