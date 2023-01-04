#include"TowerGame.hpp"
#include"calc.hpp"

using namespace std;

Asset::Asset()
{
	textureDirt = ImGuiUtils::LoadTexture("assets/map/dirt.png");
	textureGrass = ImGuiUtils::LoadTexture("assets/map/grass.png");
	texturePathBottom = ImGuiUtils::LoadTexture("assets/map/pathBottom.png");
	texturePathBottomANDLeft = ImGuiUtils::LoadTexture("assets/map/pathBottomANDLeft.png");
	texturePathBottomANDRight = ImGuiUtils::LoadTexture("assets/map/pathBottomANDRight.png");
	texturePathBottomLeft = ImGuiUtils::LoadTexture("assets/map/pathBottomLeft.png");
	texturePathBottomRight = ImGuiUtils::LoadTexture("assets/map/pathBottomRight.png");
	texturePathLeft = ImGuiUtils::LoadTexture("assets/map/pathLeft.png");
	texturePathRight = ImGuiUtils::LoadTexture("assets/map/pathRight.png");
	texturePathTop = ImGuiUtils::LoadTexture("assets/map/pathTop.png");
	texturePathTopANDLeft = ImGuiUtils::LoadTexture("assets/map/pathTopANDLeft.png");
	texturePathTopANDRight = ImGuiUtils::LoadTexture("assets/map/pathTopANDRight.png");
	texturePathTopLeft = ImGuiUtils::LoadTexture("assets/map/pathTopLeft.png");
	texturePathTopRight = ImGuiUtils::LoadTexture("assets/map/pathTopRight.png");
	textureCostaud = ImGuiUtils::LoadTexture("assets/ennemies/costaud.png");
	textureGringalet = ImGuiUtils::LoadTexture("assets/ennemies/gringalet.png");
	textureSoigneur = ImGuiUtils::LoadTexture("assets/ennemies/soigneur.png");

}


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


