#include"Heavy.hpp"
#include"tower_game.hpp"
#include"calc.hpp"


Heavy::Heavy()
{

	this->name = "Heavy";
	this->maxHealt = 400;
	this->currentHealth = 400;
	this->pos = { 0,0 };
	this->velocity = 50.f;
	this->damageToPlayer = 75;

}

Heavy::~Heavy()
{

}


void Heavy::UpdateEnemy(GameData& data,bool& erase)
{
	pathFollow(data, erase);
}
