#pragma once
#include<iostream>
#include<vector>
#include"Tile.hpp"
#include "imgui_utils.hpp"


class Map
{
public:

	ImGuiIO* io;

	int Width;
	int Height;
	std::vector<Tile> Tiles;

	void CreateMap();
	Map();
	~Map();

private:

};

