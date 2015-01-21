#include "Compass.h"
#include "AssetsManager.h"
#include <random>
#include <sstream>

Compass::Compass(){
	actualWind = sdl::Vector2Float();
	windModule = actualWind.getModule();
	ring1.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ring1.png"));
	ring1.setOrigin(ring1.getBounds().w / 2, ring1.getBounds().h / 2);
	ring1.setPosition(sdl::Vector2Float(1500, 30));
	ring2.setTexture(&AssetsManager::getInstance().getTexture("data/textures/ring2.png"));
	ring2.setOrigin(ring2.getBounds().w / 2, ring2.getBounds().h / 2);
	ring2.setPosition(sdl::Vector2Float(1615, 70));
	arrow.setTexture(&AssetsManager::getInstance().getTexture("data/textures/compassArrow.png"));
	arrow.setOrigin(arrow.getBounds().w / 2, arrow.getBounds().h / 2);
	arrow.setPosition(sdl::Vector2Float(1500, 30));
	blur.setTexture(&AssetsManager::getInstance().getTexture("data/textures/blur.png"));
	blur.setOrigin(blur.getBounds().w / 2, blur.getBounds().h / 2);
	blur.setPosition(sdl::Vector2Float(1450, 30));
	windSpeed.setFont("data/fonts/BMSpace.ttf");
	windSpeed.setOrigin(windSpeed.getBounds().w / 2, windSpeed.getBounds().h / 2);
	windSpeed.setPosition(sdl::Vector2Float(1675, 150));

}

void Compass::setWind(sdl::Vector2Float& wind){
	actualWind = wind;
	windModule = wind.getModule();
	std::stringstream ss;
	ss << int(windModule) << " p/s";
	windSpeed.setString(ss.str());
}

void Compass::update(float frametime){
	arrow.setRotation(225 + radToDeg(atan(actualWind.y / actualWind.x)));
	if (rotateClock.getElapsedTime().asSeconds() > 5){
		std::default_random_engine engine(time(0));
		std::uniform_int_distribution<int> dist(-10, 10);
		ring1.rotate(dist(engine) * frametime);
	}
	ring2.rotate(5 * frametime);
}

void Compass::draw(sdl::Window &target){
	
	target.draw(&ring1);
	target.draw(&ring2);
	target.draw(&arrow);
	target.draw(&blur);
	target.draw(&windSpeed);
}