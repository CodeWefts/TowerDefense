#pragma once
#include<iostream>
#include "enemy.hpp"

struct GameData;

#define HealRate 7.5f
#define HealBoxSize 40


class Healer : public Enemy
{
public:


	void UpdateEnemy(GameData& Data, bool& erase) override;
	void DrawDebug(ImDrawList& dl) override;


	Healer();
	~Healer();

protected:

	int healValue;
	float healRate;
	float2 healBoxSize;
	Enemy* allyIsInRange;
	void Heal(GameData& data) override;

private:

};

