#pragma once
#include<iostream>
#include<string>
#include "imgui_utils.hpp"
#include "ralentissante.hpp"
#include "explosive.hpp"


struct GameData;

class TowerRenderer
{
public:

	//Menu
	void DrawAnimation(GameData& data);
	void menuDisplay(GameData& data);
	void DrawMenu(GameData& data);
	void DrawEnd(GameData& data);

	// Game
	void drawEnemies(GameData& data);

	void drawMap(GameData& data);
	void HudInventory(GameData& data);
	void DrawPlacedTurret(GameData& data);
	void DrawHud(GameData& data);
	void DrawCheckPoint(GameData& data);

	void RendererGame(GameData& data);

	void ExplosiveTower(GameData& data, Explosive& explosive);
	void SlowingTower(GameData& data, Tower& slowing);

	TowerRenderer();
	~TowerRenderer();


protected:



private:



};

void DrawRangeTurret(GameData& data);
void TowerInInventoryHUD(GameData& data);
