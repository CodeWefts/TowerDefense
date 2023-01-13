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

enum CaseOfTile : int
{
	UpRight = 1,
	UpLeft ,
	DownRight ,
	DownLeft,

};




	float2 ReturnCaseofTile(const int& nbr, const int& indexX, const int& indexY , Map& map);
	float2 ReturnTileMax(int indexX, int indexY, Map& map);
	float2 ReturnTileMin(int indexX, int indexY, Map& map);
	float2 ReturnCenterFromTile(int indexX, int indexY,enemy& enemy, Map& map);
	float2 ReturnPosfromChar(char c, Map& map);
	float2 ReturnCheckPointNearbest(Map& map, enemy* currentenemy);
	float2 ReturnCenter(const float2& Max, const float2& Min);
	float2 ReturnCenterTile(int indexX, int indexY, Map& map);





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
