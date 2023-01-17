#pragma once
#include<iostream>
#include<string>
#include "imgui_utils.hpp"
#include "ralentissante.hpp"


/*

struct Particle
{
	float2 pos;
	// color velocity etc...
	void Draw();
};

*/

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



	void SlowingTower(GameData& data, Tower& Slowing);

	/*
		void SpawnExplosionParticles(float2 pos)
	{
		for (int i = 0; i < 64; ++i)
		{
			float2 randPos;
			float2 randVel;
			float lifetime = 2.f;
			particles.push_back(Particle(randPos, randVel, lifetime));
		}
	}

	
	*/


	TowerRenderer();
	~TowerRenderer();


protected:

//	std::vector<Particle> particles;

private:



};

void DrawRangeTurret(GameData& data);
void TowerInInventoryHUD(GameData& data);
