#include "renderer_entity.hpp"
#include "data.hpp"
#include "calc.hpp"




void RendererEntity::drawEnemies(GameData& data)
{
	for (std::vector<Enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end(); ++it)
	{
		Enemy* currentEnemy = *it;
		float2 enemy = currentEnemy->pos;

		if (currentEnemy->type == HEALER)
		{
			currentEnemy->texture = data.asset.textureSoigneur;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 15, enemy + 15, ImVec2(0, 0), ImVec2(0.35f, 0.25f), IM_COL32(255, 255, 255, 255));
		}

		else if (currentEnemy->type == HEAVY)
		{

			currentEnemy->texture = data.asset.textureNightBorne;
			if (currentEnemy->timeMove <= 0)
			{
				currentEnemy->animationMinX = currentEnemy->animationMaxX;
				currentEnemy->animationMaxX += 0.043f;
				currentEnemy->timeMove = 0.15f;
			}
			else if (currentEnemy->animationMaxX < currentEnemy->vecMaxX)
			{
				currentEnemy->timeMove -= data.deltatime;
			}
			else if (currentEnemy->animationMaxX >= currentEnemy->vecMaxX)
			{
				currentEnemy->animationMinX = 0.f;
				currentEnemy->animationMaxX = 0.043f;
			}

			data.dl->AddImage(currentEnemy->texture.id, enemy - 140, enemy += 60, float2(currentEnemy->animationMinX, 0.2f), float2(currentEnemy->animationMaxX, 0.4f), IM_COL32(255, 255, 255, 255));
		}

		else if (currentEnemy->type == WEAKLING)
		{
			currentEnemy->texture = data.asset.textureCanineWhite;
			ImVec2 point[4] =
			{
				{ enemy.x - 24 , enemy.y - 16 },
				{ enemy.x + 24 , enemy.y - 16 },
				{ enemy.x + 24 , enemy.y + 16 },
				{ enemy.x - 24 , enemy.y + 16 }
			};

			if (currentEnemy->timeMove <= 0)
			{
				currentEnemy->animationMinX = currentEnemy->animationMaxX;
				currentEnemy->animationMaxX += 0.25f;

				currentEnemy->timeMove = 0.15f;
			}

			else if (currentEnemy->animationMaxX >= 0.5f && currentEnemy->animationMaxY >= 1.f)
			{
				currentEnemy->animationMinX = 0.f;
				currentEnemy->animationMaxX = 0.25f;

				currentEnemy->animationMinY = 0.f;
				currentEnemy->animationMaxY = 0.5f;
			}

			else if (currentEnemy->animationMaxX <= currentEnemy->vecMaxX && currentEnemy->animationMaxY <= 1)
			{
				currentEnemy->timeMove -= data.deltatime;
			}

			else if (currentEnemy->animationMaxX >= currentEnemy->vecMaxX && currentEnemy->animationMaxY >= 0.5)
			{
				currentEnemy->animationMinY = currentEnemy->animationMaxY;
				currentEnemy->animationMaxY += 0.5f;

				currentEnemy->animationMinX = 0.f;
				currentEnemy->animationMaxX = 0.25f;
			}




			data.dl->AddImageQuad(currentEnemy->texture.id, point[0], point[1], point[2], point[3],
				ImVec2(currentEnemy->animationMaxX, currentEnemy->animationMinY),
				ImVec2(currentEnemy->animationMinX, currentEnemy->animationMinY),
				ImVec2(currentEnemy->animationMinX, currentEnemy->animationMaxY),
				ImVec2(currentEnemy->animationMaxX, currentEnemy->animationMaxY));
		}

		currentEnemy->DrawSlider(*data.dl);

		if (data.enableDebug)
			currentEnemy->DrawDebug(*(data.dl));
	}
}




void DrawRangeTurret(GameData& data)
{
	for (std::vector<Tower*>::iterator it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;

		ImVec2 centerTower = { (float)currentTower->TileX + 36,(float)currentTower->TileY + 36 };

		data.dl->AddCircle(centerTower, (float)currentTower->range * 72 + 36, IM_COL32(0, 255, 255, 255));
	}
}

void RendererEntity::DrawPlacedTurret(GameData& data)
{


	for (auto it = data.towerVector.begin(); it != data.towerVector.end(); it++)
	{
		Tower* currentTower = *it;



		if (currentTower->type == CLASSICAL)
		{
			currentTower->TowerEffectRender(data);
		}
		if (currentTower->type == EXPLOSIF)
		{
			currentTower->TowerEffectRender(data);
		}
		if (currentTower->type == SLOWINGTURRET)
		{
			currentTower->TowerEffectRender(data);
		}
	}

	if (data.enableDebug == true)
	{
		DrawRangeTurret(data);
	}
}


void RendererEntity::RendererEntitys(GameData& data)
{
	drawEnemies(data);
	DrawPlacedTurret(data);
}



RendererEntity::RendererEntity()
{

}

RendererEntity::~RendererEntity()
{
}