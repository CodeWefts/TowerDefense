#include"TowerGame.hpp"

using namespace std;

GameData::GameData()
{
	


	Tiles.resize(20 * 36);

	auto it = Tiles.begin();
	it->centerPos = { 36, 36 };
	
	map.ManageMap(Tiles);

	

}


void TowerGame::GameInit()
{
	
}


void TowerGame::UpdateAndDraw()
{
	
	//cout << gameData.Tiles.at(0).centerPos.x << endl;

	

	//cout << gameData.Tiles.at(0).centerPos.x << endl;
	
	renderer.RendererGame(this->gameData);
}


void TowerRenderer::RendererGame( GameData& data)
{
	dl = ImGui::GetBackgroundDrawList();
	
	

	for (auto it = data.Tiles.begin(); it != data.Tiles.end(); it++)
	{
		dl->AddRect(ImVec2(it->posMin.x, it->posMin.y), ImVec2(it->posMax.x, it->posMax.y), IM_COL32(255, 255, 255, 255), 0);
		dl->AddCircle(ImVec2(it->centerPos.x, it->centerPos.y), 5.f, IM_COL32(255, 255, 255, 255), 32, 1);
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