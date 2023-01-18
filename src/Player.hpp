#pragma once
#include "imgui_utils.hpp"

struct GameData;


class Player
{
public:

	// player stats
	int coins = 100;
	int score;
	int wave;
	int health;
	int maxHealth;


	// power
	int power;

	// tower
	int typeTower;



	void UpdatePlayer(GameData& gamedata);
	void PlayerTile(GameData& gamedata);
	void PlayerInput(GameData& gamedata);
	void DragAndDrop(GameData& gamedata);



	Player();
	~Player();

protected:



	

private:

};
