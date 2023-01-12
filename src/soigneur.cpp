
#include"soigneur.hpp"
#include"TowerGame.hpp"
#include"Collider2D.hpp"
#include"imgui.h"
#include"calc.hpp"
#include"Calcul.hpp"


soigneur::soigneur()
{
	this->name = "soigneur";
	this->maxHealt = 100;
	this->currentHealth = this->maxHealt;
	this->pos = {0,0};
	this->velocity = 90.f;
	
	
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


 void soigneur::DrawSlider(ImDrawList& dl)
 {
	 // To Do ADD % HEALTH
	 

	 float posx = pos.x - 25; 
	 float maxlenght = 50;
	 float currentLenght = maxlenght * (float(this->currentHealth) / this->maxHealt);
	 std::cout << (float(this->currentHealth) / this->maxHealt) << std::endl;

	 dl.AddRect(float2(pos.x - 28, pos.y - 35), float2(pos.x + 28, pos.y - 20), IM_COL32(255, 0, 0, 255), 0, 5.f);
	 dl.AddRectFilled(float2(posx, pos.y - 33), float2(posx + currentLenght , pos.y - 22), IM_COL32(0, 255, 0, 255), 0, 5.f);
 }

void soigneur::UpdateEnemy(GameData& data,bool& erase)
{

	 Heal(data);


	 float2 FollowPath = ReturnCheckPointNearbest(data.map, this);



	 this->Heal(data);

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
