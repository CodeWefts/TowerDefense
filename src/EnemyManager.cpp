#include"EnemyManager.hpp"
#include "TowerGame.hpp"
#include"calc.hpp"




#define enemy_Move_Speed 3.f

float2 ReturnCheckPointNearbest(Map map , enemy& currentenemy)
{

	float2 CheckPoint;
	

	for (int i = 0; i < map.Width * map.Height; ++i)
	{
		int x = i % map.Width; // return pos x on char table
		int y = i / map.Width; // return pos y on char table
		Tile& tile = map.Tiles[i]; // Get Tile texture type
		if (tile.Texture_type == currentenemy.destination)
		{
			/*std::cout << tile.Texture_type << std::endl;
			std::cout << "x = " << x << std::endl;
			std::cout << "y = " << y << std::endl;*/

			// TO DO FUNCTION Returntopleft etc..

			float2 topLeft = ReturnTileMin(x, y, map);
			float2 topRight = ReturnTileMax(x, y, map);
			float2 center = ReturnCenter(x, y, map); // center / checkpooint


			CheckPoint.x = center.x;
			CheckPoint.y = center.y;
			
			return CheckPoint;
		}
	}

	//std::cout << nearBestCheckPoint.x << " , " << nearBestCheckPoint.y << std::endl;

}





void EnemyManager::ManageEnemy(GameData& data)
{
	if(data.enemyVector.size() != 0)
	for(auto it = data.enemyVector.begin() ; it != data.enemyVector.end() ; it++)
	{
		
		float2 FollowPath = ReturnCheckPointNearbest(data.map, *(it));

		
		// TO DO GET ENEMY TILE POS ANS NEXT CHECKPOINT TILE POS
		// TO DO ADD VECTOR BETWEEN 2 CHECK POINT B - nextcheckpoint
		


		it->pos -= (it->pos - FollowPath) * data.deltatime   * enemy_Move_Speed;
		




		if (it->pos > FollowPath -10 && it->pos < FollowPath + 10)
		{
			it->destination++;


			// make enemy destroy when on castle
			if (it->destination == 'g' && it != data.enemyVector.begin())
			{
				data.enemyVector.erase(it--);
			}
			else if (it->destination == 'g' && it == data.enemyVector.begin())
			{
				data.enemyVector.erase(it);
				data.enemyVector.resize(0);
				break;
				
				
			}
			
				
			
		}

	
	}
	

}




EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}