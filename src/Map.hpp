#pragma once
#include<iostream>
#include<vector>
#include"enemy.hpp"
#include"Tile.hpp"
#include "imgui_utils.hpp"


using namespace std;





enum PathNbr : int
{
	Path0 = 0,
	Path1,
	Path2
};






class MapClass
{
public:



	float Tilesize;




	std::string map;
	int Height;
	int Width;
	float2 origin;
	vector<Tile> Tiles;

	void CreateMap();
	MapClass();
	~MapClass();

private:
	ImGuiIO* io;
};





float2 ReturnTileMax(int indexX, int indexY, MapClass& map);
float2 ReturnTileMin(int indexX, int indexY, MapClass& map);
float2 ReturnPosfromChar(char c, MapClass& map);
float2 ReturnCenter(const float2& Max, const float2& Min);
float2 ReturnCenterTile(int indexX, int indexY, MapClass& map);





int  ReturnTileIndexX(int x, MapClass& map);
int  ReturnTileIndexY(int y, MapClass& map);
int  ReturnIndexIncharMap(int x, int y, MapClass& map);

