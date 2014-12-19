#include "GameManager.h"

int main(int argc, char** argv){
	srand(time(0));
	SDL_StartTextInput();
	sdl::Window renderWindow(sdl::VideoMode(1280, 1024), "SimWorms", false);
	GameOptionsManager::getInstance().update(renderWindow);
	GameManager::getInstance().startGame(2);

	MapManager::getInstance().loadMapsFromFolder("data/maps");
	Map actualMap = MapManager::getInstance().getActualMap();

	Camera cam(renderWindow, &actualMap);

	//PhysicsPixel pixel(sdl::Color::Black, sdl::Vector2Float(100, 100), sdl::Vector2Float(0, 0));

	//GuiTextBox Text;
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
		float frametime = fpsClock.restart().asSeconds();
		int fps = (int)(1 / frametime);

		GameManager::getInstance().update(renderWindow, &cam, &actualMap, frametime);

		if (fpsDisplayUpdateClock.getElapsedTime().asSeconds() > 0.2) {
			std::stringstream ss;
			ss << "SimWorms v0.0.1" << " @ " << fps << " fps";
			fpsText.setString(ss.str());
			fpsDisplayUpdateClock.restart();
		}

		renderWindow.draw(&fpsText);

		renderWindow.show();
	}
	SDL_StopTextInput();
	return 0;
}