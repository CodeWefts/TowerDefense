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
float2* points = new float2(450, 450);



void TowerGame::UpdateAndDraw()
{
	srand(unsigned int(time(NULL)));


	gameData.dl = ImGui::GetBackgroundDrawList();
	ImGuiIO& io = ImGui::GetIO();
	gameData.deltatime = io.DeltaTime * gameData.acceleRateTime;

	if (gameData.currentScene == Menu)
	{
		gameData.dl->AddImage(gameData.asset.textureBackGround.id, { 0, 0 }, io.DisplaySize);
		gameData.time += io.DeltaTime;
		renderer.DrawMenu(gameData);
	}
	else if (gameData.currentScene == Game)
	{
		LoadALLPath(gameData);

		gameData.map.CreateMap(gameData);
		enemyManager.ManageEnemy(gameData);
		ManageAllTurret(gameData);

		
		renderer.RendererGame(gameData);


		Debug(gameData);
	}
	else if (gameData.currentScene == Option)
	{

	}
	else if (gameData.currentScene == GameOver)
	{
		renderer.DrawEnd(gameData);
	}
}


TowerGame::TowerGame()
{
	this->gameData.dl = nullptr;

}
TowerGame::~TowerGame()
{

}


