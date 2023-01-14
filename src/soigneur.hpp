#pragma once
#include<iostream>
#include "enemy.hpp"

struct GameData;

#define HealRate 7.5f

class soigneur : public enemy
{
public:

	float healRate;

	void Heal(GameData& data) override;
	void UpdateEnemy(GameData& Data,bool& erase) override;
	void DrawDebug(ImDrawList& dl) override;


	 soigneur() ;
	~soigneur();

private:

};

