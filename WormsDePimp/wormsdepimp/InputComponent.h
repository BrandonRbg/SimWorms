#pragma once 
class Player;
class InputComponent{
public:
	virtual void update(Player &player) = 0;
};