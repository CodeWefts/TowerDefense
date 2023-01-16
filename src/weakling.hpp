#pragma once
#include<iostream>
#include "enemy.hpp"


struct GameData;


class Weakling : public Enemy
{
public:




	 void UpdateEnemy(GameData& data,bool& erase) override;

	Weakling();
	~Weakling();

private:

};

