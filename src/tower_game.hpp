#pragma once
//#define MINIAUDIO_IMPLEMENTATION
#include <vector>
#include <fstream>
//#include <miniaudio.h>
#include "imgui_utils.hpp"
#include "data.hpp"
#include "map.hpp"
#include "tower_renderer.hpp"
#include "enemy_manager.hpp"
#include "player.hpp"
#include "Tower.hpp"
#include "level.hpp"
#include "wave.hpp"


using namespace std;



class TowerGame
{
public:


	void GameInit();

	void UpdateAndDraw();


	TowerGame();
	~TowerGame();
protected:

	GameData gameData;

	EnemyManager enemyManager;
	TowerRenderer renderer;

	Tower towerManger;


	
private:



};








