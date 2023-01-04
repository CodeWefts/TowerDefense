#include "Tile.hpp"


#define size 48


Tile::Tile(float2 pos)
{
	this->centerPos = pos;
	this->posMax = centerPos + size;
	this->posMin = centerPos - size;
}


Tile::Tile()
{
	this->centerPos  =  { 0,0 };
	this->posMax = centerPos + size;
	this->posMin = centerPos - size;
}

Tile::~Tile()
{
}

