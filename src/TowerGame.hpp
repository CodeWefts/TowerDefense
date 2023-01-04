#pragma once
#include "imgui_utils.hpp"
#include"Map.hpp"
#include"TowerRenderer.hpp"
#include"Player.hpp"

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




	Asset asset;
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

