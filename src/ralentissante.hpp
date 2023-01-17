#pragma once
#include "Tower.hpp"

struct GameData;


class Ralentissante : public Tower
{


public:



	void Shoot(GameData& data) override;


	Ralentissante();
	~Ralentissante();


};