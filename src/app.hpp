#pragma once
#include "imgui_utils.hpp"
#include "tower_game.hpp"

class App
{
public:
    App();
    ~App();

    void Update();

    TowerGame towerGame;

};
