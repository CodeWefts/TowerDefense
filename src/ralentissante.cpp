#include "ralentissante.hpp"


Ralentissante::Ralentissante()
{
	this->name = "Ralentissante";
	this->type = 2;
	this->TileX = 0;
	this->TileY = 0;
	this->cost = 150;
	this->range = 2; // range per tile
	this->damage = 10;
	this->fireRate = 0.5f;

}

Ralentissante::~Ralentissante()
{

}