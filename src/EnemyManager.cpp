#include"EnemyManager.hpp"
#include "TowerGame.hpp"
#include"calc.hpp"
#include"Calcul.hpp"
#include"Map.hpp"
#include"costaud.hpp"
#include"gringalet.hpp"


#define Squishy 0
#define Healer 1
#define Heavy 2









bool isOffscreen(const GameData& data, const float2& pos)
{

	if (pos.x > data.io.DisplaySize.x || pos.x < -5 || pos.y > data.io.DisplaySize.y || pos.y < 0)
	{
		return  true;
	}

	return  false;
}


/*
void SpawnEnemy(enemy* enemyToSpawn)
{
	enemy* enemyToSpawn;

	enemyToSpawn = new costaud();
	data.level[i].nbrOfHeavy--;


	float2 SpawnPoint = ReturnPosfromChar('a', data.map);
	enemyToSpawn->pos = SpawnPoint;
	data.enemyVector.push_back(enemyToSpawn);
}
*/





void EnemyManager::ManageWave(GameData& data)
{
	//Init Enemy

	//std::vector<soigneur> soigneur;
	/*
		int nbrEenemy = 1;
	enemy* ptr[4];

	data.timerWave -= data.deltatime;
	if (data.timerWave <= 0)
	{


			int random = 1 + rand() % (4 + 1 - 1);



			if (random == 3)
			{
				for (int i = 0; i < 3; i++)
				{

					ptr[i] = new soigneur();
					ptr[i]->pos = { ReturnCenterTile(0, 6,data.map).x + 40 * i,ReturnCenterTile(0, 6,data.map).y };
					ptr[i]->roadChoice = rand() % 3;
					data.enemyVector.push_back(ptr[i]);
				}
			}
			else if(random == 2)
			{
				for (int i = 0; i < 3; i++)
				{
					ptr[i] = new gringalet();
					ptr[i]->pos = { ReturnCenterTile(0, 6,data.map).x + 40 * i,ReturnCenterTile(0, 6,data.map).y };
					ptr[i]->roadChoice = rand() % 3;
					data.enemyVector.push_back(ptr[i]);
				}
			}

			else if (random == 1)
			{
				for (int i = 0; i < 3; i++)
				{
					ptr[i] = new costaud();
					ptr[i]->pos = { ReturnCenterTile(0, 6,data.map).x + 40 * i,ReturnCenterTile(0, 6,data.map).y };
					ptr[i]->roadChoice = rand() % 3;
					data.enemyVector.push_back(ptr[i]);
				}
			}
			data.addEnemy = false;

		data.timerWave = 6.f;
	}

	*/	data.timerLevel -= data.deltatime;

	for (int i = 0; i < nbrOfLevel; i++)
	{

		
		if (data.timerLevel <= 0)
		{
			data.timerWave -= data.deltatime;
			if (data.currentWave <= 0 && data.currentWave != data.level[i].nbrOfWave)
			{
				printf("dsfdsf");
				int nbrofEnemy = data.level[i].nbrOfGringalet + data.level[i].nbrOfHealer + data.level[i].nbrOfHeavy;
				data.level[i].timerBetweenSpawn -= data.deltatime;

				if (nbrofEnemy >= 0 && data.level[i].timerBetweenSpawn <= 0)
				{//  to do add enemyADD enemy
					int random = rand() % TypeOfEnemy;
					int nbrofHealer = data.level[i].nbrOfHealer;
					int nbrofSquishy = data.level[i].nbrOfGringalet;
					int nbrofheavy = data.level[i].nbrOfHeavy;

					enemy* enemyToSpawn;
					if (random == Squishy && data.level[i].nbrOfGringalet > 0)
					{

						enemyToSpawn = new gringalet();
						data.level[i].nbrOfGringalet--;
						float2 SpawnPoint = ReturnPosfromChar('a', data.map);
						enemyToSpawn->pos = SpawnPoint;
						data.enemyVector.push_back(enemyToSpawn);
					}
					else if (random == Healer && data.level[i].nbrOfHealer > 0)
					{
						enemyToSpawn = new soigneur();
						data.level[i].nbrOfHealer--;
						float2 SpawnPoint = ReturnPosfromChar('a', data.map);
						enemyToSpawn->pos = SpawnPoint;
						data.enemyVector.push_back(enemyToSpawn);
					}
					else if (random == Heavy && data.level[i].nbrOfHeavy > 0)
					{
						enemyToSpawn = new costaud();
						data.level[i].nbrOfHeavy--;
						float2 SpawnPoint = ReturnPosfromChar('a', data.map);
						enemyToSpawn->pos = SpawnPoint;
						data.enemyVector.push_back(enemyToSpawn);
					}
					data.level[i].timerBetweenSpawn = Calc::randomFloat(3.5, 7.5);
				}

					
				
					
				
				
				

			}

			if (data.level[i].nbrOfGringalet == 0 && data.level[i].nbrOfHealer == 0 && data.level[i].nbrOfHeavy == 0)
			{
				data.timerWave = TimerWave;
				data.timerLevel = TimerLevel;
			}
			
		
		}






	}





}



// to Do add /per check point index distance
void EnemyManager::MoveEnemyPath(GameData& data)
{

	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end();)
	{
		enemy* current = *it;
		bool erase = false;


		if (current->currentHealth > current->maxHealt)
		{
			current->currentHealth = current->maxHealt;
		}

		// Erase if off Screen
		if (isOffscreen(data, current->pos) || current->currentHealth <= 0)
		{
			erase = true;
		}

		current->UpdateEnemy(data, erase);

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