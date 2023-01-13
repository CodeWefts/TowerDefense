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


	// power
	int power;
	
	// tower
	int typeTower;






	void PlayerTile(GameData& gamedata);
	void PlayerInput(GameData& gamedata);
	void DragAndDrop(GameData& gamedata);

	Player();
	~Player();

private:

};

//void DrawTower(ImTextureID textureID, float Min, float Max);
