#include "StaticText.h"


void sdl::StaticText::draw(SDL_Renderer* renderer, sdl::View &view){
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_Rect destination = { position.x, position.y, getBounds().w, getBounds().h };
	SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
	SDL_RenderCopyEx(renderer, tmpTexture, NULL, &destination, orientation, &destinationOrigin, flipSide);
	SDL_DestroyTexture(tmpTexture);
}
