#pragma once
#include<iostream>
#include "enemy.hpp"


struct GameData;

class Heavy : public Enemy
{
public:
	


	


	void UpdateEnemy(GameData& data,bool& erase) override;

	
	Heavy();
	~Heavy();

private:

};

