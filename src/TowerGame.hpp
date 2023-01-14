#pragma once
#include<vector>
#include "imgui_utils.hpp"
//#include"raylib/src/raylib.h"

#include "Map.hpp"
#include "TowerRenderer.hpp"
#include "EnemyManager.hpp"
#include "Player.hpp"
#include "Tower.hpp"

#include"soigneur.hpp"


#define TimerLevel 20.f
#define TimerWave 15.f
#define nbrOfLevel 5



#define TypeOfEnemy 3

using namespace std;

struct Asset
{
	
	
	Texture textureDirt, textureGrass, texturePathBottom, texturePathBottomANDLeft, texturePathBottomANDRight, texturePathBottomLeft, texturePathBottomRight,
		texturePathLeft, texturePathRight, texturePathTop, texturePathTopANDLeft, texturePathTopANDRight, texturePathTopLeft, texturePathTopRight,

		//texture ennemy COSTAUD
		textureCostaud1, textureCostaud2, textureCostaud3, textureCostaud4, textureCostaud5, textureCostaud6, textureCostaud7, textureCostaud8, textureCostaud9,
		textureCostaud10, textureCostaud11, textureCostaud12,

		textureTower,

		PlayerHeart,
		//texture ennemy GRINGALET
		textureGringalet,

		//texture ennemy SOIGNEUR
		textureSoigneur,

		//texture tower TOWER
		textureTowerClassique, textureTowerRalentissante, textureTowerExplosive,


		//texture hud INVENTORY TOWER
		textureTowerSideLeft, textureTowerSideRight, textureTowerCase,

		textureAnimation;


	//Sound SoundTest;

	Asset();
	
};







struct GameData
{
	
	bool addEnemy;
	bool WaveStart;
	bool enableDebug;
	bool playerStopTime;


	int acceleRateTimeBuffer;
	int acceleRateTime;
	float deltatime;

	int currentLevel;
	int currentWave;
	float timerWave;
	float timerLevel;
	

	vector<float2> listOfRoad[3];
	
	
	vector<Tower*> towerVector;
	vector<enemy*> enemyVector;

	Asset asset;
	Map map;
	Player player;

	ImGuiIO& io = ImGui::GetIO();
	ImDrawList* dl;
	ImFont* font;
	
	Level level[nbrOfLevel];

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








