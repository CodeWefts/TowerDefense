#pragma once
#include<iostream>
#include<vector>
#include"Tile.hpp"
#include "imgui_utils.hpp"


class Map
{
public:

	ImGuiIO* io;

	void ManageMap( std::vector<Tile>& Tiles);
	Map();
	~Map();

private:

};

