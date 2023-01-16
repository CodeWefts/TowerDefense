#include "tower_game.hpp"
#include "calc.hpp"
#include "Healer.hpp"
#include "heavy.hpp"
#include "weakling.hpp"



using namespace std;



void TowerGame::GameInit()
{
	srand(unsigned int(time(NULL)));

}



void TowerGame::UpdateAndDraw()
{
	
	gameData.dl = ImGui::GetBackgroundDrawList();
	ImGuiIO& io = ImGui::GetIO();
	gameData.deltatime = io.DeltaTime * gameData.acceleRateTime;

	if (gameData.currentScene == Menu)
	{
		gameData.time += io.DeltaTime;
		renderer.DrawMenu(gameData);
	}
	else if (gameData.currentScene == Game)
	{
		LoadALLPath(gameData);

		gameData.map.CreateMap(gameData);
		enemyManager.ManageEnemy(gameData);
		towerManager.TargetEnemy(gameData);
		
		renderer.RendererGame(gameData);

		renderer.HudInventory(gameData);
		gameData.player.UpdatePlayer(gameData);
		tower.TargetEnemy(gameData);


		Debug(gameData);
	}
	else if (gameData.currentScene == Option)
	{

	}
	else if (gameData.currentScene == GameOver)
	{

	}
}


TowerGame::TowerGame()
{
	this->gameData.dl = nullptr;

}
TowerGame::~TowerGame()
{

}


