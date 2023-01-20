#pragma once
#include "imgui_utils.hpp"
#include "Tower.hpp"

struct GameData;



#define maxAcelerateTime 4
class Player
{

private:
	// tower
	int typeTower;
public:

	// player stats
	int coins = 100;
	int score;
	int wave;
	int health;
	int maxHealth;

	



	void UpdatePlayer(GameData& data);
	void PlayerTile(GameData& data);
	void PlayerInput(GameData& data);
	void DragAndDrop(GameData& data);

	void DrawTurretInfo(GameData& data, float x, float y, Tower* currentTower);
	void ShowTurretInfo(GameData& data);

	void ShowOption(GameData& data);



	Player();
	~Player();

protected:



	

private:

};
