#include"Heavy.hpp"
#include "data.hpp"
#include"calc.hpp"


Heavy::Heavy()
{

	this->name = "Heavy";
	this->maxHealt = 200;
	this->currentHealth = maxHealt;
	this->pos = { 0,0 };
	this->velocity = 50.f;
	this->damageToPlayer = 75;
	this->coinsToPlayer = 60;

	this->animationMinX = 0;
	this->animationMinY = 0.2;
	this->animationMaxX = 0.043;
	this->animationMaxY = 0.4;

	this->vecMaxX = 0.043 * 4;
	this->vecMaxY = 0.4;

	this->timeMove = 0.15f;
}

Heavy::~Heavy()
{

}


void Heavy::UpdateEnemy(GameData& data,bool& erase)
{
	pathFollow(data, erase);
}
