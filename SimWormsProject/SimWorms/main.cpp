#include "GameManager.h"

int main(int argc, char** argv){
	srand(time(0));
	SDL_StartTextInput();
	sdl::Window renderWindow(sdl::VideoMode(1280, 1024), "SimWorms", false);
	GameOptionsManager::getInstance().update(renderWindow);
	GameManager::getInstance().startGame(2);

	MapManager::getInstance().loadMapsFromFolder("data/maps");
	Map actualMap = MapManager::getInstance().getActualMap();

	Camera cam(renderWindow, actualMap);

	//PhysicsPixel pixel(sdl::Color::Black, sdl::Vector2Float(100, 100), sdl::Vector2Float(0, 0));


	//GuiMainMenu Game;
	//GuiTextBox Text;
	//Player player(sdl::Vector2Float(800,200));
	//view.setCenter(player.getPosition());

	sdl::StaticText fpsText;
	fpsText.setFont("data/fonts/Arial.ttf");
	fpsText.setPosition(10, 10);
	fpsText.setCharacterSize(16);
	fpsText.setColor(sdl::Color::Black);
	fpsText.setString("");

	sdl::Clock fpsClock;
	sdl::Clock fpsDisplayUpdateClock;

	//EntityManager::getInstance().addEntity(new Player(sdl::Vector2Float(800, 200), 0, 0));

	sdl::Clock runclock;
	while (renderWindow.isOpen()){
		GameManager::getInstance().update(renderWindow, cam, fpsText, actualMap, fpsClock, fpsDisplayUpdateClock);
	}
	SDL_StopTextInput();
	return 0;
}