#include "wave.hpp"
#include "tower_game.hpp"




EnemyWave::EnemyWave()
{
	this->maxEnemy = 0;
	this->nbrOfEnemy = 0; 
	this->timerbetweenSpawn = 0;
}

EnemyWave::~EnemyWave()
{
}
EnemyWave::EnemyWave(const int& maxEnemy, float& timerbetweenSpawn)
{
	this->maxEnemy = maxEnemy;
	this->nbrOfEnemy = maxEnemy;
	this->timerbetweenSpawn = timerbetweenSpawn;
}
