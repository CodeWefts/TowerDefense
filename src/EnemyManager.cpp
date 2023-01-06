#include"EnemyManager.hpp"
#include "TowerGame.hpp"




#define enemy_Move_Speed 0.5f

float2 ReturnCheckPointNearbest(Map map , float2& enemmyPos)
{
	float2 nearBestCheckPoint = {2000,2000};
	
	float2 CheckPoint;

	for (int i = 0; i < map.Width * map.Height; ++i)
	{
		int x = i % map.Width; // return pos x on char table
		int y = i / map.Width; // return pos y on char table
		Tile& tile = map.Tiles[i]; // Get Tile texture type
		if (tile.Texture_type == 'p')
		{
			std::cout << tile.Texture_type << std::endl;
			std::cout << "x = " << x << std::endl;
			std::cout << "y = " << y << std::endl;

			// TO DO FUNCTION Returntopleft etc..

			float2 topLeft = { 0.f + (float)x * map.Tilesize, y * map.Tilesize };
			float2 topRight = { topLeft.x + map.Tilesize, topLeft.y + map.Tilesize };
			float2 center = { topLeft.x + map.Tilesize / 2.f, topLeft.y + map.Tilesize / 2.f, }; // center / checkpooint


			CheckPoint.x = center.x;
			CheckPoint.y = center.y;

			//TO DO 
			if (distPoints2(enemmyPos, CheckPoint) <= distPoints2(enemmyPos, nearBestCheckPoint))
				nearBestCheckPoint = CheckPoint; 
		}
	}

	//std::cout << nearBestCheckPoint.x << " , " << nearBestCheckPoint.y << std::endl;
	return nearBestCheckPoint;
}





void EnemyManager::ManageEnemy(GameData& data)
{
	for(auto it = data.enemyVector.begin() ; it != data.enemyVector.end() ; it++)
	{
		float2 FollowPath = ReturnCheckPointNearbest(data.map, it->pos);

		it->pos.x -= (it->pos.x - FollowPath.x) * data.deltatime * enemy_Move_Speed;
		it->pos.y -= (it->pos.y - FollowPath.y) * data.deltatime * enemy_Move_Speed;

	}

}




EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}