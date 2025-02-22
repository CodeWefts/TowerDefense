#include<random>
#include "enemy.hpp"
#include"calc.hpp"
#include "data.hpp"









// Return The Position of the Next Checkpoint
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

	if (currentLenght > maxlenght)
	{
		currentLenght = maxlenght;
	}

	ImColor color = ColorByHealth((float(this->currentHealth) / this->maxHealt), 0.35f, 0.75f);

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
	this->type = NULLENEMY;
	this->destinationIndex = 1;

	this->coinsToPlayer = 0;
	this->roadChoice = 0;


	this->animationMinX = 0;
	this->animationMinY = 0;
	this->animationMaxX = 0;
	this->animationMaxY = 0;

	this->vecMaxX = 0;

	this->vecMaxY = 0;

	this->timeMove = 0;
;

}

Enemy::~Enemy()
{
}