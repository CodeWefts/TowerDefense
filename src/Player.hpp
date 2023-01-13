#pragma once
#include "imgui_utils.hpp"

struct GameData;


class Player
{
public:

	// player stats
	int coins;
	int score;
	int wave;
	int health;
	int maxHealth;


	// power
	int power;
	
	// tower
	int tower;




	void PlayerTile(GameData& gamedata);

	void PlayerInput(GameData& gamedata);

	Player();
	~Player();

private:

};

/*Player::Player()
{
}

Player::~Player()
{
}*/


enum class Power : int
{

};


enum class Tower : int
{
	Classique,
	Ralentissante,
	Explosive,
};


