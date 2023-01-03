#include"TowerGame.hpp"

using namespace std;

GameData::GameData()
{
	
	Tiles.resize(10000);
	
	auto it =Tiles.begin();
	it->centerPos = { 100.f, 100.f };

	

}


void TowerGame::GameInit()
{
	
}


void TowerGame::UpdateAndDraw()
{
	
	gameData.map.ManageMap(gameData.Tiles);

	//cout << gameData.Tiles.at(1).centerPos.x << endl;

	//cout << gameData.Tiles.at(0).centerPos.x << endl;
	
	renderer.RendererGame(this->gameData);
}


void TowerRenderer::RendererGame(const GameData& data)
{
	dl = ImGui::GetBackgroundDrawList();

	

	for (auto it = data.Tiles.begin(); it != data.Tiles.end(); it++)
	{
		dl->AddRect(ImVec2(it->posMin.x, it->posMin.y), ImVec2(it->posMax.x, it->posMax.y), IM_COL32(255, 255, 255, 255), 0); 
	}
	
}









TowerGame::TowerGame()
{
}

TowerGame::~TowerGame()
{
}


TowerRenderer::TowerRenderer()
{
	
}

TowerRenderer::~TowerRenderer()
{
}