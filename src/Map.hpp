#pragma once
#include<iostream>
#include<vector>
#include"enemy.hpp"
#include"Tile.hpp"
#include "imgui_utils.hpp"


using namespace std;









class Map
{
public:

	ImGuiIO* io;

	float Tilesize;
	
	
	
	
	std::string map;
	 int Height;
	 int Width;
	 float2 origin;
	vector<Tile> Tiles;

	void CreateMap();
	Map();
	~Map();

private:

};

	float2 ReturnTileMax(int indexX, int indexY, Map& map);
	float2 ReturnTileMin(int indexX, int indexY, Map& map);
	float2 ReturnCenter(int indexX, int indexY, Map& map);
	float2 ReturnPosfromChar(char c, Map& map);
	float2 ReturnCheckPointNearbest(Map& map, enemy* currentenemy);



	int  ReturnTileIndexX(int x, Map& map);
	int  ReturnTileIndexY(int y, Map& map);
	int  ReturnIndexIncharMap(int x, int y, Map& map);


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
