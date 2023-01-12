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







struct GameData
{
	bool addEnemy;
	bool WaveStart;
	bool enableDebug;
	bool playerStopTime;
	int currentWave;


	int acceleRateTimeBuffer;
	int acceleRateTime;
	float deltatime;




	vector<enemy*> enemyVector;
	Asset asset;
	Map map;
	Player player;

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


	
private :

	

};








