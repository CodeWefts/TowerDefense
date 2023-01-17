#include <math.h>

#include "tower_game.hpp"
#include"Tower.hpp"


float getModule(const float2& pos,  const float2& postower)
{
    float2 diff = postower - pos;
   
    return sqrtf(pow(diff.x, 2) + powf(diff.y, 2));
}


void Tower::Shoot(GameData& data)
{

}


void Tower::TargetEnemy(GameData& data)
{
    for (auto op = data.towerVector.begin(); op != data.towerVector.end(); op++)
    {
        Tower* currentTower = *op;
       


        for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
        {
           
                Enemy* currentEnemy = *it;
               

                float module = getModule(currentTower->pos, currentEnemy->pos);
                if (module <= (currentTower->range * (data.map.Tilesize + data.map.Tilesize / 2)))
                {
                    currentTower->timer += data.deltatime;
                   
                    if(currentTower->hasTarget == false)
                    {
                        currentTower->hasTarget = true;
                        currentTower->target = currentEnemy;

                    }
                }
                else
                {
                    currentTower->hasTarget = false;
                    currentTower->target = nullptr;
                }
            
                if (currentTower->timer >= currentTower->fireRate && currentTower->hasTarget)
                {

                    currentTower->Shoot(data);

                }

        }
    }

}









Tower::~Tower()
{
    
}

Tower::Tower()
{
    float angle = 0;
    hasTarget = false;
}

