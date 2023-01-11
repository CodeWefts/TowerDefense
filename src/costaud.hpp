#pragma once
#include<iostream>
#include "enemy.hpp"


struct GameData;

class costaud : public enemy
{
public:
	



	void UpdateEnemy(GameData& data) override;

	
	costaud();
	~costaud();

private:

};

