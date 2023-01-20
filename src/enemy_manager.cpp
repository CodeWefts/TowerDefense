#include "enemy_manager.hpp"
#include "data.hpp"
#include "calc.hpp"
#include "map.hpp"
#include "heavy.hpp"
#include "weakling.hpp"
#include "healer.hpp"
#include"calc.hpp"



#define WeaklingCost_def 1
#define HealerCost_def 2
#define HeavyCost_def 3

#define Weakling_def 0
#define Healer_def 1
#define Heavy_def 2

//#define TimeBetweenSpawnMin 5.5f
//#define TimeBetweenSpawnMax 7.5f


#define TimeBetweenSpawnMin 0.5f
#define TimeBetweenSpawnMax 2.f


#define TimerBetweenWaveMin 2.f
#define TimerBetweenWaveMax 4.f




bool isOffscreen(const GameData& data, const float2& pos)
{

	if (pos.x > data.io.DisplaySize.x || pos.x < -5 || pos.y > data.io.DisplaySize.y || pos.y < 0)
	{
		return  true;
	}

	return  false;
}



void turretUntargetEnemy(GameData& data,Enemy* current)
{
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



void EnemyManager::SpawnEnemy(GameData& data)
{

	int random = rand() % TypeOfEnemy;
	int roadChoice = rand() % NbrOfRoad;
	std::cout << roadChoice << std::endl;
	float2 SpawnPoint = data.listOfRoad[roadChoice].at(0);


	// To Do Create Fonction

	if (random == Weakling_def)
	{
		Enemy* currentEnemy;
		currentEnemy = new Weakling();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy -= WeaklingCost_def;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		ma_engine_play_sound(&data.engine, "assets/sound/weaklingSpawn.mp3", NULL);
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Healer_def)
	{
		Enemy* currentEnemy;
		currentEnemy = new Healer();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy -= HealerCost_def;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		ma_engine_play_sound(&data.engine, "assets/sound/healer.mp3", NULL);
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Heavy_def)
	{
		Enemy* currentEnemy;
		currentEnemy = new Heavy();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy -= HeavyCost_def;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		ma_engine_play_sound(&data.engine, "assets/sound/heavy.mp3", NULL);
		data.enemyVector.push_back(currentEnemy);

	}
}



void EnemyManager::ManageWave(GameData& data)
{
	// off set level
	if (data.currentLevel == nbrOfLevel - 1  && data.currentWave == data.levels[data.currentLevel].maxWave)
	{
		data.currentLevel = 0;
		data.currentWave = 0;
		data.currentScene = Menu;
	}
	else if(data.currentWave == data.levels[data.currentLevel].maxWave)
	{
		data.currentLevel++;
		data.currentWave = 0;
		data.changeLevel = true;
		ChangeLevel(data);
	}




	data.timerLevel -= data.deltatime;
	if (data.timerLevel <= 0 && data.currentLevel != nbrOfLevel)
	{
		data.levels.at(data.currentLevel).timerBetweenWave -= data.deltatime;


		if (data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy <= 0 && data.enemyVector.empty() && data.currentWave < data.levels.at(data.currentLevel).maxWave)
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
			turretUntargetEnemy(data, current);
		

		}
		else if (current->erase && it == data.enemyVector.begin())
		{
			data.player.coins += current->coinsToPlayer;
			it = data.enemyVector.erase(it);
			turretUntargetEnemy(data, current);
			
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