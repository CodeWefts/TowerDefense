#include "classique.hpp"







void Classique::Shoot(GameData& data)
{
   
    this->target->currentHealth -= this->damage;
    this->timer = 0;

}













Classique::Classique()
{
    this->name = "Classique";
    this->type = 1;
    this->TileX = 0;
    this->TileY = 0;
    this->cost = 25;
    this->range = 1;// range per tile
    this->damage = 30;
    this->fireRate = 0.5f;
    this->angle = 0;
}

Classique::~Classique() 
{

}