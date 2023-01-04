#include"TowerGame.hpp"
#include"calc.hpp"

using namespace std;

GameData::GameData()
{
	
	
	//map.CreateMap();
	
	

}


void TowerGame::GameInit()
{
	
}


void TowerGame::UpdateAndDraw()
{
	
	//cout << gameData.Tiles.at(0).centerPos.x << endl;

	

	//cout << gameData.Tiles.at(0).centerPos.x << endl;


	renderer.dl = ImGui::GetBackgroundDrawList();
	gameData.map.CreateMap();
	renderer.RendererGame(this->gameData);
}












TowerGame::TowerGame()
{
	renderer.dl = nullptr;
}

TowerGame::~TowerGame()
{
}


