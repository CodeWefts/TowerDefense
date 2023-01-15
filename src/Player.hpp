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
	int typeTower;


	void PlayerTile(GameData& gamedata);
	void PlayerInput(GameData& gamedata);
	void DragAndDrop(GameData& gamedata);



	Player();
	~Player();

protected:



	

private:

};

//void DrawTower(ImTextureID textureID, float Min, float Max);
