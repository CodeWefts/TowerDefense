#include<random>
#include "enemy.hpp"
#include"calc.hpp"
#include "data.hpp"



#define HealBoxSize 40







float2 Enemy::ReturnCheckPoint(GameData& data, int& index)
{
	for (auto it = data.listOfRoad[this->roadChoice].begin(); it != data.listOfRoad[this->roadChoice].end(); it++)
	{
		return data.listOfRoad[this->roadChoice].at(index);
	}
	return { 0,0 };
}



void  Enemy::pathFollow(GameData& data, bool& erase)
{

	float2 CheckpointPos = ReturnCheckPoint(data, this->destinationIndex);

	float2 Vector = this->pos - CheckpointPos;

	this->pos -= normaliseVector(Vector) * data.deltatime * this->velocity;



	if (this->pos > CheckpointPos - IsIncenter && this->pos < CheckpointPos + IsIncenter)
	{

		this->destinationIndex++;

		// make enemy destroy when on castle
		if (this->destinationIndex == data.listOfRoad[this->roadChoice].size())
		{
			data.player.health -= this->damageToPlayer;
			erase = true;
		}
	}

}



void Enemy::UpdateEnemy(GameData& data, bool& erase)
{


}

void Enemy::Heal(GameData& data)
{
	// Heal function override in Healer.cpp
}





void  Enemy::DrawDebug(ImDrawList& dl)
{

}

void Enemy::DrawSlider(ImDrawList& dl)
{



	int Height = 25;
	float posx = pos.x - 25;
	float maxlenght = 50;
	float currentLenght = maxlenght * (float(this->currentHealth) / this->maxHealt);


	ImColor color = ColorByHealth((float(this->currentHealth) / this->maxHealt), 0.35f, 0.75f);

	//dl.AddRect(float2(pos.x - maxlenght / 2, pos.y - 25), float2(pos.x + maxlenght / 2, pos.y - 20), color, 0, 0, 8.f);
	if (this->currentHealth > 0)
	{
		dl.AddRectFilled(float2(posx, pos.y - 25), float2(posx + currentLenght, pos.y - 20), color, 0, 5);
	}

}



Enemy::Enemy()
{
	this->velocity = 0.f;
	this->texture = {0};
	this->damageToPlayer = 50;
	this->maxHealt = 100;
	this->currentHealth = maxHealt;
	this->erase = false;

	this->destinationIndex = 1;

	this->coinsToPlayer = 0;
	this->healBoxSize = { HealBoxSize , HealBoxSize };
	this->roadChoice = Path0;

}

Enemy::~Enemy()
{
}