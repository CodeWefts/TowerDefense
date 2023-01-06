#include<iostream>
#include"Map.hpp"
#include"calc.hpp"
#include "imgui_utils.hpp"








void Map::CreateMap()
{
	

	Width = 18;
	Height = 10;
	/*
	char map[181] =
		"                  "
		"  *________+      "
		"  /cppppppd|      "
		"  /pt----!p|      "
		"  /p|    /p|      "
		"__jp|    /p|      "
		"appb|    /pl______"
		"----,    /eppppppf"
		"         ;--------"
		"    133333332     ";
	
	*/

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
		"    133333332     ";

	/*char hud[181] =
		"                  "
		"                  "
		"                  "
		"                  "
		"                  "
		"                  "
		"                  "
		"                  "
		"                  "
		"        13332     ";*/

	for (int y = 0; y < Height; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			int idx = ReturnIndexIncharMap(x, y, *this);

			Tile tile;
			tile.Texture_type = map[idx];
			Tiles.push_back(tile);
		}
	}

	/*for (int y = 0; y < Height; ++y)
	{
		for (int x = 0; x < Width; ++x)
		{
			int idx = x + y * Width;

			Tile tile;
			tile.Texture_type = hud[idx];
			Tiles.push_back(tile);
		}
	}*/
				
		
}
	

Map::Map()
{
	Tilesize = 72.f;
	origin = { 0,0 };
	
}

Map::~Map()
{
}

/*Hud::Hud()
{

}

Hud::~Hud()
{
}*/


int ReturnTileIndexX(int x, Map& map)
{
	return (x / int(map.Tilesize) % map.Width);
}

int ReturnTileIndexY(int y, Map& map)
{
	return y / map.Tilesize;
}


int ReturnIndexIncharMap(int x, int y, Map& map)
{
	return x + y * map.Width;
}


float2 ReturnTileMax(int indexX, int indexY, Map& map)
{

	return  { (indexX * map.Tilesize) + map.Tilesize,(indexY * map.Tilesize) + map.Tilesize };
};

float2 ReturnTileMin(int indexX, int indexY, Map& map)
{
	return { map.origin.x + (indexX * map.Tilesize),(indexY * map.Tilesize) };
}


float2 ReturnCenter(int indexX, int indexY, Map& map)
{
	return { ReturnTileMax(indexX,indexY,map).x - map.Tilesize,ReturnTileMax(indexX,indexY,map).y - map.Tilesize };
}


float2 ReturnPosfromChar(char c, Map& map)
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
				 
					return ReturnCenter(x, y, map);
				}
				
			 

			
		}
	}
	return { 0,0 };
}


