#include <math.h>

#include "tower_game.hpp"
#include"Tower.hpp"



float getModule(const float2& pos, const float2& postower)
{
    float2 diff = postower - pos;

    return sqrtf(pow(diff.x, 2) + powf(diff.y, 2));
}


void Tower::Shoot(GameData& data)
{

}
 void Tower::Reset(GameData& data)
{

}





void Tower::TargetEnemy(GameData& data, Enemy& enemy)
{
   
   // std::cout << hasTarget << std::endl;
    float module = getModule(enemy.pos, pos);
    if (module < (range * (data.map.Tilesize + data.map.Tilesize / 2)))
    {
    
        timer += data.deltatime;

        if (hasTarget == false)
        {
            Reset(data);
            hasTarget = true;
            
          

        }
        if (hasTarget)
        {
            target = &enemy;
        }

        if (timer >= fireRate && hasTarget)
        {

            Shoot(data);


        }
    }
    else
    {
        hasTarget = false;
         target = nullptr;
    }
 


}
void Tower::TowerEffectRender(GameData& data)
{
    ImVec2 TileMin = { (float)TileX , (float)TileY };
    ImVec2 TileMax = { (float)TileX + 72, (float)TileY + 72 };
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

        for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); it++)
        {
            Enemy* currentEnemy = *it;

            currentTower->TargetEnemy(data, *currentEnemy);
        }
    }
}





Tower::~Tower()
{
    
}

Tower::Tower()
{
    

    angle = 0;
    hasTarget = false;
}

