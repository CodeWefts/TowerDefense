#pragma once
#include "imgui_utils.hpp"
#include "TowerGame.hpp"

class App
{
public:
    App();
    ~App();

    void Update();

    TowerGame towerGame;

};
