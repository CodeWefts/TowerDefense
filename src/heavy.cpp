#include"Heavy.hpp"
#include "data.hpp"
#include"calc.hpp"


Heavy::Heavy()
{

	this->type = HEAVY;
	this->maxHealt = 900;
	this->currentHealth = maxHealt;
	this->pos = { 0,0 };
	this->velocity = 50.f;
	this->damageToPlayer = 75;
	this->coinsToPlayer = 60;

	this->animationMinX = 0.f;
	this->animationMinY = 0.2f;
	this->animationMaxX = 0.043f;
	this->animationMaxY = 0.4f;

	this->vecMaxX = float(0.043 * 4);
	this->vecMaxY = 0.4f;

	this->timeMove = 0.15f;
}

Heavy::~Heavy()
{

}


void Heavy::UpdateEnemy(GameData& data,bool& erase)
{
	pathFollow(data, erase);
}
