
#include <vector>

#include "player.hpp"
#include "tower_game.hpp"
#include "Tower.hpp"
#include "map.hpp"

#include "classical.hpp"
#include "explosif.hpp"
#include "SlowingTurret.hpp"







void Player::PlayerTile(GameData& data)
{
	ImGuiIO& io2 = ImGui::GetIO();

	int MouseX = int(io2.MousePos.x);
	int MouseY = int(io2.MousePos.y);

	int TileSize = int(data.map.Tilesize);

	int TileMouseX = int(ReturnTileIndexX(MouseX, data.map));
	int TileMouseY = int(ReturnTileIndexX(MouseY, data.map));


	int TileMinX = int(ReturnTileMin(TileMouseX, TileMouseY, data.map).x);
	int TileMinY = int(ReturnTileMin(TileMouseX, TileMouseY, data.map).y);



	int TileMaxX = int(ReturnTileMax(TileMouseX, TileMouseY, data.map).x);
	int TileMaxY = int(ReturnTileMax(TileMouseX, TileMouseY, data.map).y);


	if (data.enableDebug)
	{
		ImGui::Text("Coord Mouse X : %d ", MouseX);
		ImGui::Text("Coord Mouse Y : %d ", MouseY);

		ImGui::Text("Tile Mouse X : %d ", TileMouseX);
		ImGui::Text("Tile Mouse Y : %d ", TileMouseY);

		ImGui::Text("Tile min {X ; Y} : {%d ; %d} ", TileMinX, TileMinY);

		ImGui::Text("Tile max {X ; Y} :  {%d ; %d} ", TileMaxX, TileMaxY);
	}
		

	ImVec2 TileX = { (float)TileMinX,  (float)TileMinY };
	ImVec2 TileY = { (float)TileMaxX,  (float)TileMaxY };

	data.dl->AddRect(TileX, TileY, IM_COL32(255, 255, 0, 255), 0);
}

void Player::PlayerInput(GameData& data)
{

	if (ImGui::IsKeyPressed(ImGuiKey_Tab, false))
	{

		data.enableDebug = not data.enableDebug;
	}

	if (ImGui::IsKeyPressed(ImGuiKey_RightArrow, false) && data.acceleRateTime < maxAcelerateTime)
	{

		data.acceleRateTime++;
	}
	if (ImGui::IsKeyPressed(ImGuiKey_LeftArrow, false) && data.acceleRateTime > 0)
	{
		data.acceleRateTime--;
	}


	if (ImGui::IsKeyPressed(ImGuiKey_DownArrow, false) && !data.playerStopTime)
	{
		data.acceleRateTimeBuffer = data.acceleRateTime;
		data.acceleRateTime = 0;
		data.playerStopTime = !data.playerStopTime;
	}
	else if (ImGui::IsKeyPressed(ImGuiKey_DownArrow, false) && data.playerStopTime)
	{
		data.acceleRateTime = data.acceleRateTimeBuffer;
		data.playerStopTime = !data.playerStopTime;
	}

}



void Player::DragAndDrop(GameData& data)
{
	ImGuiIO& io2 = ImGui::GetIO();
	Texture textureID = { 0 };


	//Coord MOUSE
	float posMaxX = ImGui::GetMousePos().x;
	float posMaxY = ImGui::GetMousePos().y;

	ImVec2 posMin = { ImGui::GetMousePos().x - 36,  ImGui::GetMousePos().y - 36 };
	ImVec2 posMax = { posMaxX + 36 , posMaxY + 36 };

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
			typeTower = CLASSICAL;
			textureID = data.asset.textureTowerClassique;
			data.dl->AddImage(textureID.id, posMin, posMax);
		}

		if ((clickX > (8 * 72))
			&& (clickX < (9 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = EXPLOSIF;
			textureID = data.asset.textureTowerExplosive;
			//data.dl->AddImage(textureID.id, posMin, posMax);
			data.dl->AddImage(textureID.id, posMin, posMax, ImVec2(0, 0), ImVec2(1100.f / 11.f / 1100.f, 1));

		}

		if ((clickX > (9 * 72))
			&& (clickX < (10 * 72))
			&& (clickY > (9 * 72))
			&& (clickY < (10 * 72)))
		{
			typeTower = SLOWINGTURRET;
			textureID = data.asset.texureSlowing;
			data.dl->AddImage(textureID.id, posMin, posMax);
		}

	}

	//PUSH BACK POINTER TOWER
	if (ImGui::IsKeyReleased(ImGuiKey_MouseLeft))
	{
		if (IsPlaceAble(data, float2(ImGui::GetMousePos().x, ImGui::GetMousePos().y)))
		{
			if (typeTower == CLASSICAL)
			{
				Tower* tower = new Classical();

				if (coins >= tower->cost)
				{
					tower->TileX = ReturnTileIndexX((int)posMin.x + 36, data.map) * 72;
					tower->TileY = ReturnTileIndexX((int)posMin.y + 36, data.map) * 72;

					data.towerVector.push_back(tower);
					coins -= int(tower->cost);
				}
			}
			else if (typeTower == EXPLOSIF)
			{
				int tileX = ReturnTileIndexX((int)posMin.x + 36, data.map) * 72;
				int tileY = ReturnTileIndexX((int)posMin.y + 36, data.map) * 72;
				Tower* tower = new Explosif(float2(tileX + data.map.Tilesize / 2, float(tileY - 50)));

				if (coins >= tower->cost)
				{
					tower->TileX = tileX;
					tower->TileY = tileY;

					data.towerVector.push_back(tower);
					coins -= int(tower->cost);
				}
			}
			else if (typeTower == SLOWINGTURRET)
			{
				Tower* tower = new SlowingTower();

				if (coins >= tower->cost)
				{
					tower->TileX = ReturnTileIndexX((int)posMin.x + 36, data.map) * 72;
					tower->TileY = ReturnTileIndexX((int)posMin.y + 36, data.map) * 72;

					data.towerVector.push_back(tower);
					coins -= int(tower->cost);
				}
			}
			typeTower = 0;
		}


	}

}

void Player::DrawTurretInfo(GameData& data, float x, float y, Tower* currentTower)
{
	ImGuiIO& io2 = ImGui::GetIO();
	float clickX = io2.MouseClickedPos->x;
	float clickY = io2.MouseClickedPos->y;

	data.dl->AddImage(data.asset.textureMenuHUD.id, { x, y - 200 }, { x + 250, y });

	string towerName = currentTower->name;
	string towerCost = std::to_string(currentTower->cost);
	string towerRange = std::to_string(currentTower->range);
	string towerDamage = std::to_string(currentTower->damage);
	string towerFireRate = std::to_string(currentTower->fireRate);

	data.dl->AddText({ x + 20, y - 180 }, ImColor(255, 255, 255, 255), towerName.c_str());
	data.dl->AddText({ x + 20, y - 160 }, ImColor(255, 255, 255, 255), towerCost.c_str());
	data.dl->AddText({ x + 20, y - 140 }, ImColor(255, 255, 255, 255), towerRange.c_str());
	data.dl->AddText({ x + 20, y - 120 }, ImColor(255, 255, 255, 255), towerDamage.c_str());
	data.dl->AddText({ x + 20, y - 100 }, ImColor(255, 255, 255, 255), towerFireRate.c_str());

	data.dl->AddImage(data.asset.textureUpgradeButton.id, { x + 25, y - 80 }, { x + 225, y - 20 });

}


void Player::ShowTurretInfo(GameData& data)
{
	ImGuiIO& io2 = ImGui::GetIO();

	ImVec2 max, min;

	float clickX = io2.MouseClickedPos->x;
	float clickY = io2.MouseClickedPos->y;

	

	for (auto it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;
		if (clickX >= currentTower->pos.x - data.map.Tilesize / 2 && clickX <= currentTower->pos.x + data.map.Tilesize / 2 &&
			clickY >= currentTower->pos.y - data.map.Tilesize / 2 && clickY <= currentTower->pos.y + data.map.Tilesize / 2)
		{
			data.showUpgrade = true;
			DrawTurretInfo(data, currentTower->pos.x, currentTower->pos.y, currentTower);
		}

		else if (clickX >= currentTower->pos.x + 25 && clickX <= currentTower->pos.x + 225 &&
			clickY >= currentTower->pos.y - 80 && clickY <= currentTower->pos.y - 20 && data.showUpgrade)
		{
			currentTower->Upgrade(data);
		}

	}
}


void Player::ShowOption(GameData& data)
{

	ImGuiIO& io2 = ImGui::GetIO();

	float clickX = io2.MouseClickedPos->x;
	float clickY = io2.MouseClickedPos->y;

	data.dl->AddImage(data.asset.textureOption.id, { 1224 , 648 }, { 1296 , 720 });

	if (clickX >= 1224 && clickX <= 1296 && clickY >= 648 && clickY <= 720)
	{
		data.showOption = true;

		data.dl->AddImage(data.asset.textureMenuHUD.id, { 230.5, 180 }, { 999.5, 600 });

		data.dl->AddImage(data.asset.textureMenuButton.id, { 480, 250 }, { 751, 350 });
		data.dl->AddImage(data.asset.textureLevels.id, { 480, 370 }, { 751, 470 });
		data.dl->AddImage(data.asset.textureSettings.id, { 480, 490 }, { 751, 590 });
	}

	else if (clickX <= 751 && clickX >= 480 && clickY <= 350 && clickY >= 250 && data.showOption)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
		{
			data.currentScene = Menu;
		}
	}

	else if (clickX <= 751 && clickX >= 480 && clickY <= 470 && clickY >= 370 && data.showOption)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
		{
			data.currentScene = Levels;
		}
	}

	else if (clickX <= 751 && clickX >= 480 && clickY <= 590 && clickY >= 490 && data.showOption)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
		{
		}

	}
}


void Player::UpdatePlayer(GameData& data)
{
	PlayerTile(data);
	PlayerInput(data);
	DragAndDrop(data);
	ShowTurretInfo(data);
	ShowOption(data);


}



Player::Player()
{
	this->maxHealth = 5000;
	this->health = this->maxHealth;

	this->typeTower = 0;

	this->score = 0;
	this->wave = 0;

}

Player::~Player()
{
}




