#pragma once
#include "imgui_utils.hpp"

struct GameData;

class TowerRenderer
{
public:





	ImDrawList* dl;

	void drawEnemies(GameData& data);

	void drawMap(GameData& data);

	void RendererGame(GameData& data);

	TowerRenderer();
	~TowerRenderer();

private:

};