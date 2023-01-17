#include "ralentissante.hpp"
#include "tower_game.hpp"




void Ralentissante::Shoot(GameData& data)
{
	
	this->damage += (5 + data.deltatime);
	this->beamValue += (2 + data.deltatime) ;
	this->target->velocity -= 10 * data.deltatime;
	this->target->currentHealth -= this->damage;
	this->timer = 0;
	std::cout << damage << std::endl;
	if (hasTarget == false)
	{
		this->damage = baseDamage;
		this->beamValue = beamBaseValue;
	}
	

}










Ralentissante::Ralentissante()
{
	this->name = "Ralentissante";
	this->type = 3;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 150;
	this->range = 2; // range per tile
	this->damage = 10;
	this->fireRate = 1.f;
	this->beamBaseValue = 5.f;

}

Ralentissante::~Ralentissante()
{

}