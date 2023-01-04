
#include "Point2D.hpp"
#include "TowerGame.hpp"
#include "TowerRenderer.hpp"



void TowerRenderer::drawMap(GameData& data)
{
	static float tileSize = 72.f;
	ImGui::SliderFloat("tileSize", &tileSize, 0.f, 100.f);

	float originX = 0.f;
	// Build tilemap from string
	for (int i = 0; i < data.map.Width * data.map.Height; ++i)
	{
		int x = i % data.map.Width;
		int y = i / data.map.Width;
		Tile& tile = data.map.Tiles[i];

		ImVec2 topLeft = { originX + x * tileSize, y * tileSize };
		ImVec2 toRight = { topLeft.x + tileSize, topLeft.y + tileSize };
		dl->AddRect(topLeft, toRight, IM_COL32(255, 255, 255, 255), 0);

		ImVec2 center = { topLeft.x + tileSize / 2.f, topLeft.y + tileSize / 2.f, };
		/*
			if (tile.Texture_type == 'o')
			dl->AddCircle(center, 5.f, IM_COL32(255, 0, 0, 255), 32, 1);
			else
			dl->AddCircle(center, 5.f, IM_COL32(255, 255, 255, 255), 32, 1);
		*/

		

		switch (tile.Texture_type)
		{

		default:
			break;

		case ' ':
			dl->AddImage(data.asset.textureGrass.id, topLeft, toRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'p':
			dl->AddImage(data.asset.textureDirt.id, topLeft, toRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'c':
			//chateaux
			break;
		}

	}
}





void TowerRenderer::RendererGame(GameData& data)
{
	drawMap(data);

	//for (int y = 0; y < data.map.Height; ++y)
	//{
	//	for (int x = 0; x < data.map.Width; ++x)
	//	{
	//		int i = x + y * data.map.Width;
	//
	//		Tile& tile = data.map.Tiles[i];
	//	}
	//}

#if 0
	// draw tiles
	for(auto it = data.map.Tiles.begin(); it != data.map.Tiles.end(); it++)
	//for (Tile& tile : data.map.Tiles)
	{

		// TO do draw texture
		dl->AddRect(it->posMin, it->posMax, IM_COL32(255, 255, 255, 255), 0);

		if (it->Texture_type == 'o')
		{
			dl->AddCircle(it->centerPos, 5.f, IM_COL32(255, 0, 0, 255), 32, 1);
		}
		else
		{
			dl->AddCircle(it->centerPos, 5.f, IM_COL32(255, 255, 255, 255), 32, 1);
		}

	}
#endif
}

TowerRenderer::TowerRenderer()
{
	dl = nullptr;
}

TowerRenderer::~TowerRenderer()
{
}