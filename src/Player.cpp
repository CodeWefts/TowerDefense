#include "Player.hpp"
#include"TowerGame.hpp"
#include"Map.hpp"



#define maxAcelerateTime 4


void Player::PlayerTile(GameData& gamedata)
{
	ImGuiIO& io2 = ImGui::GetIO();

	int MouseX = io2.MousePos.x;
	int MouseY = io2.MousePos.y;

	int TileSize = gamedata.map.Tilesize;

	int TileMouseX = ReturnTileIndexX(MouseX,gamedata.map);
	int TileMouseY = ReturnTileIndexX(MouseY, gamedata.map);


	int TileMinX = ReturnTileMin(TileMouseX, TileMouseY, gamedata.map).x;	
	int TileMinY = ReturnTileMin(TileMouseX, TileMouseY, gamedata.map).y;



	int TileMaxX = ReturnTileMax(TileMouseX, TileMouseY, gamedata.map).x;

	//float2 Tilemax = ReturntopLeft(TileMouseX, TileMouseY, gamedata.map);

	int TileMaxY = ReturnTileMax(TileMouseX, TileMouseY, gamedata.map).y;



	ImGui::Text("Coord Mouse X : %d ", MouseX);
	ImGui::Text("Coord Mouse Y : %d ", MouseY);

	ImGui::Text("Tile Mouse X : %d ", TileMouseX);
	ImGui::Text("Tile Mouse Y : %d ", TileMouseY);

	ImGui::Text("Tile min {X ; Y} : {%d ; %d} ", TileMinX, TileMinY);

	ImGui::Text("Tile max {X ; Y} :  {%d ; %d} ", TileMaxX, TileMaxY);

	ImVec2 TileX = { (float)TileMinX,  (float)TileMinY };
	ImVec2 TileY = { (float)TileMaxX,  (float)TileMaxY };

	gamedata.dl->AddRect(TileX, TileY, IM_COL32(255, 255, 0, 255), 0);
	

}




void Player::PlayerInput(GameData& gamedata)
{






	if(ImGui::IsKeyPressed(ImGuiKey_N,false) )
	{

		gamedata.enableDebug = not gamedata.enableDebug;

	
		std::cout << gamedata.enableDebug << std::endl;
	}
		


	if (ImGui::IsKeyPressed(ImGuiKey_RightArrow, false) && gamedata.acceleRateTime < maxAcelerateTime)
	{
		
		gamedata.acceleRateTime++;
		std::cout << "acceleRateTime = " << gamedata.acceleRateTime << std::endl;
	}
	if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow, false) && gamedata.acceleRateTime  > 0)
	{
		gamedata.acceleRateTime--;
		std::cout << "acceleRateTime = " << gamedata.acceleRateTime << std::endl;
	}


	if (ImGui::IsKeyPressed(ImGuiKey_DownArrow,false) &&  !gamedata.playerStopTime)
	{
		gamedata.acceleRateTimeBuffer = gamedata.acceleRateTime;
		std::cout << "Buffer = " << gamedata.acceleRateTime << std::endl;
		gamedata.acceleRateTime = 0;
		std::cout << "acceleRateTime = " << gamedata.acceleRateTime << std::endl;
		gamedata.playerStopTime = !gamedata.playerStopTime; 
	}
	else if (ImGui::IsKeyPressed(ImGuiKey_DownArrow, false) && gamedata.playerStopTime)
	{
		gamedata.acceleRateTime = gamedata.acceleRateTimeBuffer;
		std::cout << "acceleRateTime = " << gamedata.acceleRateTime << std::endl;
		gamedata.playerStopTime = !gamedata.playerStopTime;
	}
	
	

}

Player::Player()
{
	this->coins = 0;
	this->maxHealth = 5000;
	this->health = this->maxHealth;

	this->power = 0; 
	this->tower = 0;

	this->score = 0;
	this->wave = 0;

}

Player::~Player()
{
}




