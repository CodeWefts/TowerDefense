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

	//TowerChoice choice = CLASSIQUE;
	//ImTextureID textureID = nullptr;

	std::string name;
	Texture texture;

	//functions
};

