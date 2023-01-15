
#include"Healer.hpp"
#include"tower_game.hpp"
#include"Collider2D.hpp"

#include"imgui.h"
#include"calc.hpp"


Healer::Healer()
{
	this->name = "Healer";
	this->maxHealt = 200;
	this->damageToPlayer = 100;
	this->currentHealth = this->maxHealt;
	this->pos = { 0,0 };
	this->velocity = 90.f;
	this->healRate = HealRate;

}

Healer::~Healer()
{
}


void Healer::DrawDebug(ImDrawList& dl)
{
	float2 enemypos = this->pos;

	dl.AddRect(enemypos - this->healBoxSize, enemypos + this->healBoxSize, IM_COL32(0, 255, 0, 255));
}


void Healer::Heal(GameData& data)
{
	//ImDrawList* boxhealer = ImGui::GetBackgroundDrawList();


	//boxhealer->AddRect( pos - HealBoxMax, pos + HealBoxMax, IM_COL32(0, 255, 0, 255));



	ImGui::Text("Healrate %f", healRate);
	healRate -= data.deltatime;

	
	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
	{

		enemy* current = *it;
		if (current->erase)
		{
			it++;
			current = *it;
		}
			



		float2 min = this->pos - healBoxSize;
		float2 max = this->pos + healBoxSize;

		// Not DIED

		if (current->currentHealth <= maxHealt && healRate <= 0 && colPoint2dtoAABB2d(min, max, current->pos)
			)
		{
			current->currentHealth += 10;
			healRate = HealRate;
		}





	}

}



void Healer::UpdateEnemy(GameData& data, bool& erase)
{
	pathFollow(data, erase);
	Heal(data);
}
