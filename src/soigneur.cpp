
#include"soigneur.hpp"
#include"TowerGame.hpp"
#include"Collider2D.hpp"

#include"imgui.h"
#include"calc.hpp"



soigneur::soigneur()
{
	this->name = "soigneur";
	this->maxHealt = 100;
	this->damageToPlayer = 100;
	this->currentHealth = this->maxHealt;
	this->pos = { 0,0 };
	this->velocity = 90.f;
	this->healRate = HealRate;

}

soigneur::~soigneur()
{
}


void soigneur::DrawDebug(ImDrawList& dl)
{
	float2 enemypos = this->pos;

	dl.AddRect(enemypos - this->healBoxSize, enemypos + this->healBoxSize, IM_COL32(0, 255, 0, 255));
}


void soigneur::Heal(GameData& data)
{
	//ImDrawList* boxhealer = ImGui::GetBackgroundDrawList();


	//boxhealer->AddRect( pos - HealBoxMax, pos + HealBoxMax, IM_COL32(0, 255, 0, 255));



	ImGui::Text("Healrate %f", healRate);
	healRate -= data.deltatime;

	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
	{
		enemy* current = *it;

		float2 min = this->pos - healBoxSize;
		float2 max = this->pos + healBoxSize;
		if (colPoint2dtoAABB2d(min, max, current->pos))
		{


			if (healRate <= 0)
			{
				current->currentHealth += 10.f;
				healRate = HealRate;
				std::cout << " = " << healRate << " , ";
			}

		}

	}

}



void soigneur::UpdateEnemy(GameData& data, bool& erase)
{
	pathFollow(data, erase);
	Heal(data);
}
