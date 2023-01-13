#include"costaud.hpp"
#include"TowerGame.hpp"
#include"calc.hpp"


costaud::costaud()
{
	this->name = "costaud";
	this->maxHealt = 400;
	this->currentHealth = 400;
	this->pos = { 0,0 };
	this->velocity = 50.f;
	this->damageToPlayer = 75;

}

costaud::~costaud()
{

}


void costaud::UpdateEnemy(GameData& data,bool& erase)
{
	pathFollow(data, erase);
}
