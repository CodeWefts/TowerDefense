#pragma once
#include <vector>
#include "enemy.hpp"
#include "Calcul.hpp"



struct GameData;




struct Level
{
	int nbrOfWeakling;
	int nbrOfHealer;
	int nbrOfHeavy;

	int nbrOfWave;

	float timerBetweenSpawn;


};

class EnemyManager
{
public:


	void SpawnEnemy(GameData& data, const int& index);
	void ManageWave(GameData& data);
	void MoveEnemyPath(GameData& data);
	void ManageEnemy(GameData& data);


	EnemyManager();
	~EnemyManager();

private:

};

