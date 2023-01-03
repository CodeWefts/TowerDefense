#include"Map.hpp"

#define Height 10
#define With 10



void Map::ManageMap(std::vector<Tile>& Tiles)
{
	float2 headCenterPos = Tiles.at(0).centerPos;
	float2 headposMax = Tiles.at(0).posMax;
	float2 headposMin = Tiles.at(0).posMin;



	for (auto it = Tiles.begin(); it != Tiles.end(); it++)
	{
		for (int i = 0; i < Height; i++)
		{
			it->centerPos.x += headCenterPos.x * i;
			it->posMax.x += headposMax.x * i;
			it->posMin.x += headposMin.x * i;
			 
			
			for (int k = 0; k < With; k++)
			{
				it->centerPos.y += headCenterPos.y * k;
				it->posMax.y += headposMax.y * k;
				it->posMin.y += headposMin.y * k;
			}
		}
	}
	
}

Map::Map()
{
	
}

Map::~Map()
{
}