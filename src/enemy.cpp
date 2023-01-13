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



void  enemy::pathFollow(GameData& data, bool& erase)
{

	float2 FollowPath = ReturnCheckPointNearbest(data.map, this);



	this->Heal(data);

	// TO DO GET ENEMY TILE POS ANS NEXT CHECKPOINT TILE POS
	// TO DO ADD VECTOR BETWEEN 2 CHECK POINT B - nextcheckpoint

	float2 vectorenemy;

	//std::cout << ReturnPosfromChar(current->destination, data.map).x << " , " << ReturnPosfromChar(current->destination, data.map).y << std::endl;
	//std::cout << ReturnPosfromChar(current->baseChekcpoint, data.map).x << " , " << ReturnPosfromChar(current->baseChekcpoint, data.map).y << std::endl;

	//std::cout << it->baseChekcpoint << " , " << it->destination << std::endl;

	vectorenemy = ReturnPosfromChar(this->baseChekcpoint, data.map) - ReturnPosfromChar(this->destination, data.map);

	//std::cout << vectorenemy.x << " , " << vectorenemy.y << std::endl;


	//std::cout << " it = " << &**it << std::endl;
	//std::cout << " current = " << &*current << std::endl;

	//std::cout << " base = " << this->baseChekcpoint << std::endl;
	//std::cout << " Destination = " << this->destination << std::endl;
	//std::cout << " Destination++  = " << this->afterDestination << std::endl;
	//std::cout << " path = " << this->path << std::endl;

	//std::cout << " offset =  " << current->offsetCheckPoint << std::endl;
	this->pos -= normaliseVector(vectorenemy) * data.deltatime * this->velocity;



	//std::cout << "this->pos " << this->pos.x <<" , "<< this->pos.y << std::endl;
	//std::cout << " FollowPath - IsIncenter = " << (FollowPath - IsIncenter).x <<" , " << (FollowPath - IsIncenter).y << std::endl;
	// TODO ADD better change pos if in tile


	data.dl->AddRect(FollowPath , FollowPath , IM_COL32(255, 0, 0, 255), 2, 0, 4);
	if (this->pos > FollowPath - IsIncenter && this->pos < FollowPath + IsIncenter)
	{
		this->baseChekcpoint = this->destination;
		this->destination++;
		this->afterDestination++;


		// make enemy destroy when on castle
		if (this->destination == 'g')
		{
			data.player.health -= this->damageToPlayer;
			erase = true;
		}
	}

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

	 
		
		 float posx = pos.x - 25;
		 float maxlenght = 50;
		 float currentLenght = maxlenght * (float(this->currentHealth) / this->maxHealt);
		 ImColor color = ColorByHealth((float(this->currentHealth) / this->maxHealt), 0.35f, 0.75f);
		 dl.AddRect(float2(pos.x - 28, pos.y - 35), float2(pos.x + 28, pos.y - 20), color, 0, 8.f);
		 dl.AddRectFilled(float2(posx, pos.y - 33), float2(posx + currentLenght, pos.y - 22), color, 0, 5.f);
	 
}



enemy::enemy()
{
	this->maxHealt = 100;
	this->currentHealth = maxHealt;
	this->baseChekcpoint = 'a';
	this->destination = 'b';
	this->afterDestination = 'c';
	
	this->offsetCheckPoint = getOffsetCheckpoint();

	this->healBoxSize = { HealBoxSize , HealBoxSize };


}

enemy::~enemy()
{
}