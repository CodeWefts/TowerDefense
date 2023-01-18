#pragma once
#include "tower.hpp"
#include "imgui_utils.hpp"


struct GameData;


class Ralentissante : public Tower
{


public:


	float maxBeamValue;
	float maxDebuffVelocity;
	float beamValue;

	int baseDamage;
	int beamBaseValue;

	int incrementDamage;
	int incrementeBeamValue;

	int maxDamage;

	void Shoot(GameData& data) override;
	void TowerEffectRender(GameData& data) override;

	void Reset(GameData& data) override;

	Ralentissante();
	~Ralentissante();


};