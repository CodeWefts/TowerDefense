#include"EnemyManager.hpp"
#include "TowerGame.hpp"
#include"calc.hpp"
#include"Calcul.hpp"
#include"Map.hpp"
#include"costaud.hpp"
#include"gringalet.hpp"










bool isOffscreen(float2 pos)
{

	if (pos.x > 1300 || pos.x < -10 || pos.y > 720 || pos.y < 0) 
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
					ptr[i]->pos = { ReturnCenter(0, 6,data.map).x + 40 * i,ReturnCenter(0, 6,data.map).y };
					data.enemyVector.push_back(ptr[i]);
				}
			}
			else if(random == 2)
			{
				for (int i = 0; i < 3; i++)
				{
					ptr[i] = new gringalet();
					ptr[i]->pos = { ReturnCenter(0, 6,data.map).x + 40 * i,ReturnCenter(0, 6,data.map).y };
					data.enemyVector.push_back(ptr[i]);
				}
			}

			else if (random == 1)
			{
				for (int i = 0; i < 3; i++)
				{
					ptr[i] = new costaud();
					ptr[i]->pos = { ReturnCenter(0, 6,data.map).x + 40 * i,ReturnCenter(0, 6,data.map).y };
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
	/*for (std::vector<enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end();)
	{

		
		
		
		float2 FollowPath = ReturnCheckPointNearbest(data.map, &*it);

		

		enemy* current = *it;
		bool erase = false;
		if (isOffscreen(current->pos))
		{
			erase = true;
		}


		current->Heal(data);

		// TO DO GET ENEMY TILE POS ANS NEXT CHECKPOINT TILE POS
		// TO DO ADD VECTOR BETWEEN 2 CHECK POINT B - nextcheckpoint

		float2 vectorenemy;

		//std::cout << ReturnPosfromChar(current->destination, data.map).x << " , " << ReturnPosfromChar(current->destination, data.map).y << std::endl;
		//std::cout << ReturnPosfromChar(current->baseChekcpoint, data.map).x << " , " << ReturnPosfromChar(current->baseChekcpoint, data.map).y << std::endl;

		//std::cout << it->baseChekcpoint << " , " << it->destination << std::endl;

		vectorenemy.x = ReturnPosfromChar(current->baseChekcpoint, data.map).x - ReturnPosfromChar(current->destination, data.map).x;
		vectorenemy.y = ReturnPosfromChar(current->baseChekcpoint, data.map).y - ReturnPosfromChar(current->destination, data.map).y;

		//std::cout << vectorenemy.x << " , " << vectorenemy.y << std::endl;


		//std::cout << " it = " << &**it << std::endl;
		//std::cout << " current = " << &*current << std::endl;

		//std::cout << " Destination = " << current->destination << std::endl;
		//std::cout << " offset =  " << current->offsetCheckPoint << std::endl;
		current->pos -= normaliseVector(vectorenemy) * data.deltatime  * current->velocity;
	
		
		

		// TODO ADD better change pos if in tile
		if (current->pos > FollowPath - 2.f  && current->pos < FollowPath + 2.f)
		{
			current->baseChekcpoint = current->destination;
			current->destination++;


			// make enemy destroy when on castle
			if (current->destination == 'g' && it != data.enemyVector.begin())
			{
								erase = true;
			}
			else if (current->destination == 'g' && it == data.enemyVector.begin())
			{
				
				erase = true;


			}
		}


		

		// KILL enemy if off secreen
	

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
		

		
	}*/
	
	


	
	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end();)
	{
		enemy* current = *it;
		bool erase = false;

		if (isOffscreen(current->pos))
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
	this->ManageWave(data);
	this->MoveEnemyPath(data);

}




EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}