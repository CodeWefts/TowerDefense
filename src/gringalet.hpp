#pragma once
#include<iostream>
#include "enemy.hpp"


struct GameData;


class gringalet : public enemy
{
public:

	 void UpdateEnemy(GameData& data) override;

	gringalet();
	~gringalet();

private:

};

