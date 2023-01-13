#include"TowerGame.hpp"
#include"calc.hpp"
#include"soigneur.hpp"
#include "costaud.hpp"

using namespace std;


Asset::Asset()
{
	//Grass
	textureGrass = ImGuiUtils::LoadTexture("assets/map/grass.png");

	//Path
	textureDirt = ImGuiUtils::LoadTexture("assets/map/dirt.png");
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

	//ENNEMY 1 : GRINGALET
	textureGringalet = ImGuiUtils::LoadTexture("assets/ennemies/gringalet.png");

	//ENNEMY 2 : SOIGNEUR
	textureSoigneur = ImGuiUtils::LoadTexture("assets/ennemies/soigneur.png");

	//ENNEMY 3 : COSTAUD
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

	//TOWER 1 : TOWER
	textureTowerClassique = ImGuiUtils::LoadTexture("assets/tower/classique.png");

	//INVENTORY HUD
	textureTowerSideLeft = ImGuiUtils::LoadTexture("assets/hud/SideLeft.png");
	textureTowerSideRight = ImGuiUtils::LoadTexture("assets/hud/SideRight.png");
	textureTowerCase = ImGuiUtils::LoadTexture("assets/hud/TowerCase.png");


	//MENU : START GAME
	textureAnimation = ImGuiUtils::LoadTexture("assets/menu/Animation.png");


}


GameData::GameData()
{
	this->acceleRateTime = 0;
	this->acceleRateTimeBuffer = 0;

	this->WaveStart = false;
	this->addEnemy = false;
	this->playerStopTime = false;

	this->acceleRateTime = 1.f;
	this->enableDebug = false;


	timerWave = 5.f;
	this->deltatime = 0.f;
	this->dl = nullptr;



}


void TowerGame::GameInit()
{



}

void TowerGame::Debug()
{

	if (ImGui::IsKeyPressed(ImGuiKey_S, false))
	{
		gameData.map.map.at(3) = 'k';
		printf("%s \n", gameData.map.map.c_str());

	}
	if (ImGui::IsKeyPressed(ImGuiKey_E, false))
	{
		gameData.addEnemy = !gameData.addEnemy;
		cout << "add enemy = " << gameData.addEnemy << endl;

		//ptr = &gameData.map.map;//ptr->replace(0, 0, "L");//printf("%s \n", gameData.map.map.c_str());

	}

	if (ImGui::IsKeyPressed(ImGuiKey_Z, false))
	{
		gameData.WaveStart = !gameData.WaveStart;
		cout << "Start  = " << gameData.WaveStart << endl;
	}


	// work
	if (ImGui::IsKeyPressed(ImGuiKey_A,false))
	{
		enemy* enemy = new soigneur();
		enemy->pos = ReturnCenter(0, 6, gameData.map);

		gameData.enemyVector.push_back(enemy);

	}

}

void TowerGame::UpdateAndDraw()
{
	srand(time(NULL));
	ImGuiIO& io = ImGui::GetIO();
	gameData.deltatime = io.DeltaTime * gameData.acceleRateTime;
	this->gameData.dl = ImGui::GetBackgroundDrawList();
	gameData.timerWave -= gameData.deltatime;
	
	Debug();
	ImGui::Text("Time %f", gameData.deltatime);
	ImGui::Text("vectorsise %d", gameData.enemyVector.size());
	ImGui::Text("Wavetimer = %f ", gameData.timerWave);
	
	
	
	gameData.map.CreateMap();
	enemyManager.ManageEnemy(gameData);

	renderer.RendererGame(gameData);

	gameData.player.PlayerTile(gameData);
	gameData.player.PlayerInput(gameData);

	renderer.HudInventory(gameData);
	gameData.player.DragAndDrop(gameData);



	
}


TowerGame::TowerGame()
{
	this->gameData.dl = nullptr;
}

TowerGame::~TowerGame()
{
	
}


