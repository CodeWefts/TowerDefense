#include"EnemyManager.hpp"
#include "TowerGame.hpp"
#include"calc.hpp"




#define enemy_Move_Speed 0.5f

float2 ReturnCheckPointNearbest(Map& map , enemy** currentenemy)
{

	float2 CheckPoint;
	
	for (int i = 0; i < map.Width * map.Height; ++i)
	{
		int x = i % map.Width; // return pos x on char table
		int y = i / map.Width; // return pos y on char table
		Tile& tile = map.Tiles[i]; // Get Tile texture type
		enemy* current = *currentenemy;
		if (tile.Texture_type == current->destination)
		{
			/*std::cout << tile.Texture_type << std::endl;
			std::cout << "x = " << x << std::endl;
			std::cout << "y = " << y << std::endl;*/

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


void EnemyManager::ManageWave(GameData& data)
{
	//Init Enemy
	
	//std::vector<soigneur> soigneur;
	int nbrEenemy = 1;
	enemy* ptr[2];
	

	 if (data.currentWave == Wave1 && data.addEnemy == true)
	{	
		

		for (int i = 1; i < 2; i++)
		{
			 ptr[i] = new soigneur[i];
			 ptr[i]->pos = { ReturnCenter(0, 6,data.map).x,ReturnCenter(0, 6,data.map).y + 20 * i };
			data.enemyVector.push_back(ptr[i]);
		
		}
	
		
			
		
			

		
		
			//data.enemyVector.at(10) = new soigneur();
		
		

			
			

		
		data.addEnemy = false;
		
	}
	

	
	

}













// to Do add /per check point index distance
void EnemyManager::MoveEnemyPath(GameData& data)
{
	if(!data.enemyVector.empty())
	for (std::vector<enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end();)
	{
		float2 FollowPath = ReturnCheckPointNearbest(data.map, &*it);

		

		enemy* current = *it;
		bool erase = false;



		// TO DO GET ENEMY TILE POS ANS NEXT CHECKPOINT TILE POS
		// TO DO ADD VECTOR BETWEEN 2 CHECK POINT B - nextcheckpoint

		float2 vectorenemy;

		std::cout << ReturnPosfromChar(current->destination, data.map).x << " , " << ReturnPosfromChar(current->destination, data.map).y << std::endl;
		std::cout << ReturnPosfromChar(current->baseChekcpoint, data.map).x << " , " << ReturnPosfromChar(current->baseChekcpoint, data.map).y << std::endl;

		//std::cout << it->baseChekcpoint << " , " << it->destination << std::endl;

		vectorenemy.x = ReturnPosfromChar(current->baseChekcpoint, data.map).x - ReturnPosfromChar(current->destination, data.map).x;
		vectorenemy.y = ReturnPosfromChar(current->baseChekcpoint, data.map).y - ReturnPosfromChar(current->destination, data.map).y;

		//std::cout << vectorenemy.x << " , " << vectorenemy.y << std::endl;
		current->pos -= vectorenemy * data.deltatime * enemy_Move_Speed * current->velocity;

		


		// enemy change check point off set
		
		if (current->pos > FollowPath - current->offsetCheckPoint && current->pos < FollowPath + current->offsetCheckPoint)
		{
			current->baseChekcpoint = current->destination;
			current->destination++;


			// make enemy destroy when on castle
			if (current->destination == 'g' && it != data.enemyVector.begin())
			{
				//it->velocity = 0; 
				//data.enemyVector.erase(it--);
				erase = true;
			}
			else if (current->destination == 'g' && it == data.enemyVector.begin())
			{
				//it->velocity = 0;
				//data.enemyVector.erase(it);
				//break;
				erase = true;


			}
		}


		// KILL enemy if off secreen
		if ((current->pos.x > 1300 || current->pos.x < -10 || current->pos.y > 720 || current->pos.y < 0)  && it == data.enemyVector.begin())
		{
			erase = true;
		}

		if (erase && it != data.enemyVector.end())
		{
			it = data.enemyVector.erase(it);
		}
		else if (erase && it == data.enemyVector.begin())
		{
			it = data.enemyVector.erase(it);
			
		}
		else
		{
			it++;
		}
		

		
	}
	
	
}





void EnemyManager::ManageEnemy(GameData& data)
{
	//TO DO ADD WAWE
	this->ManageWave(data);

	this->MoveEnemyPath(data);


}




EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}