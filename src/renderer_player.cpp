#include "data.hpp"
#include "renderer_player.hpp"







void RendererPlayer::DrawHud(GameData& data)
{

	if (ImGui::IsKeyPressed(ImGuiKey_Y, false))
	{
		data.player.health -= 100;
	}

	float maxlenght = 520;
	float returnHealPercent = (float(data.player.health) / data.player.maxHealth);
	float currentLenght = maxlenght * returnHealPercent;

	ImColor color = ColorByHealth(returnHealPercent, 0.35f, 0.75f);

	data.dl->AddRectFilled(float2(20, 20), float2(currentLenght, 60), color, 5.f, 0);
	if (data.player.health >= 0)
	{
		data.dl->AddRect(float2(20, 20), float2(520, 60), IM_COL32(255, 255, 255, 255), 5.f, 0, 4.f);
	}

	data.dl->AddImage(data.asset.PlayerHeart.id, float2(2.5, 2.5), float2(75, 75));




	//Print Player Coins
	string playerCoins = std::to_string(data.player.coins);

	data.dl->AddImage(data.asset.textureButton.id, float2(data.map.Tilesize / 2, data.map.Tilesize), float2(data.map.Tilesize * 4, data.map.Tilesize * 2));
	data.dl->AddImage(data.asset.textureCoin.id, float2(0, data.map.Tilesize), float2(data.map.Tilesize, data.map.Tilesize * 2));
	data.dl->AddText(float2(data.map.Tilesize, data.map.Tilesize + data.map.Tilesize / 3), IM_COL32(255, 255, 255, 255), playerCoins.c_str());

	string playerHeatl = std::to_string(data.player.health);
	data.dl->AddText(float2(100, data.map.Tilesize / 2), IM_COL32(255, 255, 255, 255), playerHeatl.c_str());

}




	void TowerInInventoryHUD(GameData & data)
	{

		ImVec2 min = {
			7 * data.map.Tilesize + 15,
			9 * data.map.Tilesize + 13
		}, max = {
			8 * data.map.Tilesize - 10,
			10 * data.map.Tilesize - 13
		};

		ImGui::Text("Mouse X %f", data.io.MousePos.x);
		ImGui::Text("Mouse Y %f", data.io.MousePos.y);

		ImGui::Text("Min X %f", min.x);
		ImGui::Text("Min Y %f", max.y);


		data.dl->AddImage(data.asset.textureTowerClassique.id, min, max, float2(0, 0), float2(1, 1));

		data.dl->AddImage(data.asset.textureTowerExplosive.id, float2(min.x + data.map.Tilesize, min.y), float2(max.x + data.map.Tilesize, max.y), float2(0, 0), float2(1100.f/11.f/1100.f, 1));

		data.dl->AddImage(data.asset.texureSlowing.id, float2(min.x + (data.map.Tilesize * 2), min.y), float2(max.x + (data.map.Tilesize * 2), max.y), float2(0, 0), float2(1, 1));

		if (data.io.MousePos.x >= min.x - 15 && data.io.MousePos.x <= max.x + 10 &&
			data.io.MousePos.y >= min.y - 13 && data.io.MousePos.y <= max.y + 13
			)
		{
			data.dl->AddImage(data.asset.textureMenuHUD.id, { data.io.MousePos.x, data.io.MousePos.y - 200 }, { data.io.MousePos.x + 250, data.io.MousePos.y });
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 180 }, ImColor(255, 255, 255, 255), "Name : Classique");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 160 }, ImColor(255, 255, 255, 255), "Cost : 25");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 140 }, ImColor(255, 255, 255, 255), "Range : 1");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 120 }, ImColor(255, 255, 255, 255), "Damage : 10");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 100 }, ImColor(255, 255, 255, 255), "FireRate : 0.5");
		}
		if (data.io.MousePos.x >= min.x + 72 - 15 && data.io.MousePos.x <= max.x + 72 + 10 &&
			data.io.MousePos.y >= min.y - 13 && data.io.MousePos.y <= max.y + 13
			)
		{
			data.dl->AddImage(data.asset.textureMenuHUD.id, { data.io.MousePos.x, data.io.MousePos.y - 200 }, { data.io.MousePos.x + 250, data.io.MousePos.y });
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 180 }, ImColor(255, 255, 255, 255), "Name : Explosive");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 160 }, ImColor(255, 255, 255, 255), "Cost : 50");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 140 }, ImColor(255, 255, 255, 255), "Range : 2");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 120 }, ImColor(255, 255, 255, 255), "Damage : 10");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 100 }, ImColor(255, 255, 255, 255), "FireRate : 0.5");
		}
		if (data.io.MousePos.x >= min.x + 72 * 2 - 15 && data.io.MousePos.x <= max.x + 72 * 2 + 10 &&
			data.io.MousePos.y >= min.y - 13 && data.io.MousePos.y <= max.y + 13
			)
		{
			data.dl->AddImage(data.asset.textureMenuHUD.id, { data.io.MousePos.x, data.io.MousePos.y - 200 }, { data.io.MousePos.x + 250, data.io.MousePos.y });
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 180 }, ImColor(255, 255, 255, 255), "Name : Ralentissante");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 160 }, ImColor(255, 255, 255, 255), "Cost : 150");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 140 }, ImColor(255, 255, 255, 255), "Range : 2");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 120 }, ImColor(255, 255, 255, 255), "Damage : 10");
			data.dl->AddText({ data.io.MousePos.x + 20, data.io.MousePos.y - 100 }, ImColor(255, 255, 255, 255), "FireRate : 0.5");
		}

	}



	void RendererPlayer::HudInventory(GameData & data)
	{
		// BRUT 
		int minX = 6;
		int maxX = 7;

		int minY = 9;
		int maxY = 10;
		for (int i = 0; i <= 5; i++)
		{
			if (i == 0)
				data.dl->AddImage(data.asset.textureTowerSideLeft.id, { minX * data.map.Tilesize, minY * data.map.Tilesize }, { maxX * data.map.Tilesize, maxY * data.map.Tilesize });

			else if (i >= 1 && i <= 4)
				data.dl->AddImage(data.asset.textureTowerCase.id, { minX * data.map.Tilesize, minY * data.map.Tilesize }, { maxX * data.map.Tilesize, maxY * data.map.Tilesize });

			else
				data.dl->AddImage(data.asset.textureTowerSideRight.id, { minX * data.map.Tilesize, minY * data.map.Tilesize }, { maxX * data.map.Tilesize, maxY * data.map.Tilesize });
			minX++;
			maxX++;
		}

		TowerInInventoryHUD(data);

	}







void RendererPlayer::DrawPlayer(GameData& data)
{
	DrawHud(data);
	HudInventory(data);
}









RendererPlayer::RendererPlayer()
{
}

RendererPlayer::~RendererPlayer()
{
}