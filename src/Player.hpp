#pragma once
#include "imgui_utils.hpp"
#include "Tower.hpp"

struct GameData;




class Player
{
public:

	// player stats
	int coins = 9000000;
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

	void DrawTurretInfo(GameData& data, float x, float y, Tower* currentTower);
	void ShowTurretInfo(GameData& data);



	Player();
	~Player();

protected:



	

private:

};
