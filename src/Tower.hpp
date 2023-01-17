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


    float beamValue;

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
<<<<<<< HEAD
    float timer = 0;
    Enemy* target;
=======
    float timer = 0.f;
    

>>>>>>> a18d7c8 (#4 closed)


    virtual void Shoot(GameData& data);

    Tower();
    ~Tower();

    //functions
    virtual void TargetEnemy(GameData& data, Enemy& enemy);

};


void ManageAllTurret(GameData& data);