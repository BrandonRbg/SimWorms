#include "Window.h"

int sdl::Window::instances = 0;

sdl::Window::Window(float x, float y, const std::string& title) {
	++instances;
	if (instances == 1)
		SDL_Init(SDL_INIT_VIDEO);
	isWindowOpen = true;

	this->size.x = x;
	this->size.y = y;
	this->windowID = SDL_GetWindowID(this->sdlWindow);
	sdlWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)size.x, (int)size.y, 0);
	sdlRender = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	this->setTitle(title);
	this->view = sdl::View(sdl::Vector2Float(this->size.x / 2, this->size.y / 2), sdl::Vector2Float(this->size.x, this->size.y));
}

sdl::Window::~Window()
{
	SDL_DestroyRenderer(this->sdlRender);
	SDL_DestroyWindow(this->sdlWindow);

	SDL_DestroyRenderer(sdlRender);
	SDL_DestroyWindow(sdlWindow);

	--instances;
	if (instances == 0)
		SDL_Quit();
}

void sdl::Window::show(){
	SDL_RenderPresent(sdlRender);
}

void sdl::Window::clear(){
	SDL_RenderClear(sdlRender);
	drawables.clear();
}

void sdl::Window::clear(sdl::Color& color){
	SDL_SetRenderDrawColor(sdlRender, color.r, color.g, color.b, color.a);
	SDL_RenderClear(sdlRender);
	drawables.clear();
}

void sdl::Window::setTitle(const std::string& title){
	this->title = title;
	SDL_SetWindowTitle(sdlWindow, title.c_str());
}

void sdl::Window::draw(sdl::Drawable* drawable){
	this->drawables.push_back(drawable);
	drawable->draw(sdlRender, this->view);
}

SDL_Renderer* sdl::Window::getRenderer(){
	return sdlRender;
}

void sdl::Window::setView(sdl::View &view){
	this->view = view;
	SDL_Rect viewport = { (int)view.getViewport().x, (int)view.getViewport().y, (int)view.getViewport().w, (int)view.getViewport().h };
	SDL_RenderSetViewport(this->sdlRender, &viewport);
}

sdl::View sdl::Window::getDefaultView(){
	return sdl::View(sdl::Vector2Float(this->size.x / 2, this->size.y / 2), sdl::Vector2Float(this->size.x, this->size.y));
}
bool sdl::Window::pollEvent(sdl::Event &event){
	SDL_Event* sdlEvent = new SDL_Event();
	while (SDL_PollEvent(sdlEvent)){
		event.type = sdlEvent->type;
		if (sdlEvent->type == SDL_WINDOWEVENT)
			if (sdlEvent->type == SDL_WINDOWEVENT_CLOSE)
				std::cout << "Allo";
		if (sdlEvent->type == SDL_KEYDOWN){
			sdl::Keyboard::updateKeyState(sdlEvent->key.keysym.sym, true);
			event.keycode = sdlEvent->key.keysym.sym;
		}
		if (sdlEvent->type == SDL_KEYUP){
			sdl::Keyboard::updateKeyState(sdlEvent->key.keysym.sym, false);
			event.keycode = sdlEvent->key.keysym.sym;
		}
		if (sdlEvent->type == SDL_MOUSEBUTTONDOWN){
			sdl::Mouse::updateMouseButtonState(sdlEvent->button.button, true);
			event.button = sdlEvent->button.button;
		}
		if (sdlEvent->type == SDL_MOUSEBUTTONUP){
			sdl::Mouse::updateMouseButtonState(sdlEvent->button.button, false);
			event.button = sdlEvent->button.button;
		}
		if (sdlEvent->type == SDL_MOUSEMOTION)
			sdl::Mouse::updateMousePosition(sdlEvent->motion.x, sdlEvent->motion.y);
	} delete sdlEvent;
	return false;
}

sdl::View sdl::Window::getView(){
	return this->view;
}

bool sdl::Window::isOpen(){
	if (isWindowOpen)
		return true;
	return false;
}

void sdl::Window::close(){
	isWindowOpen = false;
}