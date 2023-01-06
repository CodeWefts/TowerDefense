#pragma once
#include "enemy.hpp"



enemy::enemy()
{
	
	maxHealt = 100;
	currentHealth = maxHealt;
	velocity = 2.f;

}

enemy::~enemy()
{
}