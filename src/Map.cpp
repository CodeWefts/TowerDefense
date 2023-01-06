#include<iostream>
#include"Map.hpp"
#include"calc.hpp"
#include "imgui_utils.hpp"





void Map::CreateMap()
{

	Width = 18;
	Height = 10;
	char map[181] =
		"                  "
		"  *________+      "
		"  /pppppppp|      "
		"  /pt----!p|      "
		"  /p|    /p|      "
		"__jp|    /p|      "
		"pppp|    /pl______"
		"----,    /pppppppp"
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
			int idx = x + y * Width;

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