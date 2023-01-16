#pragma once




struct GameData;

class EnemyWave
{
public:

	int maxEnemy;
	int nbrOfEnemy;
	float timerbetweenSpawn;



	EnemyWave();
	EnemyWave(const int& maxEnemy, float& timerbetweenSpawn);
	~EnemyWave();

private:

};

