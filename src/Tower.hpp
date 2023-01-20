#pragma once
#include <iostream>
#include <vector>
#include "enemy.hpp"
#include "imgui_utils.hpp"
#include "entity.hpp"

struct GameData;

enum TowerChoice : int
{
    CLASSIQUE = 1,
    EXPLOSIVE,
    RALENTISSANTE,
};

class Tower : public Entity
{
public:

    int currentLevel;
    int maxLevel;


    std::string name;
    TowerChoice type;
    Texture texture;
    Texture canonTexture;
   
    int cost;
    int damage;
    float angle;
    float fireRate;
    float timer;
   

    bool upgrade = false;
 

    int TileX, TileY;
    
   
    int range;

    bool hasTarget;
    Enemy* target;

    virtual void TowerEffectRender(GameData& data);
    virtual void Reset(GameData& data);
    virtual void TargetEnemy(GameData& data, std::vector<Enemy*>& enemmyVector);
    virtual void Shoot(GameData& data);
    virtual void Upgrade(GameData& data);
    Tower();

    ~Tower();
};


void ManageAllTurret(GameData& data);