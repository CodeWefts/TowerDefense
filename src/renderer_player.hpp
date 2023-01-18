#pragma once



struct GameData;


class RendererPlayer
{
public:




	void DrawHud(GameData& data);
	void HudInventory(GameData& data);


	void DrawPlayer(GameData& data);
	RendererPlayer();
	~RendererPlayer();

private:

};
