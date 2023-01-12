#include"costaud.hpp"
#include"TowerGame.hpp"
#include"calc.hpp"


costaud::costaud()
{
	this->name = "costaud";
	this->maxHealt = 400;
	this->currentHealth = 400;
	this->pos = { 0,0 };
	this->velocity = 50.f;
}

costaud::~costaud()
{

}


void costaud::UpdateEnemy(GameData& data,bool& erase)
{
	float2 FollowPath = ReturnCheckPointNearbest(data.map, this);



	

	// TO DO GET ENEMY TILE POS ANS NEXT CHECKPOINT TILE POS
	// TO DO ADD VECTOR BETWEEN 2 CHECK POINT B - nextcheckpoint

	float2 vectorenemy;

	//std::cout << ReturnPosfromChar(current->destination, data.map).x << " , " << ReturnPosfromChar(current->destination, data.map).y << std::endl;
	//std::cout << ReturnPosfromChar(current->baseChekcpoint, data.map).x << " , " << ReturnPosfromChar(current->baseChekcpoint, data.map).y << std::endl;

	//std::cout << it->baseChekcpoint << " , " << it->destination << std::endl;

	vectorenemy.x = ReturnPosfromChar(this->baseChekcpoint, data.map).x - ReturnPosfromChar(this->destination, data.map).x;
	vectorenemy.y = ReturnPosfromChar(this->baseChekcpoint, data.map).y - ReturnPosfromChar(this->destination, data.map).y;

	//std::cout << vectorenemy.x << " , " << vectorenemy.y << std::endl;


	//std::cout << " it = " << &**it << std::endl;
	//std::cout << " current = " << &*current << std::endl;

	//std::cout << " Destination = " << current->destination << std::endl;
	//std::cout << " offset =  " << current->offsetCheckPoint << std::endl;
	this->pos -= normaliseVector(vectorenemy) * data.deltatime * this->velocity;




	// TODO ADD better change pos if in tile
	if (this->pos > FollowPath - IsIncenter && this->pos < FollowPath + IsIncenter)
	{
		this->baseChekcpoint = this->destination;
		this->destination++;


		// make enemy destroy when on castle
		if (this->destination == 'g')
		{
			erase = true;
		}
	}
}
