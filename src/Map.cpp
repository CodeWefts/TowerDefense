#include<iostream>
#include"Map.hpp"
#include"calc.hpp"
#include "imgui_utils.hpp"
#include"enemy.hpp"




#define mapWidth 18
#define mapHeight 10




void MapClass::CreateMap()
{


	Width = mapWidth;
	Height = mapHeight;























	/*
	* map =
			 "                  "
			 "a            b    "
			 "   e   f          "
			 "                  "
			 "   d   g     c    "
			 "                  "
			 "                  "
			 "       h     i    "
			 "                  "
			 "                  ";


	*/






	/*
	*  map =
			"                  "
			"     b  e   f    a"
			"                  "
			"     c  d   g     "
			"                  "
			"                  "
			"                  "
			"                  "
			"                  "
			"                  ";
	*/














	for (int y = 0; y < mapHeight; ++y)
	{
		for (int x = 0; x < mapWidth; ++x)
		{
			int idx = ReturnIndexIncharMap(x, y, *this);

			Tile tile;
			tile.Texture_type = map[idx];
			Tiles.push_back(tile);
		}
	}




}


MapClass::MapClass()
{
	Tilesize = 72.f;
	origin = { 0,0 };

	map =
		"                  "
		"  *________+      "
		"  /cppppppd|      "
		"  /pt----!p|      "
		"  /p|    /p|      "
		"__jp|    /p|      "
		"appb|    /pl______"
		"----,    /eppppppf"
		"         ;--------"
		"                  ";
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
	return y / map.Tilesize;
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




float2 ReturnCenter(const float2& Max, const float2& Min)
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
				//printf("idx = %d \n", idx);
				//printf("map.idx = %c \n", map.map[idx]);

				return ReturnCenterTile(x, y, map);
			}




		}
	}
	return { 0,0 };
}


