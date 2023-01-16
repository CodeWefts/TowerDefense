#pragma once
#include <vector>
#include "enemy.hpp"
#include "Calcul.hpp"



struct GameData;





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

