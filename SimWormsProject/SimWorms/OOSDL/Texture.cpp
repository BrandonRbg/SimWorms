#include "Texture.h"


sdl::Texture::Texture(){
	changes = 0;
	surface = NULL;
	loaded = false;
}


sdl::Texture::~Texture()
{
	if (!loaded)
		return;
	if (surface == NULL)
		return;
	if (surface->format != NULL){
		SDL_FreeSurface(surface);
		surface = NULL;
		loaded = false;
	}
}

bool sdl::Texture::loadFromFile(const std::string &path)
{
	surface = IMG_Load(path.c_str());
	loaded = true;
	return !(surface == NULL);
}

sdl::Vector2Float sdl::Texture::getSize() {
	if (surface != NULL) 
		if(surface->format != NULL)
			return sdl::Vector2Float((float)surface->w, (float)surface->h);
	return sdl::Vector2Float(0, 0);
}

SDL_Surface* sdl::Texture::getSurface(){
	return this->surface;
}

sdl::Color sdl::Texture::getPixel(sdl::Vector2Float &pixel){
	if (pixel.x < 0 || pixel.x > surface->w)
		return sdl::Color(0, 0, 0, 0);
	if (pixel.y < 0 || pixel.y > surface->h)
		return sdl::Color(0, 0, 0, 0);

	int bytesPerPixel = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8*)surface->pixels + (int)pixel.y * surface->pitch + (int)pixel.x * bytesPerPixel;
	Uint32 actualColor = *(Uint32*)p;

	Uint8 r, g, b, a;
	SDL_GetRGBA(actualColor, surface->format, &r, &g, &b, &a);
	return sdl::Color(r, g, b, a);
}
void sdl::Texture::setPixel(sdl::Vector2Float &pixel, sdl::Color& color){
	changes++;
	Uint8 * pixels = (Uint8*)surface->pixels;
	pixels += ((int)pixel.y * surface->pitch) + ((int)pixel.x * sizeof(Uint32));
	Uint32 colorInt = SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a);
	*((Uint32*)pixels) = colorInt;
}

bool sdl::Texture::hasChanged(bool reset){
	bool changed = changes != 0;
	if (reset)
		changes = 0;
	return changed;
}