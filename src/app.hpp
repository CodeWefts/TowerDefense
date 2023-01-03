#pragma once

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
