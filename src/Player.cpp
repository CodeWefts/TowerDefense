
#include <vector>

#include "player.hpp"
#include "tower_game.hpp"
#include "map.hpp"

#include "classique.hpp"
#include "explosive.hpp"
#include "ralentissante.hpp"




#define maxAcelerateTime 4


void Player::PlayerTile(GameData& gamedata)
{
	ImGuiIO& io2 = ImGui::GetIO();

	int MouseX = int(io2.MousePos.x);
	int MouseY = int(io2.MousePos.y);

	int TileSize = int(gamedata.map.Tilesize);

	int TileMouseX = int(ReturnTileIndexX(MouseX, gamedata.map));
	int TileMouseY = int(ReturnTileIndexX(MouseY, gamedata.map));


	int TileMinX = int(ReturnTileMin(TileMouseX, TileMouseY, gamedata.map).x);
	int TileMinY = int(ReturnTileMin(TileMouseX, TileMouseY, gamedata.map).y);



	int TileMaxX = int(ReturnTileMax(TileMouseX, TileMouseY, gamedata.map).x);

	//float2 Tilemax = ReturntopLeft(TileMouseX, TileMouseY, gamedata.map);

	int TileMaxY = int(ReturnTileMax(TileMouseX, TileMouseY, gamedata.map).y);



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
	Texture textureID = { 0 };


	//Coord MOUSE
	float posMaxX = ImGui::GetMousePos().x + 72;
	float posMaxY = ImGui::GetMousePos().y + 72;

	ImVec2 posMin = ImGui::GetMousePos();
	ImVec2 posMax = { posMaxX , posMaxY };

	//coord CLICK
	float clickX = io2.MouseClickedPos->x;
	float clickY = io2.MouseClickedPos->y;

	bool drag = ImGui::IsKeyDown(ImGuiKey_MouseLeft);

	// DRAG
	if (drag)
	{
		if ((clickX > (7 * 72))
			&& (clickX < (8 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = CLASSIQUE;
			textureID = gamedata.asset.textureTowerClassique;
			gamedata.dl->AddImage(textureID.id, posMin, posMax);
		}

		if ((clickX > (8 * 72))
			&& (clickX < (9 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = EXPLOSIVE;
			textureID = gamedata.asset.textureTowerExplosive;
			gamedata.dl->AddImage(textureID.id, posMin, posMax);

		}

		if ((clickX > (9 * 72))
			&& (clickX < (10 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = RALENTISSANTE;
			textureID = gamedata.asset.texureSlowing;
			gamedata.dl->AddImage(textureID.id, posMin, posMax);
		}

	}


	//PUSH BACK POINTER TOWER
	if (ImGui::IsKeyReleased(ImGuiKey_MouseLeft))
	{
		if (IsPlaceAble(gamedata, float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y)))
		{
			if (typeTower == 1)
			{
				Tower* tower = new Classique();
				tower->TileX = ReturnTileIndexX((int)posMin.x, gamedata.map) * 72;
				tower->TileY = ReturnTileIndexY((int)posMin.y, gamedata.map) * 72;

				gamedata.towerVector.push_back(tower);
			}
			else if (typeTower == 2)
			{
				int tileX = ReturnTileIndexX((int)posMin.x, gamedata.map) * 72;
				int tileY = ReturnTileIndexY((int)posMin.y, gamedata.map) * 72;
				Tower* tower = new Explosive(float2(tileX + gamedata.map.Tilesize /2, tileY - 50));
				tower->TileX = tileX;
				tower->TileY = tileY;

				gamedata.towerVector.push_back(tower);
			}
			else if (typeTower == 3)
			{
				Tower* tower = new Ralentissante();
				tower->TileX = ReturnTileIndexX((int)posMin.x, gamedata.map) * 72;
				tower->TileY = ReturnTileIndexY((int)posMin.y, gamedata.map) * 72;

				gamedata.towerVector.push_back(tower);

			}
			typeTower = 0;
		}


	}

}
void Player::UpdatePlayer(GameData& gamedata)
{
	PlayerTile(gamedata);
	PlayerInput(gamedata);
	DragAndDrop(gamedata);

}



Player::Player()
{


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




