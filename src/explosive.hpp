#pragma once
#include "Tower.hpp"
#include <vector>
#include "imgui_utils.hpp"


struct GameData;



class Explosive : public Tower
{


public:
	
	float rayonOfMissile;
	
	
	float2 firstMissile;
	float2 basePosMissile;
	float velocityMissile;

	bool explosion;
	float rayonOfExplosion;

	 void TowerEffectRender(GameData& data) override;

	void Shoot(GameData& data) override;
	Explosive();
	Explosive(float2 missileStartPoint);
	~Explosive();

};