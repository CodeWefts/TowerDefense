#pragma once
#include "imgui_utils.hpp"

struct GameData;

class TowerRenderer
{
public:

	void drawEnemies(GameData& data);

	void drawMap(GameData& data);

	void RendererGame(GameData& data);

	TowerRenderer();
	~TowerRenderer();

private:

};