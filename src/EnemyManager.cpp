#include"EnemyManager.hpp"
#include "TowerGame.hpp"
#include"calc.hpp"




#define enemy_Move_Speed 0.5f

float2 ReturnCheckPointNearbest(Map& map , enemy& currentenemy)
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

			//std::cout <<currentenemy.baseChekcpoint<<','<< std::endl;
			//printf("%c", currentenemy.baseChekcpoint);

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
	

	for(auto it = data.enemyVector.begin() ; it != data.enemyVector.end() ;)
	{
			float2 FollowPath = ReturnCheckPointNearbest(data.map, *(it));


			// TO DO GET ENEMY TILE POS ANS NEXT CHECKPOINT TILE POS
			// TO DO ADD VECTOR BETWEEN 2 CHECK POINT B - nextcheckpoint

			float2 vectorenemy;

			//std::cout << ReturnPosfromChar(it->destination, data.map).x << " , " << ReturnPosfromChar(it->destination, data.map).y << std::endl;
			//std::cout << ReturnPosfromChar(it->baseChekcpoint, data.map).x << " , " << ReturnPosfromChar(it->baseChekcpoint, data.map).y << std::endl;

			//std::cout << it->baseChekcpoint << " , " << it->destination << std::endl;

			vectorenemy.x = ReturnPosfromChar(it->baseChekcpoint, data.map).x - ReturnPosfromChar(it->destination, data.map).x;
			vectorenemy.y = ReturnPosfromChar(it->baseChekcpoint, data.map).y - ReturnPosfromChar(it->destination, data.map).y;

			//std::cout << vectorenemy.x << " , " << vectorenemy.y << std::endl;
			it->pos -= vectorenemy * data.deltatime * enemy_Move_Speed * it->velocity;





			if (it->pos > FollowPath - 10 && it->pos < FollowPath + 10)
			{
				it->baseChekcpoint = it->destination;
				it->destination++;


				// make enemy destroy when on castle
				if (it->destination == 'g' && it != data.enemyVector.begin())
				{
					//it->velocity = 0; 
					data.enemyVector.erase(it--);
				}
				else if (it->destination == 'g' && it == data.enemyVector.begin())
				{
					//it->velocity = 0;
					data.enemyVector.erase(it);
					break;


				}



			}

			if ((it->pos.x > 1300 || it->pos.x < -10 || it->pos.y > 720 || it->pos.y < 0) && ((it->pos.x > 1300 || it->pos.x < -10 || it->pos.y > 720 || it->pos.y < 0) && it == data.enemyVector.begin()))
			{
				it = data.enemyVector.erase(it);
			}
			else
			{
				it++;
			}
		


			
	

	
	}
	

}




EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}