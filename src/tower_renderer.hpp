#pragma once
#include<iostream>
#include<string>
#include "imgui_utils.hpp"
#include "ralentissante.hpp"
#include "explosive.hpp"
#include "renderer_player.hpp"
#include "renderer_entity.hpp"



struct GameData;

class TowerRenderer
{
public:


	RendererPlayer rendererPlayer;
	RendererEntity renderEntity;

	//Menu
	void DrawAnimation(GameData& data);
	void MenuDisplay(GameData& data);
	void DrawMenu(GameData& data);
	void DrawEnd(GameData& data);

	void DrawMap(GameData& data);

	void DrawLevelsMap(GameData& data);


	// Draw Player Hud
	void DrawCheckPoint(GameData& data);

	// Main Loop for Rendering
	void RendererGame(GameData& data);
	

	TowerRenderer();
	~TowerRenderer();


protected:



private:



};

void DrawRangeTurret(GameData& data);
void TowerInInventoryHUD(GameData& data);
