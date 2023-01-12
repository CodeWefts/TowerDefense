#include<random>
#include "enemy.hpp"
#include"calc.hpp"
#include"TowerGame.hpp"



#define HealBoxSize 40




float getOffsetCheckpoint()
{
	/*
	
	std::default_random_engine rd;

	std::uniform_real<float> dist(0,max);

	return dist(rd);
	*/

	srand(time(NULL));




	return Calc::randomFloat(10, 20);

}


 void enemy::UpdateEnemy(GameData& data,bool& erase)
{
	

}

void enemy::Heal(GameData& data)
{

}


void  enemy::DrawDebug(ImDrawList& dl)
{

}

 void enemy::DrawSlider(ImDrawList& dl)
{

	 
		 // To Do ADD % HEALTH


		 float posx = pos.x - 25;
		 float maxlenght = 50;
		 float currentLenght = maxlenght * (float(this->currentHealth) / this->maxHealt);
		 // std::cout << (float(this->currentHealth) / this->maxHealt) << std::endl;

		 dl.AddRect(float2(pos.x - 28, pos.y - 35), float2(pos.x + 28, pos.y - 20), IM_COL32(255, 0, 0, 255), 0, 8.f);
		 dl.AddRectFilled(float2(posx, pos.y - 33), float2(posx + currentLenght, pos.y - 22), IM_COL32(0, 255, 0, 255), 0, 5.f);
	 

}



enemy::enemy()
{
	
	this->maxHealt = 100;
	this->currentHealth = maxHealt;
	
	this->offsetCheckPoint = getOffsetCheckpoint();

	this->healBoxSize = { HealBoxSize , HealBoxSize };


}

enemy::~enemy()
{
}