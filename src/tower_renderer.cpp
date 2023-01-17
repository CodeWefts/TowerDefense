
#include <vector>
#include "Point2D.hpp"
#include "data.hpp"
#include "tower_renderer.hpp"
#include "Calcul.hpp"
#include "float2.hpp"
#include "calc.hpp"


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

		ImVec2 center = ReturnCenterTile(x, y, data.map); // center / checkpooint

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
<<<<<<< HEAD
	//ImDrawList* data.dl = ImGui::GetBackgroundDrawList();




	for (std::vector<Enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end(); ++it)
	{


		Enemy* currentEnemy = *it;

=======
	for (std::vector<enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end(); ++it)
	{
		enemy* currentEnemy = *it;
>>>>>>> a18d7c8 (#4 closed)
		float2 enemy = currentEnemy->pos;

		if (currentEnemy->name == "Healer")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureSoigneur;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 15, enemy + 15, ImVec2(0, 0), ImVec2(0.35f, 0.25f), IM_COL32(255, 255, 255, 255));
		}
		else if (currentEnemy->name == "Heavy")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureCostaud2;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 30, enemy += 30, ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 255));
		}
		else if (currentEnemy->name == "Weakling")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureGringalet;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 30, enemy += 30, ImVec2(0, 0), ImVec2(0.35f, 0.25f), IM_COL32(255, 255, 255, 255));
		}


		currentEnemy->DrawSlider(*data.dl);

		if (data.enableDebug)
			currentEnemy->DrawDebug(*(data.dl));
	}
}



void TowerInInventoryHUD(GameData& data)
{
	
	ImVec2 min = { 
		7 * data.map.Tilesize + 15,
		9 * data.map.Tilesize + 13 
	}, max = { 
		8 * data.map.Tilesize - 10, 
		10 * data.map.Tilesize - 13 
	};

	ImGui::Text("Mouse X %f", data.io.MousePos.x);
	ImGui::Text("Mouse Y %f", data.io.MousePos.y);

	ImGui::Text("Min X %f", min.x);
	ImGui::Text("Min Y %f", max.y);

	data.dl->AddImage(data.asset.textureTowerClassique.id, min, max, ImVec2(0, 0), ImVec2(1, 1));

	data.dl->AddImage(data.asset.textureTowerExplosive.id, {min.x + 72 , min.y}, { max.x + 72 , max.y }, ImVec2(0, 0), ImVec2(1, 1));

	data.dl->AddImage(data.asset.textureTowerRalentissante.id, { min.x + 72*2 , min.y }, { max.x + 72*2 , max.y }, ImVec2(0, 0), ImVec2(1, 1));

	if (data.io.MousePos.x >= min.x - 15 && data.io.MousePos.x <= max.x + 10 &&
		data.io.MousePos.y >= min.y - 13 && data.io.MousePos.y <= max.y + 13
		)
	{
		data.dl->AddImage(data.asset.textureMenuHUD.id, { data.io.MousePos.x, data.io.MousePos.y - 200 }, { data.io.MousePos.x + 250, data.io.MousePos.y });
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 180 }, ImColor(255, 255, 255, 255), "Name : Classique");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 160 }, ImColor(255, 255, 255, 255), "Cost : 25");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 140 }, ImColor(255, 255, 255, 255), "Range : 1");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 120 }, ImColor(255, 255, 255, 255), "Damage : 10");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 100 }, ImColor(255, 255, 255, 255), "FireRate : 0.5");
	}
	if (data.io.MousePos.x >= min.x + 72 - 15 && data.io.MousePos.x <= max.x + 72 + 10 &&
		data.io.MousePos.y >= min.y - 13 && data.io.MousePos.y <= max.y + 13
		)
	{
		data.dl->AddImage(data.asset.textureMenuHUD.id, { data.io.MousePos.x, data.io.MousePos.y - 200 }, { data.io.MousePos.x + 250, data.io.MousePos.y });
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 180 }, ImColor(255, 255, 255, 255), "Name : Explosive");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 160 }, ImColor(255, 255, 255, 255), "Cost : 50");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 140 }, ImColor(255, 255, 255, 255), "Range : 2");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 120 }, ImColor(255, 255, 255, 255), "Damage : 10");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 100 }, ImColor(255, 255, 255, 255), "FireRate : 0.5");
	}
	if (data.io.MousePos.x >= min.x + 72 * 2 - 15 && data.io.MousePos.x <= max.x + 72 * 2 + 10 &&
		data.io.MousePos.y >= min.y - 13 && data.io.MousePos.y <= max.y + 13
		)
	{
		data.dl->AddImage(data.asset.textureMenuHUD.id, { data.io.MousePos.x, data.io.MousePos.y - 200 }, { data.io.MousePos.x + 250, data.io.MousePos.y });
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 180 }, ImColor(255, 255, 255, 255), "Name : Ralentissante");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 160 }, ImColor(255, 255, 255, 255), "Cost : 150");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 140 }, ImColor(255, 255, 255, 255), "Range : 2");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 120 }, ImColor(255, 255, 255, 255), "Damage : 10");
		data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 100 }, ImColor(255, 255, 255, 255), "FireRate : 0.5");
	}

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


	

	//Print Player Coins
	string playerCoins = std::to_string(data.player.coins);
	data.dl->AddText(float2(20, 100), IM_COL32(255, 255, 255, 255), playerCoins.c_str());
	
	string playerHeatl = std::to_string(data.player.health);
	data.dl->AddText(float2(100, 100), IM_COL32(255, 255, 255, 255), playerHeatl.c_str());
	

}


void DrawRangeTurret(GameData& data)
{
	for (std::vector<Tower*>::iterator it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;
		//currentTower->TileX

		ImVec2 centerTower = { (float)currentTower->TileX + 36,(float)currentTower->TileY + 36 };

		data.dl->AddCircle(centerTower, (float)currentTower->range * 72 + 36, IM_COL32(0, 255, 255, 255));
	}
}



void TowerRenderer::DrawPlacedTurret(GameData& data)
{
	// TO-DO OPTIMISATION OF IF

	for (auto it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;

<<<<<<< HEAD
		

		if (currentTower->type == 1)
=======
		if (currentTower->type == 1)
		{
			ImVec2 TileMin = { (float)currentTower->TileX , (float)currentTower->TileY };
			ImVec2 TileMax = { (float)currentTower->TileX + 72, (float)currentTower->TileY + 72 };
			currentTower->pos = { (float)currentTower->TileX + data.map.Tilesize / 2, (float)currentTower->TileY + data.map.Tilesize / 2 };
			currentTower->texture = data.asset.textureTowerClassique;
			data.dl->AddImage(currentTower->texture.id, TileMin, TileMax);
			
		}
		if (currentTower->type == 2)
>>>>>>> a18d7c8 (#4 closed)
		{
			float2 tileMin = { (float)currentTower->TileX , (float)currentTower->TileY };
			float2 tileMax = { (float)currentTower->TileX + 72, (float)currentTower->TileY + 72 };		 
			currentTower->pos = { (float)currentTower->TileX + data.map.Tilesize / 2, (float)currentTower->TileY + data.map.Tilesize / 2 };
			currentTower->texture = data.asset.textureTowerClassicalBase;
			currentTower->canonTexture = data.asset.textureTowerClassicalCanon;
			data.dl->AddImage(currentTower->texture.id, tileMin, tileMax);
			
			// if turretHasTarget
			if(currentTower->hasTarget)
			{
				float2 targetVector = currentTower->target->pos  - currentTower->pos  ;
				// Fond angle between enemy and turret
				currentTower->angle = -atan2f(targetVector.x, targetVector.y) ;
				std::cout << currentTower->angle << std::endl;
			}// initiate 4 point of the image of canon
			float2 Point4[4] =
			{
			 tileMin,float2(tileMax.x,tileMin.y),tileMax , float2(tileMin.x,tileMax.y)
			};
			for (int i = 0; i < 4; i++)
			{
				// add point Rotation
				Point4[i] = Rotationfloat2(Point4[i], currentTower->pos, currentTower->angle);	
			}
			data.dl->AddImageQuad(currentTower->canonTexture.id, Point4[3], Point4[2], Point4[1], Point4[0]);


		}
		if (currentTower->type == 3)
		{
			ImVec2 TileMin = { (float)currentTower->TileX , (float)currentTower->TileY };
			ImVec2 TileMax = { (float)currentTower->TileX + 72, (float)currentTower->TileY + 72 };
			currentTower->pos = { (float)currentTower->TileX + data.map.Tilesize / 2, (float)currentTower->TileY + data.map.Tilesize / 2 };
			currentTower->texture = data.asset.textureTowerExplosive;
			currentTower->canonTexture= { 0 };
			data.dl->AddImage(currentTower->texture.id, TileMin, TileMax);
		}
		if (currentTower->type == 3)
		{
			ImVec2 TileMin = { (float)currentTower->TileX, (float)currentTower->TileY - 102 };
			ImVec2 TileMax = { (float)currentTower->TileX + 72 , (float)currentTower->TileY + 72 };
			currentTower->pos = { (float)currentTower->TileX + data.map.Tilesize / 2, (float)currentTower->TileY + data.map.Tilesize / 2 };
			currentTower->texture = data.asset.texureSlowing;
			currentTower->canonTexture = { 0 };
			
			data.dl->AddImage(currentTower->texture.id, TileMin, TileMax);
			SlowingTower(data, *currentTower);
		}
	}

	DrawRangeTurret(data);

}

void TowerRenderer::menuDisplay(GameData& data)
{
	data.dl->AddImage(data.asset.textureAnimation.id, data.posAnimationMin, data.posAnimationMax, ImVec2(0, 0), ImVec2(1, 1), ImColor(0, 0, 0, 255));

	ImGui::Text("MIN : %f ", data.posAnimationMin.y);
	ImGui::Text("MAX : %f ", data.posAnimationMax.y);

	if (data.posAnimationMin.y > 50.f)
	{
		data.posAnimationMin.y -= 0.75f;
		data.posAnimationMax.y -= 0.75f;
	}
	else
	{
		data.dl->AddImage(data.asset.textureMenuHUD.id, { 230.5, 180 }, { 999.5, 700 });

		data.dl->AddImage(data.asset.texturePlay.id, { 480, 250 }, { 751, 350 });
		data.dl->AddImage(data.asset.textureLevels.id, { 480, 370 }, { 751, 470 });
		data.dl->AddImage(data.asset.textureSettings.id, { 480, 490 }, { 751, 590 });

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 350 && data.io.MousePos.y >= 250
			)
		{
			data.dl->AddImage(data.asset.texturePlay.id, { 475, 245 }, { 756, 355 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
				data.currentScene = Game;
			}

		}

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 470 && data.io.MousePos.y >= 370
			)
		{
			data.dl->AddImage(data.asset.textureLevels.id, { 475, 365 }, { 756, 475 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
			}

		}

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 590 && data.io.MousePos.y >= 490
			)
		{
			data.dl->AddImage(data.asset.textureSettings.id, { 475, 485 }, { 756, 595 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
			}

		}
	}

}

void TowerRenderer::DrawAnimation(GameData& data)
{
	ImU32 col = ImColor(0, 0, 0, data.transparence);


	if (data.time >= data.transparenceTime)
	{
		col = ImColor(0, 0, 0, data.transparence);
		data.dl->AddImage(data.asset.textureAnimation.id, data.posAnimationMin, data.posAnimationMax, ImVec2(0, 0), ImVec2(1, 1), col);

		data.transparence += 1;
		data.transparenceTime += 0.0005f;
	}
}

void TowerRenderer::DrawMenu(GameData& data)
{
	ImGui::Text("Timer : %f ", data.time);
	ImGui::Text("Transparency : %f ", data.transparence);
	ImGui::Text("changeTimeTransparency : %f ", data.transparenceTime);


	if (data.transparence < 255)
	{
		DrawAnimation(data);
	}

	else
	{
		menuDisplay(data);

	}
}


void TowerRenderer::DrawEnd(GameData& data)
{

	//data.dl->AddImage(data.asset.textureEndBackGround.id, {0,0}, data.io.DisplaySize);
	if (data.player.health <= 0)
	{
		data.acceleRateTime = 0;
		if (data.minEnd.x >= 406)
		{
			data.minEnd.x -= 0.7f;
			data.minEnd.y -= 0.7f;
			data.maxEnd.x += 0.7f;
			data.maxEnd.y += 0.7f;

			//data.dl->AddImage(data.asset.textureEndLose.id, data.minEnd, data.maxEnd);
		}
		data.dl->AddImage(data.asset.textureEndLose.id, data.minEnd, data.maxEnd);
	}

	if (data.changeLevel)
	{
		data.acceleRateTime = 0;
		if (data.minEnd.x >= 406)
		{
			data.minEnd.x -= 0.7f;
			data.minEnd.y -= 0.7f;
			data.maxEnd.x += 0.7f;
			data.maxEnd.y += 0.7f;

			//data.dl->AddImage(data.asset.textureEndLose.id, data.minEnd, data.maxEnd);
		}
		data.dl->AddImage(data.asset.textureEndWin.id, data.minEnd, data.maxEnd);
	}

}

void TowerRenderer::DrawCheckPoint(GameData& data)
{
	if (data.enableDebug)
	{
		for (auto it = data.listOfRoad[0].begin(); it != data.listOfRoad[0].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(255, 0, 0, 255), 16, 2.f);
		}
		for (auto it = data.listOfRoad[1].begin(); it != data.listOfRoad[1].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(0, 255, 0, 255), 16, 2.f);
		}
		for (auto it = data.listOfRoad[2].begin(); it != data.listOfRoad[2].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(0, 0, 255, 255), 16, 2.f);
		}
		for (auto it = data.listOfRoad[3].begin(); it != data.listOfRoad[3].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(255, 0, 255, 255), 16, 2.f);
		}
	}
	
}

void TowerRenderer::SlowingTower(GameData& data, Tower& Slowing)
{
	if (Slowing.hasTarget)
	{
		data.dl->AddCircleFilled(float2(Slowing.pos.x, Slowing.pos.y - 100), 6.f, IM_COL32(50, 139, 255, 255), 30 );

		data.dl->AddLine(float2(Slowing.pos.x, Slowing.pos.y - 100), Slowing.target->pos, IM_COL32(50, 139, 255, 255), Slowing.beamValue);

	}
	
}





void TowerRenderer::RendererGame(GameData& data)
{
	drawMap(data);
	drawEnemies(data);
	DrawPlacedTurret(data);
	data.player.PlayerTile(data);
	DrawHud(data);
	DrawCheckPoint(data);
	DrawEnd(data);



	/*
	for (Particle& p : particles)
		p.Draw();
}
	*/
}



TowerRenderer::TowerRenderer()
{

}

TowerRenderer::~TowerRenderer()
{

}
