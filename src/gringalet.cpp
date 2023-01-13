
#include"gringalet.hpp"
#include"TowerGame.hpp"
#include"calc.hpp"
#include"Calcul.hpp"
#include"float2.hpp"

gringalet::gringalet()
{
	this->name = "gringalet";
	this->currentHealth = 100;
	this->damageToPlayer = 200;
	this->maxHealt = 100;
	this->pos = { 0,0 };
	this->velocity = 130.f;

}

gringalet::~gringalet()
{
}


void gringalet::UpdateEnemy(GameData& data,bool& erase)
{
	pathFollow(data, erase);

}
