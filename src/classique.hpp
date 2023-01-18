#pragma once
#include "Tower.hpp"
#include "imgui_utils.hpp"


struct GameData;


class Classique : public Tower
{


public:


	void TowerEffectRender(GameData& data) override;

	void Shoot(GameData& data) override; 


	Classique();
	~Classique();


};