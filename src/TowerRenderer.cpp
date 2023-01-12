
#include "Point2D.hpp"
#include "TowerGame.hpp"
#include "TowerRenderer.hpp"
#include"float2.hpp"




void TowerRenderer::drawMap(GameData& data)
{
	static float tileSize = data.map.Tilesize;

	ImGui::SliderFloat("tileSize", &data.map.Tilesize, 0.f, 100.f);

	float originX = 0.f;
	// Build tilemap from string
	for (int i = 0; i < data.map.Width * data.map.Height; ++i)
	{
		int x = i % data.map.Width; // return pos x on char table
		int y = i / data.map.Width; // return pos y on char table
		Tile& tile = data.map.Tiles[i]; // Get Tile texture type

		ImVec2 topLeft = ReturnTileMin(x, y, data.map);
		ImVec2 topRight = ReturnTileMax(x, y, data.map);

		//std::cout << " map x = " << x << " map y = " << y  << " topLeft x = " << topLeft.x << " topLeft y = " << topLeft.y << std::endl;
		

		ImVec2 center = ReturnCenter(x,y, data.map); // center / checkpooint
		
		// TO DO return NEARBEST CHEKPOINT
		

		switch (tile.Texture_type)
		{

		default:
			break;

		case ' ':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'p':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'a':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'b':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'c':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case 'd':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'e':
			data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'f':
			//data.dl->AddImage(data.asset.textureDirt.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case 'j':
			data.dl->AddImage(data.asset.texturePathBottomANDRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 'l':
			data.dl->AddImage(data.asset.texturePathBottomANDLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case 't':
			data.dl->AddImage(data.asset.texturePathTopANDLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '!':
			data.dl->AddImage(data.asset.texturePathTopANDRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case '_':
			data.dl->AddImage(data.asset.texturePathBottom.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '-':
			data.dl->AddImage(data.asset.texturePathTop.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case '|':
			data.dl->AddImage(data.asset.texturePathRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '/':
			data.dl->AddImage(data.asset.texturePathLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case '*':
			data.dl->AddImage(data.asset.texturePathTopLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '+':
			data.dl->AddImage(data.asset.texturePathTopRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case ',':
			data.dl->AddImage(data.asset.texturePathBottomLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case ';':
			data.dl->AddImage(data.asset.texturePathBottomRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;


		case 'k':
			//chateaux
			break;

		case 'g':
			//data.dl->AddImage(data.asset.textureSoigneur.id, topLeft, topRight, ImVec2(0, 0), ImVec2(0.35, 0.25));
			break;


		case '1':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			data.dl->AddImage(data.asset.textureTowerSideLeft.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '2':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			data.dl->AddImage(data.asset.textureTowerSideRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '3':
			data.dl->AddImage(data.asset.textureGrass.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			data.dl->AddImage(data.asset.textureTowerCase.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));	
			break;



		}
		
		if(data.enableDebug)
			data.dl->AddRect(topLeft, topRight, IM_COL32(255, 255, 255, 255), 0);


	}


}



void TowerRenderer::drawEnemies(GameData& data)
{
	ImDrawList* enemydrawlist = ImGui::GetBackgroundDrawList();

	


	for (std::vector<enemy*>::iterator it = data.enemyVector.begin(); it != data.enemyVector.end(); ++it)
	{
		enemy* currentEnemy = *it;

		float2 enemy = currentEnemy->pos;


		if (currentEnemy->name == "soigneur")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureSoigneur;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 15, enemy + 15, ImVec2(0, 0), ImVec2(0.35, 0.25),IM_COL32(255,255,255,255));
		}
		else if (currentEnemy->name == "costaud")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureCostaud2;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 30, enemy += 30, ImVec2(0, 0), ImVec2(1, 1),IM_COL32(255, 255, 255, 255));
		}
		else if (currentEnemy->name == "gringalet")
		{
			//std::cout << " x = " << currentEnemy->pos.x << "y = " << currentEnemy->pos.y << std::endl;
			currentEnemy->texture = data.asset.textureGringalet;
			data.dl->AddImage(currentEnemy->texture.id, enemy - 30, enemy += 30, ImVec2(0, 0), ImVec2(0.35, 0.25), IM_COL32(255, 255, 255, 255));
		}


		currentEnemy->DrawSlider(*data.dl);

		if(data.enableDebug)
		currentEnemy->DrawDebug(*(enemydrawlist));
		


	}

	



}










void TowerRenderer::RendererGame(GameData& data)
{
	drawMap(data);
	drawEnemies(data);

	//data.max.x += (data.deltatime * 100);
 
		 
	

	//std::cout << data.max.x << std::endl;

	//data.dl->AddRect(float2(200 , 200), data.max, IM_COL32(255, 0, 255, 255));
 	


}

TowerRenderer::TowerRenderer()
{
	//dl = nullptr;
}

TowerRenderer::~TowerRenderer()
{
}