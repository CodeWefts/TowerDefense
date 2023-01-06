#pragma once
#include<iostream>
#include<vector>
#include"Tile.hpp"
#include "imgui_utils.hpp"


class Map
{
public:

	ImGuiIO* io;

	float Tilesize;
	 
	 int Height;
	 int Width;
	std::vector<Tile> Tiles;

	void CreateMap();
	Map();
	~Map();

private:

};

/*class Hud
{
public:

	ImGuiIO* io;

	float Tilesize;

	int Height;
	int Width;
	std::vector<Tile> Tiles;

	Hud();
	~Hud();

private:

};*/
