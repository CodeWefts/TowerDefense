#pragma once
#include <iostream>

#include "imgui_utils.hpp"
#include "entity.hpp"

struct GameData;

enum TowerChoice : int
{
    CLASSIQUE,
    RALENTISSANTE,
    EXPLOSIVE,
};

class Tower : public entity
{
public:

    std::string name;
    Texture texture;

    int type;
    int cost;
    bool placed;

    int TileX, TileY;
    int range;

    int damage;
  
    float fireRate;
    float timer = 0;
    




    Tower();
    ~Tower();

    //functions
    void TargetEnemy(GameData& data);

};