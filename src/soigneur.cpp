
#include"soigneur.hpp"
#include"TowerGame.hpp"
#include"Collider2D.hpp"
#include"imgui.h"


soigneur::soigneur()
{
	this->name = "soigneur";
	this->currentHealth = 100;
	this->maxHealt = 100;
	this->pos = {0,0};
	this->velocity = 50.f;
	
	
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


	
	for (auto it  = data.enemyVector.begin() ; it != data.enemyVector.end(); it++)
	{
		enemy* current = *it;

		
		

	}

}


void soigneur::UpdateEnemy(GameData& data)
{

	 Heal(data);

}
