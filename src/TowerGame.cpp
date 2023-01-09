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
	this->WaveStart = false;
	this->addEnemy = false;

	this->acceleRateTime = 1.f;
	this->enableDebug = false;

	currentWave = Wave::Wave1;
	
	//enemyVector.resize(10);
	

	
	enemy* enemy = new soigneur();
	enemy->pos = ReturnCenter(0, 6,map);

	enemyVector.push_back(enemy);
	
	
	
		/*soigneur* soin = new soigneur();
		enemy* enemie = soin;

		enemie->pos = ReturnCenter(0, 6, map);

		enemyVector.push_back(enemie);
	
	*/

	
	


}


void TowerGame::GameInit()
{



}

void TowerGame::Debug()
{
	






}
void TowerGame::UpdateAndDraw()
{
	ImGuiIO& io = ImGui::GetIO();
	gameData.deltatime = io.DeltaTime;
	




	this->gameData.dl = ImGui::GetBackgroundDrawList();
	gameData.map.CreateMap();

	if (ImGui::IsKeyPressed(ImGuiKey_E, false))
	{
		gameData.addEnemy = !gameData.addEnemy;
		cout << "add enemy = " <<gameData.addEnemy << endl;

		//printf("%s \n", gameData.map.map.c_str());	
		//ptr = &gameData.map.map;//ptr->replace(0, 0, "L");//printf("%s \n", gameData.map.map.c_str());

	}


	if (ImGui::IsKeyPressed(ImGuiKey_Z, false))
	{
		gameData.WaveStart = !gameData.WaveStart;
		cout <<"Start  = " << gameData.WaveStart << endl;
	}

	
	
			
	// work
	if (ImGui::IsKeyPressed(ImGuiKey_A, false))
	{
		enemy* enemy = new soigneur();
		enemy->pos = ReturnCenter(0, 6, gameData.map);

		gameData.enemyVector.push_back(enemy);

	}

	
	


	//	std::cout << gameData.map.map

	//printf("enemie nbr  = %ld", gameData.enemyVector.size());
	enemyManager.ManageEnemy(gameData);




	//Debug();

		ImGui::Text("Time %f", gameData.deltatime);
		ImGui::Text("vectorsise %d", gameData.enemyVector.size());


	
		
	renderer.RendererGame(gameData);

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


