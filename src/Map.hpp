#pragma once
#include<iostream>
#include<vector>
#include"enemy.hpp"
#include"Tile.hpp"
#include "imgui_utils.hpp"


struct GameData;
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

	string map;

	string mapLvl1;
	string mapLvl2;
	string mapLvl3;
	string mapLvl4;


	int Height;
	int Width;
	float2 origin;
	vector<Tile> Tiles;

	void LoadMap(string& newMap);
	void CreateMap(GameData& data);
	MapClass();
	~MapClass();

private:

};


float2 ReturnTileMax(int indexX, int indexY, MapClass& map);
float2 ReturnTileMin(int indexX, int indexY, MapClass& map);
float2 ReturnPosfromChar(char c, MapClass& map);
float2 ReturnCenter(float2 Max, float2 Min);
float2 ReturnCenterTile(int indexX, int indexY, MapClass& map);

bool IsPlaceAble(GameData& data, const float2& pos);
int  ReturnTileIndexX(int x, MapClass& map);
int  ReturnTileIndexY(int y, MapClass& map);
int  ReturnIndexIncharMap(int x, int y, MapClass& map);

