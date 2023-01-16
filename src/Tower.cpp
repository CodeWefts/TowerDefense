#include <math.h>

#include "tower_game.hpp"
#include"Tower.hpp"



void Tower::TargetEnemy(GameData& data)
{
    for (auto op = data.towerVector.begin(); op != data.towerVector.end(); op++)
    {
        Tower* currentTower = *op;

        for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
        {
            enemy* currentEnemy = *it;
            currentTower->timer += data.deltatime;

            float diffX = currentTower->pos.x - currentEnemy->pos.x;
            float diffY = currentTower->pos.y - currentEnemy->pos.y;

            float module = sqrt(pow(diffX, 2) + pow(diffY, 2));

            if (module <= (currentTower->range * (data.map.Tilesize + data.map.Tilesize / 2)))
            {
                if (currentTower->fireRate >= currentTower->fireRate)
                {
                    currentTower->fireRate = 0;
                    currentEnemy->currentHealth -= currentTower->damage;
                }


            }
        }
    }

}









Tower::~Tower()
{
    
}

Tower::Tower()
{

}

