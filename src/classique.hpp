#pragma once
#include "tower.hpp"
#include "imgui_utils.hpp"


struct GameData;



class Classique : public Tower
{


public:


	void TowerEffectRender(GameData& data) override;
	void Upgrade(GameData& data) override;



	Classique();
	~Classique();

protected:

	void Shoot(GameData& data) override;

};