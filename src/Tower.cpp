#include <math.h>

#include "tower_game.hpp"
#include"Tower.hpp"


Tower::Tower()
{

}
Tower::~Tower()
{

}


void Tower::TargetEnemy(GameData& data)
{
	for (std::vector<Tower*>::iterator op = data.towerVector.begin(); op != data.towerVector.end(); op++)
	{
		Tower* currentTower = *op;

		for (std::vector<enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
		{
			enemy* currentEnemy = *it;
			currentTower->timer += data.deltatime;

			float diffX = currentTower->pos.x - currentEnemy->pos.x;
			float diffY = currentTower->pos.y - currentEnemy->pos.y;

			float module = sqrt(pow(diffX, 2) + pow(diffY, 2));

			if (module <= (currentTower->range * data.map.Tilesize + data.map.Tilesize/2))
			{
				if (currentTower->timer >= currentTower->fireRate)
				{
					currentTower->timer = 0;
					currentEnemy->currentHealth -= currentTower->damage;
				}

			}
		}
	}

}