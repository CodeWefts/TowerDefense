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




void ManageAllTurret(GameData& data) 
{
    for (auto op = data.towerVector.begin(); op != data.towerVector.end(); op++)
    {
        Tower* currentTower = *op;
        for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
        {
            Enemy* currentEnemy = *it;

<<<<<<< HEAD
            currentTower->TargetEnemy(data, *currentEnemy);
=======
            float diffX = currentTower->pos.x - currentEnemy->pos.x;
            float diffY = currentTower->pos.y - currentEnemy->pos.y;

            float module = sqrt(pow(diffX, 2) + pow(diffY, 2));

            if (module <= (currentTower->range * (data.map.Tilesize + data.map.Tilesize / 2)))
            {
                if (currentTower->timer >= currentTower->fireRate)
                {
                    currentTower->timer = 0;
                    currentEnemy->currentHealth -= currentTower->damage;
                }


            }
>>>>>>> a18d7c8 (#4 closed)
        }
    }
}



void Tower::TargetEnemy(GameData& data, Enemy& enemy)
{
   

    float module = getModule(enemy.pos, pos);
    if (module <= (range * (data.map.Tilesize + data.map.Tilesize / 2)))
     {
        timer += data.deltatime;

        if (hasTarget == false)
        {
            hasTarget = true;
            target = &enemy;

        }
    }
    else
    {
        hasTarget = false;
        target = nullptr;
    }

    if (timer >= fireRate && hasTarget)
    {

        Shoot(data);

    }


}









Tower::~Tower()
{
    
}

Tower::Tower()
{
    
    beamValue = 5.f;

    angle = 0;
    hasTarget = false;
}

