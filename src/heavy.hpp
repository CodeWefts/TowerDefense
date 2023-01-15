#pragma once
#include<iostream>
#include "enemy.hpp"


struct GameData;

class Heavy : public enemy
{
public:
	

	int indexStaticDebugCostaud;


	void UpdateEnemy(GameData& data,bool& erase) override;

	
	Heavy();
	~Heavy();

private:

};

