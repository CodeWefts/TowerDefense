#include<iostream>
#include "data.hpp"
#include"Map.hpp"
#include"calc.hpp"
#include "imgui_utils.hpp"
#include"enemy.hpp"


#define mapWidth 18
#define mapHeight 10



void MapClass::LoadMap(string& newMap)
{

	for (int y = 0; y < mapHeight; ++y)
	{
		for (int x = 0; x < mapWidth; ++x)
		{
			int idx = ReturnIndexIncharMap(x, y, *this);

			if (Tiles.size() != mapHeight * mapWidth)
			{
				Tile tile;
				tile.Texture_type = newMap[idx];
				Tiles.push_back(tile);
			}
			else
			{
				Tiles.at(idx).Texture_type = newMap[idx];
			}
		}
	}
}


void MapClass::CreateMap(GameData& data)
{
	if (data.currentLevel == 0)
	{
		map =
			"                  "
			"  *________+      "
			"  /pppppppp|      "
			"  /pt----!p|      "
			"  /p|    /p|      "
			"__jp|    /p|      "
			"pppp|    /pl______"
			"----,    /pppppppp"
			"         ;--------"
			"                  ";
		LoadMap(map);

	}
	else if (data.currentLevel == 1)
	{

		map  =
			"                  "
			"      *___________"
			"      /ppppppppppp"
			"      /pt-=====---"
			"      /p|/ppppp|  "
			" *____jpljpt-!p|  "
			" /ppppppppp| /p|  "
			" /pt-------, /p|  "
			" /p|         /p|  "
			" /p|         /p|  ";

		LoadMap(map);
	}
	else if (data.currentLevel == 2)
	{

		map  =
			" *_____+          "
			" /ppppp|          "
			" /pt-!p|          "
			" /pl_jpl__________"
			" /pppppppppppppppp"
			" ;---!p=====------"
			"     /pppppp|     "
			"   *__=---/p|     "
			"___jpppl__jp|     "
			"ppppp#pppppp|     "
			"----- ------,     ";

		LoadMap(map);
	}
	else if (data.currentLevel == 3)
	{ 

		map =
			"                  "
			"              *___"
			"____________+ /ppp"
			"pppppppppppp| /p|-"
			"  /pt-!pt-!p| /p| "
			"  /pl_jp| /p| /p| "
			"  /ppppp| /p| /p| "
			"  ;-!pt-, /pl_jp| "
			"    /p|   /ppppp| "
			"    /p|   ;-----, ";
		LoadMap(map);

	}
}


MapClass::MapClass()
{

	this->Height = mapHeight;
	this->Width = mapWidth;
	Tilesize = 72.f;
	origin = { 0,0 };
}

MapClass::~MapClass()
{
}

int ReturnTileIndexX(int x, MapClass& map)
{
	return (x / int(map.Tilesize) % map.Width);
}

int ReturnTileIndexY(int y, MapClass& map)
{
	return int(y / map.Tilesize);
}

int ReturnIndexIncharMap(int x, int y, MapClass& map)
{
	return x + y * map.Width;
}

float2 ReturnTileMax(int indexX, int indexY, MapClass& map)
{

	return  { (indexX * map.Tilesize) + map.Tilesize,(indexY * map.Tilesize) + map.Tilesize };
};

float2 ReturnTileMin(int indexX, int indexY, MapClass& map)
{
	return { map.origin.x + (indexX * map.Tilesize),(indexY * map.Tilesize) };
}

float2 ReturnCenter(float2 Max, float2 Min)
{
	return { (Max + Min) };
}

float2 ReturnCenterTile(int indexX, int indexY, MapClass& map)
{
	return { ReturnTileMax(indexX,indexY,map).x - map.Tilesize / 2 , ReturnTileMax(indexX,indexY,map).y - map.Tilesize / 2 };

}

float2 ReturnPosfromChar(char c, MapClass& map)
{
	int idx = 0;
	for (int y = 0; y < map.Height; ++y)
	{
		for (int x = 0; x < map.Width; ++x)
		{
			// char
			idx = ReturnIndexIncharMap(x, y, map);

			if (map.map[idx] == c)
			{
				return ReturnCenterTile(x, y, map);
			}
		}
	}
	return { 0,0 };
}


bool IsPlaceAble(GameData& data, const float2& pos)
{
	if(data.map.map.size() == 181 || true)
	{
		int indexX = ReturnTileIndexX(int(pos.x), data.map);
		int indexY = ReturnTileIndexY(int(pos.y), data.map);
		int index = ReturnIndexIncharMap(indexX, indexY, data.map);



		int PlacedTileX = indexX * 72;
		int PlacedTileY = indexY * 72;
		bool IsThereTower = false;



		// Looking for there is alrealy a Tower
		for (auto it = data.towerVector.begin(); it != data.towerVector.end(); it++)
		{
			Tower* currentTower = *it;		
			if (currentTower->TileX == PlacedTileX && currentTower->TileY == PlacedTileY)
			{
				IsThereTower =  true;
			}
		}


		if(data.map.map[index] != 'p' && !IsThereTower)
		{
			return true;
		}
		else
		{
			return false;
		}



		return false;
	}
}


