#include<random>
#include "enemy.hpp"
#include"calc.hpp"


float getOffsetCheckpoint(float max)
{
	/*
	
	std::default_random_engine rd;

	std::uniform_real<float> dist(0,max);

	return dist(rd);
	*/

	srand(time(NULL));




	return Calc::randomFloat(10, 20);

}





enemy::enemy()
{
	
	this->maxHealt = 100;
	this->currentHealth = maxHealt;
	this->velocity = 2.f;
	this->offsetCheckPoint = getOffsetCheckpoint(6);

}

enemy::~enemy()
{
}