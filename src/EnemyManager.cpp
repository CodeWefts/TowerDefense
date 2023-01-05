#include"EnemyManager.hpp"
#include "TowerGame.hpp"




#define enemy_Move_Speed 0.5f

float2 ReturnCheckPointNearbest(Map map , float2 enemmyPos)
{
	float2 nearBestCheckPoint = {300000,300000000 };
	
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

			float2 topLeft = { 0.f + (float)x * 72.f, y * 72.f };
			float2 topRight = { topLeft.x + 72.f, topLeft.y + 72.f };

			float2 center = { topLeft.x + 72.f / 2.f, topLeft.y + 72.f / 2.f, }; // center / checkpooint


			CheckPoint.x = center.x;
			CheckPoint.y = center.y;

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