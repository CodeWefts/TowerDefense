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
		texturePathLeft, texturePathRight , texturePathTop, texturePathTopANDLeft, texturePathTopANDRight, texturePathTopLeft, texturePathTopRight,

		textureCostaud1, textureCostaud2, textureCostaud3, textureCostaud4, textureCostaud5, textureCostaud6, textureCostaud7, textureCostaud8, textureCostaud9,
		textureCostaud10, textureCostaud11, textureCostaud12,

		textureGringalet, textureSoigneur,
		
		textureTower,
		
		textureTowerSideLeft, textureTowerSideRight, textureTowerCase;

	Asset();
	
};


enum Wave : int
{
	Wave1 = 1,
	Wave2,
	Wave3,
	Wave4,
	Wave5,
	Wave6,
	Wave7,
	Wave8,
	Wave9,
};




struct GameData
{
	bool addEnemy;
	bool WaveStart;
	bool enableDebug;
	int currentWave;
	float acceleRateTime;
	float deltatime;




	vector<enemy*> enemyVector;
	Asset asset;
	Map map;
	//Hud hud;
	Player player;

	//Wave waveEnenum;
	ImGuiIO* io;
	ImDrawList* dl;


	float timerWave;

	GameData();

};


class TowerGame
{
public:
	GameData gameData;

	EnemyManager enemyManager;
	TowerRenderer renderer;

	void GameInit();
	void Debug();

	void UpdateAndDraw();


	TowerGame();
	~TowerGame();

	
	

};








