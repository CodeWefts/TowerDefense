#pragma once
#include<vector>
#include "imgui_utils.hpp"
#include"Map.hpp"
#include"TowerRenderer.hpp"
#include"EnemyManager.hpp"
#include"Player.hpp"
#include"soigneur.hpp"


using namespace std;

struct Asset
{
	Texture textureDirt , textureGrass, texturePathBottom, texturePathBottomANDLeft, texturePathBottomANDRight, texturePathBottomLeft, texturePathBottomRight,
		texturePathLeft, texturePathRight , texturePathTop, texturePathTopANDLeft, texturePathTopANDRight, texturePathTopLeft, texturePathTopRight, textureCostaud,
		textureGringalet, textureSoigneur;

	Asset();
	
};

struct GameData
{
	bool enableDebug;
	float acceleRateTime;
	float deltatime;

	vector<enemy> enemyVector;
	Asset asset;
	Map map;
	Player player;
	


	GameData();

};




class TowerGame
{
public:

	GameData gameData;
	EnemyManager enemyManager;

	void GameInit();

	void UpdateAndDraw();


	TowerGame();
	~TowerGame();

private:

	TowerRenderer renderer;
	

};

