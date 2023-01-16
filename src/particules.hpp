#pragma once
#include "Calcul.hpp"
#include "entity.hpp"
#include "imgui_utils.hpp"

struct GameData;


void AddHealingParticules(GameData& data, const float2& pos);




class Particule : public Entity
{
public:

	float lifeTimemax;
	float lifeTime;


	Particule();
	~Particule();

private:

};

