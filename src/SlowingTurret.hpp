#pragma once
#include "tower.hpp"
#include "imgui_utils.hpp"


struct GameData;


class SlowingTower : public Tower
{


public:


	


	void Upgrade(GameData& data) override;
	void TowerEffectRender(GameData& data) override;


	SlowingTower();
	~SlowingTower();

protected:
	void Shoot(GameData& data) override;
	

	void Reset(GameData& data) override;


private:

	double maxDebuffVelocity;
	double slowingValue;


	double maxBeamValue;
	double beamValue;

	double baseDamage;
	double beamBaseValue;

	double incrementDamage;
	double incrementeBeamValue;

	double maxDamage;
};