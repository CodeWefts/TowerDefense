#include <vector>
#include "data.hpp"
#include "tower_renderer.hpp"
#include "calc.hpp"



void TowerRenderer::DrawMap(GameData& data)
{

	float originX = 0.f;
	// Build tilemap from string
	for (int i = 0; i < data.map.Width * data.map.Height; ++i)
	{
		int x = i % data.map.Width; // return pos x on char table
		int y = i / data.map.Width; // return pos y on char table
		Tile& tile = data.map.Tiles[i]; // Get Tile texture type

		ImVec2 topLeft = ReturnTileMin(x, y, data.map);
		ImVec2 topRight = ReturnTileMax(x, y, data.map);

		ImVec2 center = ReturnCenterTile(x, y, data.map); // center / checkpooint

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

		case 'u':
			data.dl->AddImage(data.asset.texturePathAroundDown.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case 'n':
			data.dl->AddImage(data.asset.texturePathAroundUp.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;

		case '=':
			data.dl->AddImage(data.asset.texturePathUpANDDown.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
			break;
		case '#':
			data.dl->AddImage(data.asset.texturePathLeftANDRight.id, topLeft, topRight, ImVec2(0, 0), ImVec2(1, 1));
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

		if (data.enableDebug)
		{
			data.dl->AddRect(topLeft, topRight, IM_COL32(255, 255, 255, 255), 0);
		}



	}
	

}




void TowerRenderer::MenuDisplay(GameData& data)
{
	data.dl->AddImage(data.asset.textureAnimation.id, data.posAnimationMin, data.posAnimationMax, ImVec2(0, 0), ImVec2(1, 1), ImColor(0, 0, 0, 255));

	if (data.posAnimationMin.y > 50.f)
	{
		data.posAnimationMin.y -= 0.75f;
		data.posAnimationMax.y -= 0.75f;
	}
	else
	{
		data.dl->AddImage(data.asset.textureMenuHUD.id, { 230.5, 180 }, { 999.5, 700 });

		data.dl->AddImage(data.asset.texturePlay.id, { 480, 250 }, { 751, 350 });
		data.dl->AddImage(data.asset.textureLevels.id, { 480, 370 }, { 751, 470 });
		data.dl->AddImage(data.asset.textureSettings.id, { 480, 490 }, { 751, 590 });

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 350 && data.io.MousePos.y >= 250
			)
		{
			data.dl->AddImage(data.asset.texturePlay.id, { 475, 245 }, { 756, 355 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
				data.currentScene = Game;
			}
		}

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 470 && data.io.MousePos.y >= 370
			)
		{
			data.dl->AddImage(data.asset.textureLevels.id, { 475, 365 }, { 756, 475 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
				data.currentScene = Levels;
			}
		}

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 590 && data.io.MousePos.y >= 490
			)
		{
			data.dl->AddImage(data.asset.textureSettings.id, { 475, 485 }, { 756, 595 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
			}

		}
	}

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 470 && data.io.MousePos.y >= 370
			)
		{
			data.dl->AddImage(data.asset.textureLevels.id, { 475, 365 }, { 756, 475 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
			}

		}

		if (data.io.MousePos.x <= 751 && data.io.MousePos.x >= 480 &&
			data.io.MousePos.y <= 590 && data.io.MousePos.y >= 490
			)
		{
			data.dl->AddImage(data.asset.textureSettings.id, { 475, 485 }, { 756, 595 });
			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
			}

		}

}

void TowerRenderer::DrawAnimation(GameData& data)
{
	ImU32 col = ImColor(0, 0, 0, data.transparence);



	if (data.time >= data.transparenceTime)
	{
		col = ImColor(0, 0, 0, data.transparence);
		data.dl->AddImage(data.asset.textureAnimation.id, data.posAnimationMin, data.posAnimationMax, ImVec2(0, 0), ImVec2(1, 1), col);

		data.transparence += 1;
		data.transparenceTime += 0.0005f;
	}
}

void TowerRenderer::DrawMenu(GameData& data)
{


	if (data.transparence < 255)
	{
		DrawAnimation(data);
	}

	else
	{
		MenuDisplay(data);

	}
}

void TowerRenderer::DrawEnd(GameData& data)
{

	if (data.player.health <= 0)
	{
		data.acceleRateTime = 0;
		if (data.minEnd.x >= 406)
		{
			data.minEnd.x--;
			data.minEnd.y--;
			data.maxEnd.x++;
			data.maxEnd.y++;

		}

		data.dl->AddImage(data.asset.textureEndLose.id, data.minEnd, data.maxEnd);

		if (data.io.MousePos.x <= 207 && data.io.MousePos.x >= 137 &&
			data.io.MousePos.y <= 342 && data.io.MousePos.y >= 297
			)
		{

			if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
			{
				data.currentScene = Levels;
			}

		}
	}

	if (data.changeLevel)
	{
		data.acceleRateTime = 1;
		if (data.minEnd.x >= 406)
		{
			data.minEnd.x -= 0.7f;
			data.minEnd.y -= 0.7f;
			data.maxEnd.x += 0.7f;
			data.maxEnd.y += 0.7f;

		}
		data.dl->AddImage(data.asset.textureEndWin.id, data.minEnd, data.maxEnd);
	}

}


void TowerRenderer::DrawCheckPoint(GameData& data)
{
	if (data.enableDebug)
	{
		for (auto it = data.listOfRoad[0].begin(); it != data.listOfRoad[0].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(255, 0, 0, 255), 16, 2.f);
		}
		for (auto it = data.listOfRoad[1].begin(); it != data.listOfRoad[1].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(0, 255, 0, 255), 16, 2.f);
		}
		for (auto it = data.listOfRoad[2].begin(); it != data.listOfRoad[2].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(0, 0, 255, 255), 16, 2.f);
		}
		for (auto it = data.listOfRoad[3].begin(); it != data.listOfRoad[3].end(); it++)
		{
			data.dl->AddCircle(*it, 15.f, IM_COL32(255, 0, 255, 255), 16, 2.f);
		}
	}

}

void TowerRenderer::DrawLevelsMap(GameData& data)
{
	float minX = data.io.MousePos.x;
	float minY = data.io.MousePos.y;

	data.dl->AddImage(data.asset.textureMap.id, { 0,0 }, data.io.DisplaySize);
	data.dl->AddImage(data.asset.textureLevelNotFinish.id, { 100 ,20 }, { 203, 118 });
	data.dl->AddText({ 151.5,69 }, IM_COL32(255, 255, 255, 255), "1");

	data.dl->AddImage(data.asset.textureLevelNotFinish.id, { 400 ,500 }, { 503, 598 });
	data.dl->AddText({ 451.5,549 }, IM_COL32(255, 255, 255, 255), "2");

	data.dl->AddImage(data.asset.textureLevelNotFinish.id, { 700 ,100 }, { 803, 198 });
	data.dl->AddText({ 751.5,149 }, IM_COL32(255, 255, 255, 255), "3");

	data.dl->AddImage(data.asset.textureLevelNotFinish.id, { 1100 ,300 }, { 1203, 398 });
	data.dl->AddText({ 1151.5,349 }, IM_COL32(255, 255, 255, 255), "4");

	if (ImGui::IsKeyPressed(ImGuiKey_MouseLeft))
	{
		if (minX >= 100 && minX <= 203 &&
			minY >= 20 && minY <= 118)
		{
			data.currentLevel = 0;
			data.currentScene = Game;
			data.changeLevel = true;
			ChangeLevel(data);
		}
		if (minX >= 400 && minX <= 503 &&
			minY >= 500 && minY <= 598)
		{
			
			data.currentLevel = 1;		
			data.currentScene = Game;
			data.changeLevel = true;
			ChangeLevel(data);	
		}
		if (minX >= 700 && minX <= 803 &&
			minY >= 100 && minY <= 198)
		{
			data.currentLevel = 2;
			data.currentScene = Game;
			data.changeLevel = true;
			ChangeLevel(data);	
		}
		if (minX >= 1100 && minX <= 1203 &&
			minY >= 300 && minY <= 398)
		{
			data.currentScene = Game;
			data.currentLevel = 3;
			data.changeLevel = true;
			ChangeLevel(data);
		}
	}

	data.player.ShowOption(data);

}

void drawCastle(GameData& data)
{
	

	if (data.currentLevel == 0)
	{
		data.dl->AddImage(data.asset.textureCastle.id, { 17 * data.map.Tilesize  , 5 * data.map.Tilesize }, { 18 * data.map.Tilesize + data.map.Tilesize , 6 * data.map.Tilesize + data.map.Tilesize }, ImVec2(0, 0), ImVec2(1, 1));

	}
	if (data.currentLevel == 1)
	{
		data.dl->AddImage(data.asset.textureCastle.id, { 17 * data.map.Tilesize ,  1 * data.map.Tilesize }, { 18 * data.map.Tilesize + data.map.Tilesize ,  1 * data.map.Tilesize + data.map.Tilesize }, ImVec2(0, 0), ImVec2(1, 1));

	}
	if (data.currentLevel == 2)
	{
		data.dl->AddImage(data.asset.textureCastle.id, { 17 * data.map.Tilesize ,  3 * data.map.Tilesize }, { 18 * data.map.Tilesize + data.map.Tilesize ,  3 * data.map.Tilesize + data.map.Tilesize }, ImVec2(0, 0), ImVec2(1, 1));

	}
	if (data.currentLevel == 3)
	{
		data.dl->AddImage(data.asset.textureCastle.id, { 0 ,  2 * data.map.Tilesize }, { data.map.Tilesize ,  2 * data.map.Tilesize + data.map.Tilesize }, ImVec2(0, 0), ImVec2(1, 1));

	}
}





void TowerRenderer::RendererGame(GameData& data)
{
	DrawMap(data);
	renderEntity.RendererEntitys(data);
	data.player.UpdatePlayer(data);
	rendererPlayer.DrawPlayer(data);

	DrawCheckPoint(data);
	DrawEnd(data);
	drawCastle(data);

	



}



TowerRenderer::TowerRenderer()
{

}

TowerRenderer::~TowerRenderer()
{

}
