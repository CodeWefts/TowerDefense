#include "ralentissante.hpp"
#include "tower_game.hpp"




void Ralentissante::Shoot(GameData& data)
{
	this->target->velocity -= 10 * data.deltatime;
	this->target->currentHealth -= this->damage;
	this->timer = 0;
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

}

Ralentissante::~Ralentissante()
{

}