#pragma once
#include "tower.hpp"
#include <vector>
#include "imgui_utils.hpp"


struct GameData;



class Explosive : public Tower
{


public:

	bool explosion;
	bool hit;
	float rayonOfMissile;
	float rayonOfExplosion;
	void Reset(GameData& data);




	void TowerEffectRender(GameData& data) override;

	Explosive();
	Explosive(float2 missileStartPoint);
	~Explosive();

protected : 
	void Shoot(GameData& data) override;

	float2 firstMissile;
	float2 basePosMissile;
	float velocityMissile;

};