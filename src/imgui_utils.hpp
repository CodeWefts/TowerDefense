#pragma once

#include <imgui.h>



#define Blue  IM_COL32(0, 0, 255, 255)
#define Red  IM_COL32(255, 0, 0, 255)
#define Green  IM_COL32(0, 255, 0, 255)




struct Texture
{
    ImTextureID id;
    int width;
    int height;
};

class ImGuiUtils
{
public:
    static Texture LoadTexture(const char* file);
    static void UnloadTexture(const Texture& texture);

    static void DrawTextureEx(ImDrawList& dl, const Texture& tex, ImVec2 pos, ImVec2 scale = { 1.f, 1.f }, float angle = 0.f);
};


ImColor ColorByHealth(const float& percent, const float& valueMin, const float& valueMax);
