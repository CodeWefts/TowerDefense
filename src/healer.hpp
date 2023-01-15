#pragma once
#include<iostream>
#include "enemy.hpp"

struct GameData;

#define HealRate 7.5f

class Healer : public enemy
{
public:



	void Heal(GameData& data) override;
	void UpdateEnemy(GameData& Data, bool& erase) override;
	void DrawDebug(ImDrawList& dl) override;


	Healer();
	~Healer();

protected:
	float healRate;

private:

};

