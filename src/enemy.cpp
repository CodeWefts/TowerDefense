#include<random>
#include "enemy.hpp"


int getOffsetCheckpoint(int max)
{
	std::default_random_engine rd;

	std::uniform_int_distribution<int> dist(0,max);

	return dist(rd);

}





enemy::enemy()
{
	
	this->maxHealt = 100;
	this->currentHealth = maxHealt;
	this->velocity = 2.f;
	this->offsetCheckPoint = getOffsetCheckpoint(10);

}

enemy::~enemy()
{
}