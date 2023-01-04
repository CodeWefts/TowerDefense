#include "Player.hpp"
#include"TowerGame.hpp"


void Player::PlayerInput(GameData& gamedata)
{
	if(ImGui::IsKeyPressed(ImGuiKey_N,false) )
	{

		gamedata.enableDebug = not gamedata.enableDebug;

	
		std::cout << gamedata.enableDebug << std::endl;
	}


}

Player::Player()
{
	this->coins = 0;
	this->health = 0;
	this->power = 0; 
	this->score = 0;
	this->wave = 0;
	this->wave = 0;
}

Player::~Player()
{
}




