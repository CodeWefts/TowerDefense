#pragma once
#include <iostream>
#include "enemy.hpp"
#include "imgui_utils.hpp"
#include "entity.hpp"

struct GameData;

enum TowerChoice : int
{
    CLASSIQUE,
    RALENTISSANTE,
    EXPLOSIVE,
};

class Tower : public Entity
{
public:


   

    std::string name;
    Texture texture;
  
    Texture canonTexture;

    bool hasTarget;

    int type;
    int cost;
    bool placed;

    int TileX, TileY;
    int range;

    int damage;
    
    float angle;
    float fireRate;
    float timer = 0;
    Enemy* target;

    virtual void TowerEffectRender(GameData& data);
    virtual void Shoot(GameData& data);
    virtual void Reset(GameData& data);

    Tower();
    ~Tower();

    //functions
    virtual void TargetEnemy(GameData& data, Enemy& enemy);

};


void ManageAllTurret(GameData& data);