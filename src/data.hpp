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

#include <miniaudio.h>
#include "audioEngine.hpp"





#define TimerLevel 7.f
#define TimerWave 5.f
#define nbrOfLevel 4
#define NbrOfRoad 4



#define TypeOfEnemy 3

struct Asset
{


	Texture textureDirt, textureGrass, texturePathBottom, texturePathBottomANDLeft, texturePathBottomANDRight, texturePathBottomLeft, texturePathBottomRight,
		texturePathLeft, texturePathRight, texturePathTop, texturePathTopANDLeft, texturePathTopANDRight, texturePathTopLeft, texturePathTopRight, texturePathAroundUp,
		texturePathAroundDown, texturePathUpANDDown, texturePathLeftANDRight,

		//texture ennemy COSTAUD
		textureNightBorne,

		PlayerHeart,
		//texture ennemy GRINGALET
		textureCanineWhite,

		//texture ennemy SOIGNEUR
		textureSoigneur,

		//texture tower TOWER
		textureTowerClassique, textureTowerClassicalBase, textureTowerClassicalCanon,

		// texture tower Slowing
		texureSlowing,

		// texture tower Explosive
		textureTowerExplosive,

		//texture hud || INVENTORY TOWER
		textureTowerSideLeft, textureTowerSideRight, textureTowerCase, textureUpgradeButton,

		textureAnimation, textureMenuHUD, textureBackGround, texturePlay, textureLevels, textureSettings,

		textureCoin, textureButton, textureOption, textureMenuButton,

		//texture Levels
		textureMap, textureLevelNotFinish,

		//texture Game's END
		textureEndBackGround, textureEndWin, textureEndOkButton, textureEndLose ;
		


	Asset();


};

enum Scene : int
{
	Menu,
	Option,
	Levels,
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
	float time = 0.f;
	int transparence = 0;

	ImVec2 posAnimationMin = { 56, 305 }; // y - 255 = 50
	ImVec2 posAnimationMax = { 1296 - 56,720 - 305 }; // y + 255 =  720 - (305 + 256)

	ImVec2 minEnd = { 476.5,171 };
	ImVec2 maxEnd = { 819.5, 549 };

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
	
	ma_result result;
	ma_engine engine;

	GameData();
	~GameData();

};

void ChangeLevel(GameData& data);
void SaveAllPath(GameData& data);
void LoadALLPath(GameData& data);
void Debug(GameData& data);

