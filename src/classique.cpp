#include "classique.hpp"


Classique::Classique()
{
    this->name = "Classique";
    this->type = 0;
    this->TileX = 0;
    this->TileY = 0;
    this->cost = 25;
    this->range = 1;// range per tile
    this->damage = 10;
    this->fireRate = 0.5f;
}

Classique::~Classique() 
{

}