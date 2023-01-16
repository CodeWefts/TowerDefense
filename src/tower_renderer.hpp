#pragma once
#include<iostream>
#include<string>
#include "imgui_utils.hpp"


struct GameData;

class TowerRenderer
{
public:


	//Menu
	void DrawMenu(GameData& data);



	// Game
	void drawEnemies(GameData& data);

	void drawMap(GameData& data);
	void HudInventory(GameData& data);
	void DrawPlacedTurret(GameData& data);
	void DrawHud(GameData& data);
	void DrawCheckPoint(GameData& data);

	void RendererGame(GameData& data);
	TowerRenderer();
	~TowerRenderer();


protected:



private:



};


void TowerInInventoryHUD(GameData& data);
