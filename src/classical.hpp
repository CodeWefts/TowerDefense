#pragma once
#include "tower.hpp"
#include "imgui_utils.hpp"


struct GameData;



class Classical : public Tower
{


public:


	void TowerEffectRender(GameData& data) override;
	void Upgrade(GameData& data) override;



	Classical();
	~Classical();

protected:

	void Shoot(GameData& data) override;

};