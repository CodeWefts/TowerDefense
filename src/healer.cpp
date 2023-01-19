
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
	this->coinsToPlayer = 20;
	this->healValue = 30;
	this->healBoxSize = { HealBoxSize , HealBoxSize };

	Enemy* allyIsInRange = nullptr;

}

Healer::~Healer()
{
	delete allyIsInRange;
}


void Healer::DrawDebug(ImDrawList& dl)
{
	float2 enemypos = this->pos;

	dl.AddRect(enemypos - this->healBoxSize, enemypos + this->healBoxSize, IM_COL32(0, 255, 0, 255));
}


void Healer::Heal(GameData& data)
{
	healRate -= data.deltatime;

	
	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
	{

		Enemy* current = *it;
		float2 min = this->pos - healBoxSize;
		float2 max = this->pos + healBoxSize;


		if(allyIsInRange != nullptr)
		{
			if(colPoint2dtoAABB2d(min, max, current->pos))
			{
				current = allyIsInRange;
			}
			else
			{
				allyIsInRange = nullptr;

			}
		}
		else if (current != this &&  current->currentHealth + 40 <= maxHealt && healRate <= 0 && colPoint2dtoAABB2d(min, max, current->pos))
		{
			if(current->currentHealth + healValue >= maxHealt)
			{
				current->currentHealth += maxHealt - current->currentHealth;
				
			}
			else
			{
				current->currentHealth += healValue;
			}
			
			healRate = HealRate;
		}

	}

}


void Healer::UpdateEnemy(GameData& data, bool& erase)
{
	pathFollow(data, erase);
	Heal(data);
}
