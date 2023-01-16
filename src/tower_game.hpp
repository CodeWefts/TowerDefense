#pragma once
#include<vector>
#include<fstream>
#include "imgui_utils.hpp"

#include "map.hpp"
#include "tower_renderer.hpp"
#include "enemy_manager.hpp"
#include "player.hpp"
#include "Tower.hpp"

#include"Healer.hpp"

#define EndOfVector '$'

#define TimerLevel 20.f
#define TimerWave 15.f
#define nbrOfLevel 5
#define NbrOfRoad 3



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



	Asset();
	

};

enum Scene  : int
{
	Menu,
	Option,
	Game,

};





struct GameData
{

	bool addEnemy;
	bool enableDebug;
	bool playerStopTime;


	int acceleRateTimeBuffer;
	int acceleRateTime;
	float deltatime;

	int currentScene;
	int currentLevel;
	int currentWave;
	float timerWave;
	float timerLevel;


	vector<float2> listOfRoad[NbrOfRoad];


	vector<Tower*> towerVector;
	vector<enemy*> enemyVector;

	Asset asset;
	MapClass map;
	Player player;

	ImGuiIO& io = ImGui::GetIO();
	ImDrawList* dl;
	//ImFont* font;

	Level level[nbrOfLevel];

	GameData();
	~GameData();

};


class TowerGame
{
public:


	void GameInit();
	void Debug();

	void UpdateAndDraw();



	TowerGame();
	~TowerGame();
protected:

	GameData gameData;

	EnemyManager enemyManager;
	TowerRenderer renderer;


	
private:



};








