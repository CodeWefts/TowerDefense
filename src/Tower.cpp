#include <math.h>

#include "tower_game.hpp"
#include"tower.hpp"
#include "calc.hpp"






void Tower::Shoot(GameData& data)
{

}
void Tower::Reset(GameData& data)
{
    timer = 0;
}


void Tower::Upgrade(GameData& data)
{
    data.player.coins -= int(this->cost * currentLevel++);
    this->damage *= 2;
    this->fireRate /= 1.2f;
    this->range += 20;
   

}






void Tower::TargetEnemy(GameData& data, std::vector<Enemy*>& enemmyVector)
{



    for (auto it = enemmyVector.begin(); it != enemmyVector.end(); it++)
    {
        Enemy* current = *it;
        // Calculate module for all enemies
        float module = getModule(current->pos, this->pos);
        
        // If Tower Has Target
        if (target != nullptr)
        {
            // We calculate the distance between turret and his target  
            float moduleTarget = getModule(target->pos, this->pos);
            timer += data.deltatime;

            if (moduleTarget <= (range * (data.map.Tilesize + data.map.Tilesize / 2)))
            {
                // If the current enemy is closer than the current Target current  become the target 
                if (module < moduleTarget)
                {
                    target = current;
                    hasTarget = true;
                }

            }
            else // is target out of range 
            {

                Reset(data);
                hasTarget = false;
                target = nullptr;
            }

            
            if (timer >= fireRate && hasTarget)
            {
                Shoot(data);
            }


        }
        else // if Have no Target
        {

            if (module < (range * (data.map.Tilesize + data.map.Tilesize / 2)))
            {
                timer += data.deltatime;
                target = current;
                hasTarget = true;

                if (timer >= fireRate)
                {
                    Shoot(data);
                }

            }
            else
            {
                target = nullptr;
                hasTarget = false;
                Reset(data);

            }

        }
    }



}







void Tower::TowerEffectRender(GameData& data)
{
    float2 TileMin = { (float)TileX , (float)TileY };
    float2 TileMax = { (float)TileX + 72, (float)TileY + 72 };
    pos = { (float)TileX + data.map.Tilesize / 2, (float)TileY + data.map.Tilesize / 2 };
    texture = data.asset.textureTowerExplosive;
    canonTexture = { 0 };
    data.dl->AddImage(texture.id, TileMin, TileMax);
}





void ManageAllTurret(GameData& data)
{

    for (auto op = data.towerVector.begin(); op != data.towerVector.end(); op++)
    {
        Tower* currentTower = *op;

        if (!data.enemyVector.empty())
        {
            currentTower->TargetEnemy(data, data.enemyVector);
        }


    }
}





Tower::~Tower()
{

}

Tower::Tower()
{
    this->currentLevel = 1;
    this->maxLevel = 3;
    this->target = nullptr;
    this->cost = 0;
    this->angle = 0;
    this->hasTarget = false;
    this->timer = 0.f;
    this->damage = 0;
    this->fireRate = 0;
    texture = { 0 };
    canonTexture = { 0 };

     TileX = 0;
     TileY = 0; 
 

    this->type = NULLTOWER;
    this->animationMinX = 0;
    this->animationMinY = 0;
    this->animationMaxX = 0;
    this->animationMaxY = 0;
    this->moveTime = 0;
    this->range = 0;


}

