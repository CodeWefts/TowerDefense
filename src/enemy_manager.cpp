#include "enemy_manager.hpp"
#include "tower_game.hpp"
#include "calc.hpp"
#include "Calcul.hpp"
#include "map.hpp"
#include "heavy.hpp"
#include "weakling.hpp"


#define Squishy_def 0
#define Healer_def 1
#define Heavy_def 2

#define TimeBetweenSpawnMin 5.5f
#define TimeBetweenSpawnMax 7.5f










bool isOffscreen(const GameData& data, const float2& pos)
{

	if (pos.x > data.io.DisplaySize.x || pos.x < -5 || pos.y > data.io.DisplaySize.y || pos.y < 0)
	{
		return  true;
	}

	return  false;
}





void EnemyManager::SpawnEnemy(GameData& data,const int& index)
{

	int random = rand() % TypeOfEnemy;
	float2 SpawnPoint = ReturnPosfromChar('a', data.map);
	int roadChoice = rand() % NbrOfRoad;


	if (random == Squishy_def && data.level[index].nbrOfWeakling > 0)
	{
		enemy* currentEnemy;
		currentEnemy = new Weakling();
		data.level[index].nbrOfWeakling--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Healer_def && data.level[index].nbrOfHealer > 0)
	{
		enemy* currentEnemy;
		currentEnemy = new Healer();
		data.level[index].nbrOfHealer--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Heavy_def && data.level[index].nbrOfHeavy > 0)
	{
		enemy* currentEnemy;
		currentEnemy = new Heavy();
		data.level[index].nbrOfHeavy--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);

	}
}










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
					ptr[i] = new Heavy();
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

		// if timer Between level is eual O
		if (data.timerLevel <= 0)
		{
			data.timerWave -= data.deltatime;
			// if timer curentwave level is eual O
			if (data.currentWave <= 0 && data.currentWave != data.level[i].nbrOfWave)
			{
				int nbrofEnemy = data.level[i].nbrOfWeakling + data.level[i].nbrOfHealer + data.level[i].nbrOfHeavy;
				data.level[i].timerBetweenSpawn -= data.deltatime;

				if (nbrofEnemy >= 0 && data.level[i].timerBetweenSpawn <= 0)
				{//  to do add enemyADD enemy
					//SpawnEnemy(data, i);
					data.level[i].timerBetweenSpawn = Calc::randomFloat(TimeBetweenSpawnMin, TimeBetweenSpawnMax);
					
				}
				
			}

			if (data.level[i].nbrOfWeakling == 0 && data.level[i].nbrOfHealer == 0 && data.level[i].nbrOfHeavy == 0)
			{
			
				data.timerWave = TimerWave;
				data.currentWave++;
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
		

		// Erase if off Screen
		if (isOffscreen(data, current->pos) || current->currentHealth <= 0)
		{
			current->erase = true;
		}

		current->UpdateEnemy(data, current->erase);

		
		
		
		if (current->erase && it != data.enemyVector.end())
		{
			it = data.enemyVector.erase(it);
		}
		else if (current->erase && it == data.enemyVector.begin())
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