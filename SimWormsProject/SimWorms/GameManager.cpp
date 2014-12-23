#include "GameManager.h"

GameManager::GameManager() {
	turn = 0;
	paused = false;

	canPlayersSpawn = false;
	started = false;

	turnText.setFont("data/fonts/Arial.ttf");
	turnText.setPosition(1240, 10);
	turnText.setCharacterSize(30);
	turnText.setColor(sdl::Color::White);
	turnText.setString("");

	movesText.setFont("data/fonts/Arial.ttf");
	movesText.setPosition(700, 10);
	movesText.setCharacterSize(30);
	movesText.setColor(sdl::Color::White);
	movesText.setString("");
	
}

void GameManager::startGame(std::vector<Team> teams) {
	reset();
	this->teams = teams;
	std::default_random_engine engine(time(0));
	std::uniform_int_distribution<int> dist(15, MapManager::getInstance().getActualMap()->getBounds().w - 15);
	for (int i = 0; i < MapManager::getInstance().getActualMap()->landMinesCount; i++) {
		EntityManager::getInstance().addEntity(new Mine(sdl::Vector2Float(dist(engine), 0)));
	}
}

void GameManager::update(sdl::Window& renderWindow, Camera* cam, Map* actualMap, float frametime, int weapon) {
	
	std::default_random_engine engine(time(0));
	std::uniform_int_distribution<int> dist(15, MapManager::getInstance().getActualMap()->getBounds().w - 15);

	if (!started && !canPlayersSpawn){
		for (auto& mine : EntityManager::getInstance().getEntities()){
			Mine* tmp = dynamic_cast<Mine*>(mine);
			if (tmp != 0){
				canPlayersSpawn = tmp->isOnGround;
			}
		}
	}

	if (!started && canPlayersSpawn){
		for (int i = 0; i < 4; i++) {
			for (auto team : teams){
				Player* tmp = new Player(sdl::Vector2Float(dist(engine), 0), teams.size() * i + team.getId(), team);
				EntityManager::getInstance().addEntity(tmp);
				players.push_back(tmp);
			}
		}
		started = true;
	}
	if (started){
		while (actualPlayer == nullptr)
		{
  			if (turn < players.size()){
				turn++;
			}
			else
				turn = 0;
			actualPlayer = players[turn];
		}
		if (actualPlayer != nullptr){
			
			if (weapon == 1){
				actualPlayer->useRocket();
			}
			if (weapon == 2){
				actualPlayer->useGrenade();
			}
			if (weapon == 3){
				actualPlayer->useMelee();
			}
			if (weapon == 4){
				actualPlayer->useJetpack();
			}
		
			if (actualPlayer->hasFinishedTurn()){
				actualPlayer->resetTurn();
				actualPlayer->resetState();
				actualPlayer = nullptr;
				turn++;
				turnClock.restart();
			}
			else if (turnClock.getElapsedTime().asSeconds() >= 60){
				turnClock.restart();
				actualPlayer->resetTurn();
				actualPlayer->resetState();
				actualPlayer = nullptr;
				turn++;
			}
		}

		if (turn >= teams.size() * 4)
			turn++;
		std::cout << turn << std::endl;
	}

	std::stringstream ss;
	ss << "Time left: " << int(60 - turnClock.getElapsedTime().asSeconds());
	turnText.setString(ss.str());
	ss.str("");
	if (actualPlayer != nullptr){
		ss << "Moves left: " << int(100 - actualPlayer->getMoves());
		movesText.setString(ss.str());
	}
}


	void GameManager::draw(sdl::Window &target){
		target.draw(&movesText);
		target.draw(&turnText);
	}

	int GameManager::getActualTurn() {
		return this->turn;
	}

	void GameManager::setActualTurn(int turn) {
		this->turn = turn;
		turnClock.restart();
		MapManager::getInstance().getActualMap()->updateWindForce();
	}

	void GameManager::reset(){
		EntityManager::getInstance().clear();
		turn = 0;
		started = false;
		canPlayersSpawn = false;
	}