#include "data.hpp"



Level::Level()
{
}

Level::~Level()
{
}


Level::Level(const int& nbrWave, const int& nbrOfRoad)
{
	this->maxWave = nbrWave;
	this->nbrOfWave = maxWave;
	this->nbrOfRoad = nbrOfRoad;
	
}
