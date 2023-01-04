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


	vector<enemy> enemyVector;
	//vector<int> intvector;
	Asset asset;
	Map map;
	Player player;
	EnemyManager enemyManager;


	GameData();

};




class TowerGame
{
public:

	GameData gameData;

	void GameInit();

	void UpdateAndDraw();


	TowerGame();
	~TowerGame();

private:

	TowerRenderer renderer;
	

};

