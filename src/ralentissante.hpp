#pragma once
#include "Tower.hpp"

struct GameData;


class Ralentissante : public Tower
{


public:

	int baseDamage;
	int beamBaseValue;
	void Shoot(GameData& data) override;


	Ralentissante();
	~Ralentissante();


};