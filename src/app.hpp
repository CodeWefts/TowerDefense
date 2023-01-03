#pragma once
#include "imgui_utils.hpp"

class App
{
public:
    App();
    ~App();

    void Update();


    ImDrawList* dl;
    ImGuiIO* io;

    Texture grass;



};
