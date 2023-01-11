
#include"gringalet.hpp"
#include"TowerGame.hpp"

gringalet::gringalet()
{
	this->name = "gringalet";
	this->currentHealth = 100;
	this->maxHealt = 100;
	this->pos = { 0,0 };
	this->velocity = 150.f;

}

gringalet::~gringalet()
{
}


void gringalet::UpdateEnemy(GameData& data)
{
}
