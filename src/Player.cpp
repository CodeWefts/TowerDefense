#include "Player.hpp"
#include"TowerGame.hpp"
#include"Map.hpp"

#include "classique.hpp"
#include "explosive.hpp"
#include "ralentissante.hpp"

#include <vector>



#define maxAcelerateTime 4


void Player::PlayerTile(GameData& gamedata)
{
	ImGuiIO& io2 = ImGui::GetIO();

	int MouseX = io2.MousePos.x;
	int MouseY = io2.MousePos.y;

	int TileSize = gamedata.map.Tilesize;

	int TileMouseX = ReturnTileIndexX(MouseX, gamedata.map);
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

	if (ImGui::IsKeyPressed(ImGuiKey_Tab, false))
	{

		gamedata.enableDebug = not gamedata.enableDebug;


		std::cout << gamedata.enableDebug << std::endl;
	}

	if (ImGui::IsKeyPressed(ImGuiKey_RightArrow, false) && gamedata.acceleRateTime < maxAcelerateTime)
	{

		gamedata.acceleRateTime++;
		std::cout << "acceleRateTime = " << gamedata.acceleRateTime << std::endl;
	}
	if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow, false) && gamedata.acceleRateTime > 0)
	{
		gamedata.acceleRateTime--;
		std::cout << "acceleRateTime = " << gamedata.acceleRateTime << std::endl;
	}


	if (ImGui::IsKeyPressed(ImGuiKey_DownArrow, false) && !gamedata.playerStopTime)
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


void Player::DragAndDrop(GameData& gamedata)
{
	ImGuiIO& io2 = ImGui::GetIO();
	Texture textureID;

	//Coord MOUSE
	float posMaxX = ImGui::GetMousePos().x + 72;
	float posMaxY = ImGui::GetMousePos().y + 72;

	ImVec2 posMin = ImGui::GetMousePos();
	ImVec2 posMax = { posMaxX , posMaxY };

	//coord CLICK
	float clickX = io2.MouseClickedPos->x;
	float clickY = io2.MouseClickedPos->y;

	// DRAG
	if (ImGui::IsKeyDown(ImGuiKey_MouseLeft))
	{
		if ((clickX > (7 * 72))
			&& (clickX < (8 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = 0;
			textureID = gamedata.asset.textureTowerClassique;
		}

		else if ((clickX > (8 * 72))
			&& (clickX < (9 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = 1;
			textureID = gamedata.asset.textureTowerExplosive;

		}

		else if ((clickX > (9 * 72))
			&& (clickX < (10 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = 2;
			textureID = gamedata.asset.textureTowerRalentissante;

		}

		//gamedata.dl->AddImage(textureID.id, posMin, posMax);
	}


	//PUSH BACK POINTER TOWER
	if (ImGui::IsKeyReleased(ImGuiKey_MouseLeft))
	{

		if (typeTower == 0)
		{
			Tower* tower = new Classique();
			tower->TileX = ReturnTileIndexX((int)posMin.x, gamedata.map) * 72;
			tower->TileY = ReturnTileIndexX((int)posMin.y, gamedata.map) * 72;

			gamedata.towerVector.push_back(tower);
		}
		else if (typeTower == 1)
		{
			Tower* tower = new Explosive();
			tower->TileX = ReturnTileIndexX((int)posMin.x, gamedata.map) * 72;
			tower->TileY = ReturnTileIndexX((int)posMin.y, gamedata.map) * 72;

			gamedata.towerVector.push_back(tower);
		}
		else if (typeTower == 2)
		{
			Tower* tower = new Ralentissante();
			tower->TileX = ReturnTileIndexX((int)posMin.x, gamedata.map) * 72;
			tower->TileY = ReturnTileIndexX((int)posMin.y, gamedata.map) * 72;

			gamedata.towerVector.push_back(tower);
		}
	}

}




Player::Player()
{
	this->coins = 0;
	this->maxHealth = 5000;
	this->health = this->maxHealth;

	this->power = 0;
	this->typeTower = 0;

	this->score = 0;
	this->wave = 0;

}

Player::~Player()
{
}




