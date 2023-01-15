#pragma once
#include "imgui_utils.hpp"
#include <iostream>

struct GameData;

enum TowerChoice : int
{
	CLASSIQUE,
	RALENTISSANTE,
	EXPLOSIVE,
};

class Tower
{
public:

	std::string name;
	Texture texture;

	int type;
	int cost;
	bool placed;

	int TileX, TileY;
	int range;


	Tower();
	~Tower();
	//functions
};

