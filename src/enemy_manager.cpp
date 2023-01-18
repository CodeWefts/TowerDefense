#include "enemy_manager.hpp"
#include "data.hpp"
#include "calc.hpp"
#include "Calcul.hpp"
#include "map.hpp"
#include "heavy.hpp"
#include "weakling.hpp"
#include "healer.hpp"



#define Squishy_def 0
#define Healer_def 1
#define Heavy_def 2

//#define TimeBetweenSpawnMin 5.5f
//#define TimeBetweenSpawnMax 7.5f


#define TimeBetweenSpawnMin 0.5f
#define TimeBetweenSpawnMax 1.5f


#define TimerBetweenWaveMin 5.f
#define TimerBetweenWaveMax 10.f




bool isOffscreen(const GameData& data, const float2& pos)
{

	if (pos.x > data.io.DisplaySize.x || pos.x < -5 || pos.y > data.io.DisplaySize.y || pos.y < 0)
	{
		return  true;
	}

	return  false;
}




void EnemyManager::SpawnEnemy(GameData& data)
{

	int random = rand() % TypeOfEnemy;
	int roadChoice = rand() % NbrOfRoad;
	std::cout << roadChoice << std::endl;
	float2 SpawnPoint = data.listOfRoad[roadChoice].at(0);


	// To Do Create Fonction

	if (random == Squishy_def)
	{
		Enemy* currentEnemy;
		currentEnemy = new Weakling();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Healer_def)
	{
		Enemy* currentEnemy;
		currentEnemy = new Healer();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Heavy_def)
	{
		Enemy* currentEnemy;
		currentEnemy = new Heavy();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);

	}
}



void EnemyManager::ManageWave(GameData& data)
{



	if (data.timerLevel <= 0)
	{
		data.levels.at(data.currentLevel).timerBetweenWave -= data.deltatime;


		if (data.currentWave == data.levels.at(data.currentLevel).maxWave - 1)
		{

			data.timerLevel = TimerLevel;
			ChangeLevel(data);
			if (data.currentLevel == nbrOfLevel && data.currentWave == data.levels[data.currentLevel].maxWave - 1)
			{
				data.currentScene = Menu;
			}
			else
			{
				data.currentLevel++;
			}


			// Load New path //
			data.currentWave = 0;
			data.changeLevel = true;
		}



		// if all the Wave of the level as been passed go next level

// if there is no enemy remaing in the current wawe and no enemie in screen Wave pass


		else if (data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy <= 0 && data.enemyVector.empty() && data.currentWave < data.levels.at(data.currentLevel).maxWave)
		{

			data.currentWave++;
			data.levels.at(data.currentLevel).timerBetweenWave = Calc::randomFloat(TimerBetweenWaveMin, TimerBetweenWaveMax);
		}







		// timer between Wave is equal 0 and There Still enemy
		if (data.levels.at(data.currentLevel).timerBetweenWave <= 0 && data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy > 0)
		{
			data.levels.at(data.currentLevel).waves.at(data.currentWave).timerbetweenSpawn -= data.deltatime;

			// Timer between 2 spawn
			if (data.levels.at(data.currentLevel).waves.at(data.currentWave).timerbetweenSpawn <= 0)
			{
				// Spawn
				SpawnEnemy(data);
				data.levels.at(data.currentLevel).waves.at(data.currentWave).timerbetweenSpawn = Calc::randomFloat(TimeBetweenSpawnMin, TimeBetweenSpawnMax);
			}



		}


	}
}



// to Do add /per check point index distance
void EnemyManager::MoveEnemyPath(GameData& data)
{
	
	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end();)
	{
		Enemy* current = *it;
		

		// Erase if off Screen
		if (isOffscreen(data, current->pos) || current->currentHealth <= 0)
		{
			current->erase = true;
		}

		current->UpdateEnemy(data, current->erase);

		
		
		
		if (current->erase && it != data.enemyVector.end())
		{
			data.player.coins += current->coinsToPlayer;
			it = data.enemyVector.erase(it);
			for (auto op = data.towerVector.begin(); op != data.towerVector.end(); op++)
			{
				Tower* tower = *op;
				if (current == tower->target)
				{
					tower->hasTarget = false;
					tower->target = nullptr;
				}
			}

		}
		else if (current->erase && it == data.enemyVector.begin())
		{
			data.player.coins += current->coinsToPlayer;
			it = data.enemyVector.erase(it);
			for (auto op = data.towerVector.begin(); op != data.towerVector.end(); op++)
			{
				Tower* tower = *op;
				if (current == tower->target)
				{
					tower->hasTarget = false;
					tower->target = nullptr;
				}
			}
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