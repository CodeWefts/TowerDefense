#include"costaud.hpp"
#include"TowerGame.hpp"

costaud::costaud()
{
	this->name = "costaud";
	this->currentHealth = 100;
	this->maxHealt = 100;
	this->pos = { 0,0 };
	this->velocity = 50.f;
}

costaud::~costaud()
{
}


void costaud::UpdateEnemy(GameData& data)
{

}
