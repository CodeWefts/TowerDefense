#include<iostream>
#include"Map.hpp"
#include"calc.hpp"
#include "imgui_utils.hpp"
#include"enemy.hpp"




#define mapWidth 18
#define mapHeight 10



float2 ReturnCheckPointNearbest(Map& map, enemy* currentenemy)
{
	// TO DO ADD MEGA SUPER ALGLHROTIM OF DOOM
	float2 CheckPoint = {0,0};


	
		for (int i = 0; i < map.Width * map.Height; ++i)
		{
			int x = i % map.Width; // return pos x on char table
			int y = i / map.Width; // return pos y on char table
			Tile& tile = map.Tiles[i]; // Get Tile texture type
			if (tile.Texture_type == currentenemy->destination)
			{
				/*std::cout << tile.Texture_type << std::endl;
				std::cout << "x = " << x << std::endl;
				std::cout << "y = " << y << std::endl;*/

				//std::cout <<currentenemy.baseChekcpoint<<','<< std::endl;
				//printf("%c", currentenemy.baseChekcpoint);

				
				float2 center = ReturnCenterFromTile(x, y, *currentenemy,map); // center / checkpooint

				
				CheckPoint.x = center.x;
				CheckPoint.y = center.y;

				return CheckPoint;
			}
		}
	




	//std::cout << nearBestCheckPoint.x << " , " << nearBestCheckPoint.y << std::endl;

}

void Map::CreateMap()
{
	

	Width = mapWidth;
	Height = mapHeight;


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


float2 ReturnCenterFromTile(int indexX, int indexY,enemy& enemy, Map& map)
{
	float2 base = ReturnPosfromChar(enemy.baseChekcpoint,map);
	float2 destinationTilePos = ReturnPosfromChar(enemy.baseChekcpoint, map);
	float2 afterDestinationTilePos = ReturnPosfromChar(enemy.afterDestination, map);


	if (enemy.path == 1)
	{
		if (afterDestinationTilePos.y > destinationTilePos.y)
		{
			if (base.x > destinationTilePos.x)
			{
				return ReturnCaseofTile(UpRight, indexX, indexY, map);
			}
			else
			{
				

				return ReturnCaseofTile(UpLeft, indexX, indexY, map);
			}
			
		}
		else if (afterDestinationTilePos.y < destinationTilePos.y)
		{
			if (base.x > destinationTilePos.x)
			{
					
				return ReturnCaseofTile(UpRight, indexX, indexY, map);
			}
			else
			{
				return ReturnCaseofTile(UpLeft, indexX, indexY, map);
			}

		}
	}

	if (enemy.path == 3)
	{
		if (afterDestinationTilePos.y > destinationTilePos.y)
		{
			if (afterDestinationTilePos.x > destinationTilePos.x)
			{
				return ReturnCaseofTile(DownRight, indexX, indexY, map);
			}
			else
			{
				return ReturnCaseofTile(DownLeft, indexX, indexY, map);
			}

		}
		else if (afterDestinationTilePos.y < destinationTilePos.y)
		{
			if (afterDestinationTilePos.x > destinationTilePos.x)
			{
				return ReturnCaseofTile(DownLeft, indexX, indexY, map);
			}
			else
			{
				return ReturnCaseofTile(DownRight, indexX, indexY, map);
			}

		}
	}
















	//return { ReturnTileMax(indexX,indexY,map).x - map.Tilesize/2 , ReturnTileMax(indexX,indexY,map).y - map.Tilesize / 2 };
}




float2 ReturnCenter(const float2& Max, const float2& Min)
{
	return { (Max + Min) / 2 }; 
}

float2 ReturnCenterTile(int indexX, int indexY, Map& map)
{
	return { ReturnTileMax(indexX,indexY,map).x - map.Tilesize/2 , ReturnTileMax(indexX,indexY,map).y - map.Tilesize / 2 };
		
}

float2 ReturnCaseofTile(const int& nbr, const int& indexX, const int& indexY,Map& map)
{
	float2 TileCenter = ReturnCenterTile(indexX, indexY, map);
	
	
	float2 tileUpRight = { TileCenter.x + map.Tilesize, TileCenter.y - map.Tilesize };



	if(nbr == UpRight)
	{
		float2 tileUpRight = { TileCenter.x - map.Tilesize, TileCenter.y - map.Tilesize };
		return ReturnCenter(TileCenter, tileUpRight);

	}
	else if (nbr == UpLeft)
	{
		float2 tileUpLeft = { TileCenter.x + map.Tilesize, TileCenter.y - map.Tilesize };
		return ReturnCenter(TileCenter, tileUpLeft);
	}
	else if (nbr == DownLeft)
	{
		float2 tileDownLeft = { TileCenter.x + map.Tilesize, TileCenter.y + map.Tilesize };
		return ReturnCenter(TileCenter, tileDownLeft);

	}
	else if (nbr == DownRight)
	{
		float2 tileDownRight = { TileCenter.x - map.Tilesize, TileCenter.y + map.Tilesize };
		return ReturnCenter(TileCenter, tileDownRight);
	}

	return { 0,0 };

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
				 
					return ReturnCenterTile(x, y, map);
				}
				
			 

			
		}
	}
	return { 0,0 };
}


