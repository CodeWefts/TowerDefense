
#include "Point2D.hpp"
#include "TowerGame.hpp"
#include "TowerRenderer.hpp"
#include"Calcul.hpp"
#include"float2.hpp"














void TowerRenderer::drawMap(GameData& data)
{
	static float tileSize = data.map.Tilesize;

	ImGui::SliderFloat("tileSize", &data.map.Tilesize, 0.f, 100.f);

	float originX = 0.f;
	// Build tilemap from string
	for (int i = 0; i < data.map.Width * data.map.Height; ++i)
	{
		int x = i % data.map.Width; // return pos x on char table
		int y = i / data.map.Width; // return pos y on char table
		Tile& tile = data.map.Tiles[i]; // Get Tile texture type
	
		ImVec2 topLeft = ReturnTileMin(x, y, data.map);
		ImVec2 topRight = ReturnTileMax(x, y, data.map);

		ImVec2 center = ReturnCenterTile(x,y, data.map); // center / checkpooint

		switch (tile.Texture_type)
		{

		default:
			break;

		case ' ':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'p':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'a':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'b':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'c':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case 'd':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'e':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'f':
			//data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case 'j':
			data.dl->AddImage(data.asset.texturePathBottomANDRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'l':
			data.dl->AddImage(data.asset.texturePathBottomANDLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 't':
			data.dl->AddImage(data.asset.texturePathTopANDLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '!':
			data.dl->AddImage(data.asset.texturePathTopANDRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case '_':
			data.dl->AddImage(data.asset.texturePathBottom.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '-':
			data.dl->AddImage(data.asset.texturePathTop.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case '|':
			data.dl->AddImage(data.asset.texturePathRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '/':
			data.dl->AddImage(data.asset.texturePathLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case '*':
			data.dl->AddImage(data.asset.texturePathTopLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '+':
			data.dl->AddImage(data.asset.texturePathTopRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case ',':
			data.dl->AddImage(data.asset.texturePathBottomLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case ';':
			data.dl->AddImage(data.asset.texturePathBottomRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case 'k':
			//chateaux
			break;

		case 'g':
			//data.dl->AddImage(data.asset.textureSoigneur.id, topLeft, topRight, ImVec2(0, 0), ImVec2(0.35, 0.25));
			break;


		case '1':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			data.dl->AddImage(data.asset.textureTowerSideLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '2':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			data.dl->AddImage(data.asset.textureTowerSideRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '3':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			data.dl->AddImage(data.asset.textureTowerCase.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;



		}

		if (data.enableDebug)
		{
			data.dl->AddRect(topLeft, topRight, IM_COL32(255, 255, 255, 255), 0);
		}
			


	}

}




void TowerRenderer::drawEnemies(GameData& data)
{
	//ImDrawList* data.dl = ImGui::GetBackgroundDrawList();




	for (std::vector<enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end(); ++it)
	{

		
		enemy* currentEnemy = *it;

		float2 enemy = currentEnemy->pos;


		if (currentEnemy->name == "soigneur")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureSoigneur;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 15, enemy + 15, ImVec2(0, 0), ImVec2(0.35, 0.25), IM_COL32(255, 255, 255, 255));
		}
		else if (currentEnemy->name == "costaud")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureCostaud2;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 30, enemy += 30, ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 255));
		}
		else if (currentEnemy->name == "gringalet")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureGringalet;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 30, enemy += 30, ImVec2(0, 0), ImVec2(0.35, 0.25), IM_COL32(255, 255, 255, 255));
		}


		currentEnemy->DrawSlider(*data.dl);

		if (data.enableDebug)
			currentEnemy->DrawDebug(*(data.dl));



	}
}



void TowerInInventoryHUD(GameData& data)
{

	ImVec2 min = { 7 * 72 + 15, 9 * 72 + 13 };
	ImVec2	max = { 8 * 72 - 10, 10 * 72 - 13 };


	data.dl->AddImage(data.asset.textureTowerClassique.id, min, max, ImVec2(0, 0), ImVec2(1, 1));
}
void TowerRenderer::HudInventory(GameData& data)
{

	// BRUT 
	int minX = 6;
	int maxX = 7;

	int minY = 9;
	int maxY = 10;
	for (int i = 0; i <= 5; i++)
	{
		if (i == 0)
			data.dl->AddImage(data.asset.textureTowerSideLeft.id, { minX * data.map.Tilesize, minY * data.map.Tilesize }, { maxX * data.map.Tilesize, maxY * data.map.Tilesize });

		else if (i >= 1 && i <= 4)
			data.dl->AddImage(data.asset.textureTowerCase.id, { minX * data.map.Tilesize, minY * data.map.Tilesize }, { maxX * data.map.Tilesize, maxY * data.map.Tilesize });

		else
			data.dl->AddImage(data.asset.textureTowerSideRight.id, { minX * data.map.Tilesize, minY * data.map.Tilesize }, { maxX * data.map.Tilesize, maxY * data.map.Tilesize });

		minX++;
		maxX++;
	}

	TowerInInventoryHUD(data);
	
}

void TowerRenderer::DrawHud(GameData& data)
{
	if (ImGui::IsKeyPressed(ImGuiKey_Y, false))
	{
		data.player.health -= 100;
	}
	
	float maxlenght = 520;
	float returnHealPercent = (float(data.player.health) / data.player.maxHealth);
	float currentLenght = maxlenght * returnHealPercent;

	ImColor color = ColorByHealth(returnHealPercent, 0.35f, 0.75f);
	
	data.dl->AddRectFilled(float2(20, 20), float2(currentLenght, 60), color, 5.f, 0);
	if (data.player.health >= 0)
	{
		data.dl->AddRect(float2(20, 20), float2(520, 60), IM_COL32(255, 255, 255, 255), 5.f, 0, 4.f);
	}
	
	data.dl->AddImage(data.asset.PlayerHeart.id, float2(2.5, 2.5), float2(75, 75));

	//data.dl->AddText(float2(10, 70), IM_COL32(255, 255, 255, 255), "sqdsqdqsdqsdsq", NULL);
	
}

void TowerRenderer::DrawPlacedTurret(GameData& data)
{
	ImDrawList* enemydrawlist = ImGui::GetBackgroundDrawList();

	for (std::vector<Tower*>::iterator it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;

		if (currentTower->type == 0)
		{
			//std::cout << "Tile X :: " << currentTower->TileX << std::endl;
			//std::cout << "Tile Y :: " << currentTower->TileY << std::endl;
			
			ImVec2 TileMin = { (float)currentTower->TileX , (float)currentTower->TileY };
			ImVec2 TileMax = { (float)currentTower->TileX +72, (float)currentTower->TileY +72 };
			currentTower->texture = data.asset.textureTowerClassique;
			data.dl->AddImage(currentTower->texture.id, TileMin, TileMax);
		}
		if (currentTower->type == 1)
		{
			ImVec2 TileMin = { (float)currentTower->TileX , (float)currentTower->TileY };
			ImVec2 TileMax = { (float)currentTower->TileX + 72, (float)currentTower->TileY + 72 };
			currentTower->texture = data.asset.textureTowerExplosive;
			data.dl->AddImage(currentTower->texture.id, TileMin, TileMax);
		}
		if (currentTower->type == 2)
		{
			ImVec2 TileMin = { (float)currentTower->TileX , (float)currentTower->TileY };
			ImVec2 TileMax = { (float)currentTower->TileX + 72, (float)currentTower->TileY + 72 };
			currentTower->texture = data.asset.textureTowerRalentissante;
			data.dl->AddImage(currentTower->texture.id, TileMin, TileMax);
		}
	}
	
}


void TowerRenderer::DrawCheckPoint(GameData& data) 
{
	for (auto it = data.listOfRoad[0].begin(); it != data.listOfRoad[0].end(); it++)
	{
		data.dl->AddCircle(*it, 15.f, IM_COL32(255, 0, 0, 255), 32, 2.f);
	}
	for (auto it = data.listOfRoad[1].begin(); it != data.listOfRoad[1].end(); it++)
	{
		data.dl->AddCircle(*it, 15.f, IM_COL32(0, 255, 0, 255), 32, 2.f);
	}
	for (auto it = data.listOfRoad[2].begin(); it != data.listOfRoad[2].end(); it++)
	{
		data.dl->AddCircle(*it, 15.f, IM_COL32(0, 0, 255, 255), 32, 2.f);
	}
}



void TowerRenderer::RendererGame(GameData& data)
{
	drawMap(data);
	drawEnemies(data);
	DrawPlacedTurret(data);
	DrawHud(data);
	DrawCheckPoint(data);

}



TowerRenderer::TowerRenderer()
{

}

TowerRenderer::~TowerRenderer()
{

}