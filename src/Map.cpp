#include<iostream>
#include"Map.hpp"
#include"calc.hpp"
#include "imgui_utils.hpp"





void Map::CreateMap()
{
#if 0

	ImGuiIO& io = ImGui::GetIO();

	int With = io.DisplaySize.x / 36;
	int Height = io.DisplaySize.y / 36;

	Tiles.resize(With * Height);

	auto it = Tiles.begin();
	it->centerPos = { 36 , 36 };

	float2 headCenterPos = Tiles[0].centerPos;
	float2 headposMax = Tiles[0].posMax;
	float2 headposMin = Tiles[0].posMin;




	int i = 0;

	int k = 0;
	// 
	for (auto it = Tiles.begin(); it != Tiles.end(); it++)
	{
		it->centerPos.x = headCenterPos.x + (k * 36) * 2;
		it->posMax.x = (it->centerPos.x + (36));
		it->posMin.x = (it->centerPos.x - (36));

		it->centerPos.y = headCenterPos.y + (i * (36)) * 2;
		it->posMax.y = (it->centerPos.y + (36));
		it->posMin.y = (it->centerPos.y - (36));

		if (k != With - 1)
		{

			k++;
		}
		else if (k == With - 1)
		{
			if (i != Height)
			{
				i++;
				k = 0;
			}
		}
		it->IndexX = k;
		it->IndexY = i;
	}





	int w = Width;
	int h = Height;
	const char* map =
		"                  "
		"      o           "
		"       ooooooooo  "
		"                  "
		"                  "
		"                  "
		"                  "
		"         o        "
		"                  "
		"                  ";




	for (auto it = Tiles.begin(); it < Tiles.end(); it++)
	{
		int idx = it->IndexX + it->IndexY * w;
		it->Texture_type = map[idx];
		
		//for (int y = 0; y < h; ++y)
		//{
		//	for (int x = 0; x < w; ++x)
		//	{
		//		int idx = x + y * w;

		//		if(x == it->IndexX && y == it->IndexY )
		//			it->Texture_type = map[idx];
		//	}


		//	//Tile tile;
		//	//tile.IndexX = x;
		//	//tile.IndexY = y;


		//	//Tiles.push_back(tile);
		//}
	}
#endif

	Width = 18;
	Height = 10;
	 char map[199] =
		"                  "
		"                  "
		"                  "
		"   pppppppp       "
		"   p      p       "
		"   p      p       "
		"   p      p       "
		"pppp      p       "
		"          pppppppp"
		"                  ";

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
		/*
		float2 min = {0 , 0};
		float2 max = { 36 , 36 };

		for (int j = 0; (min.y <= io.DisplaySize.y); j++) // afficher le décors (grass) qui fait une taille de 120 x 120 pixels
		{
			min.x = 0;
			max.x = 36;

			for (int i = 0; (min.x <= io.DisplaySize.x); i++) // permet dessiner une seule ligne horizontale
			{
				
				min = operator+(min, { 36,0 });
				max = operator+(max, { 36,0 });
			}

			min = operator+(min, { 0,36 });
			max = operator+(max, { 0,36 });
		}
		*/
			
				
				
			
			
		
	}
	

Map::Map()
{
	
}

Map::~Map()
{
}