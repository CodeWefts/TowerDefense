
#include"weakling.hpp"
#include"tower_game.hpp"
#include"calc.hpp"
#include"Calcul.hpp"
#include"float2.hpp"



Weakling::Weakling()
{
	this->name = "Weakling";
	this->currentHealth = 100;
	this->damageToPlayer = 200;
	this->maxHealt = 100;
	this->pos = { 0,0 };
	this->velocity = 90.f;
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
