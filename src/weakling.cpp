
#include "weakling.hpp"
#include "tower_game.hpp"
#include "calc.hpp"
#include "float2.hpp"



Weakling::Weakling()
{
	this->type = WEAKLING;
	this->currentHealth = 300;
	this->damageToPlayer = 200;
	this->maxHealt = 100;
	this->pos = { 0,0 };
	this->velocity = 150.f;
	this->coinsToPlayer = 10;

	this->animationMinX = 0.f;
	this->animationMinY = 0.f;
	this->animationMaxX = 0.25f;
	this->animationMaxY = 0.5f;

	this->vecMaxX = 1;
	this->vecMaxY = 1;

	this->timeMove = 0.15f;
	
}

Weakling::~Weakling()
{
}


void Weakling::UpdateEnemy(GameData& data,bool& erase)
{
	pathFollow(data, erase);

}
