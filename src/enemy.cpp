#include<random>
#include "enemy.hpp"
#include"calc.hpp"
#include"TowerGame.hpp"



#define HealBoxSize 40




float getOffsetCheckpoint()
{
	/*
	
	std::default_random_engine rd;

	std::uniform_real<float> dist(0,max);

	return dist(rd);
	*/

	srand(time(NULL));




	return Calc::randomFloat(10, 20);

}


 void enemy::UpdateEnemy(GameData& data)
{
	

}

void enemy::Heal(GameData& data)
{

}


void  enemy::DrawDebug(ImDrawList& dl)
{

}




enemy::enemy()
{
	
	this->maxHealt = 100;
	this->currentHealth = maxHealt;
	
	this->offsetCheckPoint = getOffsetCheckpoint();

	this->healBoxSize = { HealBoxSize , HealBoxSize };


}

enemy::~enemy()
{
}