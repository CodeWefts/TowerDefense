#pragma once
#include "imgui_utils.hpp"

struct GameData;

class TowerRenderer
{
public:





	ImDrawList* dl;



	void RendererGame(GameData& data);

	TowerRenderer();
	~TowerRenderer();

private:

};