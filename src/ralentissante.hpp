#pragma once
#include "Tower.hpp"
#include "imgui_utils.hpp"


struct GameData;


class Ralentissante : public Tower
{


public:

	float beamValue;
	int baseDamage;
	int beamBaseValue;
	void Shoot(GameData& data) override;
	void TowerEffectRender(GameData& data) override;

	 void Reset(GameData& data) override;

	Ralentissante();
	~Ralentissante();


};