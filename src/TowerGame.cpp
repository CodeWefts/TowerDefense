#include"TowerGame.hpp"
#include"calc.hpp"
#include"soigneur.hpp"
#include "costaud.hpp"

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

	textureCostaud1 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud1.png");
	textureCostaud2 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud2.png");
	textureCostaud3 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud3.png");
	textureCostaud4 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud4.png");
	textureCostaud5 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud5.png");
	textureCostaud6 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud6.png");
	textureCostaud7 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud7.png");
	textureCostaud8 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud8.png");
	textureCostaud9 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud9.png");
	textureCostaud10 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud10.png");
	textureCostaud11 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud11.png");
	textureCostaud12 = ImGuiUtils::LoadTexture("assets/ennemies/costaud/costaud12.png");


	textureGringalet = ImGuiUtils::LoadTexture("assets/ennemies/gringalet.png");
	textureSoigneur = ImGuiUtils::LoadTexture("assets/ennemies/soigneur.png");

	textureTower = ImGuiUtils::LoadTexture("assets/tower/tower.png");

	textureTowerSideLeft = ImGuiUtils::LoadTexture("assets/hud/SideLeft.png");
	textureTowerSideRight = ImGuiUtils::LoadTexture("assets/hud/SideRight.png");
	textureTowerCase = ImGuiUtils::LoadTexture("assets/hud/TowerCase.png");





}


GameData::GameData()
{
	this->acceleRateTime = 1.f;
	this->enableDebug = false;
	enemyVector.resize(2);
	
	enemy* enemie = new soigneur();
	
	enemie->pos = { 100,100 };

	enemyVector.push_back(*enemie);

	enemy* enemie2 = new costaud();

	enemie2->pos = { 300,300 };

	enemyVector.push_back(*enemie2);


}


void TowerGame::GameInit()
{
	
}


void TowerGame::UpdateAndDraw()
{
	ImGuiIO& io = ImGui::GetIO();
	gameData.deltatime = io.DeltaTime;


	this->gameData.dl = ImGui::GetBackgroundDrawList();
	gameData.map.CreateMap();
	enemyManager.ManageEnemy(gameData);
	renderer.RendererGame(this->gameData);

	gameData.player.PlayerTile(gameData);
	gameData.player.PlayerInput(gameData);
}












TowerGame::TowerGame()
{
	this->gameData.dl = nullptr;
}

TowerGame::~TowerGame()
{
}


