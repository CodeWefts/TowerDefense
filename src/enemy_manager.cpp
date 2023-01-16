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

#define TimeBetweenSpawnMin 5.5f
#define TimeBetweenSpawnMax 7.5f
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




void EnemyManager::SpawnEnemy(GameData& data,const int& index)
{

	int random = rand() % TypeOfEnemy;
	float2 SpawnPoint = ReturnPosfromChar('a', data.map);
	int roadChoice = rand() % NbrOfRoad;


	if (random == Squishy_def)
	{
		enemy* currentEnemy;
		currentEnemy = new Weakling();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Healer_def)
	{
		enemy* currentEnemy;
		currentEnemy = new Healer();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);


	}
	else if (random == Heavy_def)
	{
		enemy* currentEnemy;
		currentEnemy = new Heavy();
		data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy--;
		currentEnemy->pos = SpawnPoint;
		currentEnemy->roadChoice = roadChoice;
		data.enemyVector.push_back(currentEnemy);

	}
}





/*if (data.timerLevel <= 0)
{
	data.timerWave -= data.deltatime;
	// if timer curentwave level is eual O
	if (data.currentWave <= 0 && data.currentWave != data.levels.at(data.currentLevel).maxWave && enemyremain > 0)
	{
		int nbrofEnemy = data.level[i].nbrOfWeakling + data.level[i].nbrOfHealer + data.level[i].nbrOfHeavy;
		data.level[i].timerBetweenSpawn -= data.deltatime;

		if (nbrofEnemy >= 0 && data.level[i].timerBetweenSpawn <= 0)
		{//  to do add enemyADD enemy
			SpawnEnemy(data, i);
			data.level[i].timerBetweenSpawn = Calc::randomFloat(TimeBetweenSpawnMin, TimeBetweenSpawnMax);

		}

	}

	if (data.level[i].nbrOfWeakling == 0 && data.level[i].nbrOfHealer == 0 && data.level[i].nbrOfHeavy == 0)
	{

		data.timerWave = data.levels.at(data.currentLevel).timerBetweenWave;
		data.currentWave++;
		data.timerLevel = TimerLevel;
	}



*/
// if timer Between level is eual O



void EnemyManager::ManageWave(GameData& data)
{
		
	int enemyremain = data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy;
	
	data.timerLevel -= data.deltatime;
	
	
	if (data.timerLevel <= 0)
	{
		data.levels.at(data.currentLevel).timerBetweenWave -= data.deltatime;

		// timer between Wave is equal 0 and There Still enemy
		if (data.levels.at(data.currentLevel).timerBetweenWave <= 0 && data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy > 0)
		{
			data.levels.at(data.currentLevel).waves.at(data.currentWave).timerbetweenSpawn -= data.deltatime;

			// Timer between 2 spawn
			if(data.levels.at(data.currentLevel).waves.at(data.currentWave).timerbetweenSpawn <= 0)
			{
				// Spawn
				SpawnEnemy(data, 0);
				data.levels.at(data.currentLevel).waves.at(data.currentWave).timerbetweenSpawn = Calc::randomFloat(TimeBetweenSpawnMin, TimeBetweenSpawnMax);
			}


			
		}	// if there is no enemy remaing in the current wawe and no enemie in screen Wave pass
		else if (data.levels.at(data.currentLevel).waves.at(data.currentWave).nbrOfEnemy <= 0 && data.enemyVector.empty())
		{
			data.currentWave++;
			data.levels.at(data.currentLevel).timerBetweenWave = Calc::randomFloat(TimerBetweenWaveMin, TimerBetweenWaveMax);
		}

	}// if all the Wave of the level as been passed go next level
	else if (data.levels.at(data.currentLevel).currentWave == data.levels.at(data.currentLevel).maxWave)
	{
		data.timerLevel = TimerLevel;
		data.currentLevel++;
		// Load New path //
		data.changeLevel = true;
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
			data.player.coins += current->coinsToPlayer;
			it = data.enemyVector.erase(it);

		}
		else if (current->erase && it == data.enemyVector.begin())
		{
			data.player.coins += current->coinsToPlayer;
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