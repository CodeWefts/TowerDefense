#include<iostream>
#include"Map.hpp"
#include"calc.hpp"
#include "imgui_utils.hpp"

#define Height 20
#define With 36



void Map::ManageMap(std::vector<Tile>& Tiles)
{
	ImGuiIO& io = ImGui::GetIO();

	float2 headCenterPos = Tiles.at(0).centerPos;
	float2 headposMax = Tiles.at(0).posMax;
	float2 headposMin = Tiles.at(0).posMin;

	/*
	/Tiles.at(0).centerPos = {500,500};
	Tiles.at(0).posMin.x = Tiles.at(0).centerPos.x - 25;
	Tiles.at(0).posMin.y = Tiles.at(0).centerPos.y + 25;



	Tiles.at(0).posMax.x = Tiles.at(0).centerPos.x + 25;
	Tiles.at(0).posMax.y = Tiles.at(0).centerPos.y - 25;
	*/

	int i = 0;

	int k = 0;
	// 
	for (auto it = Tiles.begin(); it != Tiles.end(); it++)
	{
		
			it->centerPos.x = headCenterPos.x + (k * 36) * 2;
			it->posMax.x = (it->centerPos.x + 36);
			it->posMin.x = (it->centerPos.x - 36);

		
			it->centerPos.y = headCenterPos.y + (i * 36) * 2;
			it->posMax.y = (it->centerPos.y + 36);
			it->posMin.y = (it->centerPos.y - 36);


			//it->pos.x += (Space_between_bricks * k) + Startpos.x; // compteur ligne 
			//it->pos.y += (Space_between_bricks * j) + Startpos.y; // compteur colone


			


			if (k != With - 1)
			{

				k++;
			}
			else if (k == With - 1)
			{
				if(i != Height)
				{
					i++;
					k = 0;
				}
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