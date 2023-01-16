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

    bool hasTarget;

    int type;
    int cost;
    bool placed;

    int TileX, TileY;
    int range;

    int damage;
  
    float fireRate;
    float timer = 0;
    Enemy* target;




    Tower();
    ~Tower();

    //functions
    void TargetEnemy(GameData& data);

};