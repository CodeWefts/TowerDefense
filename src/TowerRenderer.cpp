
#include "Point2D.hpp"
#include "TowerGame.hpp"
#include "TowerRenderer.hpp"
#include"float2.hpp"



void TowerRenderer::drawMap(GameData& data)
{
	static float tileSize = data.map.Tilesize;

	ImGui::SliderFloat("tileSize", &tileSize, 0.f, 100.f);

	float originX = 0.f;
	// Build tilemap from string
	for (int i = 0; i < data.map.Width * data.map.Height; ++i)
	{
		int x = i % data.map.Width; // return pos x on char table
		int y = i / data.map.Width; // return pos y on char table
		Tile& tile = data.map.Tiles[i]; // Get Tile texture type

		ImVec2 topLeft = { originX + x * tileSize, y * tileSize };
		ImVec2 topRight = { topLeft.x + tileSize, topLeft.y + tileSize };

		//std::cout << " map x = " << x << " map y = " << y  << " topLeft x = " << topLeft.x << " topLeft y = " << topLeft.y << std::endl;
		

		ImVec2 center = { topLeft.x + tileSize / 2.f, topLeft.y + tileSize / 2.f, }; // center / checkpooint
		
		// TO DO return NEARBEST CHEKPOINT
		

		switch (tile.Texture_type)
		{

		default:
			break;

		case ' ':
			dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'p':
			dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'c':
			//chateaux
			break;

		case 'g':
			//dl->AddImage(data.asset.textureSoigneur.id, topLeft, topRight, ImVec2(0, 0), ImVec2(0.35, 0.25));
			break;
		}

		if(data.enableDebug)
		dl->AddRect(topLeft, topRight, IM_COL32(255, 255, 255, 255), 0);

	}
}


void TowerRenderer::drawEnemies(GameData& data)
{
	ImDrawList* enemydrawlist = ImGui::GetBackgroundDrawList();

	for (auto it = data.enemyVector.begin(); it != data.enemyVector.end(); ++it)
	{
		if (it->name == "soigneur")
		{
			//std::cout << " x = " << it->pos.x << "y = " << it->pos.y << std::endl;
			it->texture = data.asset.textureSoigneur;
			dl->AddImage(it->texture.id, it->pos -= 50, it->pos += 50, ImVec2(0, 0), ImVec2(0.35, 0.25));
		}
		else if (it->name == "costaud")
		{
			//std::cout << " x = " << it->pos.x << "y = " << it->pos.y << std::endl;
			it->texture = data.asset.textureCostaud;
			dl->AddImage(it->texture.id, it->pos -= 50, it->pos += 50, ImVec2(0, 0), ImVec2(0.35, 0.25));
		}
		else if (it->name == "gringalet")
		{
			//std::cout << " x = " << it->pos.x << "y = " << it->pos.y << std::endl;
			it->texture = data.asset.textureGringalet;
			dl->AddImage(it->texture.id, it->pos -= 50, it->pos += 50, ImVec2(0, 0), ImVec2(0.35, 0.25));
		}
			
	}

	
}





void TowerRenderer::RendererGame(GameData& data)
{
	drawMap(data);
	drawEnemies(data);
	

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