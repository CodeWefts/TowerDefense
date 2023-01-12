#pragma once
#include<iostream>
#include "enemy.hpp"

struct GameData;



class soigneur : public enemy
{
public:


	void Heal(GameData& data) override;
	void UpdateEnemy(GameData& Data,bool& erase) override;
	void DrawDebug(ImDrawList& dl) override;


	 soigneur() ;
	~soigneur();

private:

};

