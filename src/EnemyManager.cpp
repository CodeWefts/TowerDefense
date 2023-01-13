#include"EnemyManager.hpp"
#include "TowerGame.hpp"
#include"calc.hpp"
#include"Calcul.hpp"
#include"Map.hpp"
#include"costaud.hpp"
#include"gringalet.hpp"










bool isOffscreen(const GameData& data , const float2& pos  )
{

	if (pos.x > data.io.DisplaySize.x || pos.x < -5 || pos.y > data.io.DisplaySize.y || pos.y < 0)
	{
		return  true;
	}

	return  false;
}








void EnemyManager::ManageWave(GameData& data)
{
	//Init Enemy
	
	//std::vector<soigneur> soigneur;
	int nbrEenemy = 1;
	enemy* ptr[4];
	

	if (data.timerWave <= 0)
	{

			//min + rand() % (max+1 - min)
			int random = 1 + rand() % (4 + 1 - 1);
			//std::cout << random << std::endl;


			if (random == 3)
			{
				for (int i = 0; i < 3; i++)
				{

					ptr[i] = new soigneur();
					ptr[i]->pos = { ReturnCenterTile(0, 6,data.map).x + 40 * i,ReturnCenterTile(0, 6,data.map).y };
					data.enemyVector.push_back(ptr[i]);
				}
			}
			else if(random == 2)
			{
				for (int i = 0; i < 3; i++)
				{
					ptr[i] = new gringalet();
					ptr[i]->pos = { ReturnCenterTile(0, 6,data.map).x + 40 * i,ReturnCenterTile(0, 6,data.map).y };
					data.enemyVector.push_back(ptr[i]);
				}
			}

			else if (random == 1)
			{
				for (int i = 0; i < 3; i++)
				{
					ptr[i] = new costaud();
					ptr[i]->pos = { ReturnCenterTile(0, 6,data.map).x + 40 * i,ReturnCenterTile(0, 6,data.map).y };
					data.enemyVector.push_back(ptr[i]);
				}
			}
			data.addEnemy = false;
		
		data.timerWave = 1;
	}

}



// to Do add /per check point index distance
void EnemyManager::MoveEnemyPath(GameData& data)
{
	
	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end();)
	{
		enemy* current = *it;
		bool erase = false;

		// Erase if off Screen
		if (isOffscreen(data, current->pos))
		{
			erase = true;
		}

		current->UpdateEnemy(data,erase);

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
	//this->ManageWave(data);
	this->MoveEnemyPath(data);

}




EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}