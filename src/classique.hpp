#pragma once
#include "Tower.hpp"

struct GameData;


class Classique : public Tower
{


public:


	void Shoot(GameData& data) override; 


	Classique();
	~Classique();


};