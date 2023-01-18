#include <math.h>

#include "tower_game.hpp"
#include"tower.hpp"



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
    timer = 0;
}





void Tower::TargetEnemy(GameData& data, std::vector<Enemy*>& enemmyVector)
{
    for (auto it = enemmyVector.begin(); it != enemmyVector.end(); it++)
    {
        Enemy* current = *it;
        float module = getModule(current->pos, this->pos);
        if (target != nullptr)
        {
            float moduleTargt = getModule(target->pos, this->pos);
            timer += data.deltatime;

            if (moduleTargt <= (range * (data.map.Tilesize + data.map.Tilesize / 2)))
            {

                if (module < moduleTargt)
                {
                    target = current;
                    hasTarget = true;
                }

            }

            // is target out of range 
            else if (moduleTargt > (range * (data.map.Tilesize + data.map.Tilesize / 2)))
            {

                hasTarget = false;
                target = nullptr;
                Reset(data);
            }


            if (timer >= fireRate && hasTarget)
            {

                Shoot(data);


            }


        }
        else // if Have no Taarget
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

    this->target = nullptr;
    angle = 0;
    hasTarget = false;
}

