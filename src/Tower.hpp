#pragma once
#include <iostream>
#include <vector>
#include "enemy.hpp"
#include "imgui_utils.hpp"
#include "entity.hpp"

struct GameData;

enum TowerChoice : int
{
    CLASSICAL = 1,
    EXPLOSIF,
    SLOWINGTURRET,
    NULLTOWER = 255,
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
   
    double cost;
    double damage;
    float angle;
    float fireRate;
    float timer;

    float animationMinX = 0.f;
    float animationMinY = 0.f;
    float animationMaxX = 1.f;
    float animationMaxY = 1.f;

    float moveTime;
 

    int TileX, TileY;
    
   
    double range;

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