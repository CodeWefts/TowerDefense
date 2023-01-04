#pragma once
#include "imgui_utils.hpp"
#include"Map.hpp"
#include"TowerRenderer.hpp"
#include"Player.hpp"

using namespace std;

struct GameData
{
	bool enableDebug;
	float acceleRateTime;





	Map map;
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

