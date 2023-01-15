#include<random>
#include "enemy.hpp"
#include"calc.hpp"
#include"TowerGame.hpp"



#define HealBoxSize 40







float2 enemy::ReturnCheckPoint(GameData& data, int& index)
{
	for (auto it = data.listOfRoad[this->roadChoice].begin(); it != data.listOfRoad[this->roadChoice].end(); it++)
	{
		return data.listOfRoad[this->roadChoice].at(index);
	}
	return { 0,0 };
}



void  enemy::pathFollow(GameData& data, bool& erase)
{

	//float2 FollowPath = ReturnCheckPointNearbest(data, this);





	// TO DO GET ENEMY TILE POS ANS NEXT CHECKPOINT TILE POS
	// TO DO ADD VECTOR BETWEEN 2 CHECK POINT B - nextcheckpoint

	//float2 vectorenemy;
	//vectorenemy = ReturnPosfromChar(this->baseChekcpoint, data.map) - ReturnPosfromChar(this->destination, data.map);


	//std::cout << ReturnPosfromChar(current->destination, data.map).x << " , " << ReturnPosfromChar(current->destination, data.map).y << std::endl;
	//std::cout << ReturnPosfromChar(current->baseChekcpoint, data.map).x << " , " << ReturnPosfromChar(current->baseChekcpoint, data.map).y << std::endl;

	//std::cout << it->baseChekcpoint << " , " << it->destination << std::endl;


	//std::cout << vectorenemy.x << " , " << vectorenemy.y << std::endl;


	//std::cout << " it = " << &**it << std::endl;
	//std::cout << " current = " << &*current << std::endl;

	//std::cout << " previoius = " << this->previouscheckpoint << std::endl;
	//std::cout << " base = " << this->baseChekcpoint << std::endl;
	//std::cout << " Destination = " << this->destination << std::endl;
	//std::cout << " Destination++  = " << this->afterDestination << std::endl;
	//std::cout << " path = " << this->path << std::endl;

	//std::cout << " offset =  " << current->offsetCheckPoint << std::endl;

	float2 CheckpointPos = ReturnCheckPoint(data, this->destinationIndex);

	float2 Vector = this->pos - CheckpointPos;

	this->pos -= normaliseVector(Vector) * data.deltatime * this->velocity;



	//std::cout << "this->pos " << this->pos.x <<" , "<< this->pos.y << std::endl;
	//std::cout << " FollowPath - IsIncenter = " << (FollowPath - IsIncenter).x <<" , " << (FollowPath - IsIncenter).y << std::endl;
	// TODO ADD better change pos if in tile


	//data.dl->AddRect(FollowPath , FollowPath , IM_COL32(255, 0, 0, 255), 2, 0, 4);

	if (this->pos > CheckpointPos - IsIncenter && this->pos < CheckpointPos + IsIncenter)
	{
		/*if (baseChekcpoint != 'a')
		{
			this->previouscheckpoint = this->baseChekcpoint--;
		}

		this->baseChekcpoint = this->destination;
		this->destination++;
		this->afterDestination++;
		*/

		this->destinationIndex++;



		// make enemy destroy when on castle
		if (this->destinationIndex == data.listOfRoad[this->roadChoice].size())
		{
			data.player.health -= this->damageToPlayer;
			erase = true;
		}
	}

}



void enemy::UpdateEnemy(GameData& data, bool& erase)
{


}

void enemy::Heal(GameData& data)
{
	// Heal function override in Healer.cpp
}





void  enemy::DrawDebug(ImDrawList& dl)
{

}

void enemy::DrawSlider(ImDrawList& dl)
{



	int Height = 25;
	float posx = pos.x - 25;
	float maxlenght = 50;
	float currentLenght = maxlenght * (float(this->currentHealth) / this->maxHealt);


	ImColor color = ColorByHealth((float(this->currentHealth) / this->maxHealt), 0.35f, 0.75f);

	//dl.AddRect(float2(pos.x - maxlenght / 2, pos.y - 25), float2(pos.x + maxlenght / 2, pos.y - 20), color, 0, 0, 8.f);
	if (this->currentHealth >= 0)
	{
		dl.AddRectFilled(float2(posx, pos.y - 25), float2(posx + currentLenght, pos.y - 20), color, 0, 5.f);
	}

}



enemy::enemy()
{
	this->maxHealt = 100;
	this->currentHealth = maxHealt;


	this->destinationIndex = 0;


	this->healBoxSize = { HealBoxSize , HealBoxSize };
	this->roadChoice = Path0;

}

enemy::~enemy()
{
}