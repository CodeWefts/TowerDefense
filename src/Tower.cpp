#include <math.h>

#include "tower_game.hpp"
#include"Tower.hpp"


float getModule(float2 pos,  float2 postower)
{
    float2 diff = postower - pos;
   
    return sqrtf(pow(diff.x, 2) + powf(diff.y, 2));
}


void Tower::TargetEnemy(GameData& data)
{
    for (auto op = data.towerVector.begin(); op != data.towerVector.end(); op++)
    {
        Tower* currentTower = *op;
       


        for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
        {
           
                Enemy* currentEnemy = *it;
                float diffX = currentTower->pos.x - currentEnemy->pos.x;
                float diffY = currentTower->pos.y - currentEnemy->pos.y;

                float module = sqrt(pow(diffX, 2) + pow(diffY, 2));



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
                }
            
                if (currentTower->timer >= currentTower->fireRate && currentTower->hasTarget)
                {
                    std::cout << currentTower->hasTarget << std::endl;

                    currentTower->target->currentHealth -= currentTower->damage;
                    currentTower->timer = 0;
                    cout << " timer = " << currentTower->timer << std::endl;


                }
           


            
           


            
          
        }
    }

}









Tower::~Tower()
{
    
}

Tower::Tower()
{
    hasTarget = false;
}

