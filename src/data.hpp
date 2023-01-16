#pragma once
#include<vector>
#include<fstream>
#include "imgui_utils.hpp"

#include "map.hpp"
#include "tower_renderer.hpp"
#include "enemy_manager.hpp"
#include "player.hpp"
#include "Tower.hpp"
#include "level.hpp"
#include "wave.hpp"
#include "calc.hpp"


#define EndOfVector '$'

#define TimerLevel 20.f
#define TimerWave 15.f
#define nbrOfLevel 5
#define NbrOfRoad 4



#define TypeOfEnemy 3

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

		textureAnimation, textureMenuHUD;



	Asset();


};

enum Scene : int
{
	Menu,
	Option,
	Game,
	GameOver

};





struct GameData
{

	bool addEnemy;
	bool enableDebug;
	bool playerStopTime;
	bool changeLevel;

	int acceleRateTimeBuffer;
	int acceleRateTime;
	float deltatime;

	int currentScene;
	int currentLevel;
	int currentWave;
	float timerWave;
	float timerLevel;
		
	float transparenceTime = 0.f;
	float time = 0.f, timeMove = 2.f;
	int transparence = 0;

	ImVec2 posAnimationMin = { 56, 305 }; // y - 255 = 50
	ImVec2 posAnimationMax = { 1296 - 56,720 - 305 }; // y + 255 =  720 - (305 + 256)

	vector<float2> listOfRoad[NbrOfRoad];


	vector<Tower*> towerVector;
	vector<Enemy*> enemyVector;

	Asset asset;
	MapClass map;
	Player player;

	ImGuiIO& io = ImGui::GetIO();
	ImDrawList* dl;

	ImFont* font;

	vector<Level> levels;

	GameData();
	~GameData();

};


void SaveAllPath(GameData& data);
void LoadALLPath(GameData& data);
void Debug(GameData& gameData);

